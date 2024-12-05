#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void Swap(int* p1, int* p2)
{
	*p1 = *p1 ^ *p2;
	*p2 = *p1 ^ *p2;
	*p1 ^= *p2;
}

void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;//先默认child是左孩子
	while (child < n)//child增长的最快，所以限制child作为条件，数组的大小为n，数组的最后一个索引是n-1，不能越界所以child < n
	{
		if (child + 1 < n && a[child + 1] < a[child])//大顶堆改> //child + 1 < n 完全二叉树有可能没有右孩子，判断右孩子的下标是否超过了最大索引，超过了就证明该树没有右孩子
		{
			child += 1;//如果a[child + 1]更小/更大，将child + 1赋给child
		}
		if (a[parent] > a[child])//大顶堆改>
		{
			Swap(a + parent, a + child);
		}
		else
		{
			parent = child;
			child = parent * 2 + 1;//堆排序的逻辑树是的物理结构是用数组存储的，这里的child与parent的等式使得向下调整函数可以进入左右子树重复执行，类比链式存储结构中用root->left,root->right去递归左右子树
		}
	}
}

/// <summary>
/// 堆排序
/// </summary>
/// <param name="a">一个数组</param>
/// <param name="b">该数组的大小</param>
void HeapSort(int* a, int n)
{
	//第一步建堆
	//向下调整的前提是左右子树都是小/大顶堆，所以堆排序就要先从最下面的最小的子树开始向上面执行	AdjustDown，这个过程叫建堆/堆化
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)//child = n-1; i = parent = (child - 1) / 2 ; 
	{
		AdjustDown(a, n, i);
	}

	//第二步才是排序，怎样排序？取出堆顶元素，将堆顶元素与堆的最后一个元素交换。同时不破坏左右子树堆的结构
	 
	//排升序，要建大根堆
	int end = n - 1;
	while (end >= 1)//end最小是1，end=0时说明数组就剩一个元素了，不需要再比
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}


void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void TestSort()
{
	int a[] = { 3,5,2,7,5,8,9,2,0,4,1 };
	//InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
 
int main()
{
	//TestSort();
	//int a = 1, b = 2;
	//Swap(&a, &b);
	//printf("%d %d", a, b);
	return 0;
}