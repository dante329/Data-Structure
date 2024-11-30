#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define SeqDataType int

//#define MAX_SIZE 10

//静态版本结构体，给大了浪费空间，给小了空间不够用
//typedef struct SeqList
//{
//	SeqDataType a[MAX_SIZE];
//	int size;
//}SL;

//动态内存版结构体
typedef struct SeqList
{
	SeqDataType* a;
	int size;
	int capacity;
}SL;

//初始化
void SeqListInit(SL* ps);

//头插 尾插 头删 尾删 
void SeqListPushFront(SL* ps, SeqDataType x);
void SeqListPushBack(SL* ps, SeqDataType x);
void SeqListPopFront(SL* ps);
void SeqListPopBack(SL* ps);

//按下标插入 按下标删除
void SeqListInsert(SL* ps, SeqDataType x);
void SeqListErase(SL* ps);

//查找 修改
int SeqListFind(SL* ps, SeqDataType x);
void SeqListModify(SL* ps, SeqDataType x, SeqDataType y);

//打印
void SeqListPrint(SL* ps);

//释放空间
void SeqListDestory(SL* ps);