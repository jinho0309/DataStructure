#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"


void QueueInit(Queue *pq){
	pq->front = 0;
	pq->rear = 0;
	//front==rear :Empty
	//rear->next==front : Full
	//==>front�� ���� ������ front�� ����� ������� Empty�� Full�϶��� ���̰� ����.
	//�Ѵ� rear-> front	
}
int QIsEmpty(Queue *pq){
	if(pq->front == pq->rear)
		return TRUE;
	return FALSE;
}
int NextPosIdx(int pos)
{
	if(pos==QUE_LEN-1)
		return 0;
		//���� ������ ó�������� �ٽ�... ���� ť 
	else 
		return pos+1;
}
int QIsFull(Queue *pq){
	if(NextPosIdx(pq->rear) == pq->front)
		return TRUE;
	return FALSE;
}

void Enqueue(Queue *pq, Data data){
	if(QIsFull(pq)){
		printf("Queue Memory Error!");
		exit(-1);
	}
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear]=data;
}
Data Dequeue(Queue *pq){
	if(QIsEmpty(pq)){
		printf("Queue Memory Error!");
		exit(-1);
	}
	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}
Data QPeek(Queue *pq){
		if(QIsEmpty(pq)){
		printf("Queue Memory Error!");
		exit(-1);
	}
		return pq->queArr[NextPosIdx(pq->front)];
}