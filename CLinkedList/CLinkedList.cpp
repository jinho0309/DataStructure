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
	//���� 1 : ������ ��带 tail�� ����Ű�� ���
	//���� 2 : ������ ��尡 ����Ʈ�� Ȧ�� ���� ���
	Node* rpos=plist->cur;
	Item item = rpos->item;
	if(rpos==plist->tail){
		if(plist->tail==plist->tail->next)
			plist->tail = NULL; //�ƹ��͵� �������Ƿ� tail=NULL 
		else{
			plist->tail = plist->before; // ���� ��尡 tail�̵ȴ�. 
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
