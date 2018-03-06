#include <stdio.h>

void InsertionSort(int arr[], int n){
	int value;
	int j;
	for(int i=1 ; i<n ;i++){
		value = arr[i];
		for(j=i-1;j>=0;j--){
			if(value<arr[j]){
				arr[j+1]=arr[j];
			}
			else{
				break;
			}
			
		}
		arr[j+1]=value;
			
	}
}

int main(void){
	int arr[6]={4,3,6,5,2,1};
	InsertionSort(arr,sizeof(arr)/sizeof(int));
	
	for(int i=0; i<6;i++){
		printf("%d ",arr[i]);
	}
	
	return 0;
}
