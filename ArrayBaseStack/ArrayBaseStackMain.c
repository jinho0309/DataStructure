#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void)
{
	
	Stack stack;
	StackInit(&stack);
	
	for(int i=1 ; i<6;i++)
		Push(&stack, i);
	
	while(!IsEmpty(&stack))
		printf("%d ", Pop(&stack));
		
	
}
