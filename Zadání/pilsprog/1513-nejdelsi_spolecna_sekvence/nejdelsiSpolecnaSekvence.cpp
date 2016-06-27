#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>


/*
  Zrejme na validatoru stary GCC, ktery ma problemy s
  
   #define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })


*/

#ifdef __cplusplus
	const size_t maxsize = 102;  
#else
	#define maxsize  105
#endif

#ifndef max 
	#define max(a, b) (((a) > (b)) ? (a) : (b)) 
#endif



int main(int argc, char** argv) {

  size_t pole[maxsize][maxsize];

	char prvniRetezec[maxsize + 1];
	char druhyRetezec[maxsize + 1];
	size_t icnt, jcnt;

	size_t pocetZadani;
	scanf("%d\n", &pocetZadani);

	for (size_t n = 0; n < pocetZadani; n++) {
		//scanf("%s\n", prvniRetezec);
		//scanf("%s\n", druhyRetezec);
		fgets(prvniRetezec, maxsize, stdin);
		fgets(druhyRetezec, maxsize, stdin);

		icnt = strlen(prvniRetezec);// +1;	fgets returns \n
		jcnt = strlen(druhyRetezec);// +1;


		//výpoèet tabulky
		memset(pole, 0, sizeof(pole));
		
		for (size_t i = 1; i < icnt; i++) {
			for (size_t j = 1; j < jcnt; j++) {
				if (prvniRetezec[i - 1] == druhyRetezec[j - 1]) {
					pole[i][j] = pole[i - 1][j - 1] + 1;
				}
				else {
					pole[i][j] =  max(pole[i - 1][j], pole[i][j - 1]);
				}
			}
		}
		//v posledni bunce je vysledek
		printf("%d\n", pole[icnt - 1][jcnt - 1]);		
	}

	return 0;
}