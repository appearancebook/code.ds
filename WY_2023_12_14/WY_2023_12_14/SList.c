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

//ͷ��ÿ�ζ�Ҫ�ı�plist
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyLTNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
} 

// β��ֻ���ڿ�����ʱҪ�ı�plist
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyLTNode(x);

	//������
	//�ǿ�����
	if (*pphead == NULL)
	{
		*pphead = newnode;// �����ٵ�һ���ṹ�壬
	}                     // �ı�ṹ��ָ��plist��ʹ��ָ���һ���ṹ��

	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;// �������һ���ṹ�壨������������Ҫָ���¿��ٵĿռ�
		                     // �ı����һ���ṹ���е�ָ��ָ��Ŀռ�
	}
   
}