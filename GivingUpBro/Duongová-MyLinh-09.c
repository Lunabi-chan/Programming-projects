#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nullptr ((void*)0)

/*
* 1.	Implementuj struktury nasledujici fcionalitou pro
*		hashovaci tabulky nad retezci s resenim kolizi retezenim.
*/

typedef struct {
	char* place;
	struct chaining_node* next;
} chaining_node;

typedef struct {
	chaining_node *root;
} chaining_tree;

typedef struct {
	chaining_tree* data;
	int (*hush)(char*),
		size;
} chaining_table;

int fun(char* str) {
	return str[0] % 8;
}

chaining_table *create_chaining_table(int size, int (*hash)(char*)) {
	if (size > 0) {
		chaining_table* ret = malloc(sizeof(chaining_table));

		if (ret) {
			ret->data = calloc(size, sizeof(chaining_tree));
			ret->hush = hash;
			ret->size = size;

			if (ret->data) {
				for (int i = 0; i < size; i++) {
					ret->data[i].root = nullptr;
				}

				return ret;
			}
		}
		else {
			return nullptr;
		}
	}
	return nullptr;
}

void list_add(chaining_node *in, chaining_node* node) {
	if (!(node->next)) {
		node->next = in;
	}
	else if (node->next) {
		list_add(in, node->next);
	}
}

