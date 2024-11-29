#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void Test()
{
	ST s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	printf("%d ",StackEmpty(&s));
	//int count = StackCount(&s);
	//while (count--)
	//{
	//	printf("%d ",StackTop(&s));
	//	StackPop(&s);
	//}
	while (!StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	printf("%d ", StackEmpty(&s));
	

}

int main()
{
	Test();
	return 0;
}