#include <stdio.h>
#include "ZPC103 U03.inc"

void main()
{
	int ow[POCET], a, b;

	for (int i = 0; i < POCET; i++)
	{
		b = S[i];
		ow[i] = 0;

		for (int j = 0; j < DELKA; j++)
		{
			a = T[j];

			if (a == b || b == ((a - M)))
			{
				ow[i]++;
			}
		}

		printf("%c-%d\t", S[i], ow[i]);
		if (((i + 1) % 5 == 0))
			printf("\n");
	}

	/*for (int i = 0; i < POCET; i++)
	{
		printf("%c-%d\t", S[i], ow[i]);
		if (((i + 1) % 5 == 0))
			printf("\n");
	}*/
	
}