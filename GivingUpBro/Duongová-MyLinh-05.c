#include <stdio.h>
#include <stdlib.h>

//--------------------------------- 1. UKOL --------------------------------------------
typedef struct {
	int data;
	struct node* next;
} node;

typedef struct {
	node* first;
} list;

#define nullptr ((void*)0)

// S - Zjisteni delky seznamu
int length(list seznam) {
	int x = 0;
	node *r = seznam.first;

	while (r != NULL) {
		r = r->next;
		x++;
	}

	return x;
}

// S - Vypis prvku seznamu oddelenych carkou
void print_list(list seznam) {
	node* r = seznam.first;

	while (r->next != NULL) {
		printf("%d, ", r->data);
		r = r->next;
	}

	if (r != NULL) {
		printf("%d\n", r->data);
	}
}

// S - Pridavani hodnoty na zacatek seznamu
void add_start(list* seznam, int data) {
	node* new = malloc(sizeof(node));
	node* help = seznam->first;

	new->data = data;
	new->next = help;

	seznam->first = new;
}

// S - Pridavani hodnoty na konec seznamu 
void add_end(list* seznam, int data) {
	node* new_node = malloc(sizeof(node));
	node* lit = seznam->first;

	if (new_node) {
		new_node->data = data;
		new_node->next = NULL;

		while (lit->next != NULL) {
			lit = lit->next;
		}

		lit->next = new_node;
	}
	else {
		return NULL;
	}
}

// S - Pridavani hodnoty na zadane misto v seznamu(nebo na konec, pokud se dana pozice v seznamu nevyskytuje)
void add_position(list* seznam, int data, int position) {
	if (position > length(*seznam) - 1)
	{
		add_end(seznam, data);
	}
	else {
		node* new = malloc(sizeof(node));
		node* help = seznam->first;
		node* q;

		new->data = data;

		for (int i = 0; i < position - 1; i++) {
			help = help->next;
		}

		q = help->next;
		help->next = new;
		new->next = q;
	}
}

// Odebirani hodnoty ze zacatku seznamu - vrati 0, pokud se neco smazalo, a - 1 jinak
int remove_start(list* seznam) {
	if (seznam != NULL) {
		node* pat = seznam->first;
		node* mat = pat->next;

		pat->next = nullptr;
		free(pat);

		seznam->first = mat;

		return 0;
	}
	else {
		return -1;
	}
} 

// S - Odebirani hodnoty z konce seznamu - vrati 0, pokud se meco smazalo, a - 1 jinak
int remove_end(list* seznam) {
	if (seznam != NULL) {
		node* lit = seznam->first;
		node* help = lit->next;

		while (help->next != NULL) {
			lit = lit->next;
			help = help->next;
		}
		
		lit->next = nullptr;
		free(help);

		return 0;
	}
	else {
		return -1;
	}
}

// S - Vyhledavani hodnoty v seznamu - vrati(prvni) pozici hledane hodnoty v seznamu, nebo - 1 pokud tam neni
int search(list seznam, int data) {
	node* p = seznam.first;
	int x = length(seznam);

	for (int i = 0; i < x; i++) {
		if (p->data == data) {
			return i;
		}
		p = p->next;
	}

	return -1;
}

// Odebirani zadane hodnoty(prvniho vyskytu) ze seznamu - vrati 0, pokud hodnota byla odebrana, a - 1 jinak
int remove(list* seznam, int data) {
	int j = search(*seznam, data);
	node* p = seznam->first;
	node* q;

	if (j == -1) {
		return -1;
	}
	if (j == 0) {
		remove_start(seznam);
	}
	else if (j == (length(*seznam) - 1)) {
		remove_end(seznam);
	}
	else {
		for (int i = 0; i < j - 1; i++) {
			p = p->next;
		}

		q = p->next;
		q = q->next;
		p->next = q;

		return 0;
	}
}


//--------------------------------- 2. UKOL --------------------------------------------
typedef struct {
	int data;
	struct tree_node* parent,
		            * left,
					* right;
} tree_node;

typedef struct {
	struct tree_node* root;
} tree;


//--------------------------------- 3. UKOL --------------------------------------------
// Pridava prvek do stromu
void add(tree* t, int data) {
	tree_node* new = malloc(sizeof(tree_node));
	tree_node* help = t->root;
	tree* p;

	new->data = data;
	new->left = NULL;
	new->parent = NULL;
	new->right = NULL;
	
	if (help == NULL) {
		t->root = new;
	}
	else if (help->left == NULL && data < help->data) {
		help->left = new;
		new->parent = help;
	}
	else if (help->right == NULL && data > help->data) {
		help->right = new;
		new->parent = help;
	}
	else if (data < help->data) {
		p = help->left;
		free(new);
		add(&p, data);
	}
	else if (data > help->data) {
		p = help->right;
		free(new);
		add(&p, data);
	}
}

// Vypise prvky ve strome ve vzestupnem poradi 
void print_in_order(tree t) {
	tree_node *r = t.root;

	if (r == NULL) {
		return;
	}
	else {
		printf("%d ", r->data);
		if (r->left != NULL) { 
			tree p = { r->left };
			print_in_order(p);
		}
		if (r->right != NULL) {
			tree p = { r->right };
			print_in_order(p);
		}
	}
}

// Vypocet hloubky stromu
int depth(tree t) {
	tree_node* r = t.root;
	int a = 1, b = 1;

	if (r == NULL) {
		return 0;
	}
	else {
		if (r->left != NULL) {
			tree p = { r->left };
			a = 1 + depth(p);
		}
		if (r->right != NULL) {
			tree p = { r->right };
			b = 1 + depth(p);
		}
	}

	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}


void main() {

	// 1. ukol
	/*node* nod = NULL;

	for (int i = 0; i < 10; i++) {
		add_start(&nod, i);
	}

	list head = { nod };

	printf("Length: %d\n", length(head));
	print_list(head);
	add_start(&head, 0);
	print_list(head);
	add_end(&head, 6);
	print_list(head);
	add_position(&head, 7, 89);
	print_list(head);
	remove_start(&head);
	print_list(head);
	remove_end(&head);
	print_list(head);
	printf("Search: %d\n", search(head, 2));
	remove(&head, 9);
	print_list(head);*/


	// 2. a 3. ukol
	/*
	tree_node* tres = NULL;

	tree head = { tres };

	int pain[5] = { 5, 2, 4 , 3, 1 };

	for (int i = 0; i < 5; i++) {
		add(&head, pain[i]);
	}
	printf("\n");
	

	print_in_order(head);

	printf("\n%d", depth(head));*/

}