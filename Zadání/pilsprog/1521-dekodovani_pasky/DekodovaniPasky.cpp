#include <stdio.h>

#define linelen 80

int main(int argc, char **argv) {

	char buf[linelen];

	//cti dokud nebude zacatek pasky
	while (getchar() != '_');

	fgets(buf, linelen, stdin);
	fgets(buf, linelen, stdin);
	do {
		int cislo = 0;
		for (int i = 2; i < 10; i++) {
			switch (buf[i]) {
			   case 'o': cislo = cislo << 1;
						 cislo = cislo | 1;
						 break;
			   case ' ': cislo = cislo << 1;
						 break;
			}
		}
		putchar(cislo);
		fgets(buf, linelen, stdin);	//nacist novou radku
	} while (buf[0] != '_');

	return 0;
}