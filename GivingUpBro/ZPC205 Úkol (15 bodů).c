#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char* name;
	int age;
} information;

int string_length(char* array) {	// Zjisti delku retezce
	int a = 0;

	if (array == NULL) {
		return 0;
	}

	for (int i = 0; array[i] != '\0'; i++) {
		a++;
	}

	return a;
}

char* scan_from_string(char* array) {
	char letter, * temp = malloc(sizeof(char)), * ret = malloc(sizeof(char));
	int len = 0;
	
	sscanf_s(array, "%c", &letter, (unsigned)sizeof(char));

	while (letter != ' ' && letter != '\n' && array[0] != '\0') {
		temp = realloc(ret, (len + 2) * sizeof(char));

		if (temp != NULL) {
			temp[len] = letter;
			temp[len + 1] = '\0';

			ret = temp;
		}
		else {
			printf("Spatna alokace?");
			return NULL;
		}

		array++;
		len++;

		sscanf_s(array, "%c", &letter, (unsigned)sizeof(char));
	}
	
	return ret;
}

char* filtruj_data(char* input_string, char first_letter, int age_limit) {
	int length = string_length(input_string);
	// Nasledujicich 3 radky kontroluji zda 1. znak retezce splnuje podminku - prvni slovo musi byt jmeno s velkym pismenem a jestli je retezec delsi jak 3 znaky
	if (!(input_string == NULL || input_string[0] >= 'A' && input_string[0] <= 'Z') ||  length < 4) {
		return NULL;
	}

	int c = 0, i_info = 0, var_length = 0; 
	char *help_name, *help_age;
	
	information* info = malloc(sizeof(information)), * inf;

	do {
		information data;
		inf = realloc(info, (i_info + 1) * sizeof(information));

		if (inf == NULL) {
			return NULL;
		}

		if ((input_string[0] >= 'A' && input_string[0] <= 'Z') || (input_string[0] >= 'a' && input_string[0] <= 'z')) {
			help_name = scan_from_string(input_string);
			var_length = string_length(help_name);
			data.name = malloc(var_length * sizeof(char));
			data.name = help_name;

			if (data.name == NULL) {
				return NULL;
			}

			input_string += var_length + 1;
			c += var_length + 1;
		}
		else {
			return NULL;
		}

		if (input_string[0] >= '0' && input_string[0] <= '9') {	
			help_age = scan_from_string(input_string);	
			var_length = string_length(help_age);
			sscanf_s(help_age, "%d ", &data.age);

			input_string += var_length + 1;
			c += var_length + 1;
		}
		else {
			return NULL;
		}

		*(inf + i_info) = data;
		info = inf;
		i_info++;
	} while (c < length);

	info = inf;
	char* out = calloc(1, sizeof(char)), * temporary = calloc(1, sizeof(char));

	if (out == NULL) {
		return NULL;
	}

	for (int lamma = 0; lamma < i_info; lamma++) {
		if (info[lamma].name[0] == first_letter && info[lamma].age >= age_limit) { 
			help_name = scan_from_string(info[lamma].name);
			sprintf_s(help_age, 3, "%d", info[lamma].age);	 
			
			var_length += string_length(help_name) + string_length(help_age) + 2;
			temporary = realloc(out, var_length * (sizeof(char)));

			if (temporary == NULL) {
				return NULL;
			}
			
			sprintf_s(temporary, var_length, "%s%s %s ", temporary, help_name, help_age);

			out = temporary;
		}
	}	
	
	free(info);
	
	return out;
}

void main() {
	char* chain = calloc(1, sizeof(char)), * temp = calloc(1, sizeof(char));
	char chain_letter = '\0', letter = '\0';
	int len = 0, age = 0;

	printf("Zadejte retezec: ");

	while (scanf_s("%c", &chain_letter, 1) == 1) {
		if (chain_letter == '\n') {
			break;
		}

		temp = realloc(chain, (len + 2) * sizeof(char));

		if (temp != NULL) {
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

	printf("Zadejte podminky ve formatu [velke_pismeno vek]: ");
	scanf_s("%c %d", &letter, 1, &age);

	char* result = filtruj_data(chain, letter, age);
	printf("\n%s", result);
	
	//Anna 58 Jana 65 Hana 58 Greg 85 Olive 12 Par 68 Ann 18 Alice 34
}