#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//int main() {
//    int a;
//    while (scanf("%d", &a) != EOF) {
//        int sum = 0;
//        sum += a;
//        while (getchar() != '\n') {
//            scanf("%d", &a);
//            sum += a;
//        }
//        printf("%d \n", sum);
//    }
//}

//#include<stdio.h>
//int main()
//
//{
//    int a, b;
//    while (scanf("%d %d", &a, &b) != EOF)
//    {
//        if (a == 0 && b == 0)break;
//        printf("%d\n", a + b);
//
//
//    }
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//    long a, b;
//    long long sum = 0;
//    while (scanf("%ld", &a) != EOF)
//    {
//
//        sum += a;
//        if (getchar() == '\n')
//        {
//            printf("%ld \n", sum);
//            sum = 0;
//        }
//
//    }
//
//
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int a = 0;
//	char arr[18] = { 0 };
//	scanf("%d", &a);
//	while ((getchar()) != EOF);
//	printf("%d\n", a);
//	gets(arr);
//	printf("%s", arr);
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0;
	int a = 0;
	while (scanf("%d", &n) != EOF)
	{
		int sum = 0;
		if (n = 0)
			break;
		//if (getchar() == '\n')
		{
			while (scanf("%d", &a) != EOF)
			{
				sum += a;
				if (getchar() == '\n')
				{
					printf("%d\n", sum);
					break;
				}
			}
		}
	}
	return 0;
}