#include <stdio.h>
#include <memory.h>
#include <stdbool.h>

typedef  char tmatice[250][250];

int pocet;
tmatice matice;
int radky[250];

bool prehod(int x)
{
	//existuje radka pro prehozeni
	bool lze = false;
	//cislo radky
	int pom = 0;
	//hledani radky s 1 ve stejnem sloupci
	for (int i = x + 1; i < pocet; i++)
	{
		if (matice[radky[i]][x] == 1)
		{
			lze = true;
			pom = i;
			break;
		}
	}
	//prohozeni informace o poradi
	if (lze)
	{
		int vymena = radky[pom];
		radky[pom] = radky[x];
		radky[x] = vymena;

	}
	return lze;

}


int main(int argc, char **argv) {
	
	scanf("%d\n", &pocet);
	int nactene;	
	memset(matice, 0, sizeof(tmatice));
	memset(radky, 0, sizeof(radky));

	//nacteni ventilu k jednotlivym technikum
	for (int i = 0; i < pocet; i++)
	{
		radky[i] = i;
		for (int j = 0; j < pocet + 1; j++)
		{
			scanf("%d", &nactene);
			//ukonceni nacitani ventilu pro i-teho technika
			if (nactene == -1)
			{
				break;
			}
			else
			{
				matice[nactene - 1][i] = 1;
			}
		}
	}


	//nastavani prave strany matice
	for (int i = 0; i < pocet; i++)
	{
		matice[i][pocet] = 1;
	}


	for (int i = 0; i < pocet; i++)
	{
		//test, zda je na diagonale 1
		if (matice[radky[i]][i] != 1)
		{
			//pokus o najiti takove radky, aby se na diagonalu dostala 1
			//nasledne se prehodi
			if (prehod(i) == false)
			{			
				printf("-1\n");
				return 0;
			}
		}
		//nulovani prvku pod diagonalou
		for (int j = i + 1; j < pocet; j++)
		{
			if (matice[radky[j]][i] == 1)
			{
				for (int k = 0; k < pocet + 1; k++)
				{
					matice[radky[j]][k] = (char)(matice[radky[i]][k] ^ matice[radky[j]][k]);
				}
			}
		}
	}


	//nulovani prvku nad diagonalou
	for (int i = pocet - 1; i >= 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (matice[radky[j]][i] == 1)
			{
				for (int k = 0; k < pocet + 1; k++)
				{
					matice[radky[j]][k] = (char)(matice[radky[i]][k] ^ matice[radky[j]][k]);
				}
			}

		}
	}

	bool poprve = true;
	//vypis vysledku
	for (int i = 0; i < pocet; i++)
	{
		if (poprve)
		{
			if (matice[radky[i]][pocet] == 1)
			{				
				printf("%d", i + 1);
				poprve = false;
			}
		}
		else
		{
			if (matice[radky[i]][pocet] == 1)
			{				
				printf(" %d", i + 1);
			}
		}

	}
	if (poprve)
	{
		printf("-1\n");
	}
	else
	{
		printf("\n");
	}


	return 0;
}