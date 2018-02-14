typedef struct element *Element;
long globalcount = 0;
long maxglobal = 0;
struct element{
	char name[10];
	float cgpa;
};

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);
Element* readfromfile(FILE *fptr, int size);
void mergeSort(Element Ls[], int start, int end);
void itermerge(Element Ls[], int start, int end);
void* myalloc(int size, long count);
void myfree(void* p, int size, long count);

Element* readfromfile(FILE *fptr, int size){
	char arr[10];
	float rand = 0;
	int i =0;
	Element* ele_arr = (Element*) myalloc(sizeof(Element),size);
	Element e;	
	while(fscanf(fptr, "%[^,], %f\n", arr, &rand)!=EOF){
	e = (Element) myalloc(sizeof(struct element),1);
	strcpy(e->name, arr); 
	e->cgpa = rand;
	ele_arr[i] = e;
	i++;
	};
	return ele_arr;
};

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]){
	int i=0, j=0, k=0;
	while(j < sz1 && k < sz2){
		if(Ls1[j]->cgpa <= Ls2[k]->cgpa){
			Ls[i] = Ls1[j];
			j++;
			i++;}
		else{
			Ls[i] = Ls2[k];
			k++;
			i++;}
			             };
	if(j == sz1){
			while(k < sz2){
			Ls[i] = Ls2[k];
			k++;
			i++;
			}
		}
	if(k == sz2){
		while(j < sz1){
		Ls[i] = Ls1[j];
		j++;
		i++;
		}
	}
	return;
};

void mergeSort(Element Ls[], int start, int end){
	int k;
	if(end-start == 1){
		if(Ls[end-1]->cgpa < Ls[start-1]->cgpa){
			Element e = Ls[start-1];
			Ls[start-1] = Ls[end-1];
			Ls[end - 1] = e;
		}
		return;
	}
	mergeSort(Ls,start, (start+end-1)/2);
	mergeSort(Ls,(start+end+1)/2, end);
	Element *Ls1 = (Element*) myalloc(sizeof(Element),((end-start+1)/2));
	Element *Ls2 = (Element*) myalloc(sizeof(Element),((end-start+1)/2));
	memcpy(Ls1, Ls+start-1, sizeof(Element)*((end-start+1)/2));
	memcpy(Ls2, Ls+(start+end-1)/2, sizeof(Element)*((end-start+1)/2));
	merge(Ls1, (end-start+1)/2, Ls2, (end-start+1)/2, Ls+start-1);
	myfree(Ls1,sizeof(Element),((end-start+1)/2));
	myfree(Ls2,sizeof(Element),((end-start+1)/2));
};

void itermerge(Element Ls[], int start, int end){
	int t = (end-start+1);
	int k;
	Element *Ls1, *Ls2;
	for(int i=1; i< t; i*=2){
		for(int j=0; j < t/(2*i); j++){
			Ls1 = (Element*) myalloc(sizeof(Element),i);
			Ls2 = (Element*) myalloc(sizeof(Element),i);
			memcpy(Ls1, Ls+(2*i*j), sizeof(Element)*i);
			memcpy(Ls2, Ls+i+(2*i*j), sizeof(Element)*i);
			merge(Ls1 , i, Ls2, i, Ls+(2*i*j));
			myfree(Ls1,sizeof(Element),i );
			myfree(Ls2, sizeof(Element),i);
		}
	}
};

void* myalloc(int size, long count){
	globalcount += size * count;
	maxglobal = (maxglobal > globalcount ) ? maxglobal : globalcount;
	void* temp = malloc(size * count);
	return temp;
};

void myfree(void* p, int size, long count){
	globalcount -= size * count;
	free(p);
};


















