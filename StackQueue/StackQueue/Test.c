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
	//����һ�ִ���д����ST* s; ֻ��ָ�뱾����ڴ汻���䣨ͨ���� 4 �� 8 �ֽڣ�ȡ����ϵͳ�ܹ������� ST ����Ӧ�Ľṹ����ڴ�ռ䲢û�б�����
	//s ��һ��ָ�룬����ֵ��δ��ʼ��������ֵ���������ֱ��ͨ�� s->a �� s->b �������ᵼ��δ������Ϊ
	//ҪΪ�ṹ�屾������ڴ棬��Ҫ��ʽ�ط����ڴ棬�����ַ�����1.ʹ�ö�̬���� 2.��̬����һ���ṹ��������ٸ�ֵ���ṹ��ָ��struct ST st;s = &st;
	//�������ֻ��������һ������ΪST*��ָ�룬�൱��ֻ������һ�ſ�Ƭ�����������ƺŶ�������ģ��������Ϊû�����ƺţ����һ�û�и���������ƺŶ�Ӧ�ķ��䡣

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
	}//����Ҫ���϶����Ƚ��ȳ�������
}

int main()
{
	//StackTest();
	QueueTest();
	return 0;
}