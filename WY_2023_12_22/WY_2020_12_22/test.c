#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

void color(short x)
{
	if (x >= 0 && x <= 15)//������0-15�ķ�Χ��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//ֻ��һ���������ı�������ɫ
	else//Ĭ�ϵ���ɫ��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

int main()
{
	srand((unsigned)time(NULL));
	int count = 0;
	while (count<1314520)
	{
		int x = rand() % 10;
		if (x <3)
		{
			printf("                                                                          ");
		}
		else
		{
			color(2);
			
			printf("���Ŀ���Ŷ���");
		
			count++;
		}
	}
	return 0;
}