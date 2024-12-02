#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//添加前置声明
struct BinaryTreeNode;

//将struct BinaryTreeNode定义为QDataType
typedef struct BinaryTreeNode* QDataType;

//用单向链表实现队列
//定义队列中的每一个节点QueueNode结构体
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

//定义整个队列Queue结构体，包含head,tail两个指向QueueNode节点的指针来协调整个队列
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