#include <stdio.h>
#include <stdlib.h>

#define M 2

typedef struct tree_node {int data; struct tree_node* children[M];} tree_node;
typedef struct tree {tree_node* root;} tree;

typedef struct node {tree_node *data; struct node* next;} node;
typedef struct {node* head;} queue;

void enqueue(queue* q, tree_node* data) {
    node* new_node = malloc(sizeof(node));
    new_node->data = &data;
    new_node->next = NULL;

    if (q->head == NULL) {
        q->head = new_node;
    } else {
        node* current = q->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}


tree_node* dequeue(queue* q) {
    if (q->head == NULL) {
        return NULL;
    } else {
        node* current = q->head;
        tree_node* data = current->data;
        q->head = current->next;
        free(current);
        return data;
    }
}

int is_empty(queue* q) {
    return (q->head == NULL);
}


void dfs_print_rec(tree_node* node){
    if (node == NULL) {
        return;
    }
    printf("%i, ", node->data);
    for (int i = 0; i < M; i++) {
        dfs_print_rec(node->children[i]);
    }
}

void dfs_print(tree t) {
    dfs_print_rec(t.root);
}


void bfs_print(tree t) {
    tree_node *x = t.root;
    queue q = {NULL};
    printf("%d", !is_empty(&q));
    enqueue(&q, x);
    /*while (is_empty(&q)) {
        tree_node *y = dequeue(&q);
        printf("%d, ", y->data);
        for (int i = 0; i < M; i++) {
            enqueue(&q, y->children[i]);
        }
    }*/
}





int main () {
    tree_node node4 = { .data = 2, .children = {NULL, NULL}};
    tree_node node3 = { .data = 4, .children = { NULL, NULL } };
    tree_node node2 = { .data = 3, .children = { &node3, NULL } };
    tree_node node1 = { .data = 1, .children = { &node4, &node2} };
    queue q = {NULL};
    tree t = { .root = &node1 };
    //dfs_print(t);
    
   bfs_print(t);

}
