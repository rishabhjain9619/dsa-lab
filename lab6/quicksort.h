typedef struct element *Element;
typedef struct stack Stack;
typedef struct stack_ele *Stack_ele;

struct element{
	char *name;
	float empid;
};

struct stack{
	Stack_ele top;
}

struct stack_ele{
	Stack_ele previous;
	int lower;
	int higher;
};

void insertion_sort(Element Ls[], int lo, int hi);
void quicksort(Element Ls[], int lo, int hi, int s);
Element* readfromfile(FILE *fptr, int size);

Stack* createStack(){
	return (Stack*) malloc(sizeof(Stack));
};

Stack_ele createstack_ele(){
	return (Stack_ele) malloc(sizeof(struct stack_ele));
};

void push_ele(Stack S, int low, int high){
	Stack_ele temp = (Stack_ele) malloc(sizeof(struct stack_ele));
	temp->lower = low;
	temp->higher = high;
	temp->previous = S->top;
	S->top = temp;
};

Stack_ele pop_ele(Stack S){
	Stack_ele temp = S->top;
	S->top = S->top->previous;
	return temp;
};
