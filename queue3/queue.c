#include <assert.h>
#include <stdlib.h>
#include "queue.h"

void initQueue(Queue *pq)
{
	pq->front = pq->rear = 0;
}

void push(Queue *pq, int data)
{
	// 1. 예외 처리 첫번째
	if (pq->rear != QUEUESIZE) {
		fprintf(stderr, "queue is full\n");
		exit(1);
	}
	
	// 2. 예외 처리 두번째
	// assert(pq->rear != QUEUESIZE);

	pq->array[pq->rear] = data;
	++pq->rear;
}

int pop(Queue *pq)
{
	// 1. 예외 처리 첫번째
	if (pq->front == pq->rear) {
		fprintf(stderr, "queue is empty\n");
		exit(2);
	}
	
	// 2. 예외 처리 두번째
	// assert(pq->front != pq->rear);

	int index = pq->front;
	++pq->front;
	
	return pq->array[index];
}

