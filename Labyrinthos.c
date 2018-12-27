//Labyrinthos.c
//����������

//ͷ�ļ�
#include"labyrinthos.h"

int paneFun(Tortoise *T){
	int choice;
	Node p;
	//��ʱ�����ڵ�
	printf("**********Maze*********\n");
	printf("1:Show the path\n");				//��ʾ·������ֵ����ʽ
	printf("2:Show the crawed maze\n");			//��ʾ·����������ʽ
	printf("3:Back to last pane\n");			//������һ�˵�
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice){
		case 1:{
			system("cls");
			showPath(T);
			paneFun(T);
			break;
			}
		case 2:{
			system("cls");
			Clear(&T->tempPath);
			while(StackLength(&T->minPath)){
				PopElem(&T->minPath,&p);
				Push(&T->tempPath,&p);
				T->maze.map[p.x][p.y]=2;
			}
			while(StackLength(&T->tempPath)){
				PopElem(&T->tempPath,&p);
				Push(&T->minPath,&p);
			}
			//·����ԭ
			T->maze.map[T->maze.start.x][T->maze.start.y]=5;	//��ڻ�ԭ
			T->maze.map[T->maze.end.x][T->maze.end.y]=5;		//���ڻ�ԭ
			show(&T->maze);
			paneFun(T);
			break;
			}
		case 3:{
			system("cls");
			pane1();
			}
		default:{
			printf("Please enter the right choice\n");
			Sleep(1000);
			system("cls");
			paneFun(T);
			}
	
	}
	return 0;
}
//�ļ��Թ�1
int pane1FunMaze1(){
	system("cls");
	printf("**********Maze*********\n");
	FILE fp;
	char* filePath = "maze1.txt";			
	//���·��
	Maze maze;
	Tortoise toto;
	
	MazeInit(&maze,10,10);
	MazeSetStartPoint(&maze,1,1);
	MazeSetEndPoint(&maze,8,8);
	MazeRead(&maze,filePath);
	//�Թ���ʼ��
	printf("This is the maze from : maze1.txt\n");
	show(&maze);
	//��ʾ�Թ�
	TortoiseInit(&toto,&maze);
	toto.maze.flag[toto.maze.start.x][toto.maze.start.y]=1;
	Push(&toto.path,&toto.maze.start);
	//׼������
	craw(&toto,&toto.maze.start);
	//����
	paneFun(&toto);
	//���ö����˵��Ӳ˵�
	return 0;
}
//�ļ��Թ�2
int pane1FunMaze2(){
	
	FILE fp;
	char* filePath = "maze2.txt";
	//���·��
	Maze maze;
	Tortoise toto;

	system("cls");
	printf("**********Maze*********\n");
	MazeInit(&maze,22,22);
	MazeSetStartPoint(&maze,20,0);
	MazeSetEndPoint(&maze,0,20);
	MazeRead(&maze,filePath);
	//�Թ���ʼ��
	printf("This is the maze from : maze2.txt\n");
	show(&maze);
	TortoiseInit(&toto,&maze);
	toto.maze.flag[toto.maze.start.x][toto.maze.start.y]=1;
	Push(&toto.path,&toto.maze.start);
	//׼������
	craw(&toto,&toto.maze.start);
	//����
	paneFun(&toto);
	return 0;
	//���ö����˵��Ӳ˵�
}
//�����˵�1
int pane1(){
	
	int choice;

	system("cls");
	printf("**********Maze*********\n");
	printf("1:Read from maze1.txt\n");
	printf("2:Read from maze2.txt\n");
	printf("3:Back to main pane\n");
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice){
		case 1:{
			pane1FunMaze1();
			break;
		}
		case 2:{	
			pane1FunMaze2();
			break;
		}
		case 3:{
			system("cls");
			main();
		}
		default:{
			printf("Please enter the right choice\n");
			Sleep(1000);
			pane1();
		}
	}
	return 0;
}
//�����˵�2
int pane2(){
	
	Maze maze;
	Tortoise toto;			
	
	system("cls");
	printf("**********Maze*********\n");
	MazeInput(&maze);		//�����Թ�
	Sleep(500);
	system("cls");
	printf("**********Maze*********\n");
	printf("This is the maze you entered:\n");
	show(&maze);			//��ʾ�����Թ�
			
	TortoiseInit(&toto,&maze);
	toto.maze.flag[1][1]=1;		//������
	Push(&toto.path,&toto.maze.start);//���ѹ�뵱ǰջ
	craw(&toto,&toto.maze.start);
	paneFun(&toto);				//���ö����˵��Ӳ˵�
	return 0;
}

//������˵�(һ���˵�)
int main(){
	int choice;
	system("cls");		//����
	printf("**********Maze*********\n");
	printf("1:Choose a maze from file\n");
	printf("2:Enter your own maze\n");
	printf("3:Exit\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:pane1();break;
		case 2:pane2();break;
		case 3:exit(1);
		default:{
			printf("Please enter the right choice\n");
			Sleep(1000);
			main();
		}
	}
	return 0;
}
