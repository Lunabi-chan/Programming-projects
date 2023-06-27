#include <stdio.h>
#include <conio.h>


void Vymena(int A[], int i, int j)
{
	int pom = A[i];
	A[i] = A[j];
	A[j] = pom;
}

void MyInsertSort(int A[])
{
	for (int i = 1; i < (sizeof A); i++)
	{
		for (int j = i; j > -1; j--)
		{
			if (A[j] < A[j - 1])
			{
				Vymena(A, j - 1, j);
				Tisk(A);
			}			
		}
	}

	Tisk(A);
}

void InsertSort(int A[])
{
	for (int j = 1; j < (sizeof A); j++)
	{
		int t = A[j];
		int i = j - 1;

		while (i >= 0 && A[i] > t)
		{
			A[i + 1] = A[i];
			i--;			
		}
		A[i + 1] = t;
		Tisk(A);
	}

	Tisk(A);
}

void MySelectionSort(int A[])
{
	for (int i = 0; i < sizeof A; i++)
	{
		int iMin = i, Min = A[i];
		for (int j = i + 1; j < sizeof A; j++)
		{
			if (Min > A[j])
			{
				iMin = j;
				Min = A[j];
			}
		}
		Vymena(A, iMin, i);
		Tisk(A);
	}
	Tisk(A);
}

void SelectionSort(int A[])
{
	for (int i = 0; i <= sizeof A - 2; i++)
	{
		int iMin = i;
		for (int j = i+1; j <= sizeof A - 1; j++)
		{
			if (A[iMin] > A[j])
			{
				iMin = j;
			}
		}
		Vymena(A, iMin, i);
		Tisk(A);
	}
	Tisk(A);
}

void MyBubbleSort(int A[])
{
	for (int i = 0; i < sizeof A; i++)
	{
		for (int j = 0; j < sizeof A-1; j++)
		{
			if (A[j] > A[j + 1])
			{
				Vymena(A, j, j + 1);
				Tisk(A);
			}
		}
	}

	Tisk(A);
}

void BubbleSort(int A[])
{
	for (int i = 0; i <= sizeof A - 2; i++)
	{
		for (int j = sizeof A - 1; j >= i+1; j--)
		{
			if (A[j] < A[j - 1])
			{
				Vymena(A, j, j - 1);
				Tisk(A);
			}
		}
	}

	Tisk(A);
}

int MyPartition(int A[], int left, int right)
{
	int x = right;
	for (int i = left; i < x; i++)
	{
		if (A[x] <= A[i])
		{
			for (int j = i; j < x; j++)
			{
				Vymena(A, j, j+1);
				Tisk(A);
			}
			x--;
		}
	}

	return x - 1;
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
			Vymena(A, i, j);
			Tisk(A);
		}
	}
	Vymena(A, i + 1, right);

	return ++i;
}

void MyQuickSort(int A[], int left, int right)
{
	if (left < right)
	{
		Tisk(A);
		int q = MyPartition(A, left, right);
		MyQuickSort(A, left, q-1);
		MyQuickSort(A, q+1, right);
	}
	Tisk(A);
}

void QuickSort(int A[], int left, int right)
{
	if (left < right)
	{
		int q = Partition(A, left, right);
		QuickSort(A, left, q-1);
		QuickSort(A, q+1, right);
	}
	Tisk(A);
}

void CountingSort(int A[],int a, int k)
{
	int C[20]; 
	int B[20];

	for (int i = 0; i <= k; i++)
	{
		C[i] = 0;
		B[i] = 0;
	}
	for (int i = 0; i < a; i++)
	{
		C[A[i]] = C[A[i]] + 1;
		Tisk2(C, k +1);
	}
	for (int i = 1; i <= k; i++)
	{
		C[i] = C[i] + C[i - 1];
		Tisk2(C, k+1);

	}
	for (int i = a - 1; i >= 0; i--)
	{
		B[C[A[i]]-1] = A[i];
		C[A[i]] = C[A[i]] - 1;
		
	}

	Tisk(B);
}


int Tisk(int A[])
{
	for (int i = 0; i < (sizeof A); i++)
	{
		printf("%d\t", A[i]);
	}
	printf("\n");
}
int Tisk2(int A[], int a)
{
	for (int i = 0; i < a; i++)
	{
		printf("%d\t", A[i]);
	}
	printf("\n");
}


void main()
{
	int choice = 10;

	while (choice != 0)
	{
		int A[] = { 6, 8, 5, 3, 4, 9, 2, 7 };
		int B[] = { 6, 8, 5, 3, 4, 9, 2, 7 };
		int C[] = { 8, 7, 6, 5, 4 };

		int a = sizeof A / sizeof A[0];
		int c = sizeof C / sizeof C[0];

		printf("1: InsertSort\n2: SelectionSort\n3: BubbleSort\n");
		printf("\nVolba: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:	
			printf("\nInsertSort:\n");
			InsertSort(A);

			printf("\nMy InsertSort:\n");
			MyInsertSort(B); 
			break;

		case 2: 
			printf("\nSelectionSort:\n");
			SelectionSort(A);

			printf("\nMy SelectionSort:\n");
			MySelectionSort(B);
			break;

		case 3: 
			printf("\nBubbleSort:\n");
			BubbleSort(A);

			printf("\nMy BubbleSort:\n");
			MyBubbleSort(B);
			break;

		case 4: 
			printf("\nQuickSort:\n");
			Tisk(C);
			QuickSort(C, 0, c - 1);
			Tisk(C);
			printf("\n\n");

						
			printf("\nMy QuickSort:\n");
			MyQuickSort(B, 0, a - 1);
			break;

		case 5:
			
			printf("\nCountingSort:\n");
			for (int i = 0; i <= 10; i++)
			{
				printf("%d\t", i);
			}
			printf("\n");
			CountingSort(A, a, 10);
			printf("\n\n");
		}
		
		printf("\n\n\n\n");
	}

	printf("");
}