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


/// <summary>
/// 希尔排序
/// </summary>
/// <param name="a">一个数组</param>
/// <param name="b">该数组的大小</param>
void ShellSort(int* a, int n)
{
	int gap = n;//gap的大小是要跟n相关联的
	while (gap > 1)
	{
		gap /=  2;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;//这里跟直接插排不一样，不是--end，end每次要减去gap的距离
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



void TestSort()
{
	int a[] = { 3,5,2,7,5,8,9,2,0,4,1 };
	//InsertSort(a, sizeof(a) / sizeof(int));
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestPerformance()
{
	srand(time(0));
	int N = 100000;
	int* a1 = (int*)malloc(N * sizeof(int));
	int* a2 = (int*)malloc(N * sizeof(int));

	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
	}

}

int main()
{
	TestSort();
	return 0;
}