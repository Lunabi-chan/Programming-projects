#include <stdio.h>
#include <stdlib.h>

typedef struct node { int data; struct node* next; } node;
typedef struct list { node * head; } list;

void print_rec(node* node) {
    if (node == NULL) {
        return;
    }
    printf("%i, ", node->data);
    if (node->next == NULL) {
        return;
    }
    print_rec(node->next);
}

void print_list(list l) {
    print_rec(l.head);
}

int length_rec(node* node) {
    if (node == NULL) {
        return 0;
    }
	if (node->next == NULL) {
		return 1;
	}
	return 1 + length_rec(node->next);
}

int length_list(list *l) {
	return length_rec(l->head);
}

void add_start(list* l, int data) {
    node* node = malloc(sizeof(node));
    if (node == NULL) {
        printf("chyba alokace");
        return;
    }
    printf("_____ %p ______\n", node);
    node->data = data;
    node->next = NULL;
    node->next = l->head;
    l->head = node;
}

void add_end_rec(node* l,node *node) {
    if (l->next == NULL) {
        l->next = node;
        return;
    }
    add_end_rec(l->next, node);
}

void add_end(list* list, int data) {
    node* node = malloc(sizeof(node));
    if (node == NULL) {
        printf("chyba alokace");
        return;
    }
    node->data = data;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
    }
    else {
        add_end_rec(list->head, node);
    }
}

int remove_start(list* l) {
    if (l->head == NULL) {
        return -1;
    }
    node* temp = l->head;
    l->head = l->head->next;
    printf("???? %p ????", temp);
    //free(temp);
    return 0;
}

int main() {
    list list = { NULL };
    for (int i = 3; i > 0; i--) {
        add_start(&list, i);
    }
    //add_end(&list, 10);
    printf("\nRemove-start: %d\n", remove_start(&list));
    print_list(list);
    printf("\n%d", length_list(&list));
	return 0;
}