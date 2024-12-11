#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void _MergeSort(int* a, int left, int right, int* tmp)
{
	//��ֹ����
	if (left >= right)
		return;
	int mid = (left + right) >> 1;
	//�鲢����Ҫ���������䶼����Ϳ��Խ��й鲢�������������������ô�ͷ��Σ�������Ԫ�ؾ�ֹͣ�ݹ���й鲢������Ԫ�ؿ϶�ʱ����ģ�
	//��Ϊ��������[left,mid] [mid+1,right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	//�鲢����һ���ߵ���˵����������ֱ�ݹ鵽�˵���Ԫ�أ������Ƕ���������ĵ���Ԫ�ؽ��й鲢��
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;//��tmp����鲢����ʱ��indexΪ�±�
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

//12_07 ���£��鲢����ǵݹ�ʵ�֣�������
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	
	int gap = 1;

	while (gap < n)
	{

		for (int i = 0; i < n; i += 2 * gap)
		{
			//�������䱻�ֳ��� [i,i+gap-1] [i+gap+1,i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int index = i;//��tmp����鲢����ʱ��indexΪ�±�
			
			//����߽紦������
			//1.���������
			//�鲢�����п��ܳ��������䲻���ڣ���ֱ����������ֹ����Խ��
			//�鲢�����У�ֻ�����ڵ����ڶ��ι鲢�г��֣����ܳ��������䲻����������Ҫ������������䣨ǡǡ���ʱ������begin2 >= n����Ȼ�������ˣ������Ѿ���֮ǰ�Ĺ鲢������a�������ˣ��Ⱥ���gap���������ϴ���� 
			if (begin2 >= n)
			{
				break;
			}
			//2.�鲢�����п��ܳ��������䲻������Ĭ��end2 = i + 2 * gap - 1�϶�����ˣ�Ҫ��end2������n-1��λ��
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

			//�������tmp��aֻ��д��forѭ�����棬ÿ�ζԳɶԵ��������䴦��һ�ζ�Ҫֱ�ӿ�����a��ȥ����Ϊ�ڹ鲢�Ĺ�������ĳ���������е������ǲ�����ģ��������䲻����ʱ �ȣ������������д�����棬�ͻ��������Խ�磬�����ֵ������a��
			for (int j = i; j <= end2; j++)
			{
				//j = i j����ʼֵ������begin1����Ϊbegin1�Ѿ���++�����иı���
				//j<=end2 j������Ҫ��end2Ϊ�ο�������ֱ��дi + 2 * gap - 1����Ϊ����end2�Ѿ����������߽���
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