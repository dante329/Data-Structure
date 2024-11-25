#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//静态版本初始化
//void SeqListInit(SL* ps)
//{
//	memset(ps->a, 0, sizeof(SeqDataType) * MAX_SIZE);
//	ps->size = 0;
//}

//动态内存版本初始化
void SeqListInit(SL* ps)
{
	//ps->a = (SeqDataType*)calloc(10, sizeof(SeqDataType));//内存分匹配写到CheckCapacity里面去，这里先给一个NULL初始化
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//检查并扩容
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
		
		//用if检查最刚开始的ps->capacity为0就给它赋一个初始值，作用与上面的三目操作符效果一样
		//if (ps->capacity == 0) ps->capacity = 10;
		//ps->a = (SeqDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(SeqDataType));
		//ps->capacity *= 2;
	}
}

//头插
void SeqListPushFront(SL* ps, SeqDataType x)
{
	CheckCapacity(ps);//是插入意味着size会增大，那么就要检查capacity是否够用，因为其他的接口也会使用到检查并扩容的功能，所以写一个静态的函数实现功能的模块化
	int end = ps->size - 1;
	while (end >= 0)//终止条件end < 0是怎样得到的？要分析过程，想的都是循环结束的条件，写的都是循环继续的条件 
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;//插入操作不要忘记
	ps->size++;
}

//尾插
void SeqListPushBack(SL* ps, SeqDataType x)
{
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//头删
void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);//要确保顺序表中有数据才能删除
	int start = 1;
	while (start > ps->size - 1)
	{
		ps->a[start - 1] = ps->a[start];
		start++;
	}
	ps->size--;
}

//尾删
void SeqListPopBack(SL* ps)
{
	assert(ps->size > 0);
	ps->size--;
}

//按下标插入
void SeqListInsert(SL* ps, int pos, SeqDataType x)
{
	assert(pos < ps->size);//插入数据的位置一定要在[0,size)内，因为顺序表的数据要求连续存储
	CheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos) 
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->size++;
}

//按下标删除
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

//查找
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

//修改
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

//打印
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//释放空间
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}