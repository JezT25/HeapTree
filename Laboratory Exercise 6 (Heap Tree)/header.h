#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MIN -999999
#define MAX 999999

typedef struct structNode{
	int data;
	struct structNode *next;
} node;

typedef struct heapTree{
    int data;
    struct heapTree *left;
    struct heapTree *right;
} tree;

//healTree.c
void insertNode(node **head, int num, int index);

//damageTree.c
void deleteNode(node **head);

//findStuff.c
void searchNode(node *head, int num, int *success);

//heapStuff.c
void maxHeap(node **head, int index);
void deleteHeap(node **head, int index);

//displayTree.c
void convert(tree **root, node *head, int index, int n);
void displayTree(tree *root, int *x, int y);
void gotoxy(short x, short y);

//stuffStuff.c
int numScan(int min, int max);

#endif
