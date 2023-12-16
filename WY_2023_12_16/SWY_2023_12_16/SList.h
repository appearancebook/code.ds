#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;

}SLTNode;

void SLTPrint(SLTNode** pphead);

void SLPushFront(SLTNode** pphead, SLDataType x);

void SLPushBack(SLTNode** pphead, SLDataType x);

void SLPopFront(SLTNode** pphead);

void SLPopBack(SLTNode** PPhead);

SLTNode* SLFind(SLTNode** pphead, SLDataType x);

void SLInsert(SLTNode** pphead,SLTNode* pos, SLDataType x);

void SLInsertAfter(SLTNode* pos, SLDataType x);

void SLErase(SLTNode** pphead, SLTNode* pos);

void SLEraseAfter(SLTNode* pos);

void SLDestroy(SLTNode** pphead);

