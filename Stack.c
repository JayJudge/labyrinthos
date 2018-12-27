//Stack.c

//头文件
#include"labyrinthos.h"
//n2 = n1 节点拷贝
void copy(Node* n1, Node *n2){
	n2->x = n1->x;
	n2->y = n1->y;
}

//栈初始化
Status StackInit(Stack *S){
	S->base = (Node*)malloc(STACK_INIT_SIZE * sizeof(Node));
	if(!S->base)exit(OVERFLOW);		//内存溢出
	S->top = S->base;
	S->maxSize=STACK_INIT_SIZE;
	S->stackSize = 0;
	return SUCCESS;
}
//返回栈顶元素
Status Top(Stack *S, Node *N){
	if(S->top==S->base)			//空栈
		return ERROR;
	N->x = (*(S->top)).x;
	N->y = (*(S->top)).y;
	return SUCCESS;
}
//压栈
Status Push(Stack *S, Node *N){
	if(S->top - S->base >= S->maxSize){		//最大内存不足
		S->base = (Node*)realloc(S->base,(S->maxSize+ STACK_INCREMENT) * sizeof(Node));
		if(!S->base)exit(OVERFLOW);	//内存溢出
		S->top = S->base + S->stackSize;
		S->maxSize += STACK_INCREMENT;
	}
	(*(S->top)).x = N->x;
	(*(S->top)).y = N->y;
	
	S->top++;
	S->stackSize++;
	return SUCCESS;
}
//出栈
Status PopElem(Stack *S, Node *N){
	if(S->top==S->base)		//空栈
		return ERROR;
	S->top--;
	N->x = (*(S->top)).x;
	N->y = (*(S->top)).y;

	S->stackSize--;
	return SUCCESS;
}
//出栈
Status Pop(Stack *S){
	if(S->top==S->base)		//空栈
		return ERROR;
	S->top--;
	S->stackSize--;
	return SUCCESS;
}
//栈长  return S->top-S->base;
Status StackLength(Stack *S){
	return S->stackSize;
}
//清栈
Status Clear(Stack *S){
	if(S==NULL)				//未初始栈
		return ERROR;
	while(StackLength(S)){
		Pop(S);
	}
	return SUCCESS;
}
