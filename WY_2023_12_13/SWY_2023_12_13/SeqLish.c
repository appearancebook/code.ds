#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void SLInit(SL* psl)
{
	assert(psl);
	psl->a = (SLDatatype*)malloc(sizeof(SLDatatype) * 4);
	if (psl->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	psl->capacity = 4;
	psl->size = 0;
}

void SLDestroy(SL* psl)
{
	assert(psl);

	free(psl->a);
	psl->a = NULL;
	psl->capacity = 0;
	psl->size = 0;
}

void SLCheckCapacity(SL* psl)
{
	assert(psl);

	if (psl->size == psl->capacity)
	{
		SLDatatype* tmp = (SLDatatype*)realloc(psl->a, sizeof(SLDatatype) * psl->capacity * 2);
		if (tmp == NULL)
		{
			perror("relloc fail");
			return;
		}

		psl->a = tmp;
		psl->capacity *= 2;
	}
}

void SLPrint(SL* psl)
{
	assert(psl);

	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}

void SLPushBack(SL* psl, SLDatatype x)
{
	//检查容量
	SLCheckCapacity(psl);
	//psl->a[psl->size] = x;
	//psl->size++;

	//psl->a[psl->size++] = x;
	SLInsert(psl, psl->size, x);

}

void SLPushFront(SL* psl, SLDatatype x)
{
	assert(psl);

	SLCheckCapacity(psl);

	//挪动数据
	//int end = psl->size - 1;
	//while (end >= 0)
	//{
	//	psl->a[end + 1] = psl->a[end];
	//	--end;
	//}

	//psl->a[0] = x;
	//psl->size++;
	SLInsert(psl, 0, x);
}

void SLPopBack(SL* psl)
{
	assert(psl);

	//assert(psl->size > 0);
	//psl->size--;

	SLErase(psl, psl->size - 1);

}


void SLPopFront(SL* psl)
{
	assert(psl);

	//assert(psl->size > 0);
	//int start = 0;
	//while (start < psl->size - 1)
	//{
	//	psl->a[start] = psl->a[start + 1];
	//	start++;
	//}
	//psl->size--;

	SLErase(psl, 0);

}

void SLInsert(SL* psl, int pos, SLDatatype x)
{
	assert(psl);

	assert(pos >= 0 && pos <= psl->size);
	SLCheckCapacity(psl);
	int end = psl->size - 1;
	while (end >= pos)
	{
		psl->a[end + 1] = psl->a[end];
		end--;
	}
	psl->a[pos] = x;
	psl->size++;
}

void SLErase(SL* psl, int pos)
{
	assert(psl);

	assert(pos >= 0 && pos < psl->size);
	//assert(psl->size > 0);

	int start = pos + 1;
	while (start < psl->size)
	{
		psl->a[start - 1] = psl->a[start];
		start++;
	}

	psl->size--; 
}

int SLFind(SL* psl, SLDatatype x)
{
	assert(psl);

	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SLModify(SL* psl, int pos, SLDatatype x)
{
	assert(pos >= 0 && pos < psl->size);
    
	psl->a[pos] = x;
}