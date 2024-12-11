#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void _MergeSort(int* a, int left, int right, int* tmp)
{
	//中止条件
	if (left >= right)
		return;
	int mid = (left + right) >> 1;
	//归并排序要求左右区间都有序就可以进行归并，如果左右区间无序，那么就分治，到单个元素就停止递归进行归并（单个元素肯定时有序的）
	//分为两个区间[left,mid] [mid+1,right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	//归并（第一次走到这说明左右区间分别递归到了单个元素，下面是对左右区间的单个元素进行归并）
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;//往tmp里面归并数据时以index为下标
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	assert(tmp);
	_MergeSort(a, 0, n-1, tmp);
	free(tmp);
}

//12_07 更新：归并排序非递归实现（遍历）
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	
	int gap = 1;

	while (gap < n)
	{

		for (int i = 0; i < n; i += 2 * gap)
		{
			//左右区间被分成了 [i,i+gap-1] [i+gap+1,i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int index = i;//往tmp里面归并数据时以index为下标
			
			//特殊边界处理！！！
			//1.两种情况：
			//归并过程中可能出现右区间不存在，就直接跳过，防止数组越界
			//归并过程中（只可能在倒数第二次归并中出现）可能出现左区间不完整，不需要处理这个左区间（恰恰这个时候满足begin2 >= n，自然就跳过了），它已经被之前的归并拷贝到a数组中了，等后续gap变大给它带上处理掉 
			if (begin2 >= n)
			{
				break;
			}
			//2.归并过程中可能出现右区间不完整，默认end2 = i + 2 * gap - 1肯定算多了，要将end2调整到n-1的位置
			if (end2 >= n)
			{
				end2 = n-1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[index++] = a[begin1++];
				}
				else
				{
					tmp[index++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[index++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[index++] = a[begin2++];
			}

			//这个拷贝tmp到a只能写在for循环里面，每次对成对的左右区间处理一次都要直接拷贝到a里去，因为在归并的过程中在某个步骤中有的区间是不处理的（当左区间不完整时 等），如果将拷贝写到外面，就会出现数组越界，将随机值拷贝到a中
			for (int j = i; j <= end2; j++)
			{
				//j = i j的起始值不能用begin1，因为begin1已经在++过程中改变了
				//j<=end2 j的上限要以end2为参考，不能直接写i + 2 * gap - 1，因为可能end2已经被调整过边界了
				a[j] = tmp[j];
			}
		}
		gap *= 2;
	}
	free(tmp);
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}	
int main()
{
	int a[] = { 4,2,6,8,5,9,7,1,0 };
	MergeSortNonR(a, sizeof(a) / sizeof(int));
	//MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	return 0;
}