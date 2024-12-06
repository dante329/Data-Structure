#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

/*
void Swap(int* p1, int* p2)//����Сֵ��mini���͵�ǰ��ʼλ�ã�start����������ͬʱ��Swap(&a[start], &a[mini]) ʵ���ϵȼ��� Swap(&a[start], &a[start])���� p1 == p2������������£��������Ὣֵ����
{
	if (p1 == p2) return;//�����Ҫ����ʹ����򽻻�����Ҫ���Ӱ�ȫ����Ա������� ���� p1 �� p2 ָ����ͬ��ַ
	*p1 = *p1 ^ *p2;
	*p2 = *p1 ^ *p2;
	*p1 = *p1 ^ *p2;
}//��Ȼ���������߼��Ͽ��Խ�������ֵ��������ʵ�������ڶ�����λ����λ��������������ָ�����������һ�����������⣨���紫������ָͬ�룩���ͻᴥ�����ִ������֮�£���ʱ�����Ľ��������������ܵ�����Ӱ�졣
*/


//��û�������ʱ��������
void Swap(int* x, int* y) 
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


//��������ֱ��ѡ������
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
		//��1����ȫ��Χ����ʱ����ʱstart=0����������ֵ���±�Ϊ0����ô��ʱ�Ƚ���a[start]��a[mini]����ʹmaxiָ���ֵ�������Сֵ��������ִ��Swap(&a[end], &a[maxi])ʱ���Ὣ��Сֵ�������һλ
		//ע���i��Ҳ��һ���ģ���ʱstart=i����������ֵ���±�Ϊi����ô��ʱ�Ƚ���a[start]��a[mini]����ʹmaxiָ���ֵ�������Сֵ
		//���Լ�һ�������жϣ��������������ʱ����ʱ��maxiָ��mini����Ϊ��i�ֲ���ʱ����ʱstart=i����������ֵ���±�Ϊi��a[start]��a[mini]������a[mini]�����ֵ
		if (maxi == start)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		start++;
		end--;
	}
}

//ð������
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