#include "header.h"

void insertNode(node **head, int num, int index){															//INSERT FRONT
	if(*head == NULL){
		node *temp = malloc(sizeof(node));
		
		temp->data = num;
		temp->next = NULL;
		
		*head = temp;
	}
	else{
		insertNode(&(*head)->next, num, ++index);
		
		//Heapify after inserting
		
		maxHeap(head, index);	//for non roots
		
		//////////////////////Special Case for Root///////////////////////////////
		int i=index+1, parent, right=0, left=0;
	
		node *traverse = *head;
		
		while(traverse->next!=NULL && i<index*2){
			traverse = traverse->next;
			i++;
		}
		parent = (*head)->data;
		
		if(i>=index*2){
			left =  traverse->data;
		}
		if(traverse->next!=NULL){
			right = traverse->next->data;
		}
		
		if(index==2 && parent < left && left != 0){	
			(*head)->next = traverse->next;
			traverse->next = *head;
			(*head) = traverse;
		}
		if(index==2 && parent < right && right != 0){
			node *temp = traverse;
						
			(*head)->next = temp->next->next;
			temp->next->next = temp;
			traverse = traverse->next;
			temp->next = *head;
			*head = traverse;
		}
		////////////////////////////////////////////////////////////////////////////
		
	}
}
