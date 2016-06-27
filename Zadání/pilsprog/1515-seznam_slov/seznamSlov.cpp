#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define maxlines 5100
#define maxlinelen 210


int stringcmp(const void *a, const void *b)
{
	const char **ia = (const char **)a;
	const char **ib = (const char **)b;
	return strcmp(*ia, *ib);
}


char allchars[maxlines*maxlinelen];
char *allwords[maxlines*maxlinelen];

int main(int argc, char **argv) {


	memset(allchars, 0, maxlines*maxlinelen);
	size_t read = fread(allchars, sizeof(char), maxlines*maxlinelen, stdin);

	char **word = allwords;

	bool inword = false;

	//do allwords si udelame indexy na vsechny null-terminated slova v allchars
	for (size_t i = 0; i < read; i++) {
		if (isalpha(allchars[i])) {

			allchars[i] = tolower(allchars[i]);

			if (!inword) {
				*word = &allchars[i];
				word++;
				inword = true;
			}
		}
		else {
			allchars[i] = 0;
			inword = false;
		}

	}

	allchars[read] = 0;

	//ted musime setridit allwords podle abecedy
	char **wordend = word;
	qsort(allwords, word - allwords, sizeof(char*), stringcmp);

	word = allwords;
	char *lastword = NULL;
	while (word != wordend) {
		if (lastword != NULL) {
			if (strcmp(lastword, *word) != 0)
				printf("%s\n", *word);
		} else
		 printf("%s\n", *word);


		lastword = *word;
		word++;
	}

	return 0;
}