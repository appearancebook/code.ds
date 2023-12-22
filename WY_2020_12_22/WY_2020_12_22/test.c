#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

void color(short x)
{
	if (x >= 0 && x <= 15)//参数在0-15的范围颜色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//只有一个参数，改变字体颜色
	else//默认的颜色白色
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
			
			printf("过的开心哦，杨俊");
		
			count++;
		}
	}
	return 0;
}