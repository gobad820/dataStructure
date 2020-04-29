#include <stdio.h>

typedef struct
{
    int max;
    int ptr;
    int *stk;
} IntStack;

int Initialize(IntStack *s, int max);

int Push(IntStack *s, int x);

int Pop(IntStack *s, int *x);

int Peek(const IntStack *s, int *x);

int Peek(const IntStack *s, int *x);

void Clear(IntStack *s);

void Clear(IntStack *s);

int Size(const IntStack *s);

int Capacity(const IntStack *s);

int IsEmpty(const IntStack *s);

int IsFull(const IntStack *s);

int Search(const IntStack *s, int x);

void Print(const IntStack *s);

void Terminate(IntStack *s);

void recur(int n)
{
    IntStack stk;
    Initialize(&stk, 100);
Top:
    if (n > 0)
    {
        Push(&stk, n);
        n = n - 1;
        goto Top;
    }
    if (!IsEmpty(&stk))
    {
        Pop(&stk, &n);
        printf("%d\n", n);
        n = n - 2;
        goto Top;
    }

    Terminate(&stk);
}
int main(int argc, char const *argv[])
{
    int number;
    printf("정수를 입력하세요 : ");
    scanf("%d", &number);
    recur(number);

    return 0;
}

int Initialize(IntStack *s, int max)
{
    s->ptr = 0;
    if ((s->stk = calloc(max, sizeof(int))) == NULL)
    {
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

int Push(IntStack *s, int x)
{

    if (s->ptr >= s->max)
        return -1;
    s->stk[s->ptr++] = x;

    return 0;
}

int Pop(IntStack *s, int *x)
{

    if (s->ptr <= 0)
        return -1;
    *x = s->stk[s->ptr--];
    return 0;
}

int Peek(const IntStack *s, int *x)
{

    if (s->ptr == 0)
        return -1;
    *x = s->stk[s->ptr - 1];

    return 0;
}

void Clear(IntStack *s)
{
    s->ptr = 0;
}

int Capacity(const IntStack *s)
{

    return s->max;
}
int Size(const IntStack *s)
{

    return s->ptr;
}

int IsEmpty(const IntStack *s)
{

    return (s->ptr != 0);
}

int IsFull(const IntStack *s)
{
    return (s->ptr == s->max);
}

int Search(const IntStack *s, int x)
{
    int i;
    for (i = s->ptr - 1; i > 0; i--)
    {
        if (s->stk[i] == x)
            return x;
    }

    return -1;
}

void Print(const IntStack *s)
{

    int i;
    for (i = 0; i < s->ptr; i++)
    {
        printf("%d\n", s->stk[i]);
    }
}

void Terminate(IntStack *s) // Clear함수와의 차이점
{
    if (s->stk != NULL)
        free(s->stk);
    s->max = s->ptr = 0;
}
