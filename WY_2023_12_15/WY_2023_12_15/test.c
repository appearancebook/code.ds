#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

// 头插
void TestList1()
{
	//plist 在调用函数后，要一直要指向链表第一个结构体的地址
	SLTNode* plist = NULL;

	SLPushFront(&plist, 9);
	SLPushFront(&plist, 18);
	SLPushFront(&plist, 27);
	SLPushFront(&plist, 36);
	SLTPrint(&plist);
}

// 尾插
void TestList2()
{
	SLTNode* plist = NULL;

	//SLPushFront(&plist, 9);
	//SLPushFront(&plist, 18);
	//SLPushFront(&plist, 27);
	//SLPushFront(&plist, 36);
	//SLTPrint(&plist);

	SLPushBack(&plist, 9);
	SLTPrint(&plist);

}

//尾删
void TestList3()
{
	SLTNode* plist = NULL;

	SLPushFront(&plist, 9);
	SLPushFront(&plist, 18);
	SLPushFront(&plist, 27);
	SLPushFront(&plist, 36);
	SLTPrint(&plist);

	SLPushBack(&plist, 9);
	SLTPrint(&plist);

	SLPopBack(&plist);
	SLTPrint(&plist);


}

// 头尾删演示
void TestList4()
{
	SLTNode* plist = NULL;

	SLPushFront(&plist, 9);
	SLPushFront(&plist, 18);
	SLPushFront(&plist, 27);
	SLPushFront(&plist, 36);
	SLTPrint(&plist);

	SLPushBack(&plist, 9);
	SLTPrint(&plist);

	SLPopBack(&plist);
	SLTPrint(&plist);

	SLPopFront(&plist);
	SLTPrint(&plist);

}

// 查改演示
void TestList5()
{
	SLTNode* plist = NULL;

	SLPushFront(&plist, 9);
	SLPushFront(&plist, 18);
	SLPushFront(&plist, 27);
	SLPushFront(&plist, 36);
	SLTPrint(&plist);

	SLTNode* pos = SLFind(&plist, 9);
	if(pos)
	pos->data = 72;
	SLTPrint(&plist);


}

// 查前插 查后插
void TestList6()
{
	SLTNode* plist = NULL;

	SLPushFront(&plist, 9);
	SLPushFront(&plist, 18);
	SLPushFront(&plist, 27);
	SLPushFront(&plist, 36);
	SLTPrint(&plist);

	SLTNode* pos = SLFind(&plist, 9);
	if (pos)
		SLInsert(&plist, pos, 72);
	SLTPrint(&plist);

	pos = SLFind(&plist, 36);
	if (pos)
		SLInsertAfter(pos, 9);
	SLTPrint(&plist);

}

// 查删 查后删
void TestList7()
{
	SLTNode* plist = NULL;

	SLPushFront(&plist, 9);
	SLPushFront(&plist, 18);
	SLPushFront(&plist, 27);
	SLPushFront(&plist, 36);
	SLTPrint(&plist);

	SLTNode* pos = SLFind(&plist, 18);
	if (pos)
		SLErase(&plist, pos);
	SLTPrint(&plist);
	SLTNode* gp = SLFind(&plist, 9);
	SLDestroy(&plist);
}

int main()
{
	//TestList1();
	TestList2();
	//TestList3();
	//TestList4();
	//TestList5();
	//TestList6();
	//TestList7();

	return 0;
}