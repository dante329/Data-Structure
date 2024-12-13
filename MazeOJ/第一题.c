#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Position {
    int row;
    int col;
} Pos;

/////////////////////////////////////////////////////////
#define StackDataType Pos

typedef struct Stack {
    StackDataType* data;
    int top;
    int capacity;
} ST;

void StackInit(ST* ps);
void StackPush(ST* ps, StackDataType x);
void StackPop(ST* ps);
StackDataType StackTop(ST* ps);
int StackCount(ST* ps);
bool StackEmpty(ST* ps);
void StackDestory(ST* ps);
int StackSize(ST* ps);

void StackInit(ST* ps)
{
    ps->data = (StackDataType*)calloc(4, sizeof(StackDataType));
    ps->top = 0;
    ps->capacity = 4;
}

void StackPush(ST* ps, StackDataType x)
{
    assert(ps);
    //�������
    if (ps->top == ps->capacity)
    {
        StackDataType* tmp = realloc(ps->data, 2 * ps->capacity * sizeof(StackDataType));
        if (tmp == NULL)
        {
            perror("ps->data realloc fail");
            exit(-1);
        }
        else
        {
            ps->data = tmp;
            ps->capacity *= 2; //StackPush���ݺ�δ����capacity 12_13���޸�
        }
    }
    ps->data[ps->top] = x;
    ps->top++;
}

void StackPop(ST* ps)
{
    assert(ps);
    assert(ps->top > 0);
    ps->top--;
}

StackDataType StackTop(ST* ps)
{
    assert(ps);
    return ps->data[ps->top - 1];
}

int StackCount(ST* ps)
{
    assert(ps);
    return ps->top;
}

bool StackEmpty(ST* ps)
{
    assert(ps);
    return ps->top == 0;
}

int StackSize(ST* ps)
{
    return ps->top;
}

void StackDestory(ST* ps)
{
    assert(ps);
    free(ps->data);
    ps->data = NULL;
    ps->capacity = 0;
    ps->top = 0;
}
/////////////////////////////////////////////////////////

int** MazeCreat(int N, int M) {
    int** maze = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; ++i) {
        maze[i] = (int*)malloc(sizeof(int) * M);
    }
    return maze;
}

void MazeDestory(int** maze, int N, int M) {
    for (int i = 0; i < N; ++i) {
        free(maze[i]);
    }
    free(maze);
    maze = NULL;
}

bool IsPass(int** maze, int N, int M, Pos next) {
    return next.row >= 0 && next.row < N 
        && next.col >= 0 && next.col < M
        && maze[next.row][next.col] == 0;
}


ST path;
bool GetPath(int** maze, int N, int M, Pos cur) 
{
    StackPush(&path, cur);
    //�ж��Ƿ��ߵ�����
    if (cur.row == N - 1 && cur.col == M - 1) {
        return true;
    }
    Pos next;
    //���߹��ĵط��ĳ�2����ֹ��һ���߻�ȥ��
    maze[cur.row][cur.col] = 2;

    //��
    next = cur;
    next.row -= 1;
    if (IsPass(maze, N, M, next)) {
        if (GetPath(maze, N, M, next))
            return true;//����������˾�˵���ҵ������ˣ���ô�ڵݹ���ݹ����оͲ���Ҫȥ���������������ˣ�����Ҫ�����return����
    }
    //��
    next = cur;
    next.row += 1;
    if (IsPass(maze, N, M, next)) {
        if (GetPath(maze, N, M, next))
            return true;
    }
    //��
    next = cur;
    next.col -= 1;
    if (IsPass(maze, N, M, next)) {
        if (GetPath(maze, N, M, next))
            return true;
    }
    //��
    next = cur;
    next.col += 1;
    if (IsPass(maze, N, M, next)) {
        if (GetPath(maze, N, M, next))
            return true;
    }
    //�ߵ�������˵����������߲�ͨ�ģ���Ҫ��ջ
    StackPop(&path);
    return false;
}

void PrintPath(ST* ps)
{
    //StackReverse
    ST rPath;
    StackInit(&rPath);
    while (!StackEmpty(ps))
    {
        StackPush(&rPath, StackTop(ps));
        StackPop(ps);
    }

    //���rPath�е�����
    while (!StackEmpty(&rPath))
    {
        printf("(%d,%d)\n", StackTop(&rPath).row, StackTop(&rPath).col);
        StackPop(&rPath);
    }

    StackDestory(&rPath);

}

int main() 
{
    int N, M;
    while (scanf("%d %d", &N, &M) != EOF) 
    { 
        //�����Թ�
        int** maze = MazeCreat(N, M);
        
        //�����Թ�������
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                scanf("%d", &maze[i][j]);
            }
        }
        //��ʼ��ȫ�ֱ���
        StackInit(&path);
        //̽��·��
        Pos entry = { 0,0 };
        if (GetPath(maze, N, M, entry))
        {
            PrintPath(&path);
        }
        else
        {
            printf("�Ҳ���ͨ·\n");
        }
        StackDestory(&path);
        //����
        MazeDestory(maze, N, M);
        
    }
    return 0;
} 

