#include <stdio.h>

/*Ukol za 5 bodu
	Napis fci s hlavickou ........
	Nesmis pouzit existujici knihovnu string.h
	Fce v danem txt retezci 'text' vyhleda n-ty vyskyt zadaneho podretezce 'podrezetec'
	Fce vraci ukazatel na 1. znak nalezeného podrezezce nebo konstantu NULL,
		pokud podretezec 'podrezetec' nebyl nalezen.
	Pro retezec "mama mele maso", podretezec "ma" a n = 3 vrati index 10.
	*/

// '\0' je prazdny znak

int pomoc(char* text, char* podr, int n) { // pomocna fce, ktera nam pomuze poznat, jestli je dany usek roven podretezci
	for (int i = 0; ; i++) {
		if (podr[i] == '\0') {
			return 1;        // Jestli usek retezce obsahuje podretezec, tak vrati 1
		}
		if (text[n + i] != podr[i]) {
			return 0;        // Jestli ne, tak vrati 0 
		}
	}
}


char* najdi(char *text, char *podretezec, int n) {
	char* ret = text;        // pointer, ktery budeme vracet

	for (int i = 0; ; i++) {
		if (text[i] == '\0' || n <= 0) {
			return NULL;     // jestli je retezec prazdny/dojdeme na konec retezce nebo je n rovno/mensi jak 0, tak vrati null
		}
		else {
			if (text[i] == podretezec[0]) {        // Jestli se urceny znak v retezci bude rovnat 1. znaku v podretezci, tak
				if (pomoc(text, podretezec, i) == 1) {   // se zavola pomocna fce, ktera nam vrati 1 (true) nebo 0 (false) podle toho jestli je usek retezce roven podretezci nebo ne
					if (n == 1) {           // dale tady porovnavame poradi podretezce - jestli se n rovna 1, tak vrati ukazatel na misto v retezci
						return ret + i;
					}
					else {                                                          // - jinak zmensuje n
						n--;
					}
				}
			}
		}
	}
}




void main() {
	char text[20] = "mama mele maso.";
	char podr[20] = "ma";
	int a = 3;
	char* bee;
	
	// TESTOVACI PROSTREDI - kdyztak ho okomentujte
	while (a != 50) {
		scanf("%d", &a);
		bee = najdi(text, podr, a);
		printf("%s\n", bee);
	}

	// basic output
	//bee = najdi(text, podr, a);
	//printf("%s", bee);
}