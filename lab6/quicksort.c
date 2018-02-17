#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include "quicksort.h"

Element* readfromfile(FILE *fptr, int size){
	char arr[10];
	float rand = 0;
	int i =0;
	Element* ele_arr = (Element*) malloc(sizeof(Element)*size);
	Element e;
	while(fscanf(fptr, "%s %f\n", arr, &rand)!=EOF){
	e = (Element) malloc(sizeof(struct element));
	e->name = (char*) malloc(sizeof(char)*10);
	strcpy(e->name, arr); 
	e->empid = rand;
	ele_arr[i] = e;
	i++;
	};
	return ele_arr;
};

void quicksort(Element Ls[], int lo, int hi,  int s){
	int sz, low, high, p, r;
	float key;
	Stack st = createStack();
	push_ele(st, lo, hi);
	Stack_ele temp2;
	
	while(st->top != NULL){
		temp2 = pop_ele(st);
		lo = temp2->lower;
		hi = temp2->higher; 
		free(temp2);
		sz = hi-lo+1;
		low = lo;
		high = hi;
		//if(s >= sz)
		//	{insertion_sort(Ls, lo, hi);
		//	printf("%d ", sz);
		//	continue;}
		Element temp;
		r = lo + rand() % sz;
		key = Ls[r]->empid;
		temp = Ls[lo];
		Ls[lo] = Ls[r];
		Ls[r] = temp;
		lo++;
	
		while(lo < hi){
			if(Ls[lo]->empid <= key)
				lo++;
			else if(Ls[hi]->empid > key)
				hi--;
			else {
				temp = Ls[lo];
				Ls[lo] = Ls[hi];
				Ls[hi] = temp;
				lo++;
				hi--;
				}
			}
	
		if(Ls[hi]->empid <= key){
			temp = Ls[hi];
			Ls[hi] = Ls[low];
			Ls[low] = temp;
			p = hi;
			}
		else{
			temp = Ls[hi-1];
			Ls[hi-1] = Ls[low];
			Ls[low] = temp;
			p = hi-1;
			};
		if(p-low >1)
			push_ele(st, low, p-1);
		if(high-p>1)
			push_ele(st, p+1, high); 		
	
	};
	//quicksort(Ls, low, p-1, s);
	//quicksort(Ls, p+1, high, s);
};

void insertion_sort(Element Ls[], int lo, int hi){
	Element temp;
	int siz = hi-lo+1;
	int i,j,k;
	int sz = hi-lo+1;
	for(i=lo+1; i<lo+siz; i++){
		for(j =lo; j< i; j++){
			if(Ls[j]->empid > Ls[i]->empid){
				temp = Ls[i];
				for(k=i; k>j; k--)
					Ls[k] = Ls[k-1];
				Ls[j] = temp;
				}
			}
		}
};


Stack createStack(){
	return (Stack) malloc(sizeof(struct stack));
};

Stack_ele createstack_ele(){
	return (Stack_ele) malloc(sizeof(struct stack_ele));
};


Stack_ele pop_ele(Stack S){
	Stack_ele temp = S->top;
	if(S->top != NULL)
		S->top = S->top->previous;
	return temp;
};

void push_ele(Stack S, int low, int high){
	Stack_ele temp = (Stack_ele) malloc(sizeof(struct stack_ele));
	temp->lower = low;
	temp->higher = high;
	temp->previous = S->top;
	S->top = temp;
	return;
};

double* testRun(Element Ls[],int size){
	clock_t start, end;
	double *cpu_time_used;
	cpu_time_used = (double*) malloc(sizeof(double)*2);
	start = clock();
	quicksort(Ls, 0, size-1, 1);
	end = clock();
	cpu_time_used[0] = ((double) (end - start)) / CLOCKS_PER_SEC;
	start = clock();
	insertion_sort(Ls, size, 2*size-1);
	end = clock();
	cpu_time_used[1] = ((double) (end - start)) / CLOCKS_PER_SEC;
	return cpu_time_used;
};

int estimatecutoff(int min, int max){
	double *arr;
	double temp, temp1, temp2;
	FILE *fptr = fopen("data.txt","r");
	if(fptr == NULL){
		printf("this file isn't opening");
		return -1;
		}
	arr = (double*) malloc(sizeof(double)*2);
	Element* ele_arr; 
	fptr = fopen("data.txt","r");
	ele_arr = readfromfile(fptr, 2000);
	arr = testRun(ele_arr, min);
	temp1 = arr[1]-arr[0];
	fptr = fopen("data.txt","r");
	ele_arr = readfromfile(fptr, 2000);
	arr = testRun(ele_arr, max);
	temp2 = arr[1]-arr[0];
	int mid;
	do{
		mid = (min+max)/2;
		fptr = fopen("data.txt","r");
		ele_arr = readfromfile(fptr, 2000);
		arr = testRun(ele_arr, mid);
		temp = arr[1]-arr[0];
		if(temp<0)
			max = mid;
		else
			min = mid;
		printf("%lf %d t %d t %d t\n", temp, mid, min, max);
	}while(fabs(temp) > 0.000001);
	return mid;
};

void drawgraph(int min, int max){
	double *arr, *graph;
	double temp;
	FILE *fptr = fopen("data.txt","r");
	if(fptr == NULL){
		printf("this file isn't opening");
		return ;
		}
	arr = (double*) malloc(sizeof(double)*2);
	graph = (double*) malloc(sizeof(double)*max-min);
	Element* ele_arr; 
	FILE *fptr2 = fopen("time_profiling.csv","w");	
	for(int i = min; i< max; i++){
		fptr = fopen("data.txt","r");
		ele_arr = readfromfile(fptr, 2000);
		arr = testRun(ele_arr, i);
		temp = arr[1]-arr[0];
		graph[i-min] = temp;
		printf("%lf", temp);
		fprintf(fptr2, "%lf\n", arr[1]);
	};		

	return ;
};












