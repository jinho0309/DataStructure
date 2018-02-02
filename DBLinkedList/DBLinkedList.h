#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Item;

typedef struct _node{
	Item item;
	struct _node *next;
	struct _node *prev;
}Node;

typedef struct _DBLI{
	Node *head;
	Node *cur;
	Node *before;
	int numOfData;
}DBList;

typedef DBList List;

void ListInit(List *plist);
void Insert(List *plist, Item item);

int First(List *plist, Item *pitem);
int Next(List *plist, Item *pitem);
int Previous(List *plist, Item *pitem);
int Count(List *plist);
#endif
