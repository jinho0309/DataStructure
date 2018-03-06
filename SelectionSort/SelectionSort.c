#include <stdio.h>

void SelectionSort(int arr[], int n){
	int i, j;
	int maxIdx;
	int temp;
	
	for(i=0; i<n-1; i++){
		maxIdx = i;
		
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[maxIdx])
				maxIdx = j;
		}
		temp = arr[i];
		arr[i] =arr[maxIdx];
		arr[maxIdx] = temp;
	}
}

int main(void){
	int arr[6]={4,3,6,5,2,1};
	SelectionSort(arr,sizeof(arr)/sizeof(int));
	
	for(int i=0; i<6;i++){
		printf("%d ",arr[i]);
	}
	
	return 0;
}
