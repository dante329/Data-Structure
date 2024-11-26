#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdlib.h>

#define  SListDataType int

//易错
//typedef struct SListNode
//{
//	SListDataType data;
//	struct SListNode* next;  // 使用完整的类型名
//} SLNode;
//在 C 中，typedef 是在整个结构体定义完成之后才生效的。在结构体内部的声明必须使用完整的类型名（即 struct SListNode），而不是其别名 SLNode。

struct SListNode
{
	SListDataType data;
	struct SListNode* next;
};

typedef struct SListNode SLNode;

//不改变链表的头指针，传一级指针
void SListPrint(SLNode* phead);
//可能会改变链表的头指针，传二级指针
void SListPushBack(SLNode** pphead, SListDataType x); 
void SListPushFront(SLNode** pphead, SListDataType x); 
void SListPopBack(SLNode** pphead);
void SListPopFront(SLNode** pphead);
SLNode* SListFind(SLNode* phead, SListDataType x);
void SListInsert(SLNode** pphead, SLNode* pos, SListDataType x);//pos是由SListFind找到的
void SListErase(SLNode** pphead, SLNode* pos);
