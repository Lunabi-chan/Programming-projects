#include <stdio.h>
#include <string.h>

typedef struct { char cesky[16], anglicky[16]; } Slovnik;

#include "ZPC107 U07.inc"

int strcmp(const char* str1, const char* str2);

void Prelozit(const Slovnik S[], unsigned pocet, const char* cesky)
{
	printf("%s: ", cesky);
	for (int i = 0; i < pocet; i++)
	{
		const Slovnik *t = S + i;

		printf("%s ", t->anglicky);
	}
}

void Vymena(Slovnik S[], int i, int k)
{
	Slovnik pom = S[i];
	S[i] = S[k];
	S[k] = pom;
}

unsigned Vytvorit(const Slovnik vstupni[], unsigned pocet, Slovnik vystupni[])
{
	int k = 0;
	for (int i = 0; i < pocet; i++)
	{
		const Slovnik *u = CA + i;

		if ((strcmp(vstupni, u->cesky) == 0))
		{
			vystupni[k] = CA[i];
			k++;
		}
	}	


	if (k > 0)
	{
		for (int i = 0; i < k; i++)
		{
			for (int j = i+1; j < k; j++)
			{
				const Slovnik *u = vystupni + i;
				const Slovnik *o = vystupni + j;

				if ((strcmp(u->anglicky, o->anglicky) == 0))
				{ 
					Vymena(vystupni, j, k-1);
					k--, i = 0, j = i+1;
				}
			}
		}

		char* a = vstupni;
		Prelozit(vystupni, k, a);	
	}
	else
		printf("\nSlovo '%s' nebylo nalezeno\n", vstupni);
}


void main()
{
	char a[16];
	int b[100];

	printf("Do slovniku zadavejte slova a oddelujte mezerou.\nJestli chcete aplikaci ukoncit, napiste 'exit'.\n\n");

	while (1)
	{
		scanf("\n\t%s", a);

		if ((strcmp(a, "exit") == 0))
		{
			break;
		}

		Vytvorit(a, CAPocet, b);
		printf("\n");
	}
}