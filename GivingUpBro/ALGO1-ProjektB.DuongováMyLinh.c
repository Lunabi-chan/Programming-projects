#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
* 1. Implementujte algoritmy BubbleSort a SelectionSort. 
Demonstrujte beh programu na poli o 10k random prvcich a zmerte cas. 
Vysledky mereni porovnejte.*/

int poc = 0, pocc = 0;

void Tisk (int A[], int a)
{
	for (int i = 0; i < a; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

void Swap(int A[], int i, int j)
{
	int pom = A[i];
	A[i] = A[j];
	A[j] = pom;
}

void BubbleSort(int A[], int a)
{
	for (int i = 0; i < a - 1; i++)
	{
		for (int j = a - 1; j > 0; j--)
		{
			if (A[j] < A[j - 1])
			{
				Swap(A, j, j - 1);
				poc++;
			}
		}
	}
}

void SelectionSort(int A[], int a)
{
	for (int i = 0; i < a-1; i++)
	{
		int iMin = i;

		for (int j = i + 1; j < a; j++)
		{
			if (A[iMin] > A[j])
			{
				iMin = j;
				pocc++;
			}
		}
		Swap(A, i, iMin);
	}
}

void Compare(int a, int b)
{
	if (a < b)
	{
		printf("BubbleSort");
	}
	else
		printf("SelectionSort");

	printf("\n");
}

void main()
{
	printf("\t ZADANI B\n");

	printf("\n\t\t1. UKOL\n-----------------------------------------------------------------------------------------------------------------");

	int A[10000], a = sizeof A / sizeof A[0];
	int B[10000], b = sizeof B / sizeof B[0];

	int rad;

	for (int i = 0; i < a; i++)
	{
		rad = rand() % 201;

		A[i] = rad;
		B[i] = rad;
	}

	clock_t t;
	t = clock();
	BubbleSort(A, a);
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;

	printf("\n\tBubbleSort\n - pocet porovnani: %d\n", poc);
	printf(" - zabrany cas: %f \n", time_taken);


	clock_t ti;
	ti = clock();
	SelectionSort(B, b);
	ti = clock() - ti;
	time_taken = ((double)ti) / CLOCKS_PER_SEC;

	printf("\n\tSelectionSort\n - pocet porovnani: %d\n", pocc);
	printf(" - zabrany cas: %f \n", time_taken);

	printf("\n Efektivnejsi tridici algoritmus je ");
	Compare(poc, pocc);
	printf(" Rychlejsi tridici algoritmus je ");
	Compare(t, ti);

	printf("-----------------------------------------------------------------------------------------------------------------");

	printf("\n\n\n\t\t2. UKOL\n-----------------------------------------------------------------------------------------------------------------");

	/* 2.	Funkce seradte vzestupne dle jejich asymptoticke rychlosti rustu vuci promenne n.
			Sve reseni strucne okomentujte.
		a) f1(n) = nlog˘3(n) + n^2 * log˘2(n)
		b) f2(n) = n!
		c) f3(n) = 0.0001n^3 + 12n^2 + 12
		d) f4(n) = 4^n + 8n^2 − n
		e) f5(n) = 7logn + 6n − 1/3
		f) f6(n) = 9n^(1/3) − (12n)^(1/4)
	*/

	// f e a c d b
	printf("\n Ukol: Funkce seradte vzestupne dle jejich asymptoticke rychlosti rustu vuci promenne n. Sve reseni strucne okomentujte.");
	printf("\n\ta) f1(n) = nlog3(n) + n^2 * log2(n) \n\tb) f2(n) = n! \n\tc) f3(n) = 0.0001n^3 + 12n^2 + 12");
	printf("\n\td) f4(n) = 4^n + 8n^2 - n \n\te) f5(n) = 7logn + 6n - 1 / 3 \n\tf) f6(n) = 9n^(1 / 3) - (12n)^(1 / 4)\n\n");

	printf("\n ->            f6(n) <= f5(n) <=  f1(n) <= f3(n) <= f2(n) <= f4(n)");
	printf("\n ->                f <=     e <=      a <=     c <=     d <=     b");
	printf("\n -> 3. odmocnina z n <=     n <= n^2lgn <=   n^3 <=   c^n <=    n!");		
		
	printf("\n-----------------------------------------------------------------------------------------------------------------");

		


	printf("\n\n\n\t\t3. UKOL\n-----------------------------------------------------------------------------------------------------------------");

	/* 3.	S vyuzitim Master theorem vypocitejte asymptoticke odhady nasledujicich casovych slozitosti zadanych rekurencemi.
			Krome vysledku uvedte take, o jakych z pripadu (1,2,3) se jedna a proc.
			V pripade, ze Master theorem k reseni prikladu vyuzit nelze, strucne uvedte duvod.
		a) T(n) = 3T(n/2) + n^2
		b) T(n) = 2nT(n/2) + n
		c) T(n) = 16T(n/4) + n
		d) T(n) = 0.5T(n/2) + n^3
		e) T(n) = 2T(n/2) + nlogn
	*/

	printf("\n Ukol: Vyuzij Master Theorem k vypocitani asymptotickych odhadu cas. slozitosti zadanych rekurencemi\n");
	printf("\n\t a) T(n) = 3T(n/2) + n^2   \t<- n^(log2(3))   < n^2 \t -> Theta(n^2) - 3. pripad");
	printf("\n\t b) T(n) = 2^nT(n/2) + n   \t<- neplati, spada mezi pripady 1 a 2; n^(1-n) je asymptoticky vetsi jak n^eps");
	printf("\n\t c) T(n) = 16T(n/4) + n    \t<- n^(log4(16))  > n   \t -> Theta(n^2) - 1. pripad");
	printf("\n\t d) T(n) = 0.5T(n/2) + n^3 \t<- n^(log2(0.5)) < n^3 \t -> Theta(n^3) - 3.pripad");
	printf("\n\t e) T(n) = 2T(n/2) + nlogn \t<- neplati, spada mezi pripady 2 a 3; lgn je asymptoticky mensi jak n^eps");


	printf("\n-----------------------------------------------------------------------------------------------------------------");


}