#include "header.h"

void maxHeap(node **head, int index){
	if((*head)->next!=NULL){
		int i=index, parent, left=0, right=0;
	
		parent = (*head)->next->data;
		
		node *traverse = *head;
		
		while(traverse->next!=NULL && i<index*2){
			traverse = traverse->next;
			i++;
		}
		if(i==index*2 && traverse->next!=NULL){
			left = traverse->next->data;
		}
		if(traverse->next!=NULL){
			if(traverse->next->next != NULL){
				right = traverse->next->next->data;
			}
		}
		
		if(parent < left && left != 0){
			node *temp = (*head)->next;
				
			(*head)->next = traverse->next;
			traverse->next = temp;
			temp = temp->next;
			traverse->next->next =(*head)->next->next;
			(*head)->next->next = temp;
		}
		if(parent < right && right != 0){
			traverse = traverse->next;
			node *temp = (*head)->next;
				
			(*head)->next = traverse->next;
			traverse->next = temp;
			temp = temp->next;
			traverse->next->next =(*head)->next->next;
			(*head)->next->next = temp;
		}
	}
}

void deleteHeap(node **head, int index){
	if((*head)->next!=NULL){
		int i=index, parent, left=0, right=0, largest;
	
		parent = (*head)->data;
		
		node *traverse = *head;
		
		while(traverse->next!=NULL && i<index*2){
			traverse = traverse->next;
			i++;
		}
		if(i==index*2){
			left = traverse->data;
		}
		if(traverse->next!=NULL){
			right = traverse->next->data;
		}
		
		if((left!=0 && left>right) || (right==0 && left != 0)){
			largest = left;
		}
		else if((left==0 && right != 0) || (right!=0 && right>left)){
			largest = right;
		}
		else{
			largest = parent - 1;
		}

		if(parent < largest){
			int temp;
			
			temp = parent;
			
			if(largest == left){
				(*head)->data = traverse->data;
				traverse->data = temp;
				deleteHeap(&traverse, index*2);
			}
			else if(largest == right){
				(*head)->data = traverse->next->data;
				traverse->next->data = temp;
				deleteHeap(&traverse->next, (index*2)+1);
			}
		}
	}
}
