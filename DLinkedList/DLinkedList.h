#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Item;

typedef struct _node{
	Item item;
	struct _node *next;
}Node;

typedef struct _linkedList{
	Node *head;
	Node *cur;
	Node *before;
	int numOfData;
	int (*comp)(Item i1, Item i2);//정렬순서 
}LinkedList;

typedef LinkedList List;

void ListInit(List *plist);
void Insert(List *plist, Item item);

int First(List *plist, Item *pitem);
int Next(List *plist, Item *pitem);

Item Remove(List *plist);
int Count(List *plist);

void SetSortRule(List *plist, int(*comp)(Item i1, Item i2));
#endif
