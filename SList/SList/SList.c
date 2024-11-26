#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//打印
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
	//malloc新节点
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	//对新节点初始化
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

//void SListPushBack(SLNode* phead, SListDataType x)
//不要在这看到SLNode* phead是个指针类型的参数就放心了，看看main函数中是怎样定义节点的？main函数中也是用指针去初始化一个节点并传入进来的 SLNode* plist = NULL;
//那么在这就要用二级指针去接受main函数中定义的那个指针plist的地址，这样才能对plist中的内容进行修改，不然形参只是实参的一份临时拷贝，对形参的修改是无法影响到实参的
//如果想要在函数内改变外面的实参，那么就要传地址或者传引用（C++）
void SListPushBack(SLNode** pphead, SListDataType x)
{
	//按顺序去分析逻辑，不对的地方漏掉的地方慢慢改慢慢添加
	//既然是尾插，肯定要先建立一个新的节点
	SLNode* newnode = BuySListNode(x);

	if (*pphead == NULL)//有可能调用尾插的时候一个节点都没有，这时候phead还是空指针
	{
		*pphead = newnode;
	}
	else
	{
		SLNode* tail = *pphead;//给一个tail指针去遍历找到链表的尾巴，修改此位置的next指针，存储newnode的地址，即尾插成功一个节点
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
	//1.没有节点
	//2.只有一个节点
	//3.有一个以上的节点
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
	while (prev->next != pos)//这里一上来比较的就是prev->next与pos，如果pos是1那么永远匹配不到，所以要单独判断pos=1的情况
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