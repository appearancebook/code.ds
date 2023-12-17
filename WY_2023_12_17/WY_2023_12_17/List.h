#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDatatype;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	SLDatatype data;
}LTNode;

LTNode* LTInit();

void LTPrint(LTNode* phead);

void LTPushBack(LTNode* phead, SLDatatype x);

void LTPopback(LTNode* phead, SLDatatype x);