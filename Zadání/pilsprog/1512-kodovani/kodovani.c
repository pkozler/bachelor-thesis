#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define maxlinelen 2048

bool jecislo(char *str) {
	while (*str) {
		if (!isdigit(*str)) return false;
		str++;
	}

	return true;
}

void obrat(char *str) {
	size_t len = strlen(str);

	for (size_t i = 0; i < len / 2; i++) {
		char tmpchar = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmpchar;
	}
}


void dekoduj(char *str, char *result) {
	char znak;


	while (*str) {	
		znak = *str - '0';

		bool extended = znak == 1;

		znak *= 10;
		str++;
		
		znak += *str - '0';
		str++;

		if (extended) {
			znak *= 10;
			znak += *str - '0';
			str++;
		}

		*result = znak;
		result++;
	}

	*result = 0;
}

void zakoduj(char *str, char *result) {
	while (*str) {
		int written = sprintf(result, "%d", (int)*str);
		result += written;
		str++;
	}

	*result = 0;
}




int main(int argc, char **argv) {

	int pripadu;
	scanf("%d\n", &pripadu);
	char radka[maxlinelen];
	char vysledek[maxlinelen];

	for (int i = 0; i < pripadu; i++) {
		//scanf("%s\n", radka);
		fgets(radka, maxlinelen, stdin);
		char *tmp = strstr(radka, "\n");
		*tmp = 0;

		if (jecislo(radka)) {
			obrat(radka);
			dekoduj(radka, vysledek);
		}
		else {
			zakoduj(radka, vysledek);
			obrat(vysledek);
		}

		printf("%s\n", vysledek);
	}

	return 0;
}