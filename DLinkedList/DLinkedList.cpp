#include <iostream>
#include <stdlib.h>
#include "DLinkedList.h"


void ListInit(List *plist){
	plist->head=(Node*)malloc(sizeof(Node));
	plist->head->next=NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
	plist->comp = NULL;
	
}
void FInsert(List *plist, Item item){
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->item = item;
	newNode->next = plist->head->next;
	plist->head->next=newNode;
	(plist->numOfData)++;
}
void SInsert(List *plist, Item item){
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->item = item;
	newNode->next = plist->head->next;
	plist->head->next=newNode;
	(plist->numOfData)++;
}

void Insert(List *plist, Item item){
	if(plist->comp==NULL)
		FInsert(plist,item);
	else
		SInsert(plist,item);
}


int First(List *plist, Item *pitem){
	if(plist->head->next==NULL)
		return FALSE;
	
		plist->cur = plist->head->next;
		plist->before = plist->head;
		
		*pitem=plist->cur->item;
		return TRUE;
		
	
}
int Next(List *plist, Item *pitem){
	if(plist->cur->next==NULL)
		return FALSE;
	
	plist->cur=plist->cur->next;
	plist->before=plist->before->next;
	
	*pitem = plist->cur->item;
	return TRUE;
}

Item Remove(List *plist){
	Item item = plist->cur->item;
	Node *rpos = plist->cur;
	
	plist->before->next = plist->cur->next;
	plist->cur=plist->before->next;
	
	free(rpos);
	(plist->numOfData)--;
	return item;
}
int Count(List *plist){
	return plist->numOfData;
}
