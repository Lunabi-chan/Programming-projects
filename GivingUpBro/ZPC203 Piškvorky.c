#include <stdio.h>
#include <stdlib.h>

char** gimme(int m, int n) {
	char** pot = malloc(3 * sizeof(char*));

	for (int i = 0; i < 3; i++) {
		pot[i] = malloc(3 * (sizeof(char)));
	}

	if (pot == NULL) {
		return NULL;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			pot[i][j] = NULL;
		}
	}

	return pot;
}

int vertical(char pol[3][3]) {
	for (int i = 0; i < 3; i++) {
		if (pol[1][i] == pol[0][i] && pol[2][i] == pol[0][i]) {
			return 1;
		}
	}

	return 0;
}

int horizontal(char pol[3][3]) {
	for (int i = 0; i < 3; i++) {
		if (pol[i][1] == pol[i][0] && pol[i][2] == pol[i][0]) {
			return 1;
		}
	}

	return 0;
}

int diagnonally(char pol[3][3]) {
	if ((pol[0][0] == pol[1][1] && pol[2][2] == pol[1][1]) || (pol[0][2] == pol[1][1] && pol[2][0] == pol[1][1])) {
		return 1;
	}

	return 0;
}

void main() {
	int l, k, t = 0;

	char player1 = 0, player2 = 0;
	char** pole = gimme(3, 3);

	printf("Zadej znak pro 1. a 2. hrace ve formatu [a b]: ");
	scanf("%c %c", &player1, &player2);
	
	while (t < 9) {
		printf("\n\nHrac %d zadava souradnice [x y]: ", (t % 2) + 1);
		scanf("%d %d",&l,&k);

		if (l > 2 || k > 2) {
			printf("Mimo pole\n");
			continue;
		}
		else if (pole[l][k] != NULL) {
			printf("Pole je obsazene.\n");
			continue;
		}
		else {
			if (t % 2 == 0) {
				pole[l][k] = player1;
			}
			else {
				pole[l][k] = player2;
			}
			t++;
		}

		printf("%7d %2d %2d\n    -----------\n", 0, 1, 2);
		for (int i = 0; i < 3; i++) {
			printf("%2d | ", i);
			for (int j = 0; j < 3; j++) {
				printf("%2c ", pole[i][j]);
			}
			printf("\n");
		}
	}
}