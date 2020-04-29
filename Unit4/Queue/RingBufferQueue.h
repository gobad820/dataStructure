#ifndef __RingBufferQueue_H_
#define __RingBufferQueue_H_

typedef struct
{
    // -----큐 프론트-----
    int front;
    // -----큐 리어-----
    int rear;
    // -----큐 개수-----
    int num;
    // -----큐 크기-----
    int max;
    // -----큐-----
    int *queue;
} IntQueue;

// -----큐 초기화-----
int Initialize(IntQueue *q, int max);
// ----- 큐에 인큐 -----
int Enqueue(IntQueue *q, int x);
// ----- 큐 디큐 -----
int Dequeue(IntQueue *q, int *x);
// ----- 큐에서 데이터 피크 -----
int Peek(const IntQueue *q, int *x);
// ----- 모든 데이터 삭제 -----
int Clear(IntQueue *q);
// ----- 큐의 최대 용량 -----
int Capacity(const IntQueue *q);
// ----- 큐에 저장된 데이터 개수 -----
int Size(const IntQueue *q);
// ----- 큐가 비어 있는가? -----
int IsEmpty(const IntQueue *q);
// ----- 큐가 가득 찾는가? -----
int IsFull(const IntQueue *q);
// ----- 큐에서 검색 -----
int Search(const IntQueue *q, int x);
// ----- UNIT_4_Q4 -----
int Search2(const IntQueue* q, int x);
// ----- 모든 데이터 출력 -----
void Print(const IntQueue *q);
// ----- 큐 종료 -----
void Terminate(IntQueue *q);
#endif