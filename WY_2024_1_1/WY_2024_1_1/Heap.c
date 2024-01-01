#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void HeapInit(Hp* php)
{
	assert(php);
	php->a = NULL;
	php->Size = 0;
	php->Capacity = 0;
}

void HeapDestroy(Hp* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->Size = 0;
	php->Capacity = 0;
}

void Swap(HeapDataType* p1, HeapDataType* p2)
{
	HeapDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HeapDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);

			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDown(HeapDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		// 选出左右孩子中小/大的那个
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//O(logN)
void HeapPush(Hp* php, HeapDataType x)
{
	assert(php);
	if (php->Size == php->Capacity)
	{
		int NewCapacity = php->Capacity == 0 ? 9 : php->Capacity * 2;
		HeapDataType* tmp = (HeapDataType*)realloc(php->a, sizeof(HeapDataType) * NewCapacity);
		if (tmp == NULL)
		{
			perror("HeapPush realloc");
			return;
		}
		php->a = tmp;
		php->Capacity = NewCapacity;
	}
	php->a[php->Size] = x;
	php->Size++;

	//向上调整
	AdjustUp(php->a, php->Size - 1);
}

//O(logN)
void HeapPop(Hp* php)
{
	assert(php);
	assert(!HeapEmpty(php));

	Swap(&php->a[0], &php->a[php->Size - 1]);

	php->Size--;

	//向下调整
	AdjustDown(php->a, php->Size, 0);
}

bool HeapEmpty(Hp* php)
{
	assert(php);

	return php->Size == 0;
}

HeapDataType HeapTop(Hp* php)
{
	assert(php);
	assert(!HeapEmpty(php));

	return php->a[0];
}

int HeapSize(Hp* php)
{
	assert(php);

	return php->Size;
}
