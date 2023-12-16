#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

// ͷ��
void testlist1()
{
	SLTNode* plist = NULL;
	SLPushFront(&plist, 9);
	SLPushFront(&plist, 18);
	SLPushFront(&plist, 27);
	SLTPrint(&plist);
}

// β��
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

// ͷɾ
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

// βɾ
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

//  ��� ��ǰ�� ����
void testlist5()
{
	SLTNode* plist = NULL;
	SLPushFront(&plist, 9);
	SLPushFront(&plist, 18);
	SLPushFront(&plist, 27);
	SLTPrint(&plist);

	// ���
	SLTNode* pos = SLFind(&plist, 18);
	if (pos)
		pos->data = 72;
	SLTPrint(&plist);

	//��ǰ��
	if(pos)
	SLInsert(&plist, pos, 213);
	SLTPrint(&plist);

	// ����
	if(pos)
	SLInsertAfter(pos, 213);
	SLTPrint(&plist);
}

// ��ɾ ���ɾ
void testlist6()
{
	SLTNode* plist = NULL;
	SLPushFront(&plist, 9);
	SLPushFront(&plist, 18);
	SLPushFront(&plist, 27);
	SLTPrint(&plist);

	SLTNode* pos = SLFind(&plist, 9);

	 //��ɾ
	if (pos)
		SLErase(&plist, pos);
	SLTPrint(&plist);

	//// ���ɾ
	//if (pos)
	//	SLEraseAfter(pos);
	//SLTPrint(&plist);
}

// ����
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