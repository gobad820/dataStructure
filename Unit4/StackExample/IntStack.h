
#ifndef __IntStack_H_
#define __IntStack_H_

typedef struct
{
    int max;
    int ptr;
    int ptrB;
    int maxB;
    int *stk;
} IntStack;

int Initialize(IntStack *s, int max);

int Push(IntStack *s, int x, int check);

int Pop(IntStack *s, int *x, int check);

int Peek(const IntStack *s, int *x, int check);

int Peek(const IntStack *s, int *x, int check);

void Clear(IntStack *s, int check);

void Clear(IntStack *s, int check);

int Size(const IntStack *s, int check);

int Capacity(const IntStack *s);

int IsEmpty(const IntStack *s, int check);

int IsFull(const IntStack *s);

int Search(const IntStack *s, int x, int check);

void Print(const IntStack *s, int check);

void Terminate(IntStack *s);

#endif
