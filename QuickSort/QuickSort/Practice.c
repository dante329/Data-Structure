//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//
//void QuickSort(int* a, int left,int right)
//{
//	if (left >= right)
//	{
//		return;
//	}
//	int begin = left, end = right;
//	int pivot = begin;
//	int key = a[pivot];
//	while (begin < end)
//	{
//		while (begin < end && a[end] >= key)
//		{
//			--end;
//		}
//		a[pivot] = a[end];
//		pivot = end;
//		while (begin < end && a[begin] <= key)
//		{
//			++begin;
//		}
//		a[pivot] = a[begin];
//		pivot = begin;
//	}
//	pivot = begin;
//	a[pivot] = key;
//	//[left,pivot-1] pivot [pivot+1,right]
//	QuickSort(a, left, pivot);
//	QuickSort(a, pivot+1, right);
//}
//
//void PrintArray(int* a, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//}
//int main()
//{
//	int a[] = {4,2,6,9,8,5,4,3,0,1,2};
//	QuickSort(a, 0, sizeof(a) / sizeof(int)-1);
//	PrintArray(a, sizeof(a) / sizeof(int));
//	return 0;
//}