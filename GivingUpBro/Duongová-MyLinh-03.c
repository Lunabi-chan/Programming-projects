#include <stdio.h>

// kazdy node bude pouzit jednou
// zadne alokace

// 1. ukol
typedef struct {
	int data; 
	struct node* next;
} node;

// 2. ukol
typedef struct { 
	node first; 
} list;


// 3. ukol

// - zjisteni delky seznamu
int length(list seznam) {
	int x = 1;
	node *r = &seznam.first;

	while (r->next != NULL) {
		r = r->next;
		x++;
	}

	return x;
}

// - vypis prvku seznamu oddelenych carkou 
void print_list(list seznam) {
	node* r = &seznam.first;

	while (r->next != NULL) {
		printf("%d, ", r->data);
		r = r->next;
	}

	if (r != NULL) {
		printf("%d", r->data);
	}
}

// - pridavani uzlu na zacatek seznamu
void add_start(list* seznam, node* uzel) {
	node p = seznam->first;
	uzel->next = &p;
	seznam->first = *uzel;
}


// - pridavani uzlu na konec seznamu
void add_end(list* seznam, node* uzel) {
	node* p = &seznam->first;
	int x = length(*seznam) - 1;

	for (int i = 0; i < x; i++) {
		p = p->next;
	}

	p->next = uzel;
}


// - pridavani uzlu na zadane misto
void add_position(list* seznam, node* uzel, int position) {  // OPRAV
	node* p = &seznam->first;
	node* q;
	
	int x = length(*seznam);
	
	if (position == 0) {
		add_start(seznam, uzel);
	}
	if (position > x || position < 0) {
		printf("\nZadali jste pozici mimo frontu.\n");
	}
	else if (position > 0) {
		for (int i = 0; i < position - 1; i++) {
			p = p->next;
		}

		q = p->next;
		p->next = uzel;
		p = p->next;
		p->next = q;
	}
}

// - odebirani uzlu ze zacatku seznamu, vrati 0 jestli se neco smazalo, jinak -1
int remove_start(list* seznam) {
	node* p = &seznam->first;

	if (p->data == NULL) {
		return -1;
	}
	else {
		p = p->next;
		seznam->first = *p;

		return 0;
	}
}

// - odebirani uzlu z konce seznamu, vrati 0 jestli se neco smazalo, jinak -1
int remove_end(list* seznam) {
	node* p = &seznam->first;
	int x = length(*seznam);

	if (p->data == NULL) {
		return -1;
	}
	else {
		for (int i = 0; i < x - 2; i++) {
			p = p->next;
		}
		
		p->next = NULL;

		return 0;
	}
}


// - vyhledavani uzlu v seznamu, vratu pozici hledaneho uzlu v seznamu, jinak -1
int search(list* seznam, node* uzel) {
	node* p = &seznam->first;
	int x = length(*seznam);

	for (int i = 0; i < x; i++) {
		if (p->data == uzel->data && p->next == uzel->next) {
			return i;
		}
		p = p->next;
	}

	return -1;	
}

// - odebirani zadaneho uzlu ze seznamu - vrati 0, jestli byl odebran, jinak -1
int remove(list* seznam, node* uzel) {
	int j = search(seznam, uzel);
	node* p = &seznam->first;
	node* q;
	
	if (j == -1) {
		return -1;
	}
	if (j == 0) {
		remove_start(seznam);
	}
	else if (j > 0) {
		for (int i = 0; i < j - 1; i++) {
			p = p->next;
		}

		q = p->next;
		q = q->next;
		p->next = q;

		return 0;
	}
}


void main() {

}
