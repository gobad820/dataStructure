#ifndef __ArrayIntQueue_H_
#define __ArrayIntQueue_H_

typedef struct
{
    int max;
    int num;
    int *que;
} ArrayIntQueue;

// -----큐 초기화-----
int Initialize(ArrayIntQueue *q, int max);
// ----- 큐에 인큐 -----
int Enqueue(ArrayIntQueue *q, int x);
// ----- 큐 디큐 -----
int Dequeue(ArrayIntQueue *q, int *x);
// ----- 큐에서 데이터 피크 -----
int Peek(const ArrayIntQueue *q, int *x);
// ----- 모든 데이터 삭제 -----
int Clear(ArrayIntQueue *q);
// ----- 큐의 최대 용량 -----
int Capacity(const ArrayIntQueue *q);
// ----- 큐에 저장된 데이터 개수 -----
int Size(const ArrayIntQueue *q);
// ----- 큐가 비어 있는가? -----
int IsEmpty(const ArrayIntQueue *q);
// ----- 큐가 가득 찾는가? -----
int IsFull(const ArrayIntQueue *q);
// ----- 큐에서 검색 -----
int Search(const ArrayIntQueue *q);
// ----- 모든 데이터 출력 -----
void Print(const ArrayIntQueue *q);
// ----- 큐 종료 -----
void Terminate(ArrayIntQueue *q);
#endif