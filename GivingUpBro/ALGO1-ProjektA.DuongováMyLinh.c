#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
* 1. InsertionSort, QuickSort, MergeSort
*		pridat pocitadlo, zaznamenava pocet porovnani mezi prvky
*		demonstrovat beh programu na poli s 10k random prvky
*		který je efektivni (malo porovnani) vs ktery je rychly
*/

int poc = 0;
int pocc = 0;
int poccc = 0;

void NejNej(int a, int b, int c)
{
	if (a < b && a < c)
	{
		printf("InsertSort");
	}
	if (b < c)
	{
		printf("QuickSort");
	}
	else
	{
		printf("MergeSort");
	}
}

void Swap(int A[], int i, int j)
{
	int pom = A[i];
	A[i] = A[j];
	A[j] = pom;
}

void InsertSort(int A[], int a)
{
	int t, j;

	for (int i = 1; i < a; i++)
	{
		t = A[i];
		j = i - 1;

		while (j >= 0 && t < A[j])
		{
			++poc;
			Swap(A, j + 1, j);
			j--; 
		}
	}

}

int Partition(int A[], int left, int right)
{
	int x = A[right];
	int j = left - 1;

	for (int i = left; i < right - 1; i++)
	{
		if (A[i] >= x)
		{
			j++; 
			Swap(A, i, j);
			pocc++;
		}
	}
	Swap(A, j + 1, right);

	return j+1;
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

void Merge(int A[], int left, int q, int right)
{
	int n1 = q - left + 1;
	int n2 = right - q;

	int L[10005], R[10005];

	for (int i = 0; i < n1; i++)
	{
		L[i] = A[left + i];
	}

	for (int j = 0; j < n2; j++)
	{
		R[j] = A[q + 1 + j];
	}

	L[n1] = 1000;
	R[n2] = 1000;

	int j = 0, i = 0, k = left;

	for (int k = left; k <= right; k++)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
			poccc++;
		}
		else
		{
			A[k] = R[j];
			j++;
			poccc++;
		}
	}
	
}

void MergeSort(int A[], int left, int right)
{
	if (left < right)
	{
		int q = (left + right) / 2;
		MergeSort(A, left, q);
		MergeSort(A, q + 1, right);
		Merge(A, left, q, right);
	}
}

void main()
{
	int A[10000], a = sizeof A / sizeof A[0];
	int B[10000], b = sizeof B / sizeof B[0];
	int C[10000], c = sizeof C / sizeof C[0];

	int rad;

	for (int i = 0; i < 10000; i++)
	{
		rad = rand() % 201;

		A[i] = rad;
		B[i] = rad;
		C[i] = rad;
	}
	
	printf("\t ZADANI A\n");

	printf("\n\t\t1. UKOL\n-----------------------------------------------------------------------------------------------------------------");

	clock_t t;
	t = clock();
	InsertSort(A, a);
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC; 

	printf("\n\tInsertSort\n - pocet porovnani: %d\n", poc);
	printf(" - zabrany cas: %f \n", time_taken);


	clock_t ti;
	ti = clock();
	QuickSort(B, 0, b - 1);
	ti = clock() - ti;
	time_taken = ((double)ti) / CLOCKS_PER_SEC; 

	printf("\n\tQuickSort\n - pocet porovnani: %d\n", pocc);
	printf(" - zabrany cas: %f \n", time_taken);
	
	
	clock_t tim;
	tim = clock();
	MergeSort(C, 0, c - 1);
	tim = clock() - tim;
	time_taken = ((double)tim) / CLOCKS_PER_SEC; 

	printf("\n\tMergeSort\n - pocet porovnani: %d\n", poccc);
	printf(" - zabrany cas: %f \n", time_taken);

	printf("\n Nejefektivnejsi tridici algoritmus je ");
	NejNej(poc, pocc, poccc);

	printf("\n Nejrychlejsi tridici algoritmus je ");
	NejNej(t, ti, tim);
	printf("\n-----------------------------------------------------------------------------------------------------------------\n");


/*
*  2. Doplnit pravou stranu, aby vztahy platily
*		a) O(f) + O(g)
*		b) O(f) * O(g)
*		c) Jestliže f e O(g) a g e O(h), pak
*/

	printf("\n\t\t2. UKOL\n-----------------------------------------------------------------------------------------------------------------");
	printf("\n\t a) O(f) + O(g) = max{O(f), O(g)} \t\t\t\t <- Plati jen ta vetsi funkce.");
	printf("\n\t b) O(f) * O(g) = O(f * g) \t\t\t\t\t <- Plati zde asociativita.");
	printf("\n\t c) Jestlize f nalezi O(g) a g nalezi O(h), pak f nalezi O(h) \t <- Jde o tranzitivitu casove slozitosti");
	printf("\n-----------------------------------------------------------------------------------------------------------------\n");



/*
*  3. Je to halda? Oduvodni, popripade oprav
*		15 12 8 9 4 5 1 2 3 2 4
**/
	printf("\n\t\t3. UKOL\n-----------------------------------------------------------------------------------------------------------------");
	printf("\n\t Otazka: Je to halda? Oduvodni, popripade oprav: 15 12 8 9 4 5 1 2 3 2 4");
	printf("\n  Ano, je to halda, presneji receno max-halda. Kazdy rodic ma nejvetsi prvek mezi nim a jeho potomky.");
	printf("\n-----------------------------------------------------------------------------------------------------------------\n");
}