#include <stdio.h>
#include "ListBaseQueue.h"

int main(void)
{
	Queue q;
	QueueInit(&q);
	
	for(int i=1 ;i<6 ; i++)
		Enqueue(&q, i);
	while(!QIsEmpty(&q))
		printf("%d ",Dequeue(&q));
}
