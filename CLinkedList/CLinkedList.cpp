#include <stdlib.h>
#include "CLinkedList.h"
//typedef int Item;
//
//typedef struct _node{
//	Item item;
//	struct _node *next;
//}Node;
//
//typedef struct _CLL{
//	Node *head;
//	Node *cur;
//	Node *before;
//	int numOfData;
//}CList;
//
//typedef CList List;

void ListInit(List *plist){
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}
void Insert(List *plist, Item item){
	Node* newItem = (Node*)malloc(sizeof(Node));
	newItem->item=item;
	if(plist->tail == NULL){
		plist->tail=newItem;
		newItem->next = newItem;
	}
	else{
		newItem->next=plist->tail->next;
		plist->tail->next= newItem;
		plist->tail = newItem;
		
	}
	(plist->numOfData)++;
}
void InsertFront(List *plist, Item item){
		Node* newItem = (Node*)malloc(sizeof(Node));
	newItem->item=item;
	if(plist->tail == NULL){
		plist->tail=newItem;
		newItem->next = newItem;
	}
	else{
		newItem->next= plist->tail->next;
		plist->tail->next=newItem;
	}
	(plist->numOfData)++;
}

int First(List *plist, Item *pitem){
	if(plist->tail==NULL)
		return FALSE;
	
	plist->cur=plist->tail->next;
	plist->before=plist->tail;
	*pitem = plist->cur->item;
	
	return TRUE;
}
int Next(List *plist, Item *pitem){
	if(plist->tail==NULL)
		return FALSE;
	
	plist->cur=plist->cur->next;
	plist->before=plist->before->next;
	*pitem = plist->cur->item;
	return TRUE;
}

Item Remove(List *plist){
	//예외 1 : 삭제할 노드를 tail이 가리키는 경우
	//예외 2 : 삭제할 노드가 리스트에 홀로 남은 경우
	Node* rpos=plist->cur;
	Item item = rpos->item;
	if(rpos==plist->tail){
		if(plist->tail==plist->tail->next)
			plist->tail = NULL; //아무것도 없어지므로 tail=NULL 
		else{
			plist->tail = plist->before; // 이전 노드가 tail이된다. 
		}
	}

	plist->before->next=plist->cur->next;
	plist->cur=plist->cur->next;
	free(rpos); 
	(plist->numOfData)--;
	return item;
}
int Count(List *plist){
	return plist->numOfData;
}
