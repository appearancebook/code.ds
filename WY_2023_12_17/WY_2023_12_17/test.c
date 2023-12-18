#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

// β��
void testlist1()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 9);
	LTPushBack(plist, 18);
	LTPushBack(plist, 27);
	LTPrint(plist);

	LTDestroy(plist);
	plist = NULL;
}

// ͷ��
void testlist2()
{
	LTNode* plist = LTInit();
	LTPushFront(plist, 9);
	LTPushFront(plist, 18);
	LTPushFront(plist, 27);
	LTPrint(plist);

	LTDestroy(plist);
	plist = NULL;
}

// βɾ
void testlist3()
{
	LTNode* plist = LTInit();
	LTPushFront(plist, 9);
	LTPushFront(plist, 18);
	LTPushFront(plist, 27);
	LTPrint(plist);

	LTPopback(plist);
	LTPrint(plist);

	LTDestroy(plist);
	plist = NULL;
}

// ͷɾ
void testlist4()
{
	LTNode* plist = LTInit();
	LTPushFront(plist, 9);
	LTPushFront(plist, 18);
	LTPushFront(plist, 27);
	LTPrint(plist);

	LTPopFront(plist);
	LTPrint(plist);

	LTDestroy(plist);
	plist = NULL;
}

// ���
void testlist5()
{
	LTNode* plist = LTInit();
	LTPushFront(plist, 9);
	LTPushFront(plist, 18);
	LTPushFront(plist, 27);
	LTPrint(plist);

	LTNode* pos = LTFind(plist, 9);
	if (pos)
	{
		pos->data = 72;
	}

	LTPrint(plist);

	LTDestroy(plist);
	plist = NULL; 
}


// ��ǰ�� ��ɾ
void testlist6()
{
	LTNode* plist = LTInit();
	LTPushFront(plist, 9);
	LTPushFront(plist, 18);
	LTPushFront(plist, 27);
	LTPrint(plist);

	LTNode* pos = LTFind(plist, 18);
	if (pos)
	{
		LTInsert(pos, 72);
	}
	LTPrint(plist);

	if (pos)
	{
		LTErase(pos);
	}
	LTPrint(plist);

	LTDestroy(plist);
	plist = NULL;
}
int main()
{
	//testlist1();
	//testlist2();
	//testlist3();
	//testlist4();
	//testlist5();
	//testlist6();
	return 0;
}