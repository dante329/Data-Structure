#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdlib.h>

#define  SListDataType int

//�״�
//typedef struct SListNode
//{
//	SListDataType data;
//	struct SListNode* next;  // ʹ��������������
//} SLNode;
//�� C �У�typedef ���������ṹ�嶨�����֮�����Ч�ġ��ڽṹ���ڲ�����������ʹ������������������ struct SListNode��������������� SLNode��

struct SListNode
{
	SListDataType data;
	struct SListNode* next;
};

typedef struct SListNode SLNode;

//���ı������ͷָ�룬��һ��ָ��
void SListPrint(SLNode* phead);
//���ܻ�ı������ͷָ�룬������ָ��
void SListPushBack(SLNode** pphead, SListDataType x); 
void SListPushFront(SLNode** pphead, SListDataType x); 
void SListPopBack(SLNode** pphead);
void SListPopFront(SLNode** pphead);
SLNode* SListFind(SLNode* phead, SListDataType x);
void SListInsert(SLNode** pphead, SLNode* pos, SListDataType x);//pos����SListFind�ҵ���
void SListErase(SLNode** pphead, SLNode* pos);
