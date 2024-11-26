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
void SlistPrint(SLNode* phead);
//���ܻ�ı������ͷָ�룬������ָ��
void SlistPushBack(SLNode** pphead, SListDataType x); 
void SlistPushFront(SLNode** pphead, SListDataType x); 
void SlistPopBack(SLNode** pphead);
void SlistPopFront(SLNode** pphead);
SLNode* SlistFind(SLNode* phead, SListDataType x);
void SlistInsert(SLNode** pphead, SLNode* pos, SListDataType x);//pos����SlistFind�ҵ���
void SlistErase(SLNode** pphead, SLNode* pos);
