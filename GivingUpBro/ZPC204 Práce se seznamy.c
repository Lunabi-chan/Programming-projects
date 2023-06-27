#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
} node;

typedef struct {
	struct node* first;
} list;

node *add(node** list, int date) {
	node *new = malloc(sizeof(node));

	new->data = date;
	new->next = *list;

	*list = new;

	return new;
}

void print(node pri) {
	while (pri.next != NULL) {
		printf("%d ", pri.data);
		pri = *pri.next;
	}

	printf("%d ", pri.data);
}

int length(node list) {
	int x = 0;

	while (list.next != NULL) {
		x++;
		list = *list.next;
	}

	return x;
}

node* add_last(node *lit, int date) {
	node* new = malloc(sizeof(node));

	new->data = date;
	new->next = NULL;

	list veryBest = { lit };

	while (lit->next != NULL) {
		lit = lit->next;
	}

	lit->next = new;

	return veryBest.first;
}

node* delete_first(node* lit) {
	node *i_am_he = lit->next;
	list *but_I_will_never_be_him = { &i_am_he };

	lit->next = NULL;
	free(lit);

	return but_I_will_never_be_him->first;
}



void main() {
	node *nod = NULL;

	for (int i = 0; i < 10; i++) {
		nod = add(&nod, i);
	}

	list head = { nod };

	node *pri = head.first;

	
	print(*pri);
	printf("\n%d\n", length(*nod));
	pri = add_last(pri, 11);
	print(*pri);
	pri = delete_first(pri);
	printf("\n");
	print(*pri);
}