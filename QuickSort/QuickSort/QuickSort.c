#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Stack.h"

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
/// ֱ�Ӳ�������
/// </summary>
/// <param name="a">һ������</param>
/// <param name="b">������Ĵ�С</param>
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

//����ȡ��
//���ǿ���ͨ��ȷ�� a[left] <= a[mid] <= a[right] �� a[right] <= a[mid] <= a[left] ��ѡ����λ����ͨ������Ԫ�صıȽϺͽ���λ�ã���֤ a[mid] ��������������λ����
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

//������ȡ�з����߼��������࣬������
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

//ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int index = SelectMid(a, left, right);
	Swap(&a[left], &a[index]);
	//����˼�룺��a[left]��Ϊkey��cur++��С���ҵ���keyС�ľ�ͣ������prev++֮���ٽ���a[prev]��a[cur]
	//cur������ľͻ�����ȥ����prevָ�����cur����һλ����cur�ҵ�С��ֵ��prev++��ָ���˴��ֵ�����໥����ֵ���൱�ڽ�С�����󻻣��Ѵ�����һ�
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


//����ָ�뷨
int PartSort2(int* a, int left, int right)
{
	int index = SelectMid(a, left, right);
	Swap(&a[left], &a[index]);

	int begin = left, end = right;
	int keyi = begin;
	while (begin < end)
	{		
		//һ��Ҫ����С���������Ҵ���Ǵ��
		//Ϊʲô���������begin��end ͣ����λ�õ�ֵ�϶���Ҫ С�� key �� ��ʱ�������� begin �������Ԫ��key ���Ͻ�С��key��ֵ�ŵ�key�����һ����
		//�ȴ���߿�ʼִ��ʱ��begin �ȿ�ʼ�Ҵ�end�ٽ�����С��ѭ��������� begin end �����ʱ��ֵ�϶���Ҫ ���� key �� ��ʱ�ٽ���key������λ�� �൱�ڰѱ�key���ֵ�ŵ���key��� ��begin��Զ��endһ����ռ��һ���������൱��beginռ��������λ�������Ǻܽӽ�ʱ��begin�ͻ����ҵ�һ��������Ȼ��end�ͻ���Ϊbegin < end�����������ֹ������end���غ���beginָ��Ĵ����ϣ�����key�������൱�ڽ�һ�������ŵ���key����ߣ�
		while (begin < end && a[end] >= a[keyi])
		{
			--end;
		}
		while (begin < end && a[begin] <= a[keyi])//a[begin] < a[keyi]���ܻ���ѭ��
		{
			++begin;
		}
		Swap(&a[begin], &a[end]);//����ָ��ֱ��ҵ���ֵСֵ���໥����
	}
	Swap(&a[begin], &a[keyi]);//���ѭ��������begin��end�غϣ���keyi��ֵ����ȥ
	return begin;
}

//�ڿӷ�
int PartSort1(int* a, int left, int right)
{	
	//����ȡ�У����������������˻��������ݹ����Ϊ n-1��Ŀ���ǽ�key��ֵ���¿�����������м䣬����ȡ�����ֵ������Сֵ
	int index = SelectMid(a, left, right);

	//��ȷ
	Swap(&a[left], &a[index]);//ֱ�ӽ� ����ȡ�� �õ����е�ֵ�������������left������������߼����ǽ�begin��left������pivot��������ߵ��������ӣ�����while (begin < end)��ѭ�������ұ���С��������Ҵ���߼����䣬������ִ������������ߣ�ȴ������Ҵ����ұ���С�Ļ����޷���ȷ����

	int begin = left, end = right;
	int pivot = begin;
	int key = a[pivot];

	//����
	/*int begin = left, end = right;
	int pivot = index;
	int key = a[pivot];*/

	//��������������Ϊʲôһ���ܽ�key�ŵ�ָ����λ�ã���һЩ��������֪�������޷���⣬�����ܾ���end��������Сʱһ��Ҫ�ҵ���С�����ŷŵ�����
	//ʵ��Ȼ������ֻ��Ҫ�ҵ���keyС�����ּ��ɣ�Ȼ����������ŵ����в��ڵ�ǰλ���γ��µĿӡ����key��ֵ�ܴ���ôend�����׾����ҵ���keyС����
	//end�����ָ�������������һλ���������������λ�γ��µĿӣ�begin�����ҵ���key��������ҵĴ����ͻ�࣬������ƽ�������ǰ���£������ϣ������ƶ��ľ���;ͻ�ܴ󣬻�ܿ��ź�key����ȷλ�á�����ĺܿ�ָ���ǲ���Ҫend��begin���ؽ������ң�����һ����һ����ҵ��ˡ����ǲ������������ǳ�����ִ�е�ʱ�䶼�Ǵ�����ͬ�ġ�ֻ���߼��Ϸ������졣
	//���������������⣺���key����������������������ôendһ��������������һλ�ҵ���keyС�����֣���Ӻ������γ��µĿӣ���ʱbegin�����ұ�key�������Ҳ�������ҵõ�������begin�ͻ�һֱ����ֱ����end�غϣ���ʱ����ѭ������key������о��ź���key����ȷλ��
	while (begin < end)
	{
		//�ұ���С���ŵ����
		while (begin < end && a[end] >= key)
		{
			--end;
		}
		//����keyС��ֵ�������У�Ȼ���Լ��γ��µĿ�
		a[pivot] = a[end];
		pivot = end;
		//����Ҵ󣬷ŵ��ұߣ�a[begin]��ֵ��keyС�ͼ���++begin��������key��ľ�ͣ����
		while (begin < end && a[begin] <= key)
		{
			++begin;
		}
		//����key���ֵ�������У�Ȼ���Լ��γ��µĿ�
		a[pivot] = a[begin];
		pivot = begin;
	}
	pivot = begin;
	a[pivot] = key;

	return pivot;
}

