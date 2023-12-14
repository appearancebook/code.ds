#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void TestList1()
{
	//plist 在调用函数后，要一直要指向链表第一个结构体的地址
	SLTNode* plist = NULL;
	
	SLTPushFront(&plist, 9);
	SLTPushFront(&plist, 18);
	SLTPushFront(&plist, 27);
	SLTPushFront(&plist, 36);
	SLTPrint(&plist);
}

void TestList2()
{
	SLTNode* plist = NULL;

	SLTPushFront(&plist, 9);
	SLTPushFront(&plist, 18);
	SLTPushFront(&plist, 27);
	SLTPushFront(&plist, 36);
	SLTPrint(&plist);

	SLTPushBack(&plist, 9);
	SLTPrint(&plist);

}

int main()
{
	//TestList1();
	TestList2();

	return 0;
}