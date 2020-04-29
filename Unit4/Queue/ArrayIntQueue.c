#include <stdio.h>
#include <stdlib.h>
#include "ArrayIntQueue.h"

int Initialize(ArrayIntQueue *q, int max)
{
    q->num = 0;
    if ((q->que = calloc(max, sizeof(int))) == NULL)
    {
        q->max = 0;
        return -1;
    }
    q->max = max;
    return 0;
}
int Enqueue(ArrayIntQueue *q, int x)
{
    if (q->num >= q->max)
        return -1;
    else
    {
        q->que[q->num] = x;
        q->num++;
    }
    return 0;
}
int Dequeue(ArrayIntQueue *q, int *x)
{
    if (q->num <= 0)
        return -1;
    q->num--;
    *x = q->que[0];
    for (int i = 0; i < q->num; i++)
    {
        q->que[i] = q->que[i + 1];
    }
    return 0;
}
// ----- 큐에서 데이터 피크 -----
int Peek(const ArrayIntQueue *q, int *x)
{
    if (q->num <= 0)
        return -1;
    *x = q->que[0];
    return 0;
}
// ----- 모든 데이터 삭제 -----
int Clear(ArrayIntQueue *q)
{
    for (int i = 0; i < q->num; i++)
    {
        q->que[i] = 0;
    }
    return 0;
}
// ----- 큐의 최대 용량 -----
int Capacity(const ArrayIntQueue *q)
{
    printf("The Capacity of this Queue : %d\n", q->max);
    return 0;
}
// ----- 큐에 저장된 데이터 개수 -----
int Size(const ArrayIntQueue *q)
{
    printf("The Size of this Queue : %d", q->num);
    return 0;
}
// ----- 큐가 비어 있는가? -----
int IsEmpty(const ArrayIntQueue *q)
{
    if (q->num == 0)
        return 0;
    else
    {
        return -1;
    }
}
// ----- 큐가 가득 찾는가? -----
int IsFull(const ArrayIntQueue *q)
{
    if (q->num == q->max)
        return 0;
    else
    {
        return -1;
    }
}
// ----- 큐에서 검색 -----
int Search(const ArrayIntQueue *q)
{
    int key;
    int i;
    printf("Key : ");
    scanf("%d", &key);

    for (i = 0; i < q->num; i++)
    {
        if (q->que[i] == key)
        {
            printf("%d is Found", key);
            return 0;
        }
    }
    return -1;
}
// ----- 모든 데이터 출력 -----
void Print(const ArrayIntQueue *q)
{
    if (q->num == 0)
        puts("The Queue is Empty");

    int i;
    for (i = 0; i < q->num; i++)
    {
        printf("%d : %d \n", i, q->que[i]);
    }
}
// ----- 큐 종료 -----
void Terminate(ArrayIntQueue *q)
{
    if (q->que)
    {
        free(q->que);
        q->num = 0;
        q->max = 0;
    }
}