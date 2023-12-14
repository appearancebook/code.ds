#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

void SLTPrint(SLTNode** phead)
{
	SLTNode* cur = *phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SLTNode* BuyLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc SLTPushFront");
		return NULL;
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

//头插每次都要改变plist
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyLTNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
} 

// 尾插只有在空链表时要改变plist
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyLTNode(x);

	//空链表
	//非空链表
	if (*pphead == NULL)
	{
		*pphead = newnode;// 链表开辟第一个结构体，
	}                     // 改变结构的指针plist，使其指向第一个结构体

	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;// 链表最后一个结构体（不包括空链表）要指向新开辟的空间
		                     // 改变最后一个结构体中的指针指向的空间
	}
   
}