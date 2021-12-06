#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node 
{
    Data data;
    struct _node *next;
}Node;

typedef struct  _1Queue
{
    Node *front;    // F
    Node *rear;     // R
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);

void Enqueue(Queue *pq, Data data); // Enqueue 함수
Data Dequeue(Queue *pq); // Dequeue 함수
Data QPeek(Queue *pq);


#endif
