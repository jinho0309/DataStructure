#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "PostCalculator.h"
int EvalRPNExp(char exp[]){
	Stack stack;
	int expLen = strlen(exp);
	char tok;
	int op1, op2;
	
	StackInit(&stack);
	for(int i=0;i<expLen;i++){
		tok = exp[i];
		if(isdigit(tok)){
			
			Push(&stack,tok-'0');
		}
		else{
			op2 = Pop(&stack);
			op1 = Pop(&stack);
			switch(tok){
				case '+' :
					Push(&stack, op1+op2);
					break;
				case '-' :
					Push(&stack, op1-op2);
					break;
				case '*' :
					Push(&stack, op1*op2);
					break;
				case '/' :
					Push(&stack, op1/op2);
					break;
			}
		}
	}
	return Pop(&stack);
}

