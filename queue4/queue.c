#include <stdlib.h>
#include <assert.h>
#include "queue.h"

void initQueue(Queue *pq, int size)
{
	pq->pArr = malloc(sizeof(int) * size);
	
	// 1. 예외 처리
	/*
	if (pq->pArr == NULL) {
		
	}
	*/
	
	// 2. 예외 처리 (!= NULL 생략 가능)
	assert(pq->pArr /* != NULL */);
	
	pq->size = size;
	pq->front = pq->rear = 0;
}

void cleanupQueue(Queue *pq)
{
	free(pq->pArr);
}

void push(Queue *pq, int data)
{
	// 1. 예외 처리
	/*
	if (pq->rear == pq->size) {
		fprintf(strerr, "queue is full\n");
		exit(1);
	}
	*/
	
	// 2. 예외 처리
	assert(pq->rear != pq->size);

	pq->pArr[pq->rear] = data;
	++pq->rear;
}

int pop(Queue *pq)
{
	// 1. 예외 처리
	/*
	if (pq->rear == pq->front) {
		fprintf(strerr, "queue is empty\n");
		exit(2);
	}
	*/
	
	// 2. 예외 처리
	assert(pq->front != pq->rear);

	int i = pq->front;
	++pq->front;
	
	return pq->pArr[i];
}

