//labyrinthos.h

//头文件
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

//宏定义
#ifndef TURE
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define ERROR 0
#define OVERFLOW -1
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
#define MAX_MAZE_MAP_WIDTH	100
#define MAX_MAZE_MAP_HEIGHT	100
#define MAX_FILE_PATH_LENGTH 50
#endif

//结构体定义
typedef int Status;
typedef int ElemType;
typedef struct node{
	ElemType x;			//节点x坐标(实际点为所在行)
	ElemType y;			//节点y坐标(实际点为所在列)
}Node;

typedef struct stack{
	int stackSize;		//栈的当前大小
	int maxSize;		//栈的最大容量
	Node *base;			//栈底指针
	Node *top;			//栈顶指针
}Stack;

typedef struct maze{
	int width;			//迷宫的宽度
	int height;			//迷宫的高度
	int map[MAX_MAZE_MAP_WIDTH][MAX_MAZE_MAP_HEIGHT];		//迷宫地图的二维数组表示
	int flag[MAX_MAZE_MAP_WIDTH][MAX_MAZE_MAP_HEIGHT];		//记录点访问标记
	Node start;			//迷宫开始节点信息(入口)
	Node end;			//迷宫结束节点信息(出口)
}Maze;

typedef struct tortoise{
	int count;			//有效路径计数器
	Stack path;			//深搜路径
	Stack tempPath;		//路径暂存器
	Stack minPath;		//最短路径存储器
	Maze maze;			//地图
}Tortoise;

//函数声明
//Stack.c
void copy(Node *n1, Node *n2);
int StackInit(Stack *S);
int Top(Stack *S, Node *N); 
int Push(Stack *S, Node *N);
int PopElem(Stack *S, Node *N);
int Pop(Stack *S);
int StackLength(Stack *S);
int Clear(Stack *S);
//Maze.c
int MazeInit(Maze *M, int w, int h);
int MazeSetStartPoint(Maze *M,int x, int y);
int MazeSetEndPoint(Maze *M,int x, int y);
int MazeRead(Maze *M, char* filePath);
int MazeInput(Maze *M);
void show(Maze *M);
int in(Maze *M, Node *N);
int isWall(Maze *M, Node *N);
int past(Maze *M, Node *N);
//Tortoise.c
int TortoiseInit(Tortoise *T, Maze *m);
void craw(Tortoise *T, Node *N);
int showPath();
//Labyrinthos.c
int main();
int pane1();
int pane2();
int paneFun(Tortoise *T);
int pane1FunMaze1();
int pane1FunMaze2();
