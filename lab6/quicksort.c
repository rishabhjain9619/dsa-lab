#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
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
	int sz = hi-lo+1;
	int low = lo;
	int high = hi;
	int p;
	if(s >= sz)
		{insertion_sort(Ls, lo, hi);
		return;}
	Element temp;
	int r = lo + rand() % sz;
	float key = Ls[r]->empid;
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
		
	quicksort(Ls, low, p-1, s);
	quicksort(Ls, p+1, high, s);
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
















