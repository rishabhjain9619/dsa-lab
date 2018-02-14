#include "SeqList.h"
#include<stdio.h>
#include<stdlib.h>

SeqList merge(SeqList sl1, SeqList sl2)
{
	int q;
	SeqList sl = newList();
	Element test1, test2;
	test1 = sl1->head;
	test2 = sl2->head;
	sl->count = sl1->count + sl2->count;
	if(sl1->head <sl2->head)
	{
	sl->head = sl1->head;
	}
	while(test1 != NULL && test2 != NULL)
	{
	if(test1->key < test2->key)
	{
		insertAtEnd(sl, test1);
		test1 = test1->next;
	}	
	else
	{
		insertAtEnd(sl, test2);
		test2 = test2->next;
	}	
	}
	if(test1 == NULL)
	{
		while(test2 != NULL)
		{
			insertAtEnd(sl, test2);
			test2 = test2->next;
		}
		
	}
	if(test2 == NULL)
	{
		while(test1 != NULL)
		{
			insertAtEnd(sl, test1);
			test1 = test1->next;
		}
		
	}
	return sl;
};
