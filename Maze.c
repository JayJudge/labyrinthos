//Maze.c

//头文件
#include"labyrinthos.h"

//迷宫地图大小初始化
int MazeInit(Maze *M, int w, int h){
	M->width = w;
	M->height=h;
	for(int i=0;i<M->height;i++){
		for(int j=0;j<M->width;j++)
			M->flag[i][j]=0;
	}
	return SUCCESS;
}
//迷宫地图起点设置
int MazeSetStartPoint(Maze*M,int x,int y){
		M->start.x = x;
		M->start.y = y;
		return SUCCESS;
}
//迷宫地图终点设置
int MazeSetEndPoint(Maze*M,int x,int y){
		M->end.x = x;
		M->end.y = y;
		return SUCCESS;
}
//文件读取迷宫
int MazeRead(Maze *M, char* filePath){
	FILE* fp;
	fp = fopen(filePath,"rb");		//二进制文件
	if(fp==NULL){
		printf("No such file or directory:%s\n",filePath);
	}
	else{
		for(int i=0;i<M->height;i++){
			fread(&M->map[i],M->height*sizeof(int),1,fp);
		}
		fclose(fp);
	}
}
//输入迷宫
int MazeInput(Maze *M){
	printf("Please enter thr size of maze:\n");
	scanf("%d%d",&M->height,&M->width);
	printf("Please enter the elem of maze:\n");
	for(int i=0;i<M->height;i++){
		for(int j=0;j<M->width;j++)
			scanf("%d",&M->map[i][j]);
	}
	printf("Please enter the start point:\n");
	scanf("%d%d",&M->start.x,&M->start.y);
	printf("Please enter the end point:\n");
	scanf("%d%d",&M->end.x,&M->end.y);
}
//显示迷宫地图
void show(Maze *M){
	for(int i=0;i<M->width;i++){
		for(int j=0;j<M->height;j++){
			if(M->map[i][j]==2)			//该点为路径
				printf("%2d",2);
			else if(i==M->start.x&&j==M->start.y||
				i==M->end.x&&j==M->end.y)//该点为出口或入口
				printf("%2d",5);
			else
				printf("%2d",M->map[i][j]);
		}
		printf("\n");
	}
}
//判断节点是否在迷宫内
int in(Maze *M, Node *N){
	if(N->x>=0&&N->x<M->height&&N->y>=0&&N->y<M->width)
		return TRUE;
	return FALSE;
}
//判断节点是否为迷宫墙壁
int isWall(Maze *M, Node *N){
	if(M->map[N->x][N->y]==1)
		return TRUE;
	return FALSE;
}
//判断节点是否浏览过
int past(Maze *M, Node *N){
	if(M->flag[N->x][N->y]==1)
		return TRUE;
	return FALSE;
}
