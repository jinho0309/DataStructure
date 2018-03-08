#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right){
	int fIdx = left;
	int rIdx = mid+1;
	int *sortArr = (int*)malloc(sizeof(int*)*(right+1));
	int sIdx = left;
	
	for(int i=left;i<=right;i++)
		printf("Merge : %d\n",i);
	while(fIdx<=mid && rIdx <=right){
		if(arr[fIdx]<=arr[rIdx])
			sortArr[sIdx]=arr[fIdx++];
		else
			sortArr[sIdx]=arr[rIdx++];
		
		sIdx++;
	}
	if(fIdx>mid){
		for(int i=rIdx;i<=right;i++,sIdx++)
			sortArr[sIdx]=arr[i];
	}
	else{
		for(int i=fIdx;i<=mid;i++,sIdx++)
			sortArr[sIdx]=arr[i];
	}
	for(int i=left ; i<=right ; i++)
		arr[i]=sortArr[i];
		
	free(sortArr);
}
void MergeSort(int arr[], int left, int right){
	int mid;
	if(left<right){
	
		mid = (left+right)/2;
		printf("1. left : %d , right : %d, mid : %d\n",left,right,mid);
		MergeSort(arr,left,mid);
		printf("2. left : %d , right : %d, mid : %d\n",left,right,mid);
		MergeSort(arr,mid+1,right);
		printf("3. left : %d , right : %d, mid : %d\n",left,right,mid);
		MergeTwoArea(arr,left,mid,right);
	}
}

int main(void){
	int arr[7] = {3, 2, 4, 1, 7, 6, 5};
	
	MergeSort(arr,0,sizeof(arr)/sizeof(int)-1);
	
	for(int i=0;i<7;i++)
		printf("%d ", arr[i]);
		
	return 0;
}
