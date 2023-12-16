#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

void SLTPrint(SLTNode** pphead)
{
	assert(pphead);// 当传空指针时，下方进行解引用程序崩溃
	SLTNode* cur = *pphead;
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
void SLPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);// 当传空指针时，下方进行解引用程序崩溃
	//assert(*pphead);// 当数据为空时，也能插入数据
	SLTNode* newnode = BuyLTNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

// 尾插只有在空链表时要改变plist
void SLPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);// 当传空指针时，下方进行解引用程序崩溃
	//assert(*pphead);// 当数据为空，也能插入数据
	SLTNode* newnode = BuyLTNode(x);

	//空链表
	
	if (*pphead == NULL)
	{
		*pphead = newnode;// 链表开辟第一个结构体，
	}                     // 改变结构的指针plist，使其指向第一个结构体

	//非空链表
	// 找倒数第一个的位置
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

//找第一个
void SLPopFront(SLTNode** pphead)
{
	assert(pphead);
	// 空链表
	assert(*pphead);

	//// 一个节点
	//if (!(*pphead)->next)
	//{
	//	free(*pphead);
	//	*pphead = NULL;
	//}

	//// 多节点
	//else
	//{
	//	SLTNode* del = *pphead;
	//	*pphead = (*pphead)->next;
	//	free(del);
	//	del = NULL;
	//}

	SLTNode* del = *pphead;
	*pphead = (*pphead)->next;
	free(del);
	del = NULL;

}

// 找倒数第二个
void SLPopBack(SLTNode** pphead)
{
	assert(pphead);
	// 空链表
	assert(*pphead);

	// 一个节点
	if (!(*pphead)->next)
	{
		free(*pphead);
		*pphead = NULL;
	}

	// 多个节点
	// 找尾
	else
	{
		SLTNode* tail = *pphead;

		while (tail->next->next)// NULL 为假（0）  其他地址为真（非0）
		{
			tail = tail->next;
		}

		free(tail->next);
		tail->next = NULL;

	}
}

SLTNode* SLFind(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* cur = *pphead;
	while (cur)
	{
		if (cur->data == x)
			return cur;

		cur = cur->next;
	}
	return NULL;
}

// 在pos之前插入
// 找pos之前的第一个位置
void SLInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);

	if (*pphead == pos)
	{
		SLPushFront(pphead, x);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		SLTNode* newnode = BuyLTNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}

// 在pos之后插入
// 直接在pos后面插
void SLInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);

	SLTNode* newnode = BuyLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// 删除pos位置的值
// 找到pos之前的第一个位置
void SLErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(pos);

	if (pos == *pphead)
		SLPopFront(pphead);
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}

// 删除pos位置后面的值
// 直接删
void SLEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);

	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
}

// 销毁链表
void SLDestroy(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);

	SLTNode* gp = *pphead;
	while (gp)
	{
		SLTNode* p = gp->next;
		free(gp);
		gp = p;
	}
	*pphead = NULL;
}