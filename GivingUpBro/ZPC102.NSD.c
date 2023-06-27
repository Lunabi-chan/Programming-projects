#include <stdio.h>

void main()
{
	// Společný dělitel
	int a, b, r;

	printf("Zadej prvni cislo: ");
	scanf_s("%d", &a);
	int A = a;

	printf("Zadej druhe cislo: ");
	scanf_s("%d", &b);
	int B = b;

	while (b != 0)
	{
		r = a % b, a = b, b = r;
	}

	printf("Nejvetsi spolecny delitel cisel %d a %d je %d", A, B, a);
}