#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void TestList1()
{
	//plist �ڵ��ú�����ҪһֱҪָ�������һ���ṹ��ĵ�ַ
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