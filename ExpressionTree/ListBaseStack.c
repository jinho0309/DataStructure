#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack *pstack){
	pstack->head = NULL;
}
int IsEmpty(Stack *pstack){
	if(pstack->head == NULL)
		return TRUE;
		
	return FALSE;
}

void Push(Stack *pstack, Data data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head= newNode;
}
Data Pop(Stack *pstack){
	Data data;
	Node* rpos;
	if(IsEmpty(pstack)){
		printf("Memory error");
		exit(-1);
	}
	rpos=pstack->head;
	data=rpos->data;
	pstack->head=pstack->head->next;
	free(rpos);
	return data;
	
}
Data Peek(Stack *pstack){
	if(IsEmpty(pstack)){
		printf("Memory error");
		exit(-1);
	}
	return pstack->head->data;
}
