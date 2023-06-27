#include <stdio.h>

int V(int a, int b)
{
	int c;
	c = a;
	a = b;
	b = c;

	return a, b;
}

void main()
{
	int a = 5, b = 3, c;

	int poo[5];

	for (int i = 0; i < 5; i++)
	{
		//poo[i] = rand() % 101;
		printf("%d\n", poo[i] = rand() % 101);
	}
	
	printf("\n\n");

	// ssss
	for (int i = 1; i < 5; i++)
	{
		if (poo[i] < poo[i-1])
		{
			c = poo[i];
			poo[i] = poo[i - 1];
			poo[i - 1] = c;
			
			i = 0;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		//poo[i] = rand() % 101;
		printf("%d\n", poo[i]);
	}
}