#include <stdio.h>

void BubbleSort(int arr[], int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
int main(void){
	
	int arr[7] = {3,2,4,1,5,9,6};
	int i;
	
	BubbleSort(arr, sizeof(arr)/sizeof(int));
	for(i=0;i<7;i++)
		printf("%d ", arr[i]);
	
	return 0;
}
