typedef struct element *Element;
typedef struct stack *Stack;
typedef struct stack_ele *Stack_ele;

struct element{
	char *name;
	float empid;
};

struct stack{
	Stack_ele top;
};

struct stack_ele{
	Stack_ele previous;
	int lower;
	int higher;
};

void insertion_sort(Element Ls[], int lo, int hi);
void quicksort(Element Ls[], int lo, int hi, int s);
Element* readfromfile(FILE *fptr, int size);
Stack createStack();
Stack_ele createstack_ele();
void push_ele(Stack S, int low, int high);
Stack_ele pop_ele(Stack S);
double* testRun(Element Ls[],int size);
int estimatecutoff(int min, int max);
void drawgraph(int min, int max);
