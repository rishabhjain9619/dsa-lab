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
	quicksort(ele_arr, 0, 1999,  10);
	for(int i =0; i<2000; i++)
		printf("%f \n", ele_arr[i]->empid);
}
