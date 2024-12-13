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
    //检查扩容
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
            ps->capacity *= 2; //StackPush扩容后未更新capacity 12_13已修改
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
    //判断是否走到出口
    if (cur.row == N - 1 && cur.col == M - 1) {
        return true;
    }
    Pos next;
    //将走过的地方改成2，防止下一步走回去了
    maze[cur.row][cur.col] = 2;

    //上
    next = cur;
    next.row -= 1;
    if (IsPass(maze, N, M, next)) {
        if (GetPath(maze, N, M, next))
            return true;//如果进到这了就说明找到出口了，那么在递归回溯过程中就不需要去找它的其他方向了，所以要在这加return拦截
    }
    //下
    next = cur;
    next.row += 1;
    if (IsPass(maze, N, M, next)) {
        if (GetPath(maze, N, M, next))
            return true;
    }
    //左
    next = cur;
    next.col -= 1;
    if (IsPass(maze, N, M, next)) {
        if (GetPath(maze, N, M, next))
            return true;
    }
    //右
    next = cur;
    next.col += 1;
    if (IsPass(maze, N, M, next)) {
        if (GetPath(maze, N, M, next))
            return true;
    }
    //走到这来了说明这个点是走不通的，就要弹栈
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

    //输出rPath中的内容
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
        //创建迷宫
        int** maze = MazeCreat(N, M);
        
        //接受迷宫内数据
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                scanf("%d", &maze[i][j]);
            }
        }
        //初始化全局变量
        StackInit(&path);
        //探索路线
        Pos entry = { 0,0 };
        if (GetPath(maze, N, M, entry))
        {
            PrintPath(&path);
        }
        else
        {
            printf("找不到通路\n");
        }
        StackDestory(&path);
        //销毁
        MazeDestory(maze, N, M);
        
    }
    return 0;
} 

//更换了正确的栈结构之后是对的
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
//// 入栈
//void StackPush(ST* ps, STDataType x);
//// 出栈
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
//// 入栈
//void StackPush(ST* ps, STDataType x)
//{
//    assert(ps);
//
//    // 满了-》增容
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
//// 出栈
//void StackPop(ST* ps)
//{
//    assert(ps);
//    // 栈空了，调用Pop，直接中止程序报错
//    assert(ps->top > 0);
//
//    //ps->a[ps->top - 1] = 0;
//    ps->top--;
//}
//
//STDataType StackTop(ST* ps)
//{
//    assert(ps);
//    // 栈空了，调用Top，直接中止程序报错
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
//    //判断是否走到出口
//    if (cur.row == N - 1 && cur.col == M - 1) {
//        return true;
//    }
//    Pos next;
//    //将走过的地方改成2，防止下一步走回去了
//    maze[cur.row][cur.col] = 2;
//
//    //上
//    next = cur;
//    next.row -= 1;
//    if (IsPass(maze, N, M, next)) {
//        if (GetPath(maze, N, M, next))
//            return true;//如果进到这了就说明找到出口了，那么在递归回溯过程中就不需要去找它的其他方向了，所以要在这加return拦截
//    }
//    //下
//    next = cur;
//    next.row += 1;
//    if (IsPass(maze, N, M, next)) {
//        if (GetPath(maze, N, M, next))
//            return true;
//    }
//    //左
//    next = cur;
//    next.col -= 1;
//    if (IsPass(maze, N, M, next)) {
//        if (GetPath(maze, N, M, next))
//            return true;
//    }
//    //右
//    next = cur;
//    next.col += 1;
//    if (IsPass(maze, N, M, next)) {
//        if (GetPath(maze, N, M, next))
//            return true;
//    }
//    //走到这来了说明这个点是走不通的，就要弹栈
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
//    //输出rPath中的内容
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
//    while (scanf("%d %d", &N, &M) != EOF) { // 注意 while 处理多个 case
//        //创建迷宫
//        //int** maze = MazeCreat(N, M);
//        int** maze = (int**)malloc(sizeof(int*) * N);
//        for (int i = 0; i < N; ++i) {
//            maze[i] = (int*)malloc(sizeof(int) * M);
//        }
//        //接受迷宫内数据
//        for (int i = 0; i < N; ++i)
//        {
//            for (int j = 0; j < M; ++j)
//            {
//                scanf("%d", &maze[i][j]);
//            }
//        }
//        //初始化全局变量
//        StackInit(&path);
//        //探索路线
//        Pos entry = { 0,0 };
//        if (GetPath(maze, N, M, entry))
//        {
//            PrintPath(&path);
//        }
//        else
//        {
//            printf("找不到通路\n");
//        }
//        StackDestory(&path);
//        //销毁
//        //MazeDestory(maze, N, M);
//        for (int i = 0; i < N; ++i) {
//            free(maze[i]);
//        }
//        free(maze);
//        maze = NULL;
//    }
//    return 0;
//}