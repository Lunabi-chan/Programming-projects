#include <stdio.h>

void InsertSort(int pOo[], int k)
{
	int t;

	for (int j = 1, i; j < k; j++)
	{
		t = pOo[j];
		i = j - 1;

		while (i >= 0 && pOo[i] > t)
		{
			pOo[i + 1] = pOo[i];
			i = i - 1;
		}

		pOo[i + 1] = t;
	}

	PrintMA(pOo, k);
}







void BubbleSort(int Poo[], int k)
{
	/*
* for j <- 0 to n-2
*	do for i <- n-1 downto j+1
*		do if a[i] < a[i-1]
*			swap
*/

	int c;

	for (int j = 0; j < k-2; j++)
	{
		for (int i = k - 1; i >= j + 1; i--)
		{
			if (Poo[i] < Poo[i - 1])
			{
				c = Poo[i];
				Poo[i] = Poo[i - 1];
				Poo[i - 1] = c;
			}
		}
	}

	PrintMA(Poo, k);
}



int PrintMA(int Poe[], int k)
{
	for (int i = 0; i < k; i++)
	{
		//poo[i] = rand() % 101;
		printf("%d  ", Poe[i]);
	}
	printf("\n\n");
}

void main()
{
	int poo[7], c;

	int k = sizeof(poo)/sizeof(poo[0]);

	srand((unsigned)time(&c));

	for (int i = 0; i < k; i++)
	{
		printf("%d  ", poo[i] = rand() % 101);
	}

	printf("\n\n\nBubble Sort: ");
	BubbleSort(poo, k);

	printf("Insert Sort: ");
	InsertSort(poo, k);
}