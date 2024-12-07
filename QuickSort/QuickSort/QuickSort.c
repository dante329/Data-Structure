#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

/// <summary>
/// 直接插入排序
/// </summary>
/// <param name="a">一个数组</param>
/// <param name="b">该数组的大小</param>
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//三数取中
//我们可以通过确保 a[left] <= a[mid] <= a[right] 或 a[right] <= a[mid] <= a[left] 来选出中位数。通过三个元素的比较和交换位置，保证 a[mid] 是这三个数的中位数。
int SelectMid(int* a, int left, int right)
{
	int mid = (left + right) >> 1;

	if (a[left] > a[right]) {
		int temp = left;
		left = right;
		right = temp;
	}

	if (a[left] > a[mid]) {
		int temp = left;
		left = mid;
		mid = temp;
	}

	if (a[mid] > a[right]) {
		int temp = mid;
		mid = right;
		right = temp;
	}

	return mid;  
}

//此三数取中方法逻辑复杂冗余，不采用
//int SelectMid(int* a, int left, int right)
//{
//	int index = 0;
//	int mid = (left + right) >> 1;
//	if (a[left] > a[right])
//	{
//		if (a[right] > a[mid])
//		{
//			index = right;
//		}
//		else if(a[mid]>a[left])
//		{
//			index = left;
//		}
//		else
//		{
//			index = mid;
//		}
//	}
//	else
//	{
//		if (a[mid] > a[right])
//		{
//			index = right;
//		}
//		else if (a[mid] > a[left])
//		{
//			index = mid;
//		}
//		else
//		{
//			index = left;
//		}
//		
//	}
//	return index;
//}

//前后指针法
int PartSort3(int* a, int left, int right)
{
	int index = SelectMid(a, left, right);
	Swap(&a[left], &a[index]);
	//核心思想：将a[left]存为key，cur++找小，找到比key小的就停下来，prev++之后，再交换a[prev]和a[cur]
	//cur遇到大的就会跳过去，而prev指向的是cur的上一位，当cur找到小的值，prev++就指向了大的值，再相互交换值，相当于将小的往左换，把大的往右换
	int prev = left, cur = left + 1;
	int keyi = left;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev!=cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
}


//左右指针法
int PartSort2(int* a, int left, int right)
{
	int index = SelectMid(a, left, right);
	Swap(&a[left], &a[index]);

	int begin = left, end = right;
	int keyi = begin;
	while (begin < end)
	{		
		//一定要先找小！！！先找大就是错的
		while (begin < end && a[end] >= a[keyi])
		{
			--end;
		}
		while (begin < end && a[begin] <= a[keyi])//a[begin] < a[keyi]可能会死循环
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);//左右指针分别找到大值小值，相互交换
	}
	Swap(&a[begin], &a[keyi]);//最后循环结束，begin和end重合，将keyi的值换上去
	return begin;
}

//挖坑法
int PartSort1(int* a, int left, int right)
{	
	//三数取中，避免排有序数组退化成链表，递归深度为 n-1，目的是将key的值大致控制在数组的中间，避免取出最大值或者最小值
	int index = SelectMid(a, left, right);

	//正确
	Swap(&a[left], &a[index]);//直接将 三数取中 得到的中等值的数字与数组的left交换，下面的逻辑还是将begin（left）赋给pivot，将最左边的数当作坑，这样while (begin < end)大循环中先右边找小，再左边找大的逻辑不变，不会出现错误。如果坑在左边，却先左边找大再右边找小的话就无法正确排序

	int begin = left, end = right;
	int pivot = begin;
	int key = a[pivot];

	//错误
	/*int begin = left, end = right;
	int pivot = index;
	int key = a[pivot];*/

	//！！！单趟排序为什么一定能将key排到指定的位置？有一些常见的认知错误导致无法理解，我们总觉得end在向左找小时一定要找到最小的数才放到坑中
	//实则不然，我们只需要找到比key小的数字即可，然后立即将其放到坑中并在当前位置形成新的坑。如果key的值很大，那么end很容易就能找到比key小的数
	//end本身就指向的是数组的最后一位，就容易在数组高位形成新的坑；begin很难找到比key大的数，找的次数就会多，（数字平均分配的前提下，概率上）向右移动的距离就就会很大，会很快排好key的正确位置。这里的很快指的是不需要end和begin来回交换着找，可能一人找一遍就找到了。但是不管怎样，他们程序上执行的时间都是大致相同的。只是逻辑上分析更快。
	//极端情况更容易理解：如果key是整个数列中最大的数，那么end一定会在数组的最后一位找到比key小的数字，填坑后自身形成新的坑，此时begin向右找比key大的数字也不可能找得到，所以begin就会一直自增直到与end重合，此时结束循环，将key填入坑中就排好了key的正确位置
	while (begin < end)
	{
		//右边找小，放到左边
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		//将比key小的值赋给坑中，然后自己形成新的坑
		a[pivot] = a[end];
		pivot = end;
		//左边找大，放到右边，a[begin]的值比key小就继续++begin，遇到比key大的就停下来
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		//将比key大的值赋给坑中，然后自己形成新的坑
		a[pivot] = a[begin];
		pivot = begin;
	}
	pivot = begin;
	a[pivot] = key;

	return pivot;
}

/// <summary>
/// 快速排序
/// </summary>
/// <param name="a">待排序数组</param>
/// <param name="left">待排序区间的左下标</param>
/// <param name="right">待排序区间的右下标</param>
void QuickSort(int* a, int left, int right)
{
	if (left >= right)//子数组只有一个元素或者子数组不存在
	{
		return;
	}
	int keyIndex = PartSort2(a, left, right);

	//排好key后数组的结构：
	//[left, keyIndex - 1] keyIndex [keyIndex + 1, right]	
	//keyIndex已经在正确的位置上了，这时我们再使左子区间和右子区间有序，整个序列就都有序了，分治递归
	QuickSort(a, left, keyIndex - 1);
	QuickSort(a, keyIndex + 1, right);


	//小区间优化：当子数组大小很小时（例如 ≤10），可以直接使用插入排序，这样减少递归开销。
	//为什么子数组的大小在10左右再进行小区间优化？因为快排将原数组不断大概对半分成两个子数组，假设原数组的大小为100w，在递归深度为17层的时候子数组的大小大概在10左右，这时候进行小区间优化能节省近90w次递归调用空间
	/*if (keyIndex - 1 - left > 10)
	{
		QuickSort(a, left, keyIndex - 1);
	}
	else
	{
		InsertSort(a, keyIndex - 1 - left);
	}
	if (right-(keyIndex + 1) > 10)
	{
		QuickSort(a, keyIndex + 1, right);
	}
	else
	{
		InsertSort(a, right - (keyIndex + 1));
	}*/
}

void TestSort()
{
	int a[] = { 4,1,3,7,9,2,8,5,6};
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestSort();
	return 0;
}