int add_ct(char* data, chaining_table* table) {
	if (table) {
		int i = table->hush(data) % table->size;

		chaining_node* new = malloc(sizeof(chaining_node));
		
		if (new) {
			new->place = data;
			new->next = nullptr;

			if (!(table->data[i].root)) {
				table->data[i].root = new;
			}
			else {
				list_add(new, table->data[i].root);
			}
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

int list_remove(char* data, chaining_node* node) {
	if (node->next) {
		chaining_node* rem = node->next;

		if (!(strcmp(data, rem->place))) {
			if (rem->next) {
				chaining_node* next = rem->next;
				node->next = next;
				rem->next = nullptr;
			}
			else {
				node->next = nullptr;
			}

			free(rem);
			return 1;
		}
		else {
			list_remove(data, node->next);
		}
	}
	else {
		return 0;
	}
}

int remove_ct(char* data, chaining_table* table) {
	if (table) {
		int i = table->hush(data) % table->size;

		if (!(strcmp(data, table->data[i].root->place))) {
			chaining_node* here = table->data[i].root,
						 * next = here->next;
			
			table->data[i].root = next;
			here->next = nullptr;
			
			free(here);
			return 1;
		}
		else {
			return list_remove(data, table->data[i].root);
		}
	}
	else {
		return 0;
	}
}

int list_contains(char* data, chaining_node* node) {
	if (node->place) {
		if (!(strcmp(data, node->place))) {
			return 1;
		}
		else if (node->next) {
			list_contains(data, node->next);
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

int contains_ct(char* data, chaining_table* table) {
	if (table) {
		int i = table->hush(data) % table->size;
		return list_contains(data, table->data[i].root);
	}
	else {
		return 0;
	}
}

void print_ct(chaining_table table) {
	for (int i = 0; i < table.size; i++) {
		chaining_node* nib = table.data[i].root;

		if (nib) {
			printf("%i: ", i);
			while (nib) {
				printf("%s ", nib->place);
				nib = nib->next;
			}
			printf("\n");
		}
		else {
			continue;
		}
	}
}


/* 
*  2.	Implementuj struktury nasledujici fcionalitou pro
*		hashovaci tabulky nad retezci s resenim kolizi otevrenym adresovanim.
**/

typedef struct {
	int size,
		elements_in,
		(*hash)(char*),
		(*probe)(int, int);
	char** data;
} oa_table;

int oa_qua_probe(int a, int b) {
	return (a + (7 * b) + (5 * (b * b)));
} 

int oa_lin_probe(int a, int b) {
	return (a + b);
}

oa_table* create_oa_table(int size, int (*hash)(char*), int (*probe)(int, int)) {
	if (!(size == 0)) {
		oa_table* final;

		if (final = malloc(sizeof(oa_table))) {
			if (final->data = malloc(size * sizeof(char*))) {
				final->size = size;
				final->elements_in = 0;
				final->hash = hash;
				final->probe = probe;

				for (int i = 0; i < size; i++) {
					final->data[i] = NULL;
				}

				return final;
			}
		}
		free(final);
		return nullptr;
	}
	else {
		return nullptr;
	}
}

int add_oat(char* data, oa_table* table) {
	if (!(table->elements_in == table->size)) {
		int k = table->hash(data);

		for (int i = 0; i < table->size; i++) {
			int j = table->probe(k, i) % table->size;

			if (!(table->data[j]) || !(strcmp("REMOVED_OAT.0", table->data[j]))) {
				table->data[j] = data;
				table->elements_in++;

				return 1;
			}
		}

		return 0;
	}
	else {
		return 0;
	}
}

int remove_oat(char* data, oa_table* table) {
	int k = table->hash(data);

	for (int i = 0; i < table->size; i++) {
		int j = table->probe(k, i) % table->size;

		if (!(strcmp(data, table->data[j]))) {
			table->data[j] = "REMOVED_OAT.0";
			table->elements_in--;

			return 1;
		}
	}

	return 0;
}

int contains_oat(char* data, oa_table* table) {
	int k = table->hash(data);

	for (int i = 0; i < table->size; i++) {
		int j = table->probe(k, i) % table->size;

		if (!(strcmp(data, table->data[j]))) {
			return 1;
		}
	}

	return 0;
}

void print_oat(oa_table table) {
	for (int i = 0; i < table.size; i++) {
		printf("%i: %s\n", i, table.data[i]);
	}
}

void main() {
	chaining_table *a = create_chaining_table(3, fun);
	printf("add_ct: %d\n", add_ct("Awa", a));
	printf("add_ct: %d\n", add_ct("Aria", a));
	printf("add_ct: %d\n", add_ct("Atrocity", a));
	printf("add_ct: %d\n", add_ct("Bee", a));
	printf("add_ct: %d\n", add_ct("Ckheesekake", a));
	printf("contains_ct: %d\n", contains_ct("Awa", a));
	printf("contains_ct: %d\n", contains_ct("Developer", a));
	printf("remove_ct: %d\n", remove_ct("Awa", a));
	printf("remove_ct: %d\n", remove_ct("Developer", a));
	printf("contains_ct: %d\n", contains_ct("Aria", a));

	print_ct(*a);

	printf("\n\n\n ---- Kvadraticka pruzkumna fce ----\n");

	oa_table* b = create_oa_table(5, fun, oa_qua_probe);
	printf("add_oat: %d\n", add_oat("Awa", b));
	printf("add_oat: %d\n", add_oat("Aria", b));
	printf("add_oat: %d\n", add_oat("Alkaline", b));
	printf("add_oat: %d\n", add_oat("Anaconda", b));
	printf("add_oat: %d\n", add_oat("Atrocity", b));
	printf("remove_oat: %d\n", remove_oat("Awa", b));
	printf("remove_oat: %d\n", remove_oat("Aria", b));
	printf("remove_oat: %d\n", remove_oat("Aria", b));
	printf("add_oat: %d\n", add_oat("Always", b));
	printf("contains_oat: %d\n", contains_oat("Awa", b));
	printf("contains_oat: %d\n", contains_oat("Aria", b));
	printf("contains_oat: %d\n", contains_oat("Anaconda", b));

	print_oat(*b);


	printf("\n\n\n ---- Linearni pruzkumna fce ----\n");

	oa_table* c = create_oa_table(4, fun, oa_lin_probe);
	printf("add_oat: %d\n", add_oat("Awa", c));
	printf("add_oat: %d\n", add_oat("Aria", c));
	printf("add_oat: %d\n", add_oat("Alkaline", c));
	printf("add_oat: %d\n", add_oat("Anaconda", c));
	printf("add_oat: %d\n", add_oat("Atrocity", c));
	printf("remove_oat: %d\n", remove_oat("Awa", c));
	printf("remove_oat: %d\n", remove_oat("Aria", c));
	printf("remove_oat: %d\n", remove_oat("Aria", c));
	printf("add_oat: %d\n", add_oat("Always", c));
	printf("contains_oat: %d\n", contains_oat("Awa", c));
	printf("contains_oat: %d\n", contains_oat("Aria", c));
	printf("contains_oat: %d\n", contains_oat("Anaconda", c));

	print_oat(*c);

	free(a);
	free(b);
	free(c);
}