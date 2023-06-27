#include <stdio.h>
#include <stdlib.h>

// 1. ukol 
int** gimme(int m, int n) {
	int **pole = malloc(m*sizeof(int*));

	for (int i = 0; i < m; i++) {
		pole[i] = malloc(n * (sizeof(int)));
	}

	if (pole == NULL) {
		return NULL;
	}

	return pole;
}

// 2. ukol
int* gimme2(int m, int n) {
	int* pole2 = malloc(m * n * sizeof(int));

	if (pole2 == NULL) {
		return NULL;
	}

	return pole2;
}


// 3. ukol
int* posloup(int** poll, int m, int n) {

}


void main() {
	int m = 0, n = 0, l = 5, k = 5;
	int **pole = gimme(m, n);
	int* pole2 = gimme2(m, n);

	if (pole == NULL || pole2 == NULL) {
		printf("Nastala chyba\n");
		return 0;
	}
	

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			pole[i][j] = (i+1) * (j+1);
			printf("%3d ", pole[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < k; j++) {
			pole2[i*k + j] = (i + 1) * (j + 1);
			printf("%3d ", pole2[i*k + j]);
		}
		printf("\n");
	}
}