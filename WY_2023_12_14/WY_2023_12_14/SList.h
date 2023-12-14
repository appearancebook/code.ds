#pragma once
 
#include <stdio.h>
#include <stdlib.h>

typedef int SLTDataType;

typedef struct SListTNode
{
	SLTDataType data;
	struct SListTNode* next;

}SLTNode;

void SLTPrint(SLTNode** phead);

void SLTPushFront(SLTNode** pphead, SLTDataType x);

void SLTPushBack(SLTNode** pphead, SLTDataType x);