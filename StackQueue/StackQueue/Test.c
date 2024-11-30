#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"
#include "Queue.h"

void StackTest()
{
	/*ST* s;
	StackInit(s);
	StackPush(s, 1);
	StackPush(s, 2);
	StackPush(s, 3);
	StackPush(s, 4);
	StackPush(s, 5);*/
	//这是一种错误写法，ST* s; 只有指针本身的内存被分配（通常是 4 或 8 字节，取决于系统架构），但 ST 所对应的结构体的内存空间并没有被分配
	//s 是一个指针，它的值是未初始化的垃圾值，如果尝试直接通过 s->a 或 s->b 操作，会导致未定义行为
	//要为结构体本身分配内存，需要显式地分配内存，有两种方法：1.使用动态分配 2.静态分配一个结构体变量后再赋值给结构体指针struct ST st;s = &st;
	//这条语句只是声明了一个类型为ST*的指针，相当于只给了你一张卡片，上面连门牌号都是随机的，或者理解为没有门牌号，并且还没有给你分配门牌号对应的房间。

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

void QueueTest()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}//遍历要符合队列先进先出的特性
}

int main()
{
	//StackTest();
	QueueTest();
	return 0;
}