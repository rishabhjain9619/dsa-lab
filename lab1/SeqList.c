#include "SeqList.h"
#include<stdlib.h>
#include<stdio.h>

SeqList newList()
{
	return (SeqList) malloc (sizeof(SeqList));
};

Element newElement()
{
	return (Element) malloc (sizeof(Element));
};

SeqList insertInOrder(SeqList sl, Element e)
{
	if(sl->tail == NULL)
	{	
		sl->tail = e;
		sl->head = e;
		sl->count = 1;
		return sl;
	}
	
	if(sl->head->key > e->key)
	{
		insertAtFront(sl, e);
		return sl;
	}	
	Element test, test2;
	test = sl->head;
	int value = e->key;
	while( test != NULL && value >= test->key)
	{
		test2 = test	;	
		test  = test->next;
	}	
	e->next    = test;
	test2->next = e;
	if(test == NULL)
		sl->tail = e;
	if(test2 == NULL)
		sl->head = e;
	sl->count++;
	return sl;
};

SeqList insertAtFront(SeqList sl, Element e)
{
	if(sl->tail == NULL)
	{	
		sl->tail = e;
		sl->head = e;
		sl->count = 1;
		return sl;
	}
	e->next = sl->head;
	sl->head = e;
	sl->count++;
	return sl;
};

SeqList insertAtEnd(SeqList sl, Element e)
{
	if(sl->tail == NULL)
	{	
		sl->tail = e;
		sl->head = e;
		sl->count = 1;
		return sl;
	}
	sl->tail->next = e;
	sl->tail       = e;
	sl->count++;
	return sl;
};

SeqList delete(SeqList sl, Element e)
{
	if(sl->tail == NULL)
	{	
		printf("element not found");
		return sl;
	}
	
	Element test, test2;
	test = sl->head;
	if( test->key == e->key && test->next == e->next)
	{
		sl->head = test->next;
		free(test);
		return sl;
	}
	while( test->key != e->key && test->next != e->next)
	{
		test2 = test;		
		test  = test->next;
	}
	test2->next = test->next;
	if(test->next == NULL)
		sl->tail = test2;
	free(test);
	sl->count--;
	return sl;
};

SeqList deleteAtFront(SeqList sl)
{
	Element test = sl->head;	
	sl->head = sl->head->next;
	free(test);
	sl->count--;
	return sl;
};

Element find(SeqList sl, int k)
{
	Element test;
	test = sl->head;	
	while(  test != NULL && test->key != k)
		test = test->next;
	return test;
};















