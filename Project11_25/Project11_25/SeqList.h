#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define SeqDataType int

//#define MAX_SIZE 10

//��̬�汾�ṹ�壬�������˷ѿռ䣬��С�˿ռ䲻����
//typedef struct SeqList
//{
//	SeqDataType a[MAX_SIZE];
//	int size;
//}SL;

//��̬�ڴ��ṹ��
typedef struct SeqList
{
	SeqDataType* a;
	int size;
	int capacity;
}SL;

//��ʼ��
void SeqListInit(SL* ps);

//ͷ�� β�� ͷɾ βɾ 
void SeqListPushFront(SL* ps, SeqDataType x);
void SeqListPushBack(SL* ps, SeqDataType x);
void SeqListPopFront(SL* ps);
void SeqListPopBack(SL* ps);

//���±���� ���±�ɾ��
void SeqListInsert(SL* ps, SeqDataType x);
void SeqListErase(SL* ps);

//���� �޸�
int SeqListFind(SL* ps, SeqDataType x);
void SeqListModify(SL* ps, SeqDataType x, SeqDataType y);

//��ӡ
void SeqListPrint(SL* ps);

//�ͷſռ�
void SeqListDestory(SL* ps);