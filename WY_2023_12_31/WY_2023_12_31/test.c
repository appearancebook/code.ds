#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

//void Heaptest1()
//{
//	Hp hp;
//	HeapInit(&hp);
//
//	int arr[] = { 65,100,70,32,50,60 };
//	int i = 0;
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]);i++)
//	{
//		HeapPush(&hp, arr[i]);
//	}
//
//	HeapDestroy(&hp);
//}
//
//void Heaptest2()
//{
//	Hp hp;
//	HeapInit(&hp);
//
//	int arr[] = { 65,100,70,32,50,60 };
//	int i = 0;
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		HeapPush(&hp, arr[i]);
//	}
//
//	i = 0;
//	while (!HeapEmpty(&hp))
//	{
//		arr[i] = HeapTop(&hp);
//		i++;
//		HeapPop(&hp);
//	}
//
//	HeapDestroy(&hp);
//}
//
//int main()
//{
//	Heaptest1();
//	Heaptest2();
//	return 0;
//}

//// �׶�  1������һ����  2�� �ռ临�Ӷ� + ���ݿ���  
//void HeapSort(int* a,int n)
//{
//	Hp hp;
//	HeapInit(&hp);
//
//	// N*logN
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		HeapPush(&hp, a[i]);
//	}
//
//	// N*logN
//	i = 0;
//	while (!HeapEmpty(&hp))
//	{
//		int top = HeapTop(&hp);
//		a[i++] = top;
//
//		HeapPop(&hp);
//	}
//	HeapDestroy(&hp);
//}

// N*logN
void HeapSort(int* a, int n)
{
	
	// ���� -- ���    ѡ���������ݷŵ���n-1��λ��
	//                ѡ���δ�����ݷŵ���n-2��λ��
	
	// ���� -- С��    ѡ����С�����ݷŵ���n-1��λ��
	//                ѡ����С�����ݷŵ���n-2��λ��

	// ��С�� �� AdjustUp() �еĴ������

	// ���� -- ���ϵ�������
	//N*logN
	int i = 0;
 	for (i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);

		//�ڵ�����ѡ����С��
		AdjustDown(a, end, 0);
		
		end--;
	}
}

void HeapSort(int* a, int n)
{
	// ���� -- ���µ�������
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);

		//�ڵ�����ѡ����С��
		AdjustDown(a, end, 0);

		end--;
	}
}

int main()
{
	int a[] = { 7,8,3,5,1,9,5,4 };

	HeapSort(a, sizeof(a) / sizeof(a[0]));
	return 0;
}