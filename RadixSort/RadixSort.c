#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM	10

void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);
void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);
Data QPeek(Queue *pq);

void RadixSort(int arr[], int num, int maxLen){
	Queue buckets[BUCKET_NUM];
	int divfac = 1;
	int pos = 0;
	int div;
	
	
	for(int d=0;d<maxLen;d++){
	
		for(int i=0;i<BUCKET_NUM;i++)
			QueueInit(&buckets[i]);	
		
		for(int i=0;i<num;i++){
			div=arr[i]/divfac%10;
			Enqueue(&buckets[div], arr[i]);
			//printf("divfac : %d div : %d, arr[i] : %d\n",divfac, div,arr[i]);
		}
		for(int i=0;i<BUCKET_NUM;i++){
			while(!QIsEmpty(&buckets[i])){
			
				arr[pos]=Dequeue(&buckets[i]);
				//printf("i : %d , arr[pos] : %d, pos : %d\n",i,arr[pos],pos);
				pos++;
			}		
		}
		divfac=divfac*10;
		pos = 0;	
	}
}
int main(void){
	int arr[7] = {13, 212, 14 , 7141, 10987, 6, 15};
	int len = sizeof(arr)/sizeof(int);
	
	RadixSort(arr,len,5);
	
	for(int i=0;i<len;i++)
		printf("%d ", arr[i]);
	
}
