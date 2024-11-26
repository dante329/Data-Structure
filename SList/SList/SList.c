#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//��ӡ
void SListPrint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d -> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

static SLNode* BuySListNode(SListDataType x)
{
	//malloc�½ڵ�
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	//���½ڵ��ʼ��
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

//void SListPushBack(SLNode* phead, SListDataType x)
//��Ҫ���⿴��SLNode* phead�Ǹ�ָ�����͵Ĳ����ͷ����ˣ�����main����������������ڵ�ģ�main������Ҳ����ָ��ȥ��ʼ��һ���ڵ㲢��������� SLNode* plist = NULL;
//��ô�����Ҫ�ö���ָ��ȥ����main�����ж�����Ǹ�ָ��plist�ĵ�ַ���������ܶ�plist�е����ݽ����޸ģ���Ȼ�β�ֻ��ʵ�ε�һ����ʱ���������βε��޸����޷�Ӱ�쵽ʵ�ε�
//�����Ҫ�ں����ڸı������ʵ�Σ���ô��Ҫ����ַ���ߴ����ã�C++��
void SListPushBack(SLNode** pphead, SListDataType x)
{
	//��˳��ȥ�����߼������Եĵط�©���ĵط��������������
	//��Ȼ��β�壬�϶�Ҫ�Ƚ���һ���µĽڵ�
	SLNode* newnode = BuySListNode(x);

	if (*pphead == NULL)//�п��ܵ���β���ʱ��һ���ڵ㶼û�У���ʱ��phead���ǿ�ָ��
	{
		*pphead = newnode;
	}
	else
	{
		SLNode* tail = *pphead;//��һ��tailָ��ȥ�����ҵ������β�ͣ��޸Ĵ�λ�õ�nextָ�룬�洢newnode�ĵ�ַ����β��ɹ�һ���ڵ�
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode; 
	}

}

void SListPushFront(SLNode** pphead, SListDataType x)
{
	SLNode* newnode = BuySListNode(x);
	
	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopBack(SLNode** pphead)
{
	//1.û�нڵ�
	//2.ֻ��һ���ڵ�
	//3.��һ�����ϵĽڵ�
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLNode* prev = NULL;
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}

void SListPopFront(SLNode** pphead)
{
	SLNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLNode* SListFind(SLNode* phead, SListDataType x)
{
	SLNode* cur = phead;
	
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
	
}

void SListInsert(SLNode** pphead, SLNode* pos, SListDataType x)
{
	SLNode* newnode = BuySListNode(x);

	if (pos == 1)
	{
		SListPushFront(pphead, x);
	}
	SLNode* prev = *pphead;
	while (prev->next != pos)//����һ�����Ƚϵľ���prev->next��pos�����pos��1��ô��Զƥ�䲻��������Ҫ�����ж�pos=1�����
	{
		prev = prev->next;
	}
	prev->next = newnode;
	newnode->next = pos;
}

void SListErase(SLNode** pphead, SLNode* pos)
{
	if (pos == *pphead)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}