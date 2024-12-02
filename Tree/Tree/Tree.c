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


//先序，中序，后序
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

//求节点个数
//1.定义全局变量size = 0 在函数内访问szie++来控制节点个数的统计，但是第二次调用前未及时置0会造成累加错误，或者多线程计算时无法有效统计
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

//2.在函数外定义int size = 0 传入size的地址到函数中
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

//3.分治思想，后序思想，将统计节点总个数的操作交给 左子树 和 右子树 再加上 自己
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

//求叶子节点个数
int TreeLeafSize(BTNode* root)
{
	return (root->left == NULL) && (root->right == NULL) ? 1 : TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

//层序遍历
/*
前序中序后序遍历也叫 深度优先遍历
层序遍历也叫 广度优先遍历

这里用队列先进先出的特性实现层序遍历
核心思想：上一层带下一层 上一层的第一个节点出队列的时候带他的子节点进下一层队列
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