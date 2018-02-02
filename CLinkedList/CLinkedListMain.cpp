#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{
	List list;
	int data, i, nodeNum;
	ListInit(&list);
	
	Insert(&list,3);
	Insert(&list,4);
	Insert(&list,5);
	InsertFront(&list,2);
	InsertFront(&list,1);
	if(First(&list,&data)){
		printf("%d ",data);
		
		for(i=0; i<Count(&list)*3-1; i++)
		{
			if(Next(&list,&data))
			printf("%d ", data);
		}
	}
	printf("\n");
	
	nodeNum = Count(&list);
	
	if(nodeNum !=0)
	{
		First(&list, &data);
		if(data%2 ==  0)
			Remove(&list);
		
		for(i=0;i<nodeNum-1;i++)
		{
			Next(&list, &data);
			if(data%2 ==0)
				Remove(&list);
		}
	}
	
	if(First(&list,&data)){
		printf("%d ",data);
		
		for(i=0; i<Count(&list)-1; i++)
		{
			if(Next(&list,&data))
			printf("%d ", data);
		}
	}
	



}
