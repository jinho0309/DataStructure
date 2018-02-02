#include <iostream>
#include "DLinkedList.h"

using namespace std;
int WhoIsPrecede(int i1, int i2){
	if(i1<i2)
		return 0; //i1이 i2보다 먼저.
	else
		return 1; //i2가 먼저면..
	/*
		while(cur->next!=NULL&&plist->comp(item,cur->item)!=0)
		cur=cur->next;
		위의 while문을 통해서 0을 반환하지 않으면, 즉 i1이 i2보다 크면 
		cur을 next한다(i1이 i2보다 작을때 까지).
		ex) 1->2->3->5->9가 있을 때 6을 추가하면...
		1,2,3,5보다 6이 크기때문에 comp()함수는 1을 반환....
		5에서 5의 next가 9이고 6보다 크기때문에 cur은 5에서 멈춘다. 
	
	*/ 
}
int main(void){
	List list;
	int item;
	ListInit(&list);
	
	Insert(&list, 11);
	Insert(&list, 12);
	Insert(&list, 31);
	cout<<"현재 데이터의 수: "<<Count(&list)<<endl;
	if(First(&list,&item)){
		cout<<item<<" ";
	 	while(Next(&list,&item))
	 		cout<<item<< " ";
	}
	cout<<endl;
	if(First(&list,&item)){
		if(item==12)
			Remove(&list);
		while(Next(&list,&item)){
			if(item==12)
				Remove(&list);
		}
	}
		cout<<"현재 데이터의 수: "<<Count(&list)<<endl;
	if(First(&list,&item)){
		cout<<item<<" ";
	 	while(Next(&list,&item))
	 		cout<<item<< " ";
	}
		
}
