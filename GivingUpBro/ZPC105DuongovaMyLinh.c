#include <stdio.h>
#include "ZPC105 U05.inc"

int prunik(const int A[], int a, const int B[], int b, int C[])
{
	int k = 0;

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if (A[i] == B[j])
			{
				C[k] = A[i];
				k++;
			}
		}
	}

	return k;
}

int srozdil(const int A[], int a, const int B[], int b, int C[])
{
	int k = 0;
	int g = 1;

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if (A[i] == B[j])
			{
				g = 0;
			}
		}
		if (g == 0)
		{
			g = 1;
		}
		else
		{
			C[k] = A[i];
			k++;
		}
	}

	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (A[j] == B[i])
			{
				g = 0;
			}
		}
		if (g == 0)
		{
			g = 1;
		}
		else
		{
			C[k] = B[i];
			k++;
		}
	}

	return k;
}

int sjednoceni(const int A[],int a,const int B[],int b,int C[])
{
	int k = 0;

	for (int i = 0; i < a; i++)
	{
		C[i] = A[i];
		k = i;
	}

	int g = 0;

	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (C[j] == B[i])
			{
				g = 1;
			}
		}
		if (g == 0)
		{ C[k] = B[i];
		k++;}
		
		g = 0;
	}

	return k;
}

int rozdil(const int A[],int a,const int B[],int b,int C[])
{
	int k = 0;
	for (int i = 0; i < a; i++)
	{
		C[i] = A[i];
		k = i;
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if (C[i] == 9)
			{
				for (int l = i; l < a; l++)
				{
					C[l] = C[l + 1];
				}
			}

			if (C[i] == B[j])
			{
				for (int l = i; l < a; l++)
				{
					C[l] = C[l+1];
				}
				k--;
			}
		}
	}

	return k;
}

void vypis(const int A[], int a, int n)
{
	//printf("\n");

	for (int i = 0; i < a; i++)
	{
		if ((((i) % n)) == 0)
		{
			printf("\n");
		}

		printf("%d  ", A[i]);
	}
}

void main()
{
	int c = 0;
	int n;

	int C[aa + bb];

	while (1)
	{
		printf("\n   1 pro rozdil\n   2 pro srozdil\n   3 pro sjednoceni \n   4 pro prunik\n   5 pro exit\n------------------\nNapis volbu a kolik cisel muze byt na jednom radku. Oddel mezerou: ");
		scanf("%d %d", &c, &n);

		if (n == 0)
		{
			printf("Na jednom radku nemuze byt 0 cisel.\n\n");
			continue;
		}

		switch (c)
		{
		case 1:  vypis(C, rozdil(A, aa, B, bb, C), n);
			break;
		case 2:  vypis(C, srozdil(A, aa, B, bb, C), n);
			break;
		case 3:  vypis(C, sjednoceni(A, aa, B, bb, C), n);
			break;
		case 4:  vypis(C, prunik(A, aa, B, bb, C), n);
			break;
		case 5: return 0; break;
		default: printf("\nSpatne zadana volba!!"); break;
		}

		printf("\n\n");
	}
}