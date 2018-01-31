#include <iostream>
#include "ArrayList.h">
using namespace std;
int main(void){
	List list;
	int item;
	InitList(&list);
	Insert(&list, 1);
	Insert(&list, 2);
	Insert(&list, 5);
	Insert(&list, 6);
	Insert(&list, 9);
	Insert(&list, 8);
	Insert(&list, 7);
	cout<<"현재 데이터의 수 "<<Count(&list)<<endl;
	if(First(&list, &item)){
		cout<<item<<" ";
		
		while(Next(&list, &item))
			cout<<item<<" ";
	}
	cout<<endl<<endl;
	if(First(&list, &item)){
		if(item==2)
			Remove(&list);
		
		while(Next(&list, &item))
			if(item==2)
				Remove(&list);
	}
		cout<<"현재 데이터의 수 "<<Count(&list)<<endl;
	if(First(&list, &item)){
		cout<<item<<" ";
		
		while(Next(&list, &item))
			cout<<item<<" ";
	}
}