/// <summary>
/// ��������
/// </summary>
/// <param name="a">����������</param>
/// <param name="left">��������������±�</param>
/// <param name="right">��������������±�</param>
void QuickSort(int* a, int left, int right)
{
	if (left >= right)//������ֻ��һ��Ԫ�ػ��������鲻����
	{
		return;
	}
	int keyIndex = PartSort2(a, left, right);

	//�ź�key������Ľṹ��
	//[left, keyIndex - 1] keyIndex [keyIndex + 1, right]	
	//keyIndex�Ѿ�����ȷ��λ�����ˣ���ʱ������ʹ����������������������������оͶ������ˣ����εݹ�
	QuickSort(a, left, keyIndex - 1);
	QuickSort(a, keyIndex + 1, right);


	//С�����Ż������������С��Сʱ������ ��10��������ֱ��ʹ�ò��������������ٵݹ鿪����
	//Ϊʲô������Ĵ�С��10�����ٽ���С�����Ż�����Ϊ���Ž�ԭ���鲻�ϴ�Ŷ԰�ֳ����������飬����ԭ����Ĵ�СΪ100w���ڵݹ����Ϊ17���ʱ��������Ĵ�С�����10���ң���ʱ�����С�����Ż��ܽ�ʡ��90w�εݹ���ÿռ�
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

//12_10 ���£����ŷǵݹ�ʵ��
//�ݹ��ȱ�ݣ��ڼ�������£��ݹ���ȷǳ���ʱ���ᷢ��ջ�������Ϊջ���ڴ�ռ��Ǻ�С�ģ����ֻ��8MB
//�ǵݹ�һ��������˼·��1.ֱ���ñ������� 2.ʹ�����ݽṹ�е�ջģ��ʵ�ֵݹ�
void QuickSortNonR(int* a, int n)
{
	//����һ��ջ�ṹ���������������left��right������Ϣ��һ��ע�����ϵ��ھۣ�Ҫͨ����װ�õķ���ȥ��������
	ST st;
	StackInit(&st);
	//�Ȱ��������ݵ�left��right�����ȥ�����е�һ�˿��ţ�ע����������Ҫ������������ұߣ�����ѹջ����ѹջ��
	StackPush(&st, n - 1);
	StackPush(&st, 0);
	
	//ȡ��ջ��Ԫ�ؽ��е�һ�˿���,�õ���һ���źõ�keyindex
	//��һ���������ʱ�������鱻�ֳ���[left,keyindex-1] keyindex [keyindex+1,right]
	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);
		int keyindex = PartSort3(a, left, right);

		if (keyindex + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, keyindex + 1);
		}
		if (left < keyindex - 1)
		{
			StackPush(&st, keyindex - 1);
			StackPush(&st, left);
		}
	}

	StackDestory(&st);
}

void TestSort()
{
	int a[] = { 4,1,3,7,9,2,8,5,6};
	//QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	QuickSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

int main()
{
	TestSort();
	return 0;
}