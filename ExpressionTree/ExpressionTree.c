#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "BinaryTree.h"


typedef void (*VisitFuncPtr)(int);

BTreeNode * MakeExpTree(char exp[]){
	Stack stack;
	BTreeNode *pnode;
	int expLen = strlen(exp);
	char tok;
	StackInit(&stack);
	for(int i=0; i<expLen ; i++){
		tok = exp[i];
		pnode = MakeBTreeNode();
		if(isdigit(tok)){
			SetData(pnode, exp[i]-'0');
		}
		else{
			MakeRightSubTree(pnode, Pop(&stack));
			MakeLeftSubTree(pnode, Pop(&stack));
			SetData(pnode, exp[i]);
			
		}
		Push(&stack, pnode);
	}
	
	return Pop(&stack);
	
}
int EvaluateExpTree(BTreeNode * bt);
void ShowNodeData(int data)
{
	if(0<= data && data <=9)
		printf("%d ", data);
	else
		printf("%c ", data);
}
void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action){
	if(bt==NULL)
		return;
	action(bt->data);
	PreorderTraverse(bt->left, ShowNodeData);
	PreorderTraverse(bt->right, ShowNodeData);
}
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action){
	if(bt==NULL)
		return;
	
	InorderTraverse(bt->left, ShowNodeData);
	action(bt->data);
	InorderTraverse(bt->right, ShowNodeData);
}
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action){
	if(bt==NULL)
		return;
	
	PostorderTraverse(bt->left, ShowNodeData);
	
	PostorderTraverse(bt->right, ShowNodeData);
	action(bt->data);
}



void ShowPrefixTypeExp(BTreeNode *bt){
	PreorderTraverse(bt, ShowNodeData);
}
void ShowInfixTypeExp(BTreeNode *bt){
	InorderTraverse(bt, ShowNodeData);
}
void ShowPostfixTypeExp(BTreeNode *bt){
	PostorderTraverse(bt, ShowNodeData);
}

int main(void){
	char exp[] = "12+7*";
	BTreeNode *eTree= MakeExpTree(exp);
	ShowPrefixTypeExp(eTree);printf("\n");
	ShowInfixTypeExp(eTree);printf("\n");
	ShowPostfixTypeExp(eTree);printf("\n");
}
