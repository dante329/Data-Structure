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
void SlistPrint(SLNode* phead);
//可能会改变链表的头指针，传二级指针
void SlistPushBack(SLNode** pphead, SListDataType x); 
void SlistPushFront(SLNode** pphead, SListDataType x); 
void SlistPopBack(SLNode** pphead);
void SlistPopFront(SLNode** pphead);
SLNode* SlistFind(SLNode* phead, SListDataType x);
void SlistInsert(SLNode** pphead, SLNode* pos, SListDataType x);//pos是由SlistFind找到的
void SlistErase(SLNode** pphead, SLNode* pos);
