#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define StackDataType int

typedef struct Stack
{
	StackDataType* data;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);
void StackPush(ST* ps, StackDataType x);
void StackPop(ST* ps);
StackDataType StackTop(ST* ps);
int StackCount(ST* ps);
bool StackEmpty(ST* ps);
void StackDestory(ST* ps);
