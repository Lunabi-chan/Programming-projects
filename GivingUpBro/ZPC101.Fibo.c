#include <stdio.h>


void main()
{
	// Fibonacciho posloupnost

	int a, b;

	printf("Zadejte index cisla ve F posloupnosti: ");
	scanf_s("%d", &a);

	printf("Zadejte pocet cisel na radku: ");
	scanf_s("%d", &b);


	int k = 1, l = 1, pom = 0;

	printf("Fibonacciho cisla do n = %d: \n", a);

	if (a >= 0)
	{
		for (int i = 0; i <= a; i++)
		{
			printf("%d  ", pom);

			if ((((i + 1) % b)) == 0)
				printf("\n");

			l = k + pom;
			pom = k;
			k = l;

		}
	}
	else printf("Error");


	printf("");
}