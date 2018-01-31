#include <iostream>
#include "ArrayList.h"

using namespace std;
void InitList(List* plist){
	plist->numOfItem = 0;
	plist->curPosition = -1;//왜 -1일 부터 시작하지? 
}
void Insert(List* plist, Item item){
	if(plist->numOfItem>=LIST_LEN){
		cout<<"저장불가";
		return; 
	}
	plist->arr[plist->numOfItem]=item;
	(plist->numOfItem)++;
}

int First(List* plist, Item* item){
	if(plist->numOfItem == 0)
		return FALSE;
		
	plist->curPosition=0;
	*item =plist->arr[plist->curPosition];
	return TRUE;
}
int Next(List* plist, Item* item){
	if((plist->curPosition)>=(plist->numOfItem)-1)
		return FALSE;
	
	(plist->curPosition)++;
	*item = plist->arr[plist->curPosition];
	return TRUE;
	
}

Item Remove(List* plist){
	int pos = plist->curPosition;
	int num = plist->numOfItem;
	Item item = plist->arr[pos];
	for(int i=pos;i<num-1;i++)
		plist->arr[i]=plist->arr[i+1];
	(plist->numOfItem)--;
	(plist->curPosition)--;
	
	return item;
}
int Count(List *plist){
	return plist->numOfItem;
}

