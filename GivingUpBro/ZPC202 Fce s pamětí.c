#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*1. naprogramujte fci pro spojení 2 text. retezcu. Argumentem fce jsou 2 retezce ke spojeni, fce vrati novy retezec (jako ukazatel)*/

char* append(char* ret, char* eze) {
	return strcat(ret, eze);
}

/*2. Naprogramujte fci, ktera jakko argument bere ole cisel a vrati pole jejich
	druhych mocnin (tedy prvek na indexu i vráceného pole bude mít hodnotu druhe mocniny
	prvku na indexu i vstupniho pole)*/

int* power2(int* pole, int size) {
	int pole2[5];

	for (int i = 0; i < size; i++) {
		pole2[i] = pole[i] * pole[i];
		printf("%d ", pole2[i]);
	}

	return pole2 + 0;
}




void main() {
	char p[20] = "Hello "; char e[20] = "World";

	printf("%s\n", append(p, e));

	int pole[5] = { 1, 2,3,4,5 };
	int* pole2 = power2(pole, 5);
	
	for (int i = 0; i < 5; i++) {
		printf("%d ", *(pole2 + i));
	}
}