#include <stdio.h>
#include "DBLinkedList.h"
//void ListInit(List *plist);
//void Insert(List *plist, Item item);
//
//int First(List *plist, Item *pitem);
//int Next(List *plist, Item *pitem);
//int Previous(List *plist, Item *pitem);
//int Count(List *plist);
int main(void)
{
	
	List list;
	int data;
	ListInit(&list);
	for(int i=0;i<8;i++)
		Insert(&list,i+1);
	
	if(First(&list, &data))
	{
		printf("%d ", data);
		
		while(Next(&list, &data))
			printf("%d ", data);
		while(Previous(&list, &data))
			printf("%d ", data);
			
			printf("\n\n");
	}
}
