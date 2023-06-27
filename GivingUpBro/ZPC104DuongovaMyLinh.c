#include <stdio.h>
#include "ZPC104 U04.inc"


void main()
{
	int c = 10;

	while (c >= 2 || c <= 2000)
	{
		printf("To get your number's decomposition, input a number that is within 2 - 2000. Otherwise close the program: ");
		scanf("%d", &c);

		if (c < 2 || c > 2000)
			break;

		for (int i = 0; i < POCET; )
		{
			const int* p = P[i];

			while (*p != 0)
			{
				if (c % *p == 0)
				{
					printf(" %d *", *p);
					c = c / *p;
					i = 0; break;
				}

				p++; i++;
			}
		}


		printf("\b \n\n\n");
	}


}




