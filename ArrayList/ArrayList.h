#ifndef __ARRAY_LIST_H__
#define __ARRAY_LISH_H__

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
typedef int Item;

typedef struct __ArrayLIst {
	Item arr[LIST_LEN];
	int numOfItem;
	int curPosition;
} ArrayList;

typedef ArrayList List;

void InitList(List* plist);
void Insert(List* plist, Item item);

int First(List* plist, Item* item);
int Next(List* plist, Item* item);

Item Remove(List* plist);
int Count(List *plist);
 
#endif
