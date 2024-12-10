#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

/*
void Swap(int* p1, int* p2)//当最小值（mini）和当前起始位置（start）的索引相同时，Swap(&a[start], &a[mini]) 实际上等价于 Swap(&a[start], &a[start])，即 p1 == p2。在这种情况下，异或操作会将值清零
{
	if (p1 == p2) return;//如果想要继续使用异或交换，需要增加安全检查以避免问题 避免 p1 和 p2 指向相同地址
	*p1 = *p1 ^ *p2;
	*p2 = *p1 ^ *p2;
	*p1 = *p1 ^ *p2;
}//虽然异或操作在逻辑上可以交换两个值，但它的实现依赖于对数据位的逐位操作。如果程序的指针操作或数据一致性稍有问题（例如传递了相同指针），就会触发这种错误。相比之下，临时变量的交换更棒，不会受到这种影响。
*/


//最好还是用临时变量交换
void Swap(int* x, int* y) 
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


//最垃圾的直接选择排序
void SelectSort(int* a, int n)
{	
	int start = 0, end = n-1;
	while (start < end)
	{
		int mini = start, maxi = start;
		for (int i = start; i <= end; i++)
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
		Swap(&a[start], &a[mini]);
		//第1轮在全范围查找时（此时start=0），如果最大值的下标为0，那么此时先交换a[start]和a[mini]，会使maxi指向的值变成了最小值，下面再执行Swap(&a[end], &a[maxi])时，会将最小值换到最后一位
		//注意第i轮也是一样的（此时start=i），如果最大值的下标为i，那么此时先交换a[start]和a[mini]，会使maxi指向的值变成了最小值
		//所以加一个条件判断，当这种情况出现时，及时将maxi指向mini，因为第i轮查找时（此时start=i），如果最大值的下标为i，a[start]和a[mini]交换后，a[mini]是最大值
		if (maxi == start)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		start++;
		end--;
	}
}

//冒泡排序
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; ++j)
	{
		int exchange = 0;
		for (int i = 1; i < n-j; ++i)
		{
			if (a[i] > a[i - 1])
			{
				Swap(&a[i], &a[i - 1]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
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
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
 
int main()
{
	TestSort();
	//int a = 1, b = 2;
	//Swap(&a, &b);
	//printf("%d %d", a, b);
	return 0;
}