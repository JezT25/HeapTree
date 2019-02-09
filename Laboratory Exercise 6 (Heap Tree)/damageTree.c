#include "header.h"

void deleteNode(node **head){
	if((*head)->next!=NULL){
		node *traverse = *head;
		node *temp;
		
		while(traverse->next->next != NULL){
			traverse = traverse->next;
		}
		
		(*head)->data = traverse->next->data;
		temp = traverse->next;
		traverse->next = NULL;
		free(temp);
		
		deleteHeap(head, 1);
	}
	else{
		*head = NULL;
	}
}
