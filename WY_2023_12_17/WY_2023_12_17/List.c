#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

LTNode* BuyLTNode(x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("BuyLTNode malloc");
		return NULL;
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

LTNode* LTInit()
{
	LTNode* newnode = BuyLTNode(-1);
	newnode->prev = newnode;
	newnode->next = newnode;
	
	return newnode;
}

void LTPrint(LTNode* phead)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("%d\n", phead->data);
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