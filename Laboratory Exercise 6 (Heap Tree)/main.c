#include "header.h"

int main(int argc, char *argv[]) {
	int count=0, num=0, choice=1, x, success;
	char ch;
	
	node *head = NULL;	//singly linked list version
	tree *root = NULL;	//tree version
	
	for(;;){	
		printf("\n\t\tInputs [%d to %d]. 0 not allowed.\n", MIN, MAX);	
		
		if(choice==1){printf("\n\n\t\t\t[X] Insert Node.");}else{printf("\n\n\t\t\t[ ] Insert Node.");}
		if(choice==2){printf("\n\t\t\t[X] Delete Node.\n");}else{printf("\n\t\t\t[ ] Delete Node.\n");}
		if(choice==3){printf("\n\t\t\t[X] Exit.\n");}else{printf("\n\t\t\t[ ] Exit.\n");}
		
		//Print Tree
		if(head != NULL){
			printf("\n\n\t\t\tMax Heap Tree Diagram\n");
			x = 32-count;															//centers the tree always
			convert(&root, head, 0, count);			//convert singly to tree								
			displayTree(root, &x, 13);				//display tree
			gotoxy(48,15+(count/2));
		}
		
		ch = getch();
		
		if(tolower(ch)=='w' || ch==72){
			if(choice>1) choice--;
			else choice = 3;
		}
		else if(tolower(ch)=='s' || ch==80){
			if(choice<3) choice++;
			else choice = 1;
		}
		
		////////////////////////FUNCTION CALLS///////////////////////////
		
		else if(ch==13 || ch==32){
			
			//Insert Node
			if(choice==1){
				printf("\n\n\t\tWhat number to insert?\n");
				num = numScan(MIN,MAX);

				searchNode(head, num, &success);
			
				if(success==1){
					printf("\n\t\tNumber %d already exsists!\n", num);
				}
				else{
					insertNode(&head, num, 1);
					printf("\n\t\tNumber %d successfully inserted!\n", num);
					count++;
				}
			}
			
			//Delete Node
			else if(choice==2){
				if(head == NULL){
					printf("\n\n\n\t\tCannot delete with no tree! Create tree first!\n");
				}
				else{
					deleteNode(&head);
					printf("\n\n\t\tMax number successfully deleted!\n");
					count--;
				}
			}	
				
			//Exit
			else if(choice==3){
				return 0;
			}
			
			printf("\n\n\t\tPress any key to continue.");
			getch();
			
			//choice=1;
		}
			
		system("cls");
	}
}
