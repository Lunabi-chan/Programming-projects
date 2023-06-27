#include <stdio.h>
#include <stdlib.h>


// 2. ukol - naprogramovat strukturvane typy na nahrazeni hlabalnich promennych
typedef struct {
	int* data;
	int velikost;
	int hlava;
} parametres;

parametres para;

void init(int vel) {
	para.data = calloc(vel, sizeof(int));

	if (para.data == NULL) {
		para.velikost = 0;
	}
	else {
		para.velikost = vel;
	}
	para.hlava = 0;
}

void tisk() {
	for (int i = 0; i < para.hlava; i++) {
		printf("%i ", *(para.data + i));
	}
	printf("\n");
}

void uvolni() {
	free(para.data);
	para.data = NULL;
	para.velikost = 0;
	para.hlava = 0;
}

void pridej(int a) { // davej si pozor na to, jestli ta hlava neni vetsi jak velikost pole, protoze pak ukladam do pameti, ktera mi nepatri
	if (para.data == NULL) {
		printf("It be null");
	}
	if (para.hlava >= para.velikost) {
		para.data = realloc(para.data, 2 * para.velikost * sizeof(int));
		para.velikost *= 2;
		printf("Pripsalo se vice mista\n");
	}
	
	para.data[para.hlava] = a;
	para.hlava++;

	tisk();
}

// 3. ukol - odebrat posledni prvek ve fci
void smaz() {
	if (para.hlava < 0 || para.hlava == 0 && para.data[para.hlava] == NULL || para.data == NULL) {
		printf("Nic tu neni\n");
	}
	else { // 6. ukol - jestli je pocet prvku mensi jak polovina velikosti, tak zmensi velikost o polovinu.
		para.data[para.hlava - 1] = 0; //Toto tu nemusi byt
		para.hlava--;

		if (para.hlava < (para.velikost / 2)) {
			para.data = realloc(para.data, (para.velikost / 2) * sizeof(int));
			para.velikost /= 2;
			printf("Smazana pulka\n");
		}

		tisk();
	}
}

void jetam(int a) { // 4. ukol - nachazi se zde to cislo?
	for (int i = 0; i < para.hlava; i++) {
		if (para.data[i] == a) {
			printf("Nachazi se cislo %d\n", a);
			break;
		}
	}
}

// 5. ukol - smaze chtene cislo z pole
void nechcitotocislo(int x) {
	for (int i = 0; i < para.hlava; i++) {
		if (para.data[i] == x) {
			for (int j = i; j < para.hlava - 1; j++) {
				para.data[j] = para.data[j + 1];
			}
			para.hlava--;
			i--;
		}
	}
	printf("Nechci cislo %d: ", x);
	tisk();
}

void main() {
	int i = 7;
	init(4);
	pridej(i);
	pridej(5);
	pridej(8);
	pridej(1);
	pridej(1);
	pridej(3);
	pridej(4);
	pridej(8);
	smaz();
	smaz();
	nechcitotocislo(1);
	smaz();
	jetam(5);
	tisk();
	uvolni(); // i kdyz se vse uvolni po skonceni programu, aji tak si po sobe uklizej
	tisk();
}