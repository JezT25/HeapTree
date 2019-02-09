#include "header.h"

void searchNode(node *head, int num, int *success){
	if(head != NULL){
		do{
			if(num == head->data){
				*success = 1;
				return;
			}		
			head = head->next;
		}while(head!=NULL);
	}	
	
	*success = 0;
}
