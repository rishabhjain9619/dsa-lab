typedef struct element *Element;
typedef struct seqList *SeqList;

struct seqList
{
	int count;
	struct element *head ;
	struct element *tail ;
};

struct element
{
	int key;
	struct element *next ;
};

SeqList newList();
Element newElement();
SeqList insertInOrder(SeqList sl, Element e);
SeqList insertAtFront(SeqList sl, Element e);
SeqList insertAtEnd(SeqList sl, Element e);
SeqList delete(SeqList sl, Element e);
SeqList deleteAtFront(SeqList sl);
Element find(SeqList sl, int k);
SeqList merge(SeqList sl1, SeqList sl2);
