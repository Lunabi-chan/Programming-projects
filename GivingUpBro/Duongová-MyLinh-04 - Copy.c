#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int date;
	struct tree_node* sibling;
	struct tree_node* child;
} tree_node;

typedef struct {
	tree_node* root;
} tree;


tree_node* array_help[100];
int globgar = 1;

// 1. Pridani prvku do stromu. 
//    Muze byt pridan do nahodne pozice, ale strom stale musibyt m-arni

// Verze bez dynamicke alokace:
void add(tree* t, tree_node* data) {
	tree_node *place = t->root;

	if (place == NULL) {
		place = data;
	}

	do {
		place = place->child;
	} while (place->child != NULL);

	place->child = data;
}

// 2. Vypsani ve strome pruchodem do hloubky
void dfs_print(tree t) {
	tree_node *tool = t.root;

	if (tool == NULL) {
		return;
	}
	else {
		 do {
			printf("%d ", tool->date);
			
			tree *uwu = &tool->child;
			dfs_print(*uwu);

			tool = tool->sibling;
		} while (tool != NULL);
	}
}

void array_helper(int zar) {
	tree_node OnlyNULL = { NULL, NULL, NULL };
	for (int i = 0; i < zar + 1; i++) {
		array_help[i] = &OnlyNULL;
	}
}

int depth(tree t) {
	tree_node* tool = t.root;
	tree* uwu;
	int a = 1, b = 1;

	if (tool == NULL) {
		return 0;
	}
	else {
		if (tool->child != NULL) {
			uwu = &tool->child;
			a = depth(*uwu) + 1;
		} 
		if (tool->sibling != NULL) {
			tool = tool->sibling;
			uwu = &tool->child;
			b = depth(*uwu) + 1;
		}

		if (a <= b) {
			return b;
		}
		else
			return a;
	}
}

void bfs_help(tree t, int n) {
	tree_node* tool = t.root;
	tree_node* loot = array_help[n];

	if (tool == NULL) {
		return;
	}
	else {
		if (loot->date != NULL) {
			while (loot->sibling != NULL) {
				loot = loot->sibling;
			}

			loot->sibling = tool;
		}
		else {
			array_help[n] = tool;
		}

		do {
			tree* uwu = &tool->child;
			bfs_help(*uwu, n + 1);
			tool = tool->sibling;
		} while (tool != NULL);
	}
}

// 3. Vypsani ve strome pruchodem do sirky
void bfs_print(tree t) {
	globgar = depth(t); 
	array_helper(globgar);

	bfs_help(t, 0);

	for (int i = 0; i < globgar; i++) {
		tree_node* help = array_help[i];
		while (help != NULL) {
			printf("%d ", help->date);
			help = help->sibling;
		}
	}
}



void main() {
	tree_node a = { 11, NULL, NULL};
	tree_node b = { 10, NULL, NULL };
	tree_node c = { 9, NULL, NULL };
	tree_node d = { 8, NULL, NULL };
	tree_node e = { 7, NULL, NULL };
	tree_node f = { 6, NULL, NULL };
	tree_node g = { 5, NULL, NULL };
	tree_node h = { 4, NULL, NULL };
	tree_node i = { 3, NULL, NULL };
	tree_node j = { 2, NULL, NULL };
	tree_node k = { 1, NULL, NULL };

	k.child = &j;
	j.child = &i;
	i.child = &h;
	h.child = &g;
	g.child = &d;
	//g.child = &a;
	
	j.sibling = &i;
	i.sibling = &h;
	g.sibling = &f;
	d.sibling = &c;
	c.sibling = &b;

	tree head;
	head.root = &k;

	add(&head, &a);
	dfs_print(head);
	printf("\n");
	bfs_print(head);

}