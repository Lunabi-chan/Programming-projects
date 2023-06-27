#include <stdio.h>
#include <string.h>

typedef char* string;
typedef struct { 
	string name,
		   surname; 
	int age, 
	    debt; 
} debtor;

debtor debtdatabase[8] = {
			{ "Ann", "Bean", 38, 36547 },
			{ "Ben", "Ten", 46, 874514 },
			{ "Terry", "Kirie", 24, 1000 },
			{ "Kent", "Cannot", 85, 65478 },
			{ "Carol", "Dentist", 19, 525},
			{ "Danette", "Anemo", 51, 7457523}, 
			{ "Terry", "Johnson", 63, 2547 },
			{ "Jeanne", "Cannot", 72, 40257 } };

const int p = sizeof debtdatabase / sizeof debtdatabase[0];

string debtor_name(debtor d) {
	return d.name;
}
string debtor_surname(debtor d) {
	return d.surname;
}
int debtor_age(debtor d) {
	return d.age;
}
int debtor_debt(debtor d) {
	return d.debt;
}

// Tisk databaze dluzniku
void print_all(debtor array[], int size, int true) {
	if (true == 1) {
		printf("\t......................................................\n");
		printf("\t     | %8s | %8s |  %2s | %12s   |\n\t     ...............................................\n", "Jmeno", "Prijmeni", "Vek", "Dluh");
		for (int i = 0; i < size; i++) {
			printf("\t%3d. | %8s | %8s |  %2d  | %12d $ |\n", i + 1, debtor_name(array[i]), debtor_surname(array[i]), debtor_age(array[i]), debtor_debt(array[i]));
		}
		printf("\t......................................................\n\n");
	}
	if (true == 2) {
		printf("\t\t| %8s | %8s |\n \t\t....................... \n", "Jmeno", "Prijmeni");
		for (int i = 0; i < size; i++) {
			printf("\t\t| %8s | %8s |\n", debtor_name(array[i]), debtor_surname(array[i]));
		}
	}
	if (true == 3) {
		printf("\t| %8s | %8s |  %2s | %12s   |\n\t...............................................\n", "Jmeno", "Prijmeni", "Vek", "Dluh");
		for (int i = 0; i < size; i++) {
			printf("\t| %8s | %8s |  %2d  | %12d $ |\n", debtor_name(array[i]), debtor_surname(array[i]), debtor_age(array[i]), debtor_debt(array[i]));
		}
	}
}

// 1. Vypisuje dluznou castku
void print_debt(debtor debts[], int n, string name, string surname) {
	for (int i = 0; i < n; i++) {
		if (((strcmp(name, debtor_name(debts[i]))) == 0) && ((strcmp(surname, debtor_surname(debts[i]))) == 0)) {
			printf("\n\t Dluzna castka: %d\n\n", debtor_debt(debts[i]));
			return;
		}
	}
	printf("\t Nenasel se dluznik.\n\n");
}

// 2. Vraci dluznika s nejvetsim dluhem
debtor max_debt(debtor debts[], int n) {
	debtor mostdebt = debts[0];

	for (int i = 1; i < n; i++) {
		if (debtor_debt(mostdebt) < debtor_debt(debts[i]))
			mostdebt = debts[i];
	}

	return mostdebt;
}

// 3. Zvysi dluznou castku
void increase_debt(debtor debts[], int n, string name, string surname, int amount) {
	for (int i = 0; i < n; i++) {
		if (((strcmp(name, debtor_name(debts[i]))) == 0)) {
			if (((strcmp(surname, debtor_surname(debts[i]))) == 0)) {
				debtor* helpdebt = (debts + i);
				helpdebt->debt += amount;
				return;
			}
		}
	}
	printf("\t Nenasel se dluznik.\n");
}

// 4. Snizi dluuznou castku
void decrease_debt(debtor debts[], int n, string name, string surname, int amount) {
	for (int i = 0; i < n; i++) {
		if (((strcmp(name, debtor_name(debts[i]))) == 0) && ((strcmp(surname, debtor_surname(debts[i]))) == 0)) {
			debts[i].debt -= amount;

			if (debts[i].debt < 0) {
				debts[i].debt = 0;

				printf("\n\t Prebytek byl vracen. Nyni je dluh na 0.\n");
			}
			break;
		}
	}
}

