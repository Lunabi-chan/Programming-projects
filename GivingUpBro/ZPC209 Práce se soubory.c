#include <stdio.h>

// 1. Napiste program, ktery bude cist ze souboru desetinna cisla (libovolny pocet) a vrati jejich prumer
double des_prum() {
	FILE* f = fopen("C:\\Users\\MlpLu\\Documents\\1 - University\\ZPC2\\Soubory - 1. ukol prumer.txt", "r");
	if (f == NULL || f == 0) {
		printf("Wut");
		return -1;
	}
	else {
		double i = 0, x = 0, result = 0;

		while (feof(f) == 0) {
			if (fscanf(f, "%lf", &x) == 1) {
				result += x;
				i++;
			}
		}

		result /= i;

		if (fclose(f) == EOF) {
			printf("Wut2");
			return -1;
		}
		else {
			return result;
		}
	}
}

// 2. Napiste program tak, aby zkusil cist neexistujici soubor. Zajistete, aby program vhodne reagoval na tuto situaci
int neexistuje_soubor() {
	FILE* f = fopen("C:\\Users\\MlpLu\\Documents\\1 - University\\ZPC2\\Soubory - 2. ukol", "r");
	if (f == NULL || f == 0) {
		return -1;
	}
	else {
		if (fclose(f) == EOF) {
			printf("??");
			return -1;
		}
		else {
			return 0;
		}
	}
}

// 3. Napište program, ktery spocita celkovy pocet znaku v souboru
int pocet_znaku() {
	FILE* f = fopen("C:\\Users\\MlpLu\\Documents\\1 - University\\ZPC2\\Soubory - 3. ukol.txt", "r");

	if (f == NULL || f == 0) {
		return -1;
	}
	else {
		int i = 0;

		while (fgetc(f) != EOF) {
			i++;
		}

		if (fclose(f) == EOF) {
			return -1;
		}
		else {
			return i;
		}
	}
}



void main() {
	//printf("1. ukol: %.2f\n", des_prum());
	//printf("2. ukol: %d\n", neexistuje_soubor());
	//printf("3. ukol: %d\n", pocet_znaku());
}