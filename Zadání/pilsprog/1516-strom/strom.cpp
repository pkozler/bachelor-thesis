#include <stdio.h>
#include <string.h>

#define maxlinelen 1024

void zpracujCast(char* preorder, char* inorder) {		
	char znak;
	char *znakpos;
	do {
		if (!*preorder) return;

		znak = *preorder;
		preorder++;

		znakpos = strchr(inorder, znak);
	} while ( znakpos == NULL);
		
	*znakpos = 0;

	zpracujCast(preorder, inorder);
	zpracujCast(preorder, znakpos + 1);

	putchar(znak);
}


int main(int argc, char **argv) {

	size_t zadani;
	char preorder[maxlinelen], inorder[maxlinelen];
	
	scanf("%d\n", &zadani);
	while (zadani--) {
		scanf("%s %s\n", preorder, inorder);
		
		zpracujCast(preorder, inorder);
		
		putchar('\n');
	}


	return 0;
}