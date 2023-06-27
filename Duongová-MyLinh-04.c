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


tree_node* array_help[100];		// pomocne pole pro bfs_print
int globgar = 1;				// promenna pro velikost pole array_help

// 1. Pridani prvku do stromu. 
//    Muze byt pridan do nahodne pozice, ale strom stale musibyt m-arni
// Verze bez dynamicke alokace:
void add(tree* t, tree_node* data) {		
	tree_node *place = t->root;

	if (place == NULL) {
		return;
	}

	do {
		place = place->child;
	} while (place->child != NULL);

	place->child = data; // pridavam uzel na konec 1. vetve stromu
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
			
			tree *uwu = &tool->child;	// potomek tool je ulozen do promenne uwu a pote je pouzita rekurze
			dfs_print(*uwu);

			tool = tool->sibling;	
		} while (tool != NULL);			
	}
}

void array_helper(int zar) {		// funkce na ulozeni NULL do pomocneho pole
	tree_node OnlyNULL = { NULL, NULL, NULL };
	for (int i = 0; i < zar + 1; i++) {
		array_help[i] = &OnlyNULL;
	}
}

int depth(tree t) {			// funkce pro vysku stromu
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

void bfs_help(tree t, int n) {			// pomocna funkce pro bfs, kde ukladam uzly do array_help podle toho, na jake vysce se nachazeji
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

	for (int i = 0; i < globgar; i++) {			// tisk uzlu z array_help
		tree_node* help = array_help[i];
		while (help != NULL) {
			printf("%d ", help->date);
			help = help->sibling;
		}
	}
}



void main() {
	

}