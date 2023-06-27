#include <stdio.h>

void main()
{
	/* Napiste program, ktery pro zadanou sumu penez vytiskne 
	vyctku ceskych platidel potrebnych k vyplaceni zadané sumy. */

	int n;

	printf("Zadej sumu: ");
	scanf("%d", &n);

	int a[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000};
	int pocet = (sizeof a / sizeof a[0] - 1);

	for (int i = pocet; i >= 0; i--)
	{
		if ((n / a[i]) == 0)
			continue;
		if ((n / a[i]) == 1)
			printf(" %-4d   ", a[i]);
		else
			printf("%3d * %-4d   ", n / a[i], a[i]);
		
		n = n % a[i];
	}
}