#include <stdio.h>

void Vymena(int A[], int i, int j)
{
	int pom = A[i];
	A[i] = A[j];
	A[j] = pom;
}

int Partition(int A[], int left, int right)
{
	int x = A[right];
	int i = left - 1;

	for (int j = left; j < right; j++)
	{

		if (x >= A[j])
		{
			i++;
			int pom = A[i];
			A[i] = A[j];
			A[j] = pom;
		}
	}
	int pom = A[i+1];
	A[i+1] = A[right];
	A[right] = pom;

	return ++i;
}

void QuickSort(int A[], int left, int right)
{
	if (left < right)
	{
		int q = Partition(A, left, right);
		QuickSort(A, left, q - 1);
		QuickSort(A, q + 1, right);
	}
}


int Tisk(int A[], int a)
{
	for (int i = 0; i < a; i++)
	{
		printf("%d\t", A[i]);
	}
	printf("\n");
}


void main()
{
	int A[] = { 1, 5, 7, 2, 8, 4 };
	int a = sizeof A / sizeof A[0];


	printf("\nQuickSort:\n");
	QuickSort(A, 0, a - 1);
	printf("\n\n");
	Tisk(A, a);

}