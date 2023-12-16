#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

void SLTPrint(SLTNode** pphead)
{
	assert(pphead);// ������ָ��ʱ���·����н����ó������
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

//ͷ��ÿ�ζ�Ҫ�ı�plist
void SLPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);// ������ָ��ʱ���·����н����ó������
	//assert(*pphead);// ������Ϊ��ʱ��Ҳ�ܲ�������
	SLTNode* newnode = BuyLTNode(x);

	newnode->next = *pphead;
	*pphead = newnode;
}

// β��ֻ���ڿ�����ʱҪ�ı�plist
void SLPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);// ������ָ��ʱ���·����н����ó������
	//assert(*pphead);// ������Ϊ�գ�Ҳ�ܲ�������
	SLTNode* newnode = BuyLTNode(x);

	//������
	
	if (*pphead == NULL)
	{
		*pphead = newnode;// �����ٵ�һ���ṹ�壬
	}                     // �ı�ṹ��ָ��plist��ʹ��ָ���һ���ṹ��

	//�ǿ�����
	// �ҵ�����һ����λ��
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

//�ҵ�һ��
void SLPopFront(SLTNode** pphead)
{
	assert(pphead);
	// ������
	assert(*pphead);

	//// һ���ڵ�
	//if (!(*pphead)->next)
	//{
	//	free(*pphead);
	//	*pphead = NULL;
	//}

	//// ��ڵ�
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

// �ҵ����ڶ���
void SLPopBack(SLTNode** pphead)
{
	assert(pphead);
	// ������
	assert(*pphead);

	// һ���ڵ�
	if (!(*pphead)->next)
	{
		free(*pphead);
		*pphead = NULL;
	}

	// ����ڵ�
	// ��β
	else
	{
		SLTNode* tail = *pphead;

		while (tail->next->next)// NULL Ϊ�٣�0��  ������ַΪ�棨��0��
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

// ��pos֮ǰ����
// ��pos֮ǰ�ĵ�һ��λ��
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

// ��pos֮�����
// ֱ����pos�����
void SLInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);

	SLTNode* newnode = BuyLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// ɾ��posλ�õ�ֵ
// �ҵ�pos֮ǰ�ĵ�һ��λ��
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

// ɾ��posλ�ú����ֵ
// ֱ��ɾ
void SLEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);

	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
}

// ��������
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