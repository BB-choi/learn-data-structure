#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue * pq)  // 텅 비어있는 경우 f와 r은 같은 위치를 가리킨다.
{
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue * pq)
{
    if(pq->front == pq->rear) { // Queue가 비어있다면
        return TRUE;
    }
    else {
        return FALSE;
    }
}

int NextPosIdx(int pos) // 큐의 다음 위치에 해당하는 인덱스 값 반환
{
    if(pos == QUE_LEN - 1)  // 배열의 마지막 요소의 인덱스값이라면
    {
        return 0;
    }
    else
    {
        return pos + 1;
    }
}

void Enqueue(Queue * pq, Data data)
{
    if (NextPosIdx(pq->rear) == pq->front)  // Queue가 꽉 찬상태라면
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
    //꽉 차지 않은 상태라면
    pq->rear = NextPosIdx(pq->rear);    // rear를 한 칸 이동
    pq->queArr[pq->rear] = data;    // rear이 가리키는 곳에 data를 저장한다
}

Data Dequeue(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    pq->front = NextPosIdx(pq->front);  // front를 한 칸 이동
    return pq->queArr[pq->front];   // front가 가리키는 데이터를 반환한다.
}

Data QPeek(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    return pq->queArr[NextPosIdx(pq->front)];
}