#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 静态数据表
// 缺点
// 给小了不够用，给多了浪费
// 没什么用，实践不推荐使用
#define N 10
typedef int SLDatatype;

//struct SeqList
//{
//	SLDatatype a[N];
//	int size;
//};

//动态数据表
typedef struct SeqList
{
	SLDatatype* a;
	int size;      // 存储的有效数据的个数
	int capacity;  // 容量
}SL;

void SLInit(SL* psl);

void SLDestroy(SL* psl);

void SLPrint(SL* psl);

void SLPushBack(SL* psl, SLDatatype x);

void SLPushFront(SL* psl, SLDatatype x);

void SLPopBack(SL* psl);

void SLPopFront(SL* psl);

void SLInsert(SL* psl,int pos,SLDatatype x);

void SLErase(SL* psl, int pos);

//找到返回下标，没有找到返回-1
int SLFind(SL* psl, SLDatatype x);

void SLModify(SL* psl, int pos, SLDatatype x);