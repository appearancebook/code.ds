#define _CRT_SECURE_NO_WARNINGS 1

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
int main()
{
	SL s;
	SLInit(&s);
	
	SLPushback(&s, 1);
	SLPushback(&s, 2);
	SLPushback(&s, 3);
	SLPushback(&s, 4);
	SLPushback(&s, 5);
	SLPushback(&s, 6);
	SLPushback(&s, 7);
	SLPushback(&s, 8);
	SLPushback(&s, 9);

	SLPrint(&s);

	SLDestroy(&s);
	return 0;
}