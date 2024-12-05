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
	int child = parent * 2 + 1;//��Ĭ��child������
	while (child < n)//child��������죬��������child��Ϊ����������Ĵ�СΪn����������һ��������n-1������Խ������child < n
	{
		if (child + 1 < n && a[child + 1] < a[child])//�󶥶Ѹ�> //child + 1 < n ��ȫ�������п���û���Һ��ӣ��ж��Һ��ӵ��±��Ƿ񳬹�����������������˾�֤������û���Һ���
		{
			child += 1;//���a[child + 1]��С/���󣬽�child + 1����child
		}
		if (a[parent] > a[child])//�󶥶Ѹ�>
		{
			Swap(a + parent, a + child);
		}
		else
		{
			parent = child;
			child = parent * 2 + 1;//��������߼����ǵ�����ṹ��������洢�ģ������child��parent�ĵ�ʽʹ�����µ����������Խ������������ظ�ִ�У������ʽ�洢�ṹ����root->left,root->rightȥ�ݹ���������
		}
	}
}

/// <summary>
/// ������
/// </summary>
/// <param name="a">һ������</param>
/// <param name="b">������Ĵ�С</param>
void HeapSort(int* a, int n)
{
	//��һ������
	//���µ�����ǰ����������������С/�󶥶ѣ����Զ������Ҫ�ȴ����������С��������ʼ������ִ��	AdjustDown��������̽н���/�ѻ�
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)//child = n-1; i = parent = (child - 1) / 2 ; 
	{
		AdjustDown(a, n, i);
	}

	//�ڶ�������������������ȡ���Ѷ�Ԫ�أ����Ѷ�Ԫ����ѵ����һ��Ԫ�ؽ�����ͬʱ���ƻ����������ѵĽṹ
	 
	//������Ҫ�������
	int end = n - 1;
	while (end >= 1)//end��С��1��end=0ʱ˵�������ʣһ��Ԫ���ˣ�����Ҫ�ٱ�
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