// 5. Vytiskne i-teho nejmladsiho
debtor ith_youngest(debtor debts[], int i, int n) {
	int j;
	debtor t, pom;
	debtor debtshelp[100];

	for (int u = 0; u < n; u++) {
		debtshelp[u] = debts[u];
	}

	for (int k = 1; k < n; k++) {
		t = debtshelp[k];
		j = k - 1;

		while (j >= 0 && debtor_age(t) < debtor_age(debtshelp[j])) {
			pom = debtshelp[j + 1];
			debtshelp[j + 1] = debtshelp[j];
			debtshelp[j] = pom;

			j--;
		}
	}

	return debtshelp[i-1];
}

// 6. Seradi databazi od nejmladsiho po nejstarsiho
void sort_debts(debtor debts[], int n) {
	debtor t, pom;
	int j;

	for (int i = 1; i < n; i++) {
		t = debts[i];
		j = i - 1;

		while (j >= 0 && debtor_age(t) < debtor_age(debts[j])) {
			pom = debts[j + 1];
			debts[j + 1] = debts[j];
			debts[j] = pom;

			j--;
		}
	}

	print_all(debts, n, 1);
}

void main() {
	char tname[20], tsurname[20], end = ' ';
	int tage = 0, tdebt = 0;
	debtor helpdebt[5];

	int cond = 10;

	printf("\n-------------------------------------------------------------------------------------------\n");
	printf("\t\t Program se opakuje. Zadavejte cisla moznosti do 'Volby'.\n\n");
	printf("\t1: Dluzna castka dluznika\n");
	printf("\t2: Dluznik s nejvyssim dluhem\n");
	printf("\t3: Zvyseni dluzne castky\n");
	printf("\t4: Zmenseni dluzne castky\n");
	printf("\t5: Vraci i-teho nejmladsiho dluznika\n");
	printf("\t6: Serazeni dluzniku podle veku (od nejmladsiho po nejstarsiho)\n");
	printf("\t7: Vytisknout vsechny dluzniky a jejich informace\n");
	printf("\t0: Zavrit program");
	printf("\n-------------------------------------------------------------------------------------------\n");

	print_all(debtdatabase, p, 2);
	printf("-------------------------------------------------------------------------------------------\n");

	while (cond != 0) {
		printf("\n\n-------------------------------------------------------------------------------------------\n");

		printf("\n \t Volba: ");
		scanf_s("%d", &cond);

		printf("\n");

		switch (cond) {
		case 1: 
			printf("   Zadej ve formatu [jmeno] [prijmeni]: ");
			scanf("%s %s", tname, tsurname);
			print_debt(debtdatabase, p, tname, tsurname);
			break;
		case 2:
			helpdebt[0] = max_debt(debtdatabase, p);
			printf("\n\t Dluznik s nejvetsim dluhem: %s %s | %d | %d $\n", debtor_name(helpdebt[0]), debtor_surname(helpdebt[0]), debtor_age(helpdebt[0]), debtor_debt(helpdebt[0]));
			break;
		case 3: 
			printf("   Zadej ve formatu [jmeno] [prijmeni] [castka]: ");
			scanf("%s %s %d", tname, tsurname, &tdebt);
			increase_debt(debtdatabase, p, tname, tsurname, tdebt);
			break;
		case 4: 
			printf("   Zadej ve formatu [jmeno] [prijmeni] [castka]: ");
			scanf("%s %s %d", tname, tsurname, &tdebt);
			decrease_debt(debtdatabase, p, tname, tsurname, tdebt);
			break;
		case 5: 
			printf("   Zadej cislo poradi (od 1-8): ");
			scanf_s("%d", &tage);
			helpdebt[0] = ith_youngest(debtdatabase, tage, p);
			printf("\n\t i-ty nejmladsi: %s %s | %d | %d $\n", debtor_name(helpdebt[0]), debtor_surname(helpdebt[0]), debtor_age(helpdebt[0]), debtor_debt(helpdebt[0]));
			break;
		case 6: 
			sort_debts(debtdatabase, p);
			break;
		case 7:
			print_all(debtdatabase, p, 3);
			break;
		default: printf("\tZadat musite cisla od 0 - 7.\n\n"); break;
		}

		printf("-------------------------------------------------------------------------------------------\n\n");
	}
}