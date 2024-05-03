#include<stdio.h>
#include<stdlib.h>
#include"CircularQueue.h"

void QueueInit(Queue* pq) {
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue* pq) {
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

int NextPodIdx(int pos) {
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue* pq, Data data) {
	if (NextPodIdx(pq->rear) == pq->front) {
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->rear = NextPodIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue* pq) {
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->front = NextPodIdx(pq->front);
	return pq->queArr[pq->front];
}

Data QPeek(Queue* pq) {
	if (QIsEmpty(pq)) {
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->queArr[NextPodIdx(pq->front)];
}