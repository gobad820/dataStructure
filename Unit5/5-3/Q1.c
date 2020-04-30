#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int ptr;
    int max;
    int *stk;
} Stack;

int Initialize(Stack *stack, int max)
{
    if ((stack->stk = (int *)malloc(sizeof(int) * max)) == NULL)
    {
        stack->max = 0;
        stack->ptr = 0;
        return -1;
    }
    stack->max = max;
    stack->ptr = 0;
    return 0;
}

int Push(Stack *stack, int number)
{
    if (stack->ptr == stack->max)
        return -1;

    stack->stk[stack->ptr++] = number;
    return 0;
}

int Pop(Stack *stack, int *number)
{
    if (stack->ptr == 0)
        return -1;

    *number = stack->stk[stack->ptr--];
    return 0;
}

int isEmpty(const Stack *stack)
{
    if (stack->ptr == 0)
        return 0;
    return -1;
}

void recur3(int n);
int main(int argc, char const *argv[])
{
    int number;
    printf("Number : ");
    scanf("%d", &number);
    recur3(number);
    return 0;
}
void recur3(int n)
{
    Stack s;
    Initialize(&s, n);
    int count = 0;
Top:
    if (n > 0)
    {
        Push(&s, n);
        n = n - 1;
        goto Top;
    }
Mid:
    if (isEmpty(&s) == -1)
    {
        if (s.stk[s.ptr] >= 3)
        {
            n = s.stk[s.ptr] - 2;
            count++;
            goto Top;
        }
        do
        {
            Pop(&s, &n);
            printf("%d\n", n);
            if (count != 0)
                count--;
        } while (count > 0);
        goto Mid;
    }
}