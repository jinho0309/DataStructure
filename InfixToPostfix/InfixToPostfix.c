#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "InfixToPostfix.h"
#include "ListBaseStack.h"

int GetOpPrec(char op){
	switch(op){
		case '*' : case '/' :
			return 5;
		case '+' : case '-' :
			return 3;
		case '(' :
			return 1;
	}
}
int WhoPrecOp(char op1, char op2){
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);
	
	if(op1Prec>=op2Prec)
		return 1;
	else
		return 0;
}
void ConvToRPNExp(char exp[]){
	
	int expLen = strlen(exp);
	int idx=0;
	
	Stack stack;
	StackInit(&stack);
	
	char* convExp = (char*)malloc(expLen+1);
	memset(convExp, 0 ,sizeof(char)*expLen+1);
	char tok;
	
	for(int i=0;i<expLen;i++){
		tok=exp[i];
		if(isdigit(tok)){
			convExp[idx]=tok;
			idx++;
		}
		else{
			switch(tok){
				case '(' :
					Push(&stack,tok);
					break;
				case ')' :
					while(1){
						char temp = Pop(&stack);
						if(temp=='(')
							break;
						convExp[idx]=temp;
						idx++;
					}
					break;
				case '*' : case '+' :
				case '-' : case '/' :
					while(!IsEmpty(&stack)&&WhoPrecOp(Peek(&stack),tok)){
						convExp[idx]=Pop(&stack);
						idx++;
					}
					Push(&stack,tok);
					break;
						
			}
			
		}
	}
	while(!IsEmpty(&stack)){
		convExp[idx]=Pop(&stack);
		idx++;
	}
	strcpy(exp, convExp);
	free(convExp);
}
