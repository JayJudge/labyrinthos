//Stack.c

//ͷ�ļ�
#include"labyrinthos.h"
//n2 = n1 �ڵ㿽��
void copy(Node* n1, Node *n2){
	n2->x = n1->x;
	n2->y = n1->y;
}

//ջ��ʼ��
Status StackInit(Stack *S){
	S->base = (Node*)malloc(STACK_INIT_SIZE * sizeof(Node));
	if(!S->base)exit(OVERFLOW);		//�ڴ����
	S->top = S->base;
	S->maxSize=STACK_INIT_SIZE;
	S->stackSize = 0;
	return SUCCESS;
}
//����ջ��Ԫ��
Status Top(Stack *S, Node *N){
	if(S->top==S->base)			//��ջ
		return ERROR;
	N->x = (*(S->top)).x;
	N->y = (*(S->top)).y;
	return SUCCESS;
}
//ѹջ
Status Push(Stack *S, Node *N){
	if(S->top - S->base >= S->maxSize){		//����ڴ治��
		S->base = (Node*)realloc(S->base,(S->maxSize+ STACK_INCREMENT) * sizeof(Node));
		if(!S->base)exit(OVERFLOW);	//�ڴ����
		S->top = S->base + S->stackSize;
		S->maxSize += STACK_INCREMENT;
	}
	(*(S->top)).x = N->x;
	(*(S->top)).y = N->y;
	
	S->top++;
	S->stackSize++;
	return SUCCESS;
}
//��ջ
Status PopElem(Stack *S, Node *N){
	if(S->top==S->base)		//��ջ
		return ERROR;
	S->top--;
	N->x = (*(S->top)).x;
	N->y = (*(S->top)).y;

	S->stackSize--;
	return SUCCESS;
}
//��ջ
Status Pop(Stack *S){
	if(S->top==S->base)		//��ջ
		return ERROR;
	S->top--;
	S->stackSize--;
	return SUCCESS;
}
//ջ��  return S->top-S->base;
Status StackLength(Stack *S){
	return S->stackSize;
}
//��ջ
Status Clear(Stack *S){
	if(S==NULL)				//δ��ʼջ
		return ERROR;
	while(StackLength(S)){
		Pop(S);
	}
	return SUCCESS;
}
