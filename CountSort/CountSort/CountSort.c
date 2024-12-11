#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

void CountSort(int* a, int n)
{
	if (a == NULL || n <= 0)
		perror("Error array is NULL");

	int min = a[0], max = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	assert(count);
	memset(count, 0, sizeof(int) * range);
	//开始统计
	for (int i = 0; i < n; ++i)
	{
		count[a[i] - min]++;
	}

	//将统计结果输出到数组a
	int j = 0;
	for (int i = 0; i <	range; ++i)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}
	
	free(count);
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int a[] = { 100,104,103,106,108,102,107,109 };
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	return 0;
}