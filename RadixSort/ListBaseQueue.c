#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue *pq){
	pq->front =NULL;
	pq->rear = NULL;
}
int QIsEmpty(Queue *pq){
	if(pq->front==NULL)
		return TRUE;

	return FALSE;
}
void Enqueue(Queue *pq, Data data){
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	
	if(QIsEmpty(pq)){
		pq->front = newNode;
		pq->rear =  newNode;
	}
	else{
		pq->rear->next= newNode;
		pq->rear = newNode;
	}
}
Data Dequeue(Queue *pq){
	Node* delNode;
	Data data;
	if(QIsEmpty(pq)){
		printf("Queue Memory Error!");
		exit(-1);
	}
	delNode = pq->front;
	data = pq->front->data;
	pq->front= pq->front->next;
	free(delNode);
	
	return data;
}
Data QPeek(Queue *pq){
	if(QIsEmpty){
		printf("Queue Memory Error!");
		exit(-1);
	}
	
	return pq->front->data;
}
