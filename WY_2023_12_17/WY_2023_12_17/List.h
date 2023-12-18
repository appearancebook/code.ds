#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int SLDatatype;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	SLDatatype data;
}LTNode;

LTNode* LTInit();

bool LTEmpty(LTNode* phead);

void LTPrint(LTNode* phead);

void LTPushBack(LTNode* phead, SLDatatype x);

void LTPushFront(LTNode* phead, SLDatatype x);

void LTPopback(LTNode* phead);

void LTPopFront(LTNode* phead);

LTNode* LTFind(LTNode* phead,SLDatatype x);

void LTInsert(LTNode* pos, SLDatatype x);

void LTErase(LTNode* pos);

void LTDestroy(LTNode* phead);