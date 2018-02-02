#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Item;

typedef struct _node{
	Item item;
	struct _node *next;
}Node;

typedef struct _CLL{
	Node *tail;
	Node *cur;
	Node *before;
	int numOfData;
}CList;

typedef CList List;

void ListInit(List *plist);
void Insert(List *plist, Item item);
void InsertFront(List *plist, Item item);

int First(List *plist, Item *pitem);
int Next(List *plist, Item *pitem);

Item Remove(List *plist);
int Count(List *plist);
#endif
