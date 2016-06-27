#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define maxlinelen 100

char hashMap[256];
	
void nastavZnaky() {
		 hashMap['A']= 'A';
		 hashMap['B']= ' ';
		 hashMap['C']= ' ';
		 hashMap['D']= ' ';
		 hashMap['E']= '3';
		 hashMap['F']= ' ';
		 hashMap['G']= ' ';
		 hashMap['H']= 'H';
		 hashMap['I']= 'I';
		 hashMap['J']= 'L';
		 hashMap['K']= ' ';
		 hashMap['L']= 'J';
		 hashMap['M']= 'M';
		 hashMap['N']= ' ';
		 hashMap['O']= 'O';
		 hashMap['P']= ' ';
		 hashMap['Q']= ' ';
		 hashMap['R']= ' ';
		 hashMap['S']= '2';
		 hashMap['T']= 'T';
		 hashMap['U']= 'U';
		 hashMap['V']= 'V';
		 hashMap['W']= 'W';
		 hashMap['X']= 'X';
		 hashMap['Y']= 'Y';
		 hashMap['Z']= '5';
		 hashMap['1']= '1';
		 hashMap['2']= 'S';
		 hashMap['3']= 'E';
		 hashMap['4']= ' ';
		 hashMap['5']= 'Z';
		 hashMap['6']= ' ';
		 hashMap['7']= ' ';
		 hashMap['8']= '8';
		 hashMap['9']= ' ';
}
	

bool jePalindrom(char* str) {

	size_t len = strlen(str);

	size_t ri = len;
	for (size_t i = 0; i < len; i++) {
		ri--;
		if (str[i] != str[ri]) return false;
	}

	return true;
}

bool jeZrcadlenyRetezec(char *str) {
	size_t len = strlen(str);

		for (size_t i = 0, j = len-1; i <= len/2; i++, j--) {
			if (str[i] != hashMap[str[j]]) {
				return false;
			}
		}
	return true;
}
	
int main(int argc, char **argv) {
	size_t n, pocetZadani = 0;
	bool palindrom;
	bool zrcadlenyRetezec;

	
	char radka[maxlinelen];

	nastavZnaky();

	scanf("%d\n", &pocetZadani);
	for (n = 0; n < pocetZadani; n++) {
		//fgets(radka, maxlinelen, stdin);
		scanf("%s\n", &radka);
		

		palindrom = jePalindrom(radka);
		zrcadlenyRetezec = jeZrcadlenyRetezec(radka);


		if (palindrom && zrcadlenyRetezec) {
				printf("%s: zrcadlovy palindrom\n\n", radka);
			} else if (palindrom && !zrcadlenyRetezec){
				printf("%s: palindrom\n\n", radka);
			} else if (!palindrom && zrcadlenyRetezec){
				printf("%s: zrcadlovy retezec\n\n", radka);
			} else {
				printf("%s: retezec\n\n", radka);
			}
	}

	return 0;
}