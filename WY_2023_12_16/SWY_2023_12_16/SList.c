#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void SLTPrint(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* cur = *pphead;

	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLTNode* BuyLTNode(SLDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("SLPushFront malloc");
		return NULL;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SLPushFront(SLTNode** pphead, SLDataType x)
{
	assert(pphead);
	SLTNode* newnode = BuyLTNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

void SLPushBack(SLTNode** pphead, SLDataType x)
{
	assert(pphead);
	SLTNode* newnode = BuyLTNode(x);
	// 空链表
	if (*pphead == NULL)
		*pphead = newnode;
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next)
		{
			tail=tail->next;
		}
		tail->next = BuyLTNode(x);
	}
}

void SLPopFront(SLTNode** pphead)
{
	assert(pphead);
	// 空链表
	assert(*pphead);
	
	SLTNode* del = *pphead;
	*pphead = (*pphead)->next;
	free(del);
	del = NULL;
}

void SLPopBack(SLTNode** PPhead)
{
	assert(PPhead);
	// 空链表
	assert(*PPhead);

	// 单节点
	if ((*PPhead)->next == NULL)
	{
		free(*PPhead);
		*PPhead = NULL;
	}

	// 多节点
	else
	{
		SLTNode* tail = *PPhead;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

SLTNode* SLFind(SLTNode** pphead, SLDataType x)
{
	assert(pphead);
	
	//// 空链表
	//if (*pphead == NULL)
	//	return NULL;


	// 非空链表

	SLTNode* cur = *pphead;


	while (cur)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}

	//// 尾节点
	//if (cur->data == x)
	//	return cur;

	return NULL;
}

void SLInsert(SLTNode** pphead, SLTNode* pos, SLDataType x)
{
	assert(pphead);
	// 空链表
	assert(pos);

	// 单节点
	if (*pphead == pos)
	{
		SLPushFront(pphead, x);
	}

	// 多节点
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SLTNode* newnode = BuyLTNode(x);
		newnode->next = pos;
		prev->next = newnode;
	}

}

void SLInsertAfter(SLTNode* pos, SLDataType x)
{
	// 空链表
	assert(pos);

	// 非空链表
	SLTNode* newnode = BuyLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	// 空链表
	assert(*pphead);
	assert(pos);
	// 单节点
	if (*pphead == pos)
	{
		SLPopFront(pphead);
	}

	// 多节点
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SLEraseAfter(SLTNode* pos)
{
	assert(pos);
	// 末数据
	assert(pos->next);

	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
	
}

void SLDestroy(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);
	SLTNode* p = *pphead;
	while (p)
	{
		SLTNode* gp = p;
		p = p->next;
		free(gp);
	}
	*pphead = NULL;
}
