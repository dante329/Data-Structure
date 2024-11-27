#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

//��ʼ���ĵ�һ�ַ�ʽ��Ҫ������ָ����ܶԺ�����ı��������޸�
//void ListInit(LNode** pphead)
//{
//	(*pphead)->data = 0;
//	(*pphead)->prev = *pphead;
//	(*pphead)->next = *pphead;
//}

//��ʼ���ĵڶ��ַ�ʽ��ֱ���ڳ�ʼ�������д���˫�������ͷ�ڵ�plist����return��ȥ������Ҫ����
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
	//��newnode�е�next��prev�Ƿ�Ӧ�ó�ʼ��ΪNULL���ڽ����½ڵ�ʱ���½ڵ㻹û����ǰ��ڵ������
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