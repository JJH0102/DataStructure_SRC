#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "queue.h"

void initQueue(Queue *pq, int size, int eleSize)
{
	pq->pArr = malloc(eleSize * size);
	
	assert(pq->pArr );
	
	pq->eleSize = eleSize;
	pq->size = size;

	pq->front = pq->rear = 0;
}

void cleanupQueue(Queue *pq)
{
	free(pq->pArr);
}

void push(Queue *pq, const void *pData)
{
	assert(pq->rear != pq->size);

	// 1. 치환 방법
	// pq->pArr[pq->rear] = data;
	
	// 2. 치환 방법
	memcpy( (unsigned char *)pq->pArr + pq->eleSize * pq->rear, pData, pq->eleSize);
	
	++pq->rear;
}

void pop(Queue *pq, void *pResult)
{
	assert(pq->front != pq->rear);

	// 1. 치환 방법
	// *pResult = pq->pArr[pq->front];

	// 2. 치환 방법
	memcpy(pResult, (unsigned char *)pq->pArr + pq->eleSize * pq->front, pq->eleSize);
	
	++pq->front;
}

