#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

//初始化的第一种方式，要传二级指针才能对函数外的变量进行修改
//void ListInit(LNode** pphead)
//{
//	(*pphead)->data = 0;
//	(*pphead)->prev = *pphead;
//	(*pphead)->next = *pphead;
//}

//初始化的第二种方式，直接在初始化函数中创建双向链表的头节点plist，并return出去，不需要传参
LNode* ListInit()
{
	LNode* plist = (LNode*)malloc(sizeof(LNode));
	//LNode* plist;
	plist->data = 0;
	plist->prev = plist;
	plist->next = plist;
	return plist;
}


static LNode* BuyListNode(ListNodeData x)
{
	LNode* newnode = (LNode*)malloc(sizeof(LNode));
	newnode->data = x;
	//对newnode中的next和prev是否应该初始化为NULL，在建立新节点时，新节点还没有与前后节点相关联
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void ListPrint(LNode* phead)
{
	LNode* tail = phead->next;
	while (tail != phead)
	{
		printf("%d ", tail->data);
		tail = tail->next;
	}
	printf("NULL");
}

void ListNodeInsert(LNode* phead, LNode* pos, ListNodeData x)
{
	LNode* newnode = BuyListNode(x);
	LNode* head = pos->prev;

	newnode->next = pos;
	pos->prev = newnode;
	head->next = newnode;
	newnode->prev = head;
}

void ListNodeErase(LNode* phead, LNode* pos)
{
	LNode* first = pos->prev;
	LNode* second = pos->next;

	first->next = second;
	second->prev = first;
	free(pos);
}

LNode* ListNodeFind(LNode* phead, ListNodeData x)
{
	LNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void ListNodePushBack(LNode* phead, ListNodeData x)
{
	ListNodeInsert(phead, phead, x);
}

void ListNodePushFront(LNode* phead, ListNodeData x)
{
	ListNodeInsert(phead, phead->next, x);
}

void ListNodePopBack(LNode* phead)
{
	ListNodeErase(phead, phead->prev);
}

void ListNodePopFront(LNode* phead)
{
	ListNodeErase(phead, phead->next);
}

void ListDestory(LNode* phead)
{
	LNode* cur = phead->next;

	while (cur != phead)
	{
		LNode* next = cur->next;
		free(cur);
		cur = next;
	}

}