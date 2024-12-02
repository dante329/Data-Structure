#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

#define BTDataType int

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;


//�������򣬺���
void PreOrder(BTNode* root)
{
	if (root == NULL)
		return 0;
	printf("%c ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
		return 0;
	PreOrder(root->left);
	printf("%c ", root->data); 
	PreOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
		return 0;
	PreOrder(root->left);
	PreOrder(root->right);
	printf("%c ", root->data);
}

//��ڵ����
//1.����ȫ�ֱ���size = 0 �ں����ڷ���szie++�����ƽڵ������ͳ�ƣ����ǵڶ��ε���ǰδ��ʱ��0������ۼӴ��󣬻��߶��̼߳���ʱ�޷���Чͳ��
//int size = 0;
//void TreeSize(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	else
//	{
//		size++;
//	}
//	TreeSize(root->left);
//	TreeSize(root->right);
//}

//2.�ں����ⶨ��int size = 0 ����size�ĵ�ַ��������
//int TreeSize(BTNode* root,int* size)
//{
//	if (root == NULL)
//	{
//		return *size;
//	}
//	else
//	{
//		(*size)++;
//	}	
//	TreeSize(root->left,size);
//	TreeSize(root->right,size);
//}

//3.����˼�룬����˼�룬��ͳ�ƽڵ��ܸ����Ĳ������� ������ �� ������ �ټ��� �Լ�
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//��Ҷ�ӽڵ����
int TreeLeafSize(BTNode* root)
{
	return (root->left == NULL) && (root->right == NULL) ? 1 : TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//�������
/*
ǰ������������Ҳ�� ������ȱ���
�������Ҳ�� ������ȱ���

�����ö����Ƚ��ȳ�������ʵ�ֲ������
����˼�룺��һ�����һ�� ��һ��ĵ�һ���ڵ�����е�ʱ��������ӽڵ����һ�����
*/
void LevelOrder(BTNode* root)
{
	Queue pq;
	QueueInit(&pq);
	if (root)
	{
		QueuePush(&pq, root);
	}
	while (!QueueEmpty(&pq))
	{
		BTNode* front = QueueFront(&pq);
		QueuePop(&pq);
		printf("%c ", front->data);
		if (front->left)
		{
			QueuePush(&pq,front->left);
		}
		if (front->right)
		{
			QueuePush(&pq, front->right);
		}
	}
	QueueDestory(&pq);
	printf("\n");
}
int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	PreOrder(A);
	printf("\n");

	int asize = 0;
	printf("%d \n", TreeSize(A));
	printf("%d \n", TreeLeafSize(A));
	LevelOrder(A);
	return 0;
}