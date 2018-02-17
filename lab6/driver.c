#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "quicksort.h"

void main(){
	FILE *fptr = fopen("data.txt","r");
	if(fptr == NULL){
		printf("this file isn't opening");
		return;
		}
	Element* ele_arr = readfromfile(fptr, 2000);
	
	Stack* a = createStack();
	push_ele(*a, 5, 6);
	Stack_ele temp= pop_ele(*a);
	printf("%d %d\n",temp->lower, temp->higher);
	/*quicksort(ele_arr, 0, 1999,  10);
	for(int i =0; i<2000; i++)
		printf("%f \n", ele_arr[i]->empid);*/
}

Stack_ele pop_ele(Stack S){
	Stack_ele temp = S.top;
	if(S.top != NULL)
		S.top = S.top->previous;
	return temp;
};

void push_ele(Stack S, int low, int high){
	printf("this is working");
	Stack_ele temp = (Stack_ele) malloc(sizeof(struct stack_ele));
	temp->lower = low;
	temp->higher = high;
	temp->previous = S.top;
	S.top = temp;
	return;
};
