//labyrinthos.h

//ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

//�궨��
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

//�ṹ�嶨��
typedef int Status;
typedef int ElemType;
typedef struct node{
	ElemType x;			//�ڵ�x����(ʵ�ʵ�Ϊ������)
	ElemType y;			//�ڵ�y����(ʵ�ʵ�Ϊ������)
}Node;

typedef struct stack{
	int stackSize;		//ջ�ĵ�ǰ��С
	int maxSize;		//ջ���������
	Node *base;			//ջ��ָ��
	Node *top;			//ջ��ָ��
}Stack;

typedef struct maze{
	int width;			//�Թ��Ŀ��
	int height;			//�Թ��ĸ߶�
	int map[MAX_MAZE_MAP_WIDTH][MAX_MAZE_MAP_HEIGHT];		//�Թ���ͼ�Ķ�ά�����ʾ
	int flag[MAX_MAZE_MAP_WIDTH][MAX_MAZE_MAP_HEIGHT];		//��¼����ʱ��
	Node start;			//�Թ���ʼ�ڵ���Ϣ(���)
	Node end;			//�Թ������ڵ���Ϣ(����)
}Maze;

typedef struct tortoise{
	int count;			//��Ч·��������
	Stack path;			//����·��
	Stack tempPath;		//·���ݴ���
	Stack minPath;		//���·���洢��
	Maze maze;			//��ͼ
}Tortoise;

//��������
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
