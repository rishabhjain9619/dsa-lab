#include<stdio.h>
#include<stdlib.h>
#include "SeqList.h"

int main()
{	
	SeqList sl1 = newList();
	SeqList sl2 = newList();
	SeqList sl;
	Element a,b,c,d, e;
	a = newElement();
	b = newElement();
	c = newElement();
	d = newElement();
	a->key = 3;
	b->key = 5;
	c-> key = 134;
	d-> key = 786;
	sl2 = insertInOrder(sl2, b);	
	sl2 = insertInOrder(sl2, a);
	sl2 = insertInOrder(sl2, c);
	sl2 = insertInOrder(sl2, d);
	sl  = merge(sl1, sl2);	
	Element test;
	test = sl->head;
	while(test->next != NULL)
	{
	printf("%d\n",test->key);
	test = test->next;
	}
	printf("%d\n",test->key);
	printf("%d\n", sl->count);
	return 0;
}
