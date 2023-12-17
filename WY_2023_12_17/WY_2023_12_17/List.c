#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

LTNode* BuyLTNode(x)
{
	LTNode* 
}

void LTPushBack(LTNode* phead, SLDatatype x)
{
	assert(phead);
	LTNode* tail = phead->prev;
	LTNode* newhead = BuyLTNode(x);

	tail->next = newhead;
	newhead->prev = tail;
	newhead->next = phead;
	phead->prev = newhead;
}