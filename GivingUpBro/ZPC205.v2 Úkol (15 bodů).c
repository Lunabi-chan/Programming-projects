#include <stdio.h>
#include <stdlib.h>

int string_length(char* array) {		// Zjisti delku retezce
	int a = 0;

	if (array) {
		for (int i = 0; array[i] != '\0'; i++) {
			a++;
		}
	}

	return a;
}

char* scan_from_string(char* array) {	// fce scanuje z retezce (array) a vrati string (slovo za nimz je mezera/prazdny znak)
	char letter, 
		* temp, 
		* ret = malloc(sizeof(char));
	int len = 0;

	if (ret == NULL) {
		return NULL;
	}

	sscanf_s(array, "%c", &letter, (unsigned)sizeof(char));

	while (letter != ' ' && letter != '\n' && array[0] != '\0') {
		temp = realloc(ret, (len + 2) * sizeof(char));

		if (temp) {
			temp[len] = letter;
			temp[len + 1] = '\0';

			ret = temp;
		}
		else {
			return NULL;
		}

		array++;
		len++;

		sscanf_s(array, "%c", &letter, (unsigned)sizeof(char));
	}

	return ret;
}

char* filtruj_data(char* input_string, char first_letter, int age_limit) {
	int length = string_length(input_string) - 1,		// delka input_sgtringu
		position_in_string = 0,							// promenna na zaznamovani pozice v input_stringu
		out_length = 2,									// delka retezce, kteroy se vraci
		age_length = 0,									// delka stringu veku
		name_length = 0,								// delka stringu jmena
		int_age;										// pomocna promenna pro vek v integeru 
	
	char* help_name,									// pole pro jednotlive jmeno
		* help_age,										// pole pro jednotlivy vek
		* out = calloc(2, sizeof(char)),				// retezec, ktery se vrati
		* temporary;								// pomocny retezec

	if (input_string && out) {
		out = "0";
		temporary = out;

		do {
			if ((input_string[0] >= 'A' && input_string[0] <= 'Z') || (input_string[0] >= 'a' && input_string[0] <= 'z')) {
				if (help_name = scan_from_string(input_string)) {	// scan 1. jmena v retezci
					name_length = string_length(help_name);			// delka jmena

					input_string += name_length + 1;				// pohyb po input_stringu
					position_in_string += name_length + 1;			// sledovani pozice v input_stringu
				}
				else {
					return NULL;
				}
			}
			else {
				return NULL;
			}

			if (input_string[0] >= '0' && input_string[0] <= '9') {
				if (help_age = scan_from_string(input_string)) {	// scan 1. veku v retezci
					age_length = string_length(help_age);			// delka veku
					sscanf_s(help_age, "%d ", &int_age);			// pretypovani z char na int

					input_string += age_length + 1;					// posunuti v input_stringu
					position_in_string += age_length + 1;			// sledovani pozice input_stringu
				}
				else {
					return NULL;
				}
			}
			else {
				return NULL;
			}

			if (help_name[0] == first_letter && int_age >= age_limit) {			// checkovani podminek na aktualni jmeno a vek
				out_length += name_length + age_length + 3;						// jestli to plati, tak se ulozi delky veku a jmena do delky finalniho retezce
				temporary = realloc(out, out_length * (sizeof(char)));			// realokace pameti out do temporary a zvetseni jeho mista v pameti

				if (temporary) {
					sprintf_s(temporary, out_length, "%s%s %s ", temporary, help_name, help_age);	// ukladani aktualniho jmena a veku, ktere sedi podmince, do temporary
					out = temporary;																// tady se myslim predava pointer z temporary outu?
				}
				else {
					return NULL;
				}
			}

			free(help_name);
			free(help_age);
		} while (position_in_string < length);			// jestli je pozice v input_stringu mensi jak jeho velikost, cyklus pokracuje

		if (out[0] != '0') {
			out[string_length(out) - 1] = '\0';
		}

		return out;		// vracim retezec s jmeny a veky, ktere sedi podmince
	}
	else {
		return NULL;
	}
}

void main() {
	/*char* chain = malloc(sizeof(char)),
		* temp,
		chain_letter = '\0',
		letter = '\0';
	int len = 0,
		age = 0;

	printf("Zadejte retezec: ");

	if (chain) {
		while (scanf_s("%c", &chain_letter, 1)) {	// scan inputu char po charu a jeho ukladani do pole
			if (chain_letter == '\n') {
				break;
			}

			temp = realloc(chain, (len + 2) * sizeof(char));

			if (temp) {
				temp[len] = chain_letter;
				temp[len + 1] = '\0';

				chain = temp;
			}
			else {
				printf("Spatna alokace?");
				return;
			}

			len++;
		}
	}

	printf("Zadejte podminky ve formatu [velke_pismeno vek]: ");
	scanf_s("%c %d", &letter, 1, &age);

	char* result = filtruj_data(chain, letter, age);
	printf("\n%s", result);
	printf("\n%s", chain);

	/* Retezec na testovani :
	Anna 58 Jana 65 Hana 58 Greg 85 Olive 12 Par 68 Ann 18 Alice 34
	*/

	char r1[] = "Alena 20 Anna 30 Alan 40";
	printf("\n-%s- \n", filtruj_data(r1, 'C', 20));
	printf("-%s- \n", filtruj_data(r1, 'C', 30));

	printf("%s", r1);

	//free(chain);
	//free(result);
}