#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 1. Implementujte vhodne struktury pro AVL strom(muzete vhodne modifikovat struktury, ktere mate z BST).
typedef struct {
	int data;
	struct avl_node* parent;
	struct avl_node* left;
	struct avl_node* right;
	int bf;
} avl_node;

typedef struct {
	avl_node* root;
} avl_tree;

// 2. Implementujte pomocne procedury pro udrzovani vysky AVL stromu - rotace.
avl_node* avl_rotation_R(avl_node* r) {
	avl_node* x = r->left;
	avl_node* y = x->right;

	r->left = y;
	x->right = r;

	return x;
}

avl_node* avl_rotation_L(avl_node* r) {
	avl_node* x = r->right;
	avl_node* y = x->left;

	r->right = y;
	x->left = r;

	return x;
}

avl_node* partition(avl_node* r, int k) {
	avl_node* t = (r->left == NULL) ? 0 : r->bf;
	if (t == (k - 1)) {
		return r;
	}
	else if (t > (k - 1)) {
		r->left = partition(r->left, k);
		return avl_rotation_R(r);
	}
	else {
		r->right = partition(r->right, k);
		return avl_rotation_L(r);
	}
}

avl_node* balance(avl_node* r) {
	if (!(r) || r->bf <= 2) {
		return r;
	}
	else {
		avl_node* ret = partition(r, floor(r->bf / 2) + 1);
		ret->left = balance(ret->left);
		ret->right = balance(ret->right);
		return ret;
	}
}

// 3. Implementujte pridavani prvku do AVL stromu(s vyuzitim rotaci z predchoziho bodu).
avl_node* avl_node_create(int data) {
	avl_node* new_node = malloc(sizeof(avl_node));
	
	new_node->data = data;
	
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	new_node->bf = 0;

	return new_node;
}

avl_node* avl_add(avl_node* r, avl_node* added) {
	if (!(r)) {
		return added;
	}
	else if (r->data > added->data) {
		r->left = avl_add(r->left, added);
		return avl_rotation_R(r);
	}
	else {
		r->right = avl_add(r->right, added);
		return avl_rotation_L(r);
	}
}

void avl_insert(avl_tree* t, avl_node* added) {
	t->root = avl_add(t->root, added);
	added->bf = 0;
	avl_node* u = added->parent;
	avl_node* v = added;

	while (u) {
		u->bf += (v == u->left) ? 1 : -1;

		if (u->bf == 0) {
			return;
		}
		if (u->bf == 2 || u->bf == -2) {
			avl_node* p = u->parent;
			avl_node* w = balance(u);
			// provedeni prislusne rotace stromu s korenem u, obdrzeni stromu s korenem w
			if (!(p)) {
				t->root = w;
			}
			else {
				avl_tree par = { p };
				avl_insert(&par, w);
				return;
			}
		}

		v = u;
		u = u->parent;
	}
}


// Tisk vyhledavanim do sirky
int** global_array;
int array_row, * array_column;

void array_redo_column(int m, int n) {
	int* helper = realloc(global_array[m], n * (sizeof(int)));

	if (helper) {
		global_array[m] = helper;
		array_column[m] = n;

		return;
	}
	return NULL;
}

void array_redo_row(int m) {
	int** temp = realloc(global_array, m * (sizeof(int*)));
	int* temp_column = realloc(array_column, m * (sizeof(int)));

	if (temp && temp_column) {
		global_array = temp;
		array_column = temp_column;

		global_array[m - 1] = malloc(sizeof(int));
		array_row = m;
		array_column[m - 1] = 1;

		return;
	}
	return NULL;
}

//Vypis prvku stromu v poradi pruchodu stromem do sirky 
void bft_help(avl_node* a, int n) {
	if (a) {
		if (n < array_row) {
			array_redo_column(n, array_column[n] + 1);
			global_array[n][array_column[n] - 1] = a->data;
		}
		else {
			array_redo_row(n + 1);
			global_array[n][0] = a->data;
		}

		if (a->left) {
			bft_help(a->left, n + 1);
		}
		if (a->right) {
			bft_help(a->right, n + 1);
		}
	}

	return;
}

void print_bft(avl_tree* t) {
	global_array = calloc(1, sizeof(int*));
	array_column = calloc(1, sizeof(int));

	if (global_array && array_column) {
		bft_help(t->root, 0);

		printf("\n");

		for (int i = 0; i < array_row; i++) {
			for (int j = 0; j < array_column[i]; j++) {
				printf("%d ", global_array[i][j]);
			}
			printf("\n");
		}

		free(global_array);
		free(array_column);
		array_row = 0;
	}
	else {
		return NULL;
	}
}

void main() {
	avl_node strom1 = { 1, NULL, NULL, NULL };
	avl_node strom2 = { 2, NULL, NULL, NULL };
	avl_node strom3 = { 3, NULL, NULL, NULL };
	avl_node strom4 = { 4, NULL, NULL, NULL };
	avl_node strom5 = { 5, NULL, NULL, NULL };
	avl_node strom6 = { 6, NULL, NULL, NULL };
	avl_node strom7 = { 7, NULL, NULL, NULL };

	avl_node pain[6] = { strom1, strom2, strom3, strom5, strom6, strom7 };

	avl_tree head = { &strom7 };

	avl_node testh = { 33, NULL, NULL, NULL };
	avl_tree headt = { &testh };

	int date[15] = { 3, 5, 8, 6, 4, 11, 2, 13, 14, 15, 1, 4, 9, 10, 16 };
	int test[7] = { 13, 53, 11, 21, 61, 8, 9 };

	for (int i = 0; i < 7; i++) {
		avl_insert(&head, avl_node_create(date[i]));
	}

	print_bft(&head);
	printf("\n\n");
}