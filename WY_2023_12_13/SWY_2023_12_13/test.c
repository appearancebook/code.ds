#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}
//
//int main()
//{
//	int a = 9;
//	int b = 18;
//	int c = add(a, b);
//	return 0;
//}
//
//
//#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//#include <stdio.h>
//
//void test1()
//{
//	int a = 0;
//	printf("%p\n", &a);
//}
//
//void test3()
//{
//	int a = 0;
//	printf("%p\n", &a);
//}
//
//void test2()
//{
//	int a = 0;
//	printf("%p\n", &a);
//}
//
//int main()
//{
//	test1();
//	test2();
//	test3();
//	return 0;
//}

//˳���
// �����ɾ��Ų�����ݸ���
// ���������±��������ʣ���������

// ��̬

TestSeqList1()
{
	SL s;
	SLInit(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPushBack(&s, 7);
	SLPushBack(&s, 8);
	SLPushBack(&s, 9);

	SLPrint(&s);

	SLDestroy(&s);
}

TestSeqList2()
{
	SL s;
	SLInit(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2); 
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPushFront(&s, 9);
	SLPushFront(&s, 9);
	SLPushFront(&s, 9);

	SLPrint(&s);

	SLDestroy(&s);
}

TestSeqList3()
{
	SL s;
	SLInit(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPushFront(&s, 9);
	SLPushFront(&s, 9);
	SLPushFront(&s, 9);

	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);

	SLPrint(&s);

	SLDestroy(&s);
}

TestSeqList4()
{
	SL s;
	SLInit(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPushFront(&s, 9);
	SLPushFront(&s, 9);
	SLPushFront(&s, 9);

	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);
	SLPrint(&s);

	SLPopFront(&s);
	SLPopFront(&s);
	SLPrint(&s);


	SLDestroy(&s);
}

TestSeqList5()
{
	SL s;
	SLInit(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPushFront(&s, 9);
	SLPushFront(&s, 9);
	SLPushFront(&s, 9);

	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);
	SLPrint(&s);

	SLPopFront(&s);
	SLPopFront(&s);
	SLPrint(&s);

	SLInsert(&s, 1, 9);
	SLPrint(&s);

	SLDestroy(&s);
}

TestSeqList6()
{
	SL s;
	SLInit(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPushFront(&s, 9);
	SLPushFront(&s, 9);
	SLPushFront(&s, 9);

	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);
	SLPrint(&s);

	SLPopFront(&s);
	SLPopFront(&s);
	SLPrint(&s);

	SLInsert(&s, 1, 9);
	SLPrint(&s);

	SLErase(&s, 2);
	SLPrint(&s);

	SLDestroy(&s);
}

TestSeqList7()
{
	SL s;
	SLInit(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPushFront(&s, 9);
	SLPushFront(&s, 9);
	SLPushFront(&s, 9);
	SLPrint(&s);

	int pos = SLFind(&s, 6);
	if (pos != -1)
	{

	}

	SLDestroy(&s);
}

void meue()
{
	printf("********************************************\n");
	printf("1.β������  2.βɾ����");
	printf("3.β������  4.βɾ����");
	printf("5.β������  -1.βɾ����");
	printf("********************************************\n");

}

int main()
{
	//TestSeqList1();
	//TestSeqList2();
	//TestSeqList3();
	//TestSeqList4();
	//TestSeqList5();
	//TestSeqList6();
	TestSeqList7();

	return 0;
}