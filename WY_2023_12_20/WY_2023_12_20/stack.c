#define _CRT_SECURE_NO_WARNINGS 1

#include "stack.h"

void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;
}

void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;
}

void STPush(ST* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 3 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity*sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("STPush realloc");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}

	pst->a[pst->top] = x;
	pst->top++;
}

void STPop(ST* pst)
{
	assert(pst);
	assert(!STEmpty(pst));

	pst->top--;
}

STDataType STTop(ST* pst)
{
	assert(pst);
	assert(!STEmpty(pst));

	return pst->a[pst->top - 1];
}

bool STEmpty(ST* pst)
{
	assert(pst);
	
	return pst->top == 0;
}

int STSize(ST* pst)
{
	assert(pst);

	return pst->top;
}