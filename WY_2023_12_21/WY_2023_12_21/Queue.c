#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);

	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
	
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode==NULL)
	{
		perror("QueuePush malloc");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->phead == NULL)
	{
		assert(pq->ptail == NULL);
		pq->phead = newnode;
		pq->ptail = newnode;
		//pq->size++;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	QNode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;
	pq->size--;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->phead->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->ptail->data;
}

int  QueueSize(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->size;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	//return (pq->phead == NULL
	//	&& pq->ptail == NULL);

	return pq->size == 0;
}