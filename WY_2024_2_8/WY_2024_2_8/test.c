#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char file1[100] = "1";
	sprintf(file1, "%s%d", file1, 2);
	
	return 0;
}