//��������ȷ��ջ�ṹ֮���ǶԵ�
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <assert.h>
//
//typedef struct Postion
//{
//    int row;
//    int col;
//}Pos;
///////////////////////////////////////////////////////////////////
//typedef Pos STDataType;
//
//typedef struct Stack
//{
//    STDataType* a;
//    int top;
//    int capacity;
//}ST,Stack;
//
//void StackInit(ST* ps);
//void StackDestory(ST* ps);
//// ��ջ
//void StackPush(ST* ps, STDataType x);
//// ��ջ
//void StackPop(ST* ps);
//STDataType StackTop(ST* ps);
//
//int StackSize(ST* ps);
//bool StackEmpty(ST* ps);
//
//void StackInit(ST* ps)
//{
//    assert(ps);
//
//    ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
//    if (ps->a == NULL)
//    {
//        printf("malloc fail\n");
//        exit(-1);
//    }
//
//    ps->capacity = 4;
//    ps->top = 0;
//}
//
//void StackDestory(ST* ps)
//{
//    assert(ps);
//    free(ps->a);
//    ps->a = NULL;
//    ps->top = ps->capacity = 0;
//}
//
//// ��ջ
//void StackPush(ST* ps, STDataType x)
//{
//    assert(ps);
//
//    // ����-������
//    if (ps->top == ps->capacity)
//    {
//        STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
//        if (tmp == NULL)
//        {
//            printf("realloc fail\n");
//            exit(-1);
//        }
//        else
//        {
//            ps->a = tmp;
//            ps->capacity *= 2;
//        }
//    }
//
//    ps->a[ps->top] = x;
//    ps->top++;
//}
//
//// ��ջ
//void StackPop(ST* ps)
//{
//    assert(ps);
//    // ջ���ˣ�����Pop��ֱ����ֹ���򱨴�
//    assert(ps->top > 0);
//
//    //ps->a[ps->top - 1] = 0;
//    ps->top--;
//}
//
//STDataType StackTop(ST* ps)
//{
//    assert(ps);
//    // ջ���ˣ�����Top��ֱ����ֹ���򱨴�
//    assert(ps->top > 0);
//
//    return ps->a[ps->top - 1];
//}
//
//int StackSize(ST* ps)
//{
//    assert(ps);
//
//    return ps->top;
//}
//
//bool StackEmpty(ST* ps)
//{
//    assert(ps);
//
//    return ps->top == 0;
//}
//
//Stack path;
///////////////////////////////////////////////////////////
//
////int** MazeCreat(int N, int M) {
////    int** maze = (int**)malloc(sizeof(int*) * N);
////    for (int i = 0; i < N; ++i) {
////        maze[i] = (int*)malloc(sizeof(int) * M);
////    }
////    return maze;
////}
//
////void MazeDestory(int** maze, int N, int M) {
////    for (int i = 0; i < N; ++i) {
////        free(maze[i]);
////    }
////    free(maze);
////    maze = NULL;
////}
//
//bool IsPass(int** maze, int N, int M, Pos next) {
//    return next.row >= 0 && next.row < N
//        && next.col >= 0 && next.col < M
//        && maze[next.row][next.col] == 0;
//}
//
//
//ST path;
//bool GetPath(int** maze, int N, int M, Pos cur)
//{
//    StackPush(&path, cur);
//    //�ж��Ƿ��ߵ�����
//    if (cur.row == N - 1 && cur.col == M - 1) {
//        return true;
//    }
//    Pos next;
//    //���߹��ĵط��ĳ�2����ֹ��һ���߻�ȥ��
//    maze[cur.row][cur.col] = 2;
//
//    //��
//    next = cur;
//    next.row -= 1;
//    if (IsPass(maze, N, M, next)) {
//        if (GetPath(maze, N, M, next))
//            return true;//����������˾�˵���ҵ������ˣ���ô�ڵݹ���ݹ����оͲ���Ҫȥ���������������ˣ�����Ҫ�����return����
//    }
//    //��
//    next = cur;
//    next.row += 1;
//    if (IsPass(maze, N, M, next)) {
//        if (GetPath(maze, N, M, next))
//            return true;
//    }
//    //��
//    next = cur;
//    next.col -= 1;
//    if (IsPass(maze, N, M, next)) {
//        if (GetPath(maze, N, M, next))
//            return true;
//    }
//    //��
//    next = cur;
//    next.col += 1;
//    if (IsPass(maze, N, M, next)) {
//        if (GetPath(maze, N, M, next))
//            return true;
//    }
//    //�ߵ�������˵����������߲�ͨ�ģ���Ҫ��ջ
//    StackPop(&path);
//    return false;
//}
//
//void PrintPath(ST* ps)
//{
//    //StackReverse
//    ST rPath;
//    StackInit(&rPath);
//    while (!StackEmpty(ps))
//    {
//        StackPush(&rPath, StackTop(ps));
//        StackPop(ps);
//    }
//
//    //���rPath�е�����
//    while (!StackEmpty(&rPath))
//    {
//        printf("(%d,%d)\n", StackTop(&rPath).row, StackTop(&rPath).col);
//        StackPop(&rPath);
//    }
//
//    StackDestory(&rPath);
//
//}
//
//int main() {
//    int N, M;
//    while (scanf("%d %d", &N, &M) != EOF) { // ע�� while ������ case
//        //�����Թ�
//        //int** maze = MazeCreat(N, M);
//        int** maze = (int**)malloc(sizeof(int*) * N);
//        for (int i = 0; i < N; ++i) {
//            maze[i] = (int*)malloc(sizeof(int) * M);
//        }
//        //�����Թ�������
//        for (int i = 0; i < N; ++i)
//        {
//            for (int j = 0; j < M; ++j)
//            {
//                scanf("%d", &maze[i][j]);
//            }
//        }
//        //��ʼ��ȫ�ֱ���
//        StackInit(&path);
//        //̽��·��
//        Pos entry = { 0,0 };
//        if (GetPath(maze, N, M, entry))
//        {
//            PrintPath(&path);
//        }
//        else
//        {
//            printf("�Ҳ���ͨ·\n");
//        }
//        StackDestory(&path);
//        //����
//        //MazeDestory(maze, N, M);
//        for (int i = 0; i < N; ++i) {
//            free(maze[i]);
//        }
//        free(maze);
//        maze = NULL;
//    }
//    return 0;
//}