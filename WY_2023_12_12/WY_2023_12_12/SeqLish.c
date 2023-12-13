#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void SLInit(SL* psl)
{
	psl->a = (SLDatatype*)malloc(sizeof(SLDatatype) * 4);
	if (psl->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	psl->capacity = 4;
	psl->size = 0;
}

void SLDestroy(SL* ps1)
{
	free(ps1->a);
	ps1->a = NULL;
	ps1->capacity = 0;
	ps1->size = 0;
}

void SLCheckCapacity(SL* psl)
{
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
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
}

void SLPushback(SL* psl, SLDatatype x)
{
	//¼ì²éÈÝÁ¿
	SLCheckCapacity(psl);
	//psl->a[psl->size] = x;
	//psl->size++;

	psl->a[psl->size++] = x;

}

void SLPushFront(SL* psl, SLDatatype x);

void SLPopback(SL* psl);

void SLPopFront(SL* psl);