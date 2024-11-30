#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//��̬�汾��ʼ��
//void SeqListInit(SL* ps)
//{
//	memset(ps->a, 0, sizeof(SeqDataType) * MAX_SIZE);
//	ps->size = 0;
//}

//��̬�ڴ�汾��ʼ��
void SeqListInit(SL* ps)
{
	//ps->a = (SeqDataType*)calloc(10, sizeof(SeqDataType));//�ڴ��ƥ��д��CheckCapacity����ȥ�������ȸ�һ��NULL��ʼ��
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//��鲢����
static void CheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{		
		int newcapacity = ps->capacity == 0 ? 10 : ps->capacity*2;
		SeqDataType* tmp = (SeqDataType*)realloc(ps->a, newcapacity * sizeof(SeqDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(1);
		}
		else
		{
			ps->a = tmp; 
			ps->capacity = newcapacity;
		}
		
		//��if�����տ�ʼ��ps->capacityΪ0�͸�����һ����ʼֵ���������������Ŀ������Ч��һ��
		//if (ps->capacity == 0) ps->capacity = 10;
		//ps->a = (SeqDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(SeqDataType));
		//ps->capacity *= 2;
	}
}

//ͷ��
void SeqListPushFront(SL* ps, SeqDataType x)
{
	CheckCapacity(ps);//�ǲ�����ζ��size��������ô��Ҫ���capacity�Ƿ��ã���Ϊ�����Ľӿ�Ҳ��ʹ�õ���鲢���ݵĹ��ܣ�����дһ����̬�ĺ���ʵ�ֹ��ܵ�ģ�黯
	int end = ps->size - 1;
	while (end >= 0)//��ֹ����end < 0�������õ��ģ�Ҫ�������̣���Ķ���ѭ��������������д�Ķ���ѭ������������ 
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;//���������Ҫ����
	ps->size++;
}

//β��
void SeqListPushBack(SL* ps, SeqDataType x)
{
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//ͷɾ
void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);//Ҫȷ��˳����������ݲ���ɾ��
	int start = 1;
	while (start > ps->size - 1)
	{
		ps->a[start - 1] = ps->a[start];
		start++;
	}
	ps->size--;
}

//βɾ
void SeqListPopBack(SL* ps)
{
	assert(ps->size > 0);
	ps->size--;
}

//���±����
void SeqListInsert(SL* ps, int pos, SeqDataType x)
{
	assert(pos < ps->size);//�������ݵ�λ��һ��Ҫ��[0,size)�ڣ���Ϊ˳��������Ҫ�������洢
	CheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos) 
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->size++;
}

//���±�ɾ��
void SeqListErase(SL* ps, int pos)
{
	assert(pos < ps->size);
	int start = pos;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}

//����
int SeqListFind(SL* ps, SeqDataType x)
{
	assert(ps -> size != 0);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
}

//�޸�
void SeqListModify(SL* ps, SeqDataType x, SeqDataType y)
{
	assert(ps->size != 0);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			ps->a[i] = y;
		}
	}
}

//��ӡ
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//�ͷſռ�
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}