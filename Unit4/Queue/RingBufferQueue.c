#include "RingBufferQueue.h"
#include <stdio.h>
#include <stdlib.h>

// -----큐 초기화-----
int Initialize(IntQueue *q, int max)
{
    if ((q->queue = (int *)malloc(sizeof(int) * max)) == NULL)
        return -1;
    q->num = 0;
    q->max = max;
    q->front = q->rear = 0;
    return 0;
}
// ----- 큐에 인큐 -----
int Enqueue(IntQueue *q, int x)
{
    if (q->num >= q->max)
        return -1;
    q->num++;
    q->queue[q->rear++] = x;
    if (q->rear == q->max) // rear값이 max와 같아지면 다시 0으로 넘어가서 커지기 시작함 // 유동적
        q->rear = 0;

    return 0;
}
// ----- 큐 디큐 -----
int Dequeue(IntQueue *q, int *x)
{
    if (q->num == 0)
        return -1;

    q->num--;
    *x = q->queue[q->front++];
    if (q->front == q->max) // front값이 max와 같아지면 다시 0으로 넘어가서 커지기 시작함 // 유동적
        q->front = 0;

    return 0;
}
// ----- 큐에서 데이터 피크 -----
int Peek(const IntQueue *q, int *x)
{
    if (q->num == 0)
        return -1;

    *x = q->queue[q->rear];
    return 0;
}
// ----- 모든 데이터 삭제 -----
int Clear(IntQueue *q)
{
    q->front = 0;
    q->rear = 0;
    q->num = 0;
    return 0;
}
// ----- 큐의 최대 용량 -----
int Capacity(const IntQueue *q)
{
    if (q)
        return q->max;
    return -1;
}
// ----- 큐에 저장된 데이터 개수 -----
int Size(const IntQueue *q)
{
    if (q)
        return q->num;
    return -1;
}
// ----- 큐가 비어 있는가? -----
int IsEmpty(const IntQueue *q)
{
    if (q->num == 0)
        return 0;
    return -1;
}
// ----- 큐가 가득 찾는가? -----
int IsFull(const IntQueue *q)
{
    if (q->num == q->max)
        return 0;
    return -1;
}
// ----- 큐에서 검색 -----
int Search(const IntQueue *q, int x)
{
    int i, idx;
    for (i = 0; i < q->num; i++)
    {
        if (q->queue[idx = (i + q->front) % q->max] == x)
            return idx;
    }
    return -1;
}

// ----- UNIT_4_Q4 -----
int Search2(const IntQueue *q, int x)
{
    int i, key;
    printf("Key : ");
    scanf("%d", &key);
    if (q->rear < q->front)
    {
        for (i = q->front; i < q->max; i++)
        {
            if (q->queue[i] == key)
            {
                printf("%d is Found in %d\n", key, i);
                return 0;
            }
        }
        for (i = 0; i < q->rear; i++)
        {
            if (q->queue[i] == key)
            {
                printf("%d is Found in %d\n", key, i);
                return 0;
            }
        }
    }
    else
    {
        for (i = q->front; i < q->rear; i++)
        {
            if (q->queue[i] == key)
            {
                printf("%d is Found in %d\n", key, i);
                return 0;
            }
        }
    }
    return -1;
}
// ----- 모든 데이터 출력 -----
void Print(const IntQueue *q)
{
    int i;
    if (q->rear < q->front)
    {
        for (i = q->front; i < q->max; i++)
        {
            printf("%d : %d\n", i, q->queue[i]);
        }
        for (i = 0; i < q->rear; i++)
        {
            printf("%d : %d\n", i, q->queue[i]);
        }
    }
    else
    {
        for (i = q->front; i < q->rear; i++)
        {
            printf("%d : %d\n", i, q->queue[i]);
        }
    }
}
void Terminate(IntQueue *q)
{
    if (q->queue != NULL)
    {
        free(q->queue);
    }
    q->max = q->rear = q->front = q->num = 0;
}
// ----- 큐 종료 -----