#include <stdlib.h>
#include "DBLinkedList.h"


void ListInit(List *plist){
	plist->head=NULL;
	plist->numOfData=0;
}
void Insert(List *plist, Item item){
	Node* newItem = (Node*)malloc(sizeof(Node));
	newItem->item = item;
	if(plist->head==NULL){
		newItem->next=NULL;
	}
	else{
		newItem->next = plist->head;
		plist->head->prev = newItem;
	}
	newItem->prev=NULL;
	plist->head = newItem;
}

int First(List *plist, Item *pitem){

	if(plist->head==NULL)
		return FALSE;
	
	plist->cur=plist->head;
	*pitem=plist->cur->item;

	return TRUE;
}
int Next(List *plist, Item *pitem){
	Item item;
	if(plist->cur->next==NULL)
		return FALSE;
	
	plist->cur=plist->cur->next;
	*pitem=plist->cur->item;

	return TRUE;
}
int Previous(List *plist, Item *pitem){
	Item item;
	if(plist->cur->prev==NULL)
		return FALSE;
	
	plist->cur=plist->cur->prev;
	*pitem=plist->cur->item;
	
	return TRUE;
	
}
int Count(List *plist){
	return plist->numOfData;
}
