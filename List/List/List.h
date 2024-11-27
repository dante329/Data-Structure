#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ListNodeData int

struct ListNode
{
	ListNodeData data;
	struct ListNode* prev;
	struct ListNode* next;
};

typedef struct ListNode LNode;

LNode* ListInit();

//��дInsert��Erase�������Ľӿ�ֱ�Ӹ�����������ʵ��
void ListNodeInsert(LNode* phead, LNode* pos, ListNodeData x);
void ListNodeErase(LNode* phead, LNode* pos);
void ListPrint(LNode* phead);
void ListNodePushBack(LNode* phead, ListNodeData x);
void ListNodePushFront(LNode* phead, ListNodeData x);
void ListNodePopBack(LNode* phead);
void ListNodePopFront(LNode* phead);
LNode* ListNodeFind(LNode* phead, ListNodeData x);
void ListDestory(LNode* phead);
