#include <iostream>
#include "DLinkedList.h"

using namespace std;
int WhoIsPrecede(int i1, int i2){
	if(i1<i2)
		return 0; //i1�� i2���� ����.
	else
		return 1; //i2�� ������..
	/*
		while(cur->next!=NULL&&plist->comp(item,cur->item)!=0)
		cur=cur->next;
		���� while���� ���ؼ� 0�� ��ȯ���� ������, �� i1�� i2���� ũ�� 
		cur�� next�Ѵ�(i1�� i2���� ������ ����).
		ex) 1->2->3->5->9�� ���� �� 6�� �߰��ϸ�...
		1,2,3,5���� 6�� ũ�⶧���� comp()�Լ��� 1�� ��ȯ....
		5���� 5�� next�� 9�̰� 6���� ũ�⶧���� cur�� 5���� �����. 
	
	*/ 
}
int main(void){
	List list;
	int item;
	ListInit(&list);
	
	Insert(&list, 11);
	Insert(&list, 12);
	Insert(&list, 31);
	cout<<"���� �������� ��: "<<Count(&list)<<endl;
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
		cout<<"���� �������� ��: "<<Count(&list)<<endl;
	if(First(&list,&item)){
		cout<<item<<" ";
	 	while(Next(&list,&item))
	 		cout<<item<< " ";
	}
		
}
