#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct node* parent;
	struct node* left;
	struct node* right;
} node;

typedef struct {
	node* root;
} tree;

int** global_array;
int array_row, *array_column;

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

void add(tree* t, int data) {
	node* new_node = malloc(sizeof(node));
	node* help = t->root;
	tree* p;

	if (new_node) {
		new_node->data = data;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->parent = NULL;

		if (!(help)) {
			t->root = new_node;
		}
		else if (!(help->left) && data < help->data) {
			help->left = new_node;
			new_node->parent = help;
		}
		else if (!(help->right) && data > help->data) {
			help->right = new_node;
			new_node->parent = help;
		}
		else if (data < help->data) {
			free(new_node);
			p = help->left;
			add(&p, data);
		}
		else if (data > help->data) {
			free(new_node);
			p = help->right;
			add(&p, data);
		}
	}
	else {
		return;
	}
}

//--------------------------------- 1. UKOL --------------------------------------------
//Muzete predpokladat, ze procedury nikdy nebudou volany s root == NULL, tj.minimum i maximu budou vzdy existovat.
//Hledani minima a maxima (korenovym uzlem) v zadaném podstromu : 
int tree_max(node* root) {
	if (root) {		// Kontroluji jestli je root NULL nebo ne. Jen tak pro jistotu
		int c = root->data;
		int a = (c > (a = (root->left) ? tree_max(root->left) : 0)) ? c : a;
		int b = (root->right) ? tree_max(root->right) : 0;

		return (a >= b) ? a : b;
	}
	else {
		return 0;
	}
}

int tree_min(node* root) {
	if (root) {	
		int c = root->data;
		int a = (c <= (a = (root->left) ? tree_min(root->left) : c)) ? c : a;
		int b = (root->right) ? tree_min(root->right) : c;

		return (a <= b) ? a : b;
	}
	else {
		return 0;
	}
}

//--------------------------------- 2. UKOL --------------------------------------------
//Odebirani prvku ze stromu - vracejici 1 pokud neco bylo smazano a 0 jinak.
void tree_swap(tree* t, node* u, node* v) {
	if (u->parent == NULL) {
		t->root = v;
		return;
	}

	node* y = u->parent;

	if (u == y->left) {
		y->left = v;
	}
	else {
		y->right = v;
	}

	if (v != NULL) {
		v->parent = u->parent;
	}

	return;
}

void node_swap(tree* t, node* u, node* v) {
	v->left = u->left;
	v->right = u->right;

	if (t->root == u) {
		t->root = v;
		return;
	}

	node* y = u->parent;

	if (u == y->left) {
		y->left = v;
	}
	if (u == y->right) {
		y->right = v;
	}

	return;
}

node* tree_min_rem(node* y) {
	while (y->left != NULL) {
		y = y->left;
	}

	return y;
}

void tree_delete(tree* t, node* nod) {
	if (!(nod->left)) {
		tree_swap(t, nod, nod->right);
		return;
	}
	else if (!(nod->right)) {
		tree_swap(t, nod, nod->left);
		return;
	}

	node* y = tree_min_rem(nod->right);
	tree_delete(t, y);
	node_swap(t, nod, y);
}

int tree_remove(tree* t, int data) {
	node* here = t->root;
	if (here) {
		if (here->data == data) {
			tree_delete(t, here);
			return 1;
		}
		else {
			tree* tr = &here->left;
			if (tree_remove(tr, data)) {
				return 1;
			}
			
			tr = &here->right;
			if (tree_remove(tr, data)) {
				return 1;
			}
		}
	}
	return 0;
}

//--------------------------------- 3. UKOL --------------------------------------------
//Vypis prvku stromu v poradi pruchodu stromem do sirky 
void bft_help(node* a, int n) {
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

void print_bft(tree* t) {
	global_array = calloc(1, sizeof(int*));
	array_column = calloc(1, sizeof(int));

	if (global_array && array_column) {
		bft_help(t->root, 0);

		printf("\n");

		for (int i = 0; i < array_row; i++) {
			for (int j = 0; j < array_column[i]; j++) {
				printf("%d ", global_array[i][j]);
			}
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
	node* tres = NULL;

	tree head;
	head.root = tres;
	
	int pole[10] = { 3, 2, 4, 5, 1, 8, 13, 6, 10, 7};
	
	for (int i = 0; i < sizeof pole / sizeof pole[0]; i++) {
		add(&head, pole[i]);
	}

	printf("Max: %d\n", tree_max(head.root));
	printf("Min: %d\n\n", tree_min(head.root));

	print_bft(&head);
	
	printf("\n\nRem?: %d\n", tree_remove(&head, 8));
	printf("Rem?: %d\n", tree_remove(&head, 4));

	print_bft(&head);
}