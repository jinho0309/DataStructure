#include <stdio.h>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode **pRoot){
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode *bst){
	return bst->data;
}

void BSTInsert(BTreeNode **pRoot, BSTData data){
	BTreeNode * pNode = NULL;//parent
	BTreeNode * cNode = *pRoot;//current
	BTreeNode * nNode = NULL;//new
	
	while(cNode!=NULL){
		if(data == GetData(cNode))
			return ;//�ߺ� ��� X
		pNode=cNode;
		
		if(GetData(cNode)>data)
			cNode=GetLeftSubTree(cNode);
		else
			cNode=GetRightSubTree(cNode);
		 
	}
	nNode = MakeBTreeNode();
	SetData(nNode, data);
	if(pNode!=NULL){
		if(data<GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
		
	}
	else
		*pRoot=nNode;
}

BTreeNode *BSTSearch(BTreeNode *bst, BSTData target){
	BTreeNode *cNode =bst;
	BSTData cd;
	while(cNode!=NULL){
		cd = GetData(cNode);
		if(target == cd)
			return cNode;
		else if(target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	return NULL;
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target){
	BTreeNode * pVRoot = MakeBTreeNode();
	BTreeNode * pNode = pVRoot;
	BTreeNode * cNode = *pRoot;
	BTreeNode * dNode;

// ��Ʈ ��带 pVRoot�� ����Ű�� ����� ���������� 
	ChangeRightSubTree(pVRoot, *pRoot);
	
	while(cNode !=NULL && GetData(cNode)!=target){
		pNode = cNode;
		if(target<GetData(cNode))
			cNode= GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	
	if(cNode == NULL) //����� �������� ����. 
		return NULL;
	
	dNode = cNode;
	
	//1. ���� ����� �ܸ� ����� ���
	if(GetLeftSubTree(dNode)==NULL && GetRightSubTree(dNode)==NULL){
		if(GetLeftSubTree(pNode)==dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}
}

void BSTShowAll(BTreeNode *bst);
