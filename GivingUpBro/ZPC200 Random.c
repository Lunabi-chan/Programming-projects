#include <stdio.h>
#include <time.h>

struct struktura { /*definovane polozky datoveho typu*/ int test; };

void Bezpoint(int pole[], int size)
{
	printf("\n");

	clock_t t;
	t = clock();	

	for (int i = 0; i < size; i++)
	{
		printf("%d ", pole[i]);
	}

	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;

	printf("\nBezpoint - zabrany cas: %f \n", time_taken);
}

void Spoint(int pole[], int size)
{
	clock_t ti;
	ti = clock();

	/*printf("\n");

	for (int i = 0; i < sizeof pole / sizeof pole[0]; i++)
	{
		printf("%d ", *(pole + i));
	}*/

	printf("\n");

	int* poi = pole;
	for (int i = 0; i < size; poi++)
	{
		printf("%d ", *poi);
		i++;
	}

	ti = clock() - ti;
	double time_taken = ((double)ti) / CLOCKS_PER_SEC;

	printf("\nSpoint - zabrany cas: %f \n", time_taken);
}

void vypis(int* pole, int zacatek, int krok, int konec)
{
	for (int i = zacatek; i < konec; i = i + krok)
	{
		printf("%d ", *(pole + i));
	}
}

void main()
{		
	/*
	int* ptr = (pole + 0);
	int* ptr2 = (pole + 2);
	int ptr3 = ptr2 - ptr;

	printf("\n%d", *ptr);

	// ptr = ptr + 1; //vyjde 5
	ptr = (pole + 1); //vyjde 2

	printf("\n%d", *ptr);
	printf("\n\%d", ptr3);*/

	int pole[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	char polec[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };

	/*
	*	1. Jak zjistime adresu 4. prvku pole?		(pole + 3); &pole[3]
	*	2. Jak zjistim index pointeru, ktery ukazuje na pole?		ptr - pole
	*	3. Mame 2 ukazatele stejneho pole. Jak zjistíme, ktery ukazatel ukazuje do pole drive?			ptr > ptr2
	*/

	/*	Naprogramujte predchozi fci bez pointerove aritmetiky (pristup k prvkum pole pres hranate zavorky) a srovnejte dobu behu techto dvou programu */

	Bezpoint(pole, 10);
	Spoint(pole, 10);

	/* Bez pouziti fce sizeof zjistete, jak velkou cast pameti zabiraji typy char, int a double: (a + 1) - a */

	/*	Vytvorte libovolnou strukturu a zjistete, jak velkou cast pameti tato struktura zabira. Bez pouziti fce sizeof. Vyzkoušejte pro ruzne datove typy polozek struktury */
	int integ[10]; printf("\nint pamet: %d", *(&integ + 1) - integ);
	char chareg[8]; printf("\nchar pamet: %d", *(&chareg + 1) - chareg);
	double doubleg[3]; printf("\ndouble pamet: %d", *(&doubleg + 1) - doubleg);
	float floateg[5]; printf("\nfloat pamet: %d", *(&floateg + 1) - floateg);

	printf("\npole pamet: %d", *(&pole + 1) - pole);
	printf("\npole pamet: %d\n", *(&polec + 1) - polec);
	
	/* Naprogramujte fci void vypis(int *pole, int zacatek, int krok, int konec), ktera vypise prvky pole od indexu zacatek po index konec s krokem krok.
		Napr.: pro pole = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } a zacatek = 0, krok = 2, konec = 9 vypise prvky 1, 3, 5, 7, 9 */

	printf("\n");
	vypis(pole, 0, 2, 9);

}


