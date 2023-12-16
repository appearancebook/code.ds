#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

// ͷ��
void TestList1()
{
	//plist �ڵ��ú�����ҪһֱҪָ�������һ���ṹ��ĵ�ַ
	SLTNode* plist = NULL;

	SLPushFront(&plist, 9);
	SLPushFront(&plist, 18);
	SLPushFront(&plist, 27);
	SLPushFront(&plist, 36);
	SLTPrint(&plist);
}

// β��
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

//βɾ
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

// ͷβɾ��ʾ
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

// �����ʾ
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

// ��ǰ�� ����
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

// ��ɾ ���ɾ
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