#include <stdlib.h>
#include <stdio.h>
#include "ArrayBaseStack.h"
//typedef struct _arrayStack{
//	Data stackArr[STACK_LEN];
//	int topIndex;
//}ArrayStack;

void StackInit(Stack *pstack){
	pstack->topIndex = -1;
}
int IsEmpty(Stack *pstack){
	if(pstack->topIndex==-1)
		return TRUE;
	
	return FALSE;
}

void Push(Stack *pstack, Data data){
	if(pstack->topIndex<STACK_LEN-1){
		pstack->topIndex+=1;
		pstack->stackArr[pstack->topIndex]=data;
	}
}
Data Pop(Stack *pstack){
	Data data;
	if(IsEmpty(pstack)){
		printf("Stack Memory Error!");
		exit(-1);
	}
	data=pstack->stackArr[pstack->topIndex];
	pstack->topIndex-=1;
	
	return data;
}
Data Peek(Stack *pstack){
		if(IsEmpty(pstack)){
		printf("Stack Memory Error!");
		exit(-1);
	}
	return pstack->stackArr[pstack->topIndex];
}
