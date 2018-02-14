typedef struct element *Element;

struct element{
	char name[10];
	float cgpa;
};

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);
Element* readfromfile(FILE *fptr, int size);
void mergeSort(Element Ls[], int start, int end);
void itermerge(Element Ls[], int start, int end);
