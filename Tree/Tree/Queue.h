#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//���ǰ������
struct BinaryTreeNode;

//��struct BinaryTreeNode����ΪQDataType
typedef struct BinaryTreeNode* QDataType;

//�õ�������ʵ�ֶ���
//��������е�ÿһ���ڵ�QueueNode�ṹ��
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

//������������Queue�ṹ�壬����head,tail����ָ��QueueNode�ڵ��ָ����Э����������
typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;


void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);