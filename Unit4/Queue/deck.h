#ifndef __DECK_H_
#define __DECK_H_

typedef struct
{
    int front;
    int rear;
    int LBottom;
    int RBottom;
    int max;
    int num;
    int *queue;
} Deck;

// -----큐 초기화-----
int Initialize(Deck *d, int max);
// ----- 큐에 인큐 -----
int Enqueue(Deck *d, int key, int bottom);
// ----- 큐 디큐 -----
int Dequeue(Deck *d, int *x, int botoom);
// ----- 큐에서 데이터 피크 -----
int Peek(const Deck *d, int *x, int bottom);
// ----- 모든 데이터 삭제 -----
int Clear(Deck *d);
// ----- 큐의 최대 용량 -----
int Capacity(const Deck *d);
// ----- 큐에 저장된 데이터 개수 -----
int Size(const Deck *d);
// ----- 큐가 비어 있는가? -----
int IsEmpty(const Deck *d);
// ----- 큐가 가득 찾는가? -----
int IsFull(const Deck *d);
// ----- 큐에서 검색 -----
int Search(const Deck *d, int key);
// // ----- UNIT_4_Q4 -----
// int Search2(const Deck *d, int key);
// ----- 모든 데이터 출력 -----
void Print(const Deck *d);
// ----- 큐 종료 -----
void Terminate(Deck *d);
#endif