#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void HeapSort1(int* a, int n)
{

	// 升序 -- 大堆    选出最大的数据放到第n-1个位置
	//                选出次大的数据放到第n-2个位置

	// 降序 -- 小堆    选出最小的数据放到第n-1个位置
	//                选出次小的数据放到第n-2个位置

	// 大小堆 由 AdjustUp() 中的代码决定

	// 建堆 -- 向上调整建堆
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

		//在调整，选出次小数
		AdjustDown(a, end, 0);

		end--;
	}
}


void HeapSort(int* a, int n)
{
	//// 建堆 -- 向上调整建堆
	//// O(N*logN)
	//int i = 0;
	//for (i = 1; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}

	// 建堆 -- 想下调整建堆
	// O(N);
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);

		//在调整，选出次小数
		AdjustDown(a, end, 0);

		end--;
	}
}

void CreateNDate()
{
	// 造数据

	int n = 9;
	srand((unsigned) time(NULL));

	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int x = rand() % 10000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

void PrintTopK(int k)
{
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror(" PrintTopK fopen");
		return;
	}

	int* kminheap = (int*)malloc(sizeof(int) * k);
	if (kminheap == NULL)
	{
		perror("PrintTopK malloc");
		return;
	}

	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &kminheap[i]);
	}

	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(kminheap, k, i);
	}

	int val = 0;
	while (!feof(fout))
	{
		fscanf(fout, "%d", &val);
		if (val > kminheap[0])
		{
			kminheap[0] = val;
			AdjustDown(kminheap, k, 0);
		}
	}
	
	for (int i = 0; i < k; i++)
	{
		printf("%d ", kminheap[i]);
	}
}



int main()
{
	//int a[] = { 7,8,3,5,1,9,5,4 };

	//HeapSort(a, sizeof(a) / sizeof(a[0]));
	//CreateNDate();
	PrintTopK(1);
	return 0;
}

//typedef int BTDataType;
//typedef struct BinaryTreeNode
//{
//	BTDataType data;
//	struct BinaryTreeNode* left;
//	struct BinaryTreeNode* right;
//}BTNode;
//
//BTNode* BuyNode(BTDataType x)
//{
//	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
//	if (node == NULL)
//	{
//		perror("BuyNode malloc");
//		return NULL;
//	}
//	node->data = x;
//	node->left = NULL;
//	node->right = NULL;
//
//	return node;
//}
//
//BTNode* CreatBinaryTree()
//{
//	BTNode* node1 = BuyNode(1);
//	BTNode* node2 = BuyNode(2);
//	BTNode* node3 = BuyNode(3);
//	BTNode* node4 = BuyNode(4);
//	BTNode* node5 = BuyNode(5);
//	BTNode* node6 = BuyNode(6);
//
//	node1->left = node2;
//	node1->right = node4;
//	node2->left = node3;
//	node4->left = node5;
//	node4->right = node6;
//	return node1;
//}
//
//void PrevOrder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		printf("N ");
//		return;
//	}
//
//	PrevOrder(root->left);
//	PrevOrder(root->right);
//	printf("%d ", root->data);
//}

//int main()
//{
//	BTNode* root = CreatBinaryTree();
//	PrevOrder(root);
//	return 0;
//}