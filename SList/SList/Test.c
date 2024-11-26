#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void Test()
{
	SLNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPushBack(&plist, 6);
	SListPrint(plist);
	SLNode* pos = SListFind(plist, 6);
	if (pos != NULL)
	{
		SListInsert(&plist, pos, 10);
	}
	SListPrint(plist);
	pos = SListFind(plist, 10);
	SListErase(&plist, pos);
	SListPrint(plist);
	pos = SListFind(plist, 1);
	SListErase(&plist, pos);
	SListPrint(plist);


}

int main()
{
	Test();
	return 0;
}