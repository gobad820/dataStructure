#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int top;
	int* stk;
	int max;
}Stack;

int Initialize(Stack* s, int size){
	s->top = 0;
	if((s->stk = (int*)malloc(sizeof(int)*size)) == NULL){
		s->top = 0;
		s->max = 0;
		return -1;}
	s->max = size;
	return 0;
}

int Push(Stack* s, int number){
	if(s->top >= s->max){
		puts("THE STACK IS FULL");
		return -1;}
	
	s->stk[s->top++] = number;
	return 0;}

int Pop(Stack* s, int* number){
	if(s->top == 0){
		puts("THE STACK IS EMPTY");
		return -1;}

   *number = s->stk[--(s->top)];
	return 0;
}

int isEmpty(Stack* s){
	if(s->top == 0)
		return 1;
	return 0;
}

void Terminate(Stack* s){
	if(s->stk != NULL)
		free(s->stk);
	s->max = s->top = 0;
}
