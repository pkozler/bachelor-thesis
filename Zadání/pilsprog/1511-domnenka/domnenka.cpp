#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//jestlize je liche prvocislo
bool jePrvocislo(int cislo) {
	if (cislo <= 2) {
		return false;
	}
	/*if (cislo == 2) {
	return true;
	}*/
	if (cislo % 2 == 0) {
		return false;
	}

	int sqrttmp = (int) sqrt(cislo);
	for (int i = 3; i <= sqrttmp; i += 2) {
		if (cislo % i == 0) {
			return false;
		}
	}
	return true;

}

int main(int argc, char **argv) {
	int sudeCislo;
	bool nalezeno;

	for (;;) {
		scanf("%d\n", &sudeCislo);
		if (sudeCislo == 0) break;

		nalezeno = false;

		for (int i = 1, j = sudeCislo - 1; i <= sudeCislo / 2; i++, j--) {
			if (jePrvocislo(i) && jePrvocislo(j)) {
				printf("%d = %d + %d\n", sudeCislo, i, j);
				nalezeno = true;
				break;
			}
		}

		if (nalezeno == false) {
			printf("Neplati!\n");
		}
	}

	return 0;
}