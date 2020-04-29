#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

// -----큐 초기화-----
int Initialize(Deck *d, int max)
{
    d->max = max;
    if ((d->queue = (int *)malloc(sizeof(int) * max)) == NULL)
    {
        d->max = 0;
        return -1;
    }
    d->front = d->rear = d->LBottom = d->RBottom = d->num = 0;
    return 0;
}
// ----- 큐에 인큐 -----
int Enqueue(Deck *d, int key, int bottom)
{
    if (d->num >= d->max)
        return -1;

    d->num++;
    if (bottom == 1) // 오른쪽 방향으로 넣을 때
    {
        d->queue[d->rear++] = key;
        d->rear %= d->max;
        d->RBottom = d->rear;
        if (d->num == 1)
        {
            d->LBottom = --d->LBottom % d->max;
            if (d->LBottom < 0)
                d->LBottom += d->max;
            d->front = d->LBottom;
        }
    }
    else if (bottom == 2) // 왼쪽 방향으로 넣을 때
    {
        d->queue[d->front--] = key;
        d->front %= d->max;
        d->LBottom = (--d->LBottom % d->max);
        if (d->LBottom < 0)
            d->LBottom += d->max;
        if (d->num == 1)
        {
            d->RBottom = ++d->RBottom % d->max;
            d->rear = d->RBottom;
        }
    }
    else
    {
        return -1;
    }

    return 0;
}
// ----- 큐 디큐 -----
int Dequeue(Deck *d, int *x, int bottom)
{
    if (d->num == 0)
        return -1;
    d->num--;
    if (bottom == 1) // 오른쪽 끝에서 디큐
    {
        *x = d->queue[--d->rear % d->max];
        d->RBottom = --d->RBottom % d->max;
        if (d->num == 0)
            d->LBottom = 0;
    }
    else if (bottom == 2) // 왼쪽 끝에서 디큐
    {
        *x = d->queue[++d->front % d->max];
        d->LBottom = ++d->LBottom % d->max;
        if (d->num == 0)
            d->RBottom = 0;
    }
    else
    {
        return -1;
    }

    return 0;
}
// ----- 큐에서 데이터 피크 -----
int Peek(const Deck *d, int *x, int bottom)
{
    if (d->num == 0)
        return -1;

    if (bottom == 1) // 오른쪽 끝에서 피크
        *x = d->queue[d->rear];
    else if (bottom == 2) // 왼쪽 끝에서 피크
        *x = d->queue[d->front];
    else
        return -1;

    return 0;
}
// ----- 모든 데이터 삭제 -----
int Clear(Deck *d)
{
    d->LBottom = 0;
    d->RBottom = 0;
    d->front = 0;
    d->rear = 0;
    d->num = 0;
    return 0;
}
// ----- 큐의 최대 용량 -----
int Capacity(const Deck *d)
{
    if (d->queue == NULL)
        return -1;
    return d->max;
}
// ----- 큐에 저장된 데이터 개수 -----
int Size(const Deck *d)
{
    if (d->queue == NULL)
        return -1;
    return d->num;
}
// ----- 큐가 비어 있는가? -----
int IsEmpty(const Deck *d)
{
    if (d->queue == NULL)
        return -1;

    if (d->num == 0)
        return 1;
    return 0;
}
// ----- 큐가 가득 찾는가? -----
int IsFull(const Deck *d)
{
    if (d->queue == NULL)
        return -1;

    if (d->num == d->max)
        return 1;
    return 0;
}
// ----- 큐에서 검색 -----
int Search(const Deck *d, int key)
{
    int i, idx;
    for (i = 0; i < d->num; i++)
    {
        if (d->queue[idx = (i + d->front) % d->max] == key)
            return idx;
    }
    return -1;
}
// // ----- UNIT_4_Q4 -----
// int Search2(const Deck *d, int key)
// {
// }
// ----- 모든 데이터 출력 -----
void Print(const Deck *d)
{
    int i;
    int idx;
    for (i = 0; i < d->num; i++)
    {
        idx = (d->front + i + 1) % d->max;
        printf("%d : %d\n", idx, d->queue[idx]);
    }
}
// ----- 큐 종료 -----
void Terminate(Deck *d)
{
    if (d->queue)
        free(d->queue);
}