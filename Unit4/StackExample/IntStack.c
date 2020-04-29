#include "IntStack.h"
#include <stdio.h>
#include <stdlib.h>

int Initialize(IntStack *s, int max)
{
    s->ptr = 0;
    s->ptrB = max;
    if ((s->stk = calloc(max, sizeof(int))) == NULL)
    {
        s->max = 0;
        return -1;
    }
    s->maxB = 0;
    s->max = max;
    return 0;
}

int Push(IntStack *s, int x, int check)
{
    if (check == 1)
    {
        if (s->ptr >= s->max || s->ptr >= s->ptrB)
            return -1;
        s->stk[s->ptr++] = x;
    }
    else if (check == 2)
    {
        if (s->ptrB <= s->maxB || s->ptrB <= s->ptr)
            return -1;
        s->stk[s->ptrB--] = x;
        return 0;
    }
    else
    {
        printf("ERROR\n");
    }
    return 0;
}

int Pop(IntStack *s, int *x, int check)
{
    if (check == 1)
    {

        if (s->ptr == 0)
            return -1;
        *x = s->stk[s->ptr - 1];
        s->ptr--;
    }
    else if (check == 2)
    {

        if (s->ptrB == s->max)
            return -1;
        *x = s->stk[s->ptrB + 1];
        s->ptrB++;
    }
    else
    {
        puts("ERROR");
    }
    return 0;
}

int Peek(const IntStack *s, int *x, int check)
{
    if (check == 1)
    {
        if (s->ptr == 0)
            return -1;
        *x = s->stk[s->ptr - 1];
    }
    else if (check == 2)
    {
        if (s->ptrB == s->max)
            return -1;
        *x = s->stk[s->ptrB + 1];
    }
    else
    {
        puts("ERROR");
    }

    return 0;
}

void Clear(IntStack *s, int check)
{
    s->ptr = 0;
}

int Capacity(const IntStack *s)
{

    return s->max;
}
int Size(const IntStack *s, int check)
{
    if (check == 1)
        return s->ptr;
    else if (check == 2)
        return s->max - s->ptrB;
    else
    {
        return 0;
    }
}

int IsEmpty(const IntStack *s, int check)
{
    if (check == 1)
        return (s->ptr != 0);
    else if (check == 2)
        return (s->ptrB != s->max);
    else
    {
        return 0;
    }
}

int IsFull(const IntStack *s)
{
    return (s->ptr == s->ptrB);
}

int Search(const IntStack *s, int x, int check)
{
    if (check == 1)
    {

        int i;
        for (i = s->ptr - 1; i > 0; i--)
        {
            if (s->stk[i] == x)
                return x;
        }
    }
    else if (check == 2)
    {
        int j;
        for (j = s->ptrB + 1; j < s->max; j++)
        {
            if (s->stk[j] == x)
                return x;
        }
    }
    return -1;
}

void Print(const IntStack *s, int check)
{
    if (check == 1)
    {

        int i;
        for (i = 0; i < s->ptr; i++)
        {
            printf("%d\n", s->stk[i]);
        }
    }
    else if (check == 2)
    {
        int i;
        for (i = s->max; i > s->ptrB; i--)
        {
            printf("%d\n", s->stk[i]);
        }
    }
    else
    {
    }
}

void Terminate(IntStack *s) // Clear함수와의 차이점
{
    if (s->stk != NULL)
        free(s->stk);
    s->max = s->ptr = 0;
}
