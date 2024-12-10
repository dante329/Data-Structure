#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void StackInit(ST* ps)
{
	ps->data = (StackDataType*)calloc(4, sizeof(StackDataType));
	ps->top = 0;
	ps->capacity = 4;
}

void StackPush(ST* ps, StackDataType x)
{
	assert(ps);
	//¼ì²éÀ©ÈÝ
	if (ps->top == ps->capacity)
	{
		StackDataType* tmp = realloc(ps->data, 2 * ps->capacity * sizeof(StackDataType));
		if (tmp == NULL)
		{
			perror("ps->data realloc fail");
		}
		else
		{
			ps->data = tmp;
		}
	}
	ps->data[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top>0);
	ps->top--;
}

StackDataType StackTop(ST* ps)
{
	assert(ps);
	return ps->data[ps->top - 1];
}

int StackCount(ST* ps)
{
	assert(ps);
	return ps->top;
}

//bool StackEmpty(ST* ps)
//{
//	assert(ps);
//	if (ps->top > 0)
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//}

bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->capacity = 0;
	ps->top = 0;
}