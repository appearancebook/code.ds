#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"
#include "stack.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
}

//O(N^2)
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];

		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}

			else
			{
				break;
			}
		}

		a[end + 1] = tmp;
	}
	
}

// O(N^1.3)
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;

		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}

			a[end + gap] = tmp;
		}
	}
}

void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		bool exchange = false;
		for (int j = 1; j < n - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				exchange = true;
				int tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
		}

		if (exchange == false)
		{
			break;
		}
	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int maxi = begin, mini = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}

			if (a[i] < a[mini])
			{
				mini = i;
			}
		}

		Swap(&a[begin], &a[mini]);
		// 如果 maxi 和 begin 重叠
		if(begin == maxi)
		{
			maxi = mini;
		}

		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while(child < n)
	{
		//左右孩子找小的--小堆
		//          大   大
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}

		else
		{
			break;
		}
	}
	
}

void HeapSort(int* a, int n)
{
	// 向下调整建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) / 2;

	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}

		else if (a[left] < a[right])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
	else
	{
		if (a[left] < a[right])
		{
			return left;
		}
		else if (a[mid] < a[right])
		{
			return right;
		}
		else
		{
			return mid;
		}
	}
}

// hoare版本
int PartSort(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midi]);

	int keyi = left;
	while (left < right)
	{
		// 右边找小
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}

		while (left < right && a[left] <= a[keyi])
		{
			left++;
		} 

		Swap (&a[right], &a[left]);
	}

	Swap(&a[keyi], &a[left]);
	keyi = left;

	return keyi;
}

// 挖坑法
int PartSort2(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midi]);

	int key = a[left];
	int hole = left;
	while (left < right)
	{
		// 右边找小
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[hole] = a[right];
		hole = right;

		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}

	a[hole] = key;

	return hole;
}

int PartSort3(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midi]);

	int prev = left;
	int cur = prev + 1;
	int keyi = left;

	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}

		cur++;
	}

	Swap(&a[keyi], &a[prev]);
	keyi = prev;

	return keyi;
}

// O(N*logN) 时间
// O(logN)   空间
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int mid = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[mid]);

	int left = begin, right = end;
	int cur = begin , key = a[begin];

	while (cur <= right)
	{
		if (a[cur] < key)
		{
			Swap(&a[cur], &a[left]);
			cur++;
			left++;
		}

		else if (a[cur] > key)
		{
			Swap(&a[cur], &a[right]);
			right--;
		}
		
		else
		{
			cur++;
		}
	}


	QuickSort(a, begin, left - 1);  
	QuickSort(a, right + 1, end);
}

void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	STInit(&st);
	STPush(&st, end);
	STPush(&st, begin);

	while (!STEmpty(&st))
	{
		int left = STTop(&st);
		STPop(&st);

		int right = STTop(&st);
		STPop(&st);

		int keyi = PartSort3(a, left, right);

		if (keyi + 1 < right)
		{
			STPush(&st, right);
			STPush(&st, keyi + 1);
		}

		if (keyi - 1 > left)
		{
			STPush(&st, keyi - 1);
			STPush(&st, left);
		}
	}

	STDestroy(&st);
}

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	//递归结束条件
	if (begin == end)
	{
		return;
	}

	//排好左右区间
	int midi = (begin + end) / 2;

	_MergeSort(a, begin, midi, tmp);
	_MergeSort(a, midi + 1, end, tmp);

	//归并左右两个区间
	int begin1 = begin, end1 = midi;
	int begin2 = midi + 1, end2 = end;
	int i = 0;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	//归并完后拷贝
	memcpy(a + begin, tmp, (end - begin + 1) * sizeof(a[0]));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(n * sizeof(a[0]));
	if (tmp == NULL)
	{
		perror("MergeSort malloc");
		return;
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}

//void MergeSortNonR(int* a, int n)
//{
//	int* tmp = (int*)malloc(n * sizeof(a[0]));
//	if (tmp == NULL)
//	{
//		perror("MergeSort malloc");
//		return;
//	}
//
//	int gap = 1;
//
//	while (gap < n)
//	{
//		int j = 0;
//		for (int i = 0; i < n; i += 2 * gap)
//		{
//			// 每组的合并数据
//			int begin1 = i, end1 = begin1 + gap - 1;
//			int begin2 = i + gap, end2 = begin2 + gap - 1;
//
//			if (end1 >= n || begin2 >= n)
//			{
//				break;
//			}
//
//			if (end2 >= n)
//			{
//				end2 = n - 1;
//			}
//
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//				{
//					tmp[j++] = a[begin1++];
//				}
//				else
//				{
//					tmp[j++] = a[begin2++];
//				}
//			}
//
//			while (begin1 <= end1)
//			{
//				tmp[j++] = a[begin1++];
//			}
//
//			while (begin2 <= end2)
//			{
//				tmp[j++] = a[begin2++];
//			}
//			
//			//memcpy(a + i, tmp + i, sizeof(a[0]) * (end2 - i + 1));
//		}
//
//		memcpy(a, tmp, sizeof(a[0]) * n);
//		gap *= 2;
//	}
//
//	free(tmp);
//	tmp = NULL;
//}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(n * sizeof(a[0]));
	if (tmp == NULL)
	{
		perror("MergeSort malloc");
		return;
	}

	int gap = 1;

	while (gap < n)
	{
		int j = 0;
		for (int i = 0; i < n; i += 2 * gap)
		{
			// 每组的合并数据
			int begin1 = i, end1 = begin1 + gap - 1;
			int begin2 = i + gap, end2 = begin2 + gap - 1;

			if (end1 >= n)
			{
				end1 = n - 1;
			}

			if (begin2 >= n)
			{
				begin2 = n + 1;
				end2 = n;

			}

			if (end2 >= n)
			{
				end2 = n - 1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

			//memcpy(a + i, tmp + i, sizeof(a[0]) * (end2 - i + 1));
		}

		memcpy(a, tmp, sizeof(a[0]) * n);
		gap *= 2;
	}

	free(tmp);
	tmp = NULL;
}


void CountSort(int* a, int n)
{
	int max = a[0];
	int min = a[0];

	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}

		if (a[i] < min)
		{
			min = a[i];
		}
	}

	int range = max - min + 1;

	int* CountA = (int*)malloc(sizeof(a[0]) * range);
	if (CountA == NULL)
	{
		perror("CountSort malloc");
	}
	memset(CountA, 0, sizeof(a[0]) * range);

	for (int i = 0; i < n; i++)
	{
		CountA[a[i] - min]++;
	}

	int j = 0;
	for (int i = 0; i < n; i++)
	{
		while (CountA[i]--)
		{
			a[j++] = i + min;
		}
	}
}


void HeapSort1(int* a,int n)
{
	// 建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

void AdjustDown1(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void ShellSort1(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;

		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end > 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break; 
				}
			}
			a[end + gap] = tmp;
		}

	}
}

void BubbleSort1(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		bool exchange = false;
		for (int j = 1; j < n - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				exchange = true;
				Swap(&a[j - 1], &a[j]);
			}
		}
		if (exchange == true)
		{
			break;
		}
	}
}

void SelectSort1(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int maxi = begin, mini = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}

		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--; 
	}
}