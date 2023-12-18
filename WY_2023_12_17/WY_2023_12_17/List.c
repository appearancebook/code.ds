#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

LTNode* BuyLTNode(x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("BuyLTNode() malloc");
		return NULL;
	}

	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

bool LTEmpty(LTNode* phead)
{
	assert(phead);
	return phead->next == phead;
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
	printf("guard<==>");
	while (cur != phead)
	{
		printf("%d<==>", cur->data);
		cur = cur->next;
	}
	printf("guard\n");
}


void LTPushBack(LTNode* phead, SLDatatype x)
{
	//assert(phead);
	//LTNode* tail = phead->prev;
	//LTNode* newhead = BuyLTNode(x);

	//tail->next = newhead;
	//newhead->prev = tail;
	//newhead->next = phead;
	//phead->prev = newhead;
	LTInsert(phead, x);
}

void LTPushFront(LTNode* phead, SLDatatype x)
{
	//assert(phead);

	//LTNode* newnode = BuyLTNode(x);

	//// 我的写法顺序是从后往前改变指针
	//phead->next->prev = newnode;

	//newnode->next = phead->next;
	//newnode->prev = phead;

	//phead->next = newnode;
	LTInsert(phead->next, x);
}

void LTPopback(LTNode* phead)
{
	//assert(phead);
	//assert(!LTEmpty(phead));

	//LTNode* del = phead->prev;
	//LTNode* newtail = del->prev;

	//newtail->next = phead;
	//phead->prev = newtail;

	//free(del);
	////del = NULL;

	LTErase(phead->prev);
}

void LTPopFront(LTNode* phead)
{
	//assert(phead);
	//assert(!LTEmpty(phead));

	//LTNode* del = phead->next;
	//LTNode* newfirst = del->next;

	//newfirst->prev = phead;
	//phead->next = newfirst;


	//free(del);
	////del = NULL;
	LTErase(phead->next);
}

LTNode* LTFind(LTNode* phead, SLDatatype x)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur!=phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}

// 在pos之前插入
void LTInsert(LTNode* pos, SLDatatype x)
{
	assert(pos);
	
	LTNode* newnode = BuyLTNode(x);
	LTNode* pos_prev = pos->prev;

	pos->prev = newnode;
	
	newnode->next = pos;
	newnode->prev = pos_prev;

	pos_prev->next = newnode;

}

// 删除pos位置的值
void LTErase(LTNode* pos)
{
	assert(pos);
	assert(!LTEmpty(pos));

	LTNode* pos_next = pos->next;
	LTNode* pos_prev = pos->prev;

	pos_next->prev = pos_prev;
	pos_prev->next = pos_next;

	free(pos);
	//pos = NULL;
}

void LTDestroy(LTNode* phead)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* rel = cur;
		cur = cur->next;
		free(rel);
		//del = NULL;
	}

	free(phead);
}