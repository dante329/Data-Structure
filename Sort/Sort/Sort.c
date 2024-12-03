#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

/// <summary>
/// ֱ�Ӳ�������
/// </summary>
/// <param name="a">һ������</param>
/// <param name="b">������Ĵ�С</param>
/// <returns>�������������飨����</returns>
int* InsertSort(int* a, int n)
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
	return a;
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

TestInsertSort()
{
	int a[] = { 3,5,2,7,5,8,9,2,0,4,1 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestInsertSort();
	return 0;
}