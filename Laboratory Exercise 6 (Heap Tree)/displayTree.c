#include "header.h"

void convert(tree **root, node *head, int index, int n){
    if(index < n) {
		int i;
		
		node *temp = head;
		
		for(i=0;i<index;i++) temp = temp->next;
	
		tree *node = malloc(sizeof(tree));
		
		*root = node;
		
		node->data = temp->data;
       	node->left = NULL;
       	node->right = NULL;
       		
       	convert(&node->left, head, 2*index+1, n);
       	convert(&node->right, head, 2*index+2, n);
    }
}

void displayTree(tree *root, int *x, int y){
	if(root!=NULL){
		displayTree(root->left, x, y+2);
		gotoxy(*x, y);
		printf("%d", root->data);
		*x += 4;
		displayTree(root->right, x, y+2);
	}
}

void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

