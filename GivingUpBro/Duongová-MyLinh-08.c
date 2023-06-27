#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define t 3
#define TRUE 1
#define FALSE 0

/* 1. Implementujte strukturu pro B-strom*/
typedef struct {
	int leaf;
	int n;
	int id[(2 * t) - 1];

	struct b_node *parent;
	struct b_node *children[2 * t];	
} b_node;

typedef struct {
	b_node *root;
} b_tree;

/* 2. Implementujte vyhledavani prvku v B-stromu*/
typedef struct {
	b_node *place;
	int index;
} b_searched_key;

b_searched_key b_search(b_node *x, int key) {
	int i = 0;
	b_searched_key renata;

	while (i < x->n && key > x->id[i]) {
		i++;
	}	

	if (i < x->n && key == x->id[i]) {
		renata.place = x;
		renata.index = i;

		return renata;
	}
	else if (x->leaf == TRUE) {
		renata.place = NULL;
		renata.index = i;
	}
	else {
		renata = b_search(x->children[i], key);
	}

	return renata;
}

/* 3. Implementujte vkladani do B-stromu jejim pruchodem*/
typedef struct {
	int median;
	b_node* child_l;
	b_node* child_r;
} split_keys;

b_node* create_node() {
	b_node* node = malloc(sizeof(b_node));

	if (node) {
		node->n = 0;
		node->leaf = TRUE;
		node->parent = NULL;

		for (int i = 0; i < 2 * t; i++) {
			node->children[i] = NULL;
		}

		return node;
	}
	else {
		return NULL;
	}
}

b_tree* create_tree() {
	b_tree* tree = malloc(sizeof(b_tree));
	b_node* node = create_node();

	if (tree) {
		tree->root = node;
		return tree;
	}
	else {
		return NULL;
	}
}

void b_print(b_node* root) {
	if (root) {
		for (int i = 0; i < root->n; i++) {
			printf("%d ", root->id[i]);
		}
		printf("\n");

		if (!(root->leaf)) {
			for (int i = 0; i < root->n + 1; i++) {
				b_print(root->children[i]);
			}
		}
	}
	else {
		printf("(null)");
	}
}

void b_set_child_to_par(b_node* child, b_node* pare, int i) {
	pare->children[i] = child;
	if (child) {
		child->parent = pare;
	}
}

void b_shift_r(b_node* node, int i) {
	node->children[node->n] = node->children[node->n - 1];
	
	for (int j = node->n; j > i; j--) {
		node->id[j] = node->id[j - 1];
		node->children[j] = node->children[j - 1];
		node->children[j - 1] = NULL;
	}
}

split_keys* b_split(b_node* node) {
	b_node* right = create_node();

	int median = node->id[t - 1];
	right->leaf = node->leaf;
	right->n = t - 1;

	for (int i = 0; i < t - 1; i++) {
		right->id[i] = node->id[t + i];
		right->children[i] = node->children[i + t];
	}

	right->children[t - 1] = node->children[(2 * t) - 1];
	node->n = t - 1;

	split_keys* ret = malloc(sizeof(split_keys));

	if (ret) {
		ret->median = median;
		ret->child_l = node;
		ret->child_r = right;

		return ret;
	}
	else {
		return;
	}
}

void b_insert_with_sub(b_tree* tree, b_node* node, int key, b_node* left, b_node* right) {
	if (!(node)) {
		b_node* new = create_node();
		new->n++;
		new->leaf = FALSE;
		new->id[0] = key;
		
		b_set_child_to_par(left, new, 0);
		b_set_child_to_par(right, new, 1);

		tree->root = new;
		printf("");
	}
	else if (node->n == (2 * t) - 1) {
		b_node* pare = node->parent;
		split_keys* splk = b_split(node);

		if (key < splk->median) {
			b_insert_with_sub(tree, splk->child_l, key, left, right);
		}
		else {
			b_insert_with_sub(tree, splk->child_r, key, left, right);
		}

		b_insert_with_sub(tree, pare, splk->median, splk->child_l, splk->child_r);
	}
	else {
		int i = 0;
		while (i < node->n && key > node->id[i]) {
			i++;
		}

		node->n++;

		b_shift_r(node, i);

		node->id[i] = key;

		b_set_child_to_par(left, node, i);
		b_set_child_to_par(right, node, i+1);
	}
}

b_node* b_find_insertion_vertex(b_node* node, int key) {
	int i = 0;
	while (i < node->n && key > node->id[i]) {
		i++;
	}

	if (node->leaf) {
		return node;
	}
	else {
		b_find_insertion_vertex(node->children[i], key);
	}
}

void b_insert(b_tree *tree, int key) {
	b_node* here = b_find_insertion_vertex(tree->root, key);
	b_insert_with_sub(tree, here, key, NULL, NULL);
}

void main() {
	b_tree* tree = create_tree();

	int pole[10] = { 2, 3, 8, 19, 1, 485, 14, 23, 67, 54 };

	for (int i = 0; i < 10; i++) {
		b_insert(tree, pole[i]);
	}
	
	int pole2[5] = { 741, 145, 0, 36, 91 };

	for (int i = 0; i < 5; i++) {
		b_insert(tree, pole2[i]);
	}

	b_print(tree->root);

	b_searched_key b_searc = b_search(tree->root, 36);

	printf("\n%d\n", b_searc.index);
	b_print(b_searc.place);

	b_searc = b_search(tree->root, 400);

	printf("\n%d\n", b_searc.index);
	b_print(b_searc.place);
}