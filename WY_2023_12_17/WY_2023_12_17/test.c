#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

void testlist1()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 9);
	LTPushBack(plist, 18);
	LTPushBack(plist, 27);
	LTPrint(plist);
}


int main()
{
	testlist1();
	return 0;
}