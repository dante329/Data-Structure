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


/// <summary>
/// ϣ������
/// </summary>
/// <param name="a">һ������</param>
/// <param name="b">������Ĵ�С</param>
void ShellSort(int* a, int n)
{
	int gap = n;//gap�Ĵ�С��Ҫ��n�������
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
					end -= gap;//�����ֱ�Ӳ��Ų�һ��������--end��endÿ��Ҫ��ȥgap�ľ���
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

void TestPerformance(void (*sortFunc)(int*, int), const char* sortName, int* a, int n)//���ｫ����ָ����Ϊ�������룬���õ�ʵ�ֲ��Թ���ģ�黯
{
    clock_t start = clock(); // ��¼��ʼʱ��
    sortFunc(a, n);          // ִ��������
    clock_t end = clock();   // ��¼����ʱ��

    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;//CLOCKS_PER_SEC ��һ���꣬������ C �� <time.h> ͷ�ļ��У����ڽ� clock() �����ķ���ֵת��Ϊ����Ϊ��λ��ʱ�䡣����ʾÿ���Ӧ�� ʱ�Ӽ�ʱ��Ԫ������ clock() ����ÿ�롰�δ𡱵Ĵ�����
    printf("%s ��������ʱ�䣺%.3f ��\n", sortName, timeTaken);
}

void TestOP()
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

	TestPerformance(InsertSort, "ֱ�Ӳ�������", a1, N);
	TestPerformance(ShellSort, "ϣ������", a2, N);

	free(a1);
	free(a2);
}

int main()
{
	//TestSort();
	TestOP();
	return 0;
}