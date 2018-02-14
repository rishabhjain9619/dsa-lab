#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "merge.h"

void main(){
	FILE *fptr = fopen("1024.txt","r");
	Element* ele_arr = readfromfile(fptr, 1024);
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	itermerge(ele_arr, 1, 1024);
	end = clock();
	cpu_time_used = (double) (end - start)/CLOCKS_PER_SEC;
	printf("the time used in sec is %lf\n", cpu_time_used);
	for(int i=0; i<1024;i++)
		printf("%s has cgpa %f\n",ele_arr[i]->name, ele_arr[i]->cgpa);
	//printf("the memory used is %ld\n",globalcount);
	//printf("the maximum memory used is %ld\n",maxglobal);
}
