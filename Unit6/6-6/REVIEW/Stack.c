#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int ptr;
	int max;
	int *stk;
} Stack;

int Initialize(Stack *s, int size)
{
	s->ptr = 0;
	if ((s->stk = (int *)malloc(sizeof(int) * size)) == NULL)
	{
		s->max = 0;
		return -1;
	}
	s->max = size;
	return 0;
}

int Push(Stack *s, int number)
{
	if (s->ptr == s->max)
		return -1;

	s->stk[s->ptr] = number;
	printf("%d is Pushed\n", number);
	return 0;
}

int Pop(Stack *s, int *number)
{
	if (s->ptr == 0)
		return -1;

	*number = s->stk[--s->ptr];
	printf("%d is Poped\n", *number);
	return 0;
}

int isEmpty(Stack *s)
{
	if (s->ptr == 0)
		return 1;
	return 0;
}

void Terminate(Stack *s)
{
	if (s->stk != NULL)
		free(s->stk);
	s->ptr = s->max = 0;
}

int main(void)
{
	int index = -1;
	puts("Size ? ");
	int size;
	scanf("%d", &size);
	Stack s;
	if (Initialize(&s, size) == -1)
	{
		puts("ERROR");
		return 0;
	}

	while (1)
	{
		printf(" 1 : Push / 2 : Pop / 3 : isEmpty / 4 : Terminate / 0 : Exit\n");
		scanf("%d", &index);
		int number = 0;
		switch (index)
		{
		case 1:
			printf("Input the Number : ");
			scanf("%d", &number);
			if (Push(&s, number) == -1)
				puts("The Stack Is Full");
			break;
		case 2:
			if (Pop(&s, &number) == -1)
				puts("The Stack is Empty");
			printf("%d is Popped\n", number);
			break;
		case 3:
			if (isEmpty(&s))
				printf("This Stack Is Empty\n");
			else
				puts("This Stack is Not Empty");
			break;
		case 4:
			puts("Terminate This Stack");
			Terminate(&s);
			index = 0;
			break;
		default:
			puts("Wrong Index");
		}
		if (index == 0)
			break;
	}
}
