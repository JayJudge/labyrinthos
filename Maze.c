//Maze.c

//ͷ�ļ�
#include"labyrinthos.h"

//�Թ���ͼ��С��ʼ��
int MazeInit(Maze *M, int w, int h){
	M->width = w;
	M->height=h;
	for(int i=0;i<M->height;i++){
		for(int j=0;j<M->width;j++)
			M->flag[i][j]=0;
	}
	return SUCCESS;
}
//�Թ���ͼ�������
int MazeSetStartPoint(Maze*M,int x,int y){
		M->start.x = x;
		M->start.y = y;
		return SUCCESS;
}
//�Թ���ͼ�յ�����
int MazeSetEndPoint(Maze*M,int x,int y){
		M->end.x = x;
		M->end.y = y;
		return SUCCESS;
}
//�ļ���ȡ�Թ�
int MazeRead(Maze *M, char* filePath){
	FILE* fp;
	fp = fopen(filePath,"rb");		//�������ļ�
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
//�����Թ�
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
//��ʾ�Թ���ͼ
void show(Maze *M){
	for(int i=0;i<M->width;i++){
		for(int j=0;j<M->height;j++){
			if(M->map[i][j]==2)			//�õ�Ϊ·��
				printf("%2d",2);
			else if(i==M->start.x&&j==M->start.y||
				i==M->end.x&&j==M->end.y)//�õ�Ϊ���ڻ����
				printf("%2d",5);
			else
				printf("%2d",M->map[i][j]);
		}
		printf("\n");
	}
}
//�жϽڵ��Ƿ����Թ���
int in(Maze *M, Node *N){
	if(N->x>=0&&N->x<M->height&&N->y>=0&&N->y<M->width)
		return TRUE;
	return FALSE;
}
//�жϽڵ��Ƿ�Ϊ�Թ�ǽ��
int isWall(Maze *M, Node *N){
	if(M->map[N->x][N->y]==1)
		return TRUE;
	return FALSE;
}
//�жϽڵ��Ƿ������
int past(Maze *M, Node *N){
	if(M->flag[N->x][N->y]==1)
		return TRUE;
	return FALSE;
}
