#pragma once

#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int HeapDataType;
typedef struct Heao
{
	HeapDataType* a;
	int Size;
	int Capacity;
}Hp;

void HeapInit(Hp* php);

void HeapDestroy(Hp* php);

void HeapPush(Hp* php, HeapDataType x);

void HeapPop(Hp* php);

HeapDataType HeapTop(Hp* php);

int HeapSize(Hp* php);

bool HeapEmpty(Hp* php);

void AdjustUp(HeapDataType* a, int child);

void Swap(HeapDataType* p1, HeapDataType* p2);

void AdjustDown(HeapDataType* a, int n, int parent);
