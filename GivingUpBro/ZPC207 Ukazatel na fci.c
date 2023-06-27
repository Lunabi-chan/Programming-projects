#include <stdio.h>
#include <stdlib.h>

/* 1. ukol: Naprogramujte fce n0, n1, n2, n3, n4 z predchoziho slidu, vyzkousejte si praci s timto polem */
double n4(double x) {
	return x * x * x * x;
}

double n3(double x) {
	return x * x * x;
}

double n2(double x) {
	return x * x;
}

double n1(double x) {
	return x;
}

double n0(double x) {
	return 1;
}

/* 2. ukol: Vyuzijtepredchozi priklad a funkci map a vypise vzdy prvnich 10 nultych mocnin,prvnich mocnin, ..., ctvrtych mocnin. */
double* map(double (*fce)(double), double* vstup, int pocet) {
	double* vratit = malloc(sizeof(double));
	double* pom;

	if (vratit) {
		for (int i = 0; i < pocet; i++) {
			pom = realloc(vratit, (i + 1) * sizeof(double));

			if (pom) {
				pom[i] = fce((double)vstup[i]);
				vratit = pom;
			}
			else {
				return NULL;
			}
		}

		return vratit;
	}
	else {
		return NULL;
	}
}

/* 3. ukol: Naprogramujte obecnou funkci pro trizeni s tim, ze ji je mozne predat jako parametry funkce funkci porovnani a funkci vymeny. */
#define lambda(lambda$_ret, lambda$_args, lambda$_body)\
	({\
		lambda$_ret lambda$__anon$ lambda$_args\
					lambda$_body\
			&amp;lambda$__anon$;\
	})

// lambda(int, (int x, int y), { )
// lambda(int, (int x, int y), { return (x < y) ? 1 : 0; })

int desc(int x, int y) {
	return (x >= y) ? 1 : 0;
}

int asc(int x, int y) {
	return (x <= y) ? 1 : 0;
}

void Swap(int A[], int i, int j) {
	int pom = A[i];
	A[i] = A[j];
	A[j] = pom;
}

int Partition(int (*pred)(int, int), int A[], int left, int right) {
	int x = A[right];
	int j = left - 1;

	for (int i = left; i < right - 1; i++) {
		if (pred(A[i], x)) {
			j++;
			Swap(A, i, j);
		}
	}
	Swap(A, j + 1, right);

	return j + 1;
}

void QuickSort(int (*pred)(int, int), int A[], int left, int right) {
	if (left < right) {
		int q = Partition(pred, A, left, right);
		QuickSort(*pred, A, left, q - 1);
		QuickSort(*pred, A, q + 1, right);
	}
}


void main() {
	double (*pole_mocnin[5])(double) = { n0, n1, n2, n3, n4 };
	double pole_cisel[10] = { 5, -3, 2, -1, 4, -6, 8, -7, 9, -10 };

	for (int i = 0; i < 5; i++) {
		double *vystup = map(pole_mocnin[i], pole_cisel, 10);

		for (int j = 0; j < 10; j++) {
			printf("%8.2f ", vystup[j]);
		}
		printf("\n");

		free(vystup);
	}

	printf("\n");

	int pole_cisel2[10] = { 5, 9, 3, 2, 1, 4, 6, 8, 7, 10 };

	QuickSort(desc, pole_cisel2, 0, 9);
	for (int i = 0; i < 10; i++) {
		printf("%3d ", pole_cisel2[i]);
	}
	printf("\n");

	QuickSort(asc, pole_cisel2, 0, 9);
	for (int i = 0; i < 10; i++) {
		printf("%3d ", pole_cisel2[i]);
	}
	printf("\n");
}