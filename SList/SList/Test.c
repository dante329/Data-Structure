#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void Test()
{
	SLNode* plist = NULL;
	SlistPushBack(&plist, 1);
	SlistPushBack(&plist, 2);
	SlistPushBack(&plist, 3);
	SlistPushBack(&plist, 4);
	SlistPushBack(&plist, 5);
	SlistPushBack(&plist, 6);
	SlistPrint(plist);
	SLNode* pos = SlistFind(plist, 6);
	if (pos != NULL)
	{
		SlistInsert(&plist, pos, 10);
	}
	SlistPrint(plist);
}

int main()
{
	Test();
	return 0;
}