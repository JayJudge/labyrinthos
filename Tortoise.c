//Tortoise.c

//ͷ�ļ�
#include"labyrinthos.h"

//�ڹ��ʼ��
int TortoiseInit(Tortoise *T,Maze *m){
	T->maze = *m;
	T->count=0;

	StackInit(&(T->path));
	StackInit(&(T->tempPath));
	StackInit(&(T->minPath));
}
//�ڹ����Թ�(�����������)
void craw(Tortoise *T, Node *N){
	int dirx[] = {0,1,0,-1};	//��һ�ڵ��뵱ǰ�ڵ������
	int diry[] = {1,0,-1,0};	//˳��Ϊ���ң��£�����
	Node current = *N;			//��ǰ�ڵ�
	Node next;					//��һ�ڵ�
	Node p;
	//��ʱ�����ڵ�
	if(current.x == T->maze.end.x && current.y == T->maze.end.y){
	//��һ�ڵ�����յ㣬������ɣ�·����Ч
		if(StackLength(&T->path) < StackLength(&T->minPath) || T->count==0){
		//������·������С����С·�����Ȼ���Ϊ��һ��·��ʱ
			Clear(&T->minPath);
			//�����С·��
			while(StackLength(&T->path)){
				PopElem(&T->path,&p);
				Push(&T->tempPath,&p);
				Push(&T->minPath,&p);
			}
			//��������С·������յ�ǰ·��(ͬʱ��������ʱ·������������)
			while(StackLength(&T->tempPath)){
				PopElem(&T->tempPath,&p);
				Push(&T->path,&p);
			}
			//����ʱ·�������ص�ǰ·��������
		}
		T->count++;
		//��¼��Ч·����
		return ;
	}
	if(!in(&T->maze,&current))
		return;
	//��ǰ�ڵ㳬����ͼ��Χ����������
	for(int i=0;i<4;i++){
		next.x = current.x + dirx[i];
		next.y = current.y + diry[i];
		if((!isWall(&T->maze,&next))&&(!past(&T->maze,&next))){
		//�����������ڵ�δ�������Ҳ��ڵ�ͼ��
			T->maze.flag[next.x][next.y]=1;
			Push(&T->path,&next);
			//�½ڵ�ѹ�뵱ǰ·��ջ
			craw(T,&next);
			//�ݹ�����
			Pop(&T->path);
			T->maze.flag[next.x][next.y]=0;
			//����״̬������
		}
	}
	return;
}
//��ʾ�ڹ�������·��
int showPath(Tortoise *T){
	Node temp;
	//��ʱ�����ڵ�
	if(T->count==0){
	//û����Ч·��
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
