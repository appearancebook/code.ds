#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

// 头插
void testlist1()
{
	SLTNode* plist = NULL;
	SLPushFront(&plist, 9);
	SLPushFront(&plist, 18);
	SLPushFront(&plist, 27);
	SLTPrint(&plist);
}

// 尾插
void testlist2()
{
	SLTNode* plist = NULL;
	//SLPushFront(&plist, 9);
	//SLPushFront(&plist, 18);
	//SLPushFront(&plist, 27);
	//SLTPrint(&plist);

	SLPushBack(&plist, 36);
	SLTPrint(&plist);
}

// 头删
void testlist3()
{
	SLTNode* plist = NULL;
	//SLPushFront(&plist, 9);
	//SLPushFront(&plist, 18);
	//SLPushFront(&plist, 27);
	SLTPrint(&plist);

	//SLPushBack(&plist, 36);
	SLTPrint(&plist);

	SLPopFront(&plist);
	SLTPrint(&plist);
}

// 尾删
void testlist4()
{
	SLTNode* plist = NULL;
	SLPushFront(&plist, 9);
	SLPushFront(&plist, 18);
	SLPushFront(&plist, 27);
	SLTPrint(&plist);

	SLPushBack(&plist, 36);
	SLTPrint(&plist);

	SLPopBack(&plist);
	SLTPrint(&plist);
}

//  查该 查前插 查后插
void testlist5()
{
	SLTNode* plist = NULL;
	SLPushFront(&plist, 9);
	SLPushFront(&plist, 18);
	SLPushFront(&plist, 27);
	SLTPrint(&plist);

	// 查改
	SLTNode* pos = SLFind(&plist, 18);
	if (pos)
		pos->data = 72;
	SLTPrint(&plist);

	//查前插
	if(pos)
	SLInsert(&plist, pos, 213);
	SLTPrint(&plist);

	// 查后插
	if(pos)
	SLInsertAfter(pos, 213);
	SLTPrint(&plist);
}

// 查删 查后删
void testlist6()
{
	SLTNode* plist = NULL;
	SLPushFront(&plist, 9);
	SLPushFront(&plist, 18);
	SLPushFront(&plist, 27);
	SLTPrint(&plist);

	SLTNode* pos = SLFind(&plist, 9);

	 //查删
	if (pos)
		SLErase(&plist, pos);
	SLTPrint(&plist);

	//// 查后删
	//if (pos)
	//	SLEraseAfter(pos);
	//SLTPrint(&plist);
}

// 销毁
void testlist7()
{
	SLTNode* plist = NULL;
	SLPushFront(&plist, 9);
	SLPushFront(&plist, 9);
	SLPushFront(&plist, 9);
	SLPushFront(&plist, 9);
	SLTPrint(&plist);

	SLDestroy(&plist);
	SLTPrint(&plist);
}

int main()
{
	//testlist1();
	//testlist2();
	//testlist3();
	//testlist4();
	//testlist5();
	//testlist6();
	testlist7();
	return 0;
}