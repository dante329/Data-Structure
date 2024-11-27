#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

void Test()
{
	//第一种初始化
	//LNode* plist = NULL;
	//ListInit(plist);
	//第二种初始化
	LNode* plist = ListInit();
	ListNodePushBack(plist, 1);
	ListNodePushBack(plist, 2);
	ListNodePushBack(plist, 3);
	ListNodePushBack(plist, 4);
	ListNodePushBack(plist, 5);
	ListPrint(plist);
	ListDestory(plist);
}

int main()
{
	Test();
	return 0;
}