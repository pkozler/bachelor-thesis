#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

#ifndef max 
	#define max(a, b) (((a) > (b)) ? (a) : (b)) 
#endif

#define maxnumlen 10002
#define ZNAMENKO_PLUS  1
#define  ZNAMENKO_MINUS  -1
#define  POCET_DESETINNYCH_MIST_NAVIC  400000
#define  MAXIMALNI_DELKA_ZBYTKU 1000

#define MAX_ZBYTKU POCET_DESETINNYCH_MIST_NAVIC  

#ifndef __cplusplus
	typedef long long ssize_t;
#else 
	//if defined (_MSC_VER) && !

#endif

typedef struct {
	int znamenko;
	bool neniNula;
	char cislice[maxnumlen];
	ssize_t cislicelength;
} TVelkeCislo;

typedef struct {
	char *val;
	ssize_t len;
} TZbytek;

void clearzbytky(TZbytek *zbytky) {
	for (ssize_t i = 0; i < MAX_ZBYTKU; i++) {
		if (zbytky[i].val != NULL) {
			free(zbytky[i].val);
			zbytky[i].len = 0;
			zbytky[i].val = NULL;
			break;
		}
	}
}

TVelkeCislo *AllocVelkeCislo(char *str) {
	TVelkeCislo *result = (TVelkeCislo*)calloc(1, sizeof(TVelkeCislo));
	
	if (str[0] == '-') {
		result->znamenko = ZNAMENKO_MINUS;
		str++;
	}
	else
		result->znamenko = ZNAMENKO_PLUS;


	ssize_t len = strlen(str);
	bool nz = false;
	for (ssize_t i = 0; i < len; i++) {
		char tmp = str[i] - '0';
		result->cislice[i] = tmp;
		nz |= tmp != 0;
	}

	result->cislicelength = len;
	result->neniNula = nz;

	return result;
}

int porovnej(char* cislice1, int posun1, char* cislice2, int delka2) {
	if (posun1 - 1 >= 0) {
		if (cislice1[posun1 - 1] > 0) {
			return -1;
		}
	}

	int i = 0;
	for (i = 0; i < delka2; i++) {
		if (cislice1[i + posun1] != cislice2[i]) {
			break;
		}
	}
	if (i == delka2) {
		i--;
	}

	if (cislice1[i + posun1] > cislice2[i]) {
		return -1;
	}
	else if (cislice1[i + posun1] < cislice2[i]){
		return 1;
	}
	else {
		return 0;
	}
}

bool jsouZbytkyShodne(TZbytek* zbytek1, TZbytek* zbytek2) {
	if (zbytek1->len != zbytek2->len) return false;

	return memcmp(zbytek1->val, zbytek2->val, zbytek1->len) == 0 ? true : false;
}

void vydel(TVelkeCislo *todle, TVelkeCislo *delitel, char *vysledekStr) {
	if (!(todle->neniNula) | (!delitel->neniNula)) {  //Delenec je nulovy
		vysledekStr[0] = '0';
		vysledekStr[1] = 0;
		return;
	}

	char *vysledekStrOldPr = vysledekStr;
	
	ssize_t vysledeklength = todle->cislicelength + POCET_DESETINNYCH_MIST_NAVIC;
	char *vysledek = (char*)calloc(vysledeklength, sizeof(char));
	char *delenec = (char*)calloc(vysledeklength, sizeof(char));

	TZbytek *zbytky = (TZbytek*)calloc(MAX_ZBYTKU, sizeof(TZbytek));
	int pocetZbytku = 0;	
	TZbytek zbytek = {0};	//neuvolnujeme
	for (ssize_t i = 0; i < todle->cislicelength; i++) {
		delenec[i] = todle->cislice[i];
		vysledek[i] = 0;
	}


	ssize_t posunDelenec = 0;
	int poziceDelenec = 0;
	int poziceDelitel = 0;
	int cisliceOdcitani = 0;
	int cislicePrenosu = 0;
	int indexCisliceVysledku = 0;
	int porovnani = 0;

	int indexZacatkuPeriody = 0;
	int indexDesetinneTecky = 0;
	bool perioda = false;
	int delkaPeriody = -1;
	bool uzJsemTuByl = false;

	//Transformace delence (posun vravo), aby byl pri prvnim deleni vetsi nez delitel. Pokud vyjde posun zaporny, znamena to, ze delenec je vetsi nez delitel a pak vyuzijeme jen cast delence   
	int pocatecniPosunDelenec = delitel->cislicelength - todle->cislicelength;
	indexDesetinneTecky = -pocatecniPosunDelenec;
	if (porovnej(delenec, 0, delitel->cislice, delitel->cislicelength) == 1) {  //Delitel je vetsi kdyz vezmu stejny pocet cislic delence - uprava o jedno misto
		pocatecniPosunDelenec++;
		posunDelenec++;
		indexDesetinneTecky--;
	}

	while (true) {
		while ((porovnani = porovnej(delenec, posunDelenec, delitel->cislice, delitel->cislicelength)) <= 0) { //Dokud je delenec vetsi nebo stejny nez delitel, odecitej delitele od delence
			cislicePrenosu = 0;
			for (int i = delitel->cislicelength - 1; i >= 0; i--) {  //Jedno odecteni delitele od delence
				cisliceOdcitani = delenec[i + posunDelenec] - (delitel->cislice[i] + cislicePrenosu);

				if (cisliceOdcitani < 0) {
					cisliceOdcitani += 10;
					cislicePrenosu = 1;
				}
				else {
					cislicePrenosu = 0;
				}

				delenec[i + posunDelenec] = cisliceOdcitani;
			}
			if (cislicePrenosu > 0) {
				delenec[posunDelenec - 1] -= cislicePrenosu;
			}

			vysledek[indexCisliceVysledku]++;
		}

		bool nulovyDelenec = true;
		ssize_t i = 0;
		for (i = 0; i < max(delitel->cislicelength, todle->cislicelength); i++) {
			if (delenec[posunDelenec + i] != 0) {
				nulovyDelenec = false;
				posunDelenec += i;
				indexCisliceVysledku += i;
				break;
			}
		}
		if (nulovyDelenec) { //Nezbyl zadny zbytek
			break;
		}
		else  {  //Nejaky zbytek zbyl, ulozim si ho do pole zbytku		
			zbytek.len = delitel->cislicelength;
			if (todle->cislicelength > i) {
				ssize_t tmp = todle->cislicelength - i;
				if (tmp > zbytek.len) zbytek.len = tmp;
			}

			//zbytek.len = max(delitel->cislicelength, todle->cislicelength - i);
			zbytek.val = (char*)calloc(zbytek.len, sizeof(char));
			
			if (delitel->cislicelength >= i) {
				for (ssize_t j = 0; j < delitel->cislicelength - i; j++) {
					zbytek.val[j] = delenec[posunDelenec + j];
				}
			}

			if (posunDelenec >= todle->cislicelength - delitel->cislicelength) {

				int shodnyZbytekIndex = -1;
				for (int j = 0; j < pocetZbytku; j++) { //Prohledani zbytku, zda uz novy zbytek neni obsazen
					if (jsouZbytkyShodne(&zbytek, &zbytky[j])) {
						if (!uzJsemTuByl) {
							clearzbytky(zbytky);
							pocetZbytku = 0;
							uzJsemTuByl = true;
							delkaPeriody = posunDelenec;
						}
						else {
							delkaPeriody = posunDelenec - delkaPeriody;
							shodnyZbytekIndex = j;
							break;
						}
					}
				}
				if (shodnyZbytekIndex < 0) {
					//zbytky.add(zbytek);
					zbytky[pocetZbytku] = zbytek;
					pocetZbytku++;
				}
				else { //Novy zbytek uz je obsazen - detekovana perioda
					perioda = true;
					break;
				}
			}
		}

		if (porovnej(delenec, posunDelenec, delitel->cislice, delitel->cislicelength) == 1) {
			posunDelenec++;
			indexCisliceVysledku++;
		}
	}

	if (todle->znamenko != delitel->znamenko) {
		*vysledekStr = '-';
		vysledekStr++;
	}	

	int puvodniIndexDesetinneTecky = indexDesetinneTecky;

	if (indexDesetinneTecky < 0) {		
		*vysledekStr = '0';
		vysledekStr++;
		*vysledekStr = '.';
		vysledekStr++;

		indexDesetinneTecky++;
		while (indexDesetinneTecky < 0) {
			*vysledekStr = '0';
			vysledekStr++;
			indexDesetinneTecky++;
		}
		indexDesetinneTecky = -1; //Abych uz se ji nezabyval v nasledujicim cyklu
	}
	else if (indexDesetinneTecky == 0) {
		if ((delitel->cislicelength > todle->cislicelength) || ((delitel->cislicelength == todle->cislicelength) && (porovnej(todle->cislice, 0, delitel->cislice, delitel->cislicelength) == 1))) {  //Delitel je vetsi nez delenec
			*vysledekStr = '0';
			vysledekStr++;
			*vysledekStr = '.';
			vysledekStr++;
		}
		else {
			indexDesetinneTecky++;
		}
	}

	if (puvodniIndexDesetinneTecky > 0) {
		indexDesetinneTecky++;
	}

	for (int i = 0; i <= indexCisliceVysledku; i++) {
		if (indexDesetinneTecky > 0) {
			if (i == indexDesetinneTecky) {				
				*vysledekStr = '.';
				vysledekStr++;
			}
		}

		*vysledekStr = vysledek[i]+'0';
		vysledekStr++;
	}

	*vysledekStr = 0;

	vysledekStr = vysledekStrOldPr;

	if (delkaPeriody >= 0) {
				ssize_t tecka = strchr(vysledekStr, '.') - vysledekStr;

		ssize_t vysledekStrlength = strlen(vysledekStr);

		for (ssize_t i = 0; i < vysledekStrlength - tecka; i++) {
			bool nalezeno = true;

			for (int j = 0; j < delkaPeriody; j++) {
				if ((((j + tecka + 1 + delkaPeriody + i) >= vysledekStrlength)) || (vysledekStr[j + tecka + 1 + i] != vysledekStr[j + tecka + 1 + delkaPeriody + i])) {
					nalezeno = false;
					break;
				}
			}

			if (nalezeno) {
				indexZacatkuPeriody = (i + tecka + 1);
				break;
			}
		}

		memmove(&vysledekStr[indexZacatkuPeriody + 1], &vysledekStr[indexZacatkuPeriody], delkaPeriody);
		vysledekStr[indexZacatkuPeriody] = '(';
		vysledekStr[indexZacatkuPeriody + delkaPeriody + 1] = ')';
		vysledekStr[indexZacatkuPeriody + delkaPeriody + 2] = 0;

		//vysledekStr = vysledekStr.substring(0, indexZacatkuPeriody) + "(" + vysledekStr.substring(indexZacatkuPeriody, indexZacatkuPeriody + delkaPeriody) + ")";
	}


	free(vysledek);
	free(delenec);
	clearzbytky(zbytky);
	free(zbytky);	
}


int main(int argc, char **argv) {

	char numastr[maxnumlen*2 + POCET_DESETINNYCH_MIST_NAVIC];
	char numbstr[maxnumlen];

	int pripadu;
	scanf("%d\n", &pripadu);
	while (pripadu--) {
		scanf("%s : %s\n", &numastr, &numbstr);

		TVelkeCislo *delenec = AllocVelkeCislo(numastr);
		TVelkeCislo *delitel = AllocVelkeCislo(numbstr);

		vydel(delenec, delitel, numastr);
		printf("%s\n", numastr);

		free(delenec);
		free(delitel);
	}

	return 0;
}