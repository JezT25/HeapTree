#include "header.h"

int numScan(int min, int max){
	char input[10];
	int num=1;
	
	do{
		if(num<min || num>max){
			printf("\t\tInvalid input, enter again: ");
		}	
		else{
			printf("\t\tEnter Number: ");
		}
		
		gets(input);
		
		num = atoi(input); //rand() % 1000;
		
		if(num==0){
			num = max+1;
		}
	}while(num<min || num>max);
	
	return num;
}
