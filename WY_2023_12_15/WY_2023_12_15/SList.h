#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListTNode
{
	SLTDataType data;
	struct SListTNode* next;

}SLTNode;

void SLTPrint(SLTNode** phead);

void SLPushFront(SLTNode** pphead, SLTDataType x);

void SLPushBack(SLTNode** pphead, SLTDataType x);

void SLPopFront(SLTNode** pphead);

void SLPopBack(SLTNode** pphead);

SLTNode* SLFind(SLTNode** pphead, SLTDataType x);

void SLInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

void SLInsertAfter(SLTNode* pos, SLTDataType x);

void SLErase(SLTNode** pphead, SLTNode* pos);

void SLEraseAfter(SLTNode* pos);

void SLDestroy(SLTNode** pphead);