//Tortoise.c

//头文件
#include"labyrinthos.h"

//乌龟初始化
int TortoiseInit(Tortoise *T,Maze *m){
	T->maze = *m;
	T->count=0;

	StackInit(&(T->path));
	StackInit(&(T->tempPath));
	StackInit(&(T->minPath));
}
//乌龟爬迷宫(深度优先搜索)
void craw(Tortoise *T, Node *N){
	int dirx[] = {0,1,0,-1};	//下一节点与当前节点坐标差
	int diry[] = {1,0,-1,0};	//顺序为下右，下，左，上
	Node current = *N;			//当前节点
	Node next;					//下一节点
	Node p;
	//临时工作节点
	if(current.x == T->maze.end.x && current.y == T->maze.end.y){
	//下一节点等于终点，搜索完成，路径有效
		if(StackLength(&T->path) < StackLength(&T->minPath) || T->count==0){
		//当搜索路径长度小于最小路径长度或者为第一条路径时
			Clear(&T->minPath);
			//清空最小路径
			while(StackLength(&T->path)){
				PopElem(&T->path,&p);
				Push(&T->tempPath,&p);
				Push(&T->minPath,&p);
			}
			//拷贝至最小路径，清空当前路径(同时拷贝到临时路径，用作回溯)
			while(StackLength(&T->tempPath)){
				PopElem(&T->tempPath,&p);
				Push(&T->path,&p);
			}
			//将临时路径拷贝回当前路径，回溯
		}
		T->count++;
		//记录有效路径数
		return ;
	}
	if(!in(&T->maze,&current))
		return;
	//当前节点超出地图范围，放弃搜索
	for(int i=0;i<4;i++){
		next.x = current.x + dirx[i];
		next.y = current.y + diry[i];
		if((!isWall(&T->maze,&next))&&(!past(&T->maze,&next))){
		//搜索条件，节点未被访问且不在地图外
			T->maze.flag[next.x][next.y]=1;
			Push(&T->path,&next);
			//新节点压入当前路径栈
			craw(T,&next);
			//递归深搜
			Pop(&T->path);
			T->maze.flag[next.x][next.y]=0;
			//返回状态，回溯
		}
	}
	return;
}
//显示乌龟爬过的路径
int showPath(Tortoise *T){
	Node temp;
	//临时工作节点
	if(T->count==0){
	//没有有效路径
		printf("This maze has no way to solve\n");	
		return 0;
	}
	printf("There are %d ways to solove this maze\n",T->count);
	printf("The shortest path to solve the maze is :\n");

	while(StackLength(&T->minPath)){
		PopElem(&T->minPath,&temp);
		Push(&T->tempPath,&temp);
		printf("(%d,%d)\n",temp.y,temp.x);
	}
	while(StackLength(&T->tempPath)){
		PopElem(&T->tempPath,&temp);
		Push(&T->minPath,&temp);
	}
}
