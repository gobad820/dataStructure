#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) \
	do                   \
	{                    \
		type t = x;      \
		x = y;           \
		y = t;           \
	} while (0)
typedef struct
{
	int top;
	int max;
	int *stk;
} Stack;

int Initialize(Stack *s, int size)
{
	s->top = 0;

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
	if (s->top == s->max)
		return -1;

	s->stk[s->top++] = number;
	return 0;
}

int Pop(Stack *s, int *number)
{
	if (s->top == 0)
		return -1;

	*number = s->stk[--(s->top)];
	return 0;
}

int isEmpty(Stack *s)
{
	if (s->top <= 0)
		return 1;
	return 0;
}

void Terminate(Stack *s)
{
	if (s->stk != NULL)
	{
		free(s->stk);
	}
	s->max = s->top = 0;
}

void quickSort(int *arr, int left, int right)
{
	Stack lstack;
	Stack rstack;

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	Push(&lstack, left);
	Push(&rstack, right);
		
	while (!isEmpty(&lstack))
	{
		int pl = (Pop(&lstack, &left), left);
		int pr = (Pop(&rstack, &right), right);
		int pivot = arr[(left + right) / 2];

		do
		{
			while (arr[pl] < pivot)
				pl++;
			while (arr[pr] > pivot)
				pr--;
			if (pl <= pr)
			{
				swap(int, arr[pl], arr[pr]);
				pr--;
				pl++;
			}
		} while (pl <= pr);

		if (left < pr)
		{
			Push(&lstack, left);
			Push(&rstack, pr);
		}

		if (pl < right)
		{
			Push(&lstack, pl);
			Push(&rstack, right);
		}
	}

	Terminate(&lstack);
	Terminate(&rstack);
}

int main(void)
{
	srand((unsigned)time(NULL));

	int size;
	printf("Input the Size:");
	scanf("%d", &size);

	int *arr = (int *)malloc(sizeof(int) * size);
	int i;
	for (i = 0; i < size; i++)
	{
		arr[i] = rand() % 200;
		printf("x[%d] = %d\n", i, arr[i]);
	}

	puts("오름차순으로 정렬합니다");
	quickSort(arr, 0, size - 1);
	for (i = 0; i < size; i++)
	{
		printf("x[%d] = %d\n", i, arr[i]);
	}
	return 0;
}
