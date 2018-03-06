#include "SimpleHeap.h"

void HeapInit(Heap *ph)
{
	ph->numOfData = 0;
}

int HIsEmpty(Heap *ph){
	if(ph->numOfData==0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx){
	return idx/2;
}

int GetLChildIDX(int idx){
	return idx*2;
}

int GetRChildIDX(int idx){
	return (idx*2)+1;
}

int GetHiPriChildIDX(Heap * ph, int idx){
	//자식노드가 없으면 0반환
	// numOfData가 맨 마지막의 노드의 idx를 가리키고 있는데
	// 왼쪽자식 노드의 idx 값이 더 크다는 것은
	// 자식노드가 없다는 것 
	if(GetLChildIDX(idx) > ph->numOfData)
		return 0; 
	//왼쪽 자식 노드의 idx값과 numOfData가 같다는 것은
	//왼쪽 자식노드만 존재하는 것 이므로 왼쪽 자식노드 반환 
	else if(GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);
	else{
		if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}
void HInsert(Heap *ph, HData data, Priority pr)
{
	int idx = ph->numOfData+1;
	HeapElem newElem = {pr,data};
	
	while(idx != 1){
		if(pr < (ph->heapArr[GetParentIDX(idx)].pr))
		{
			ph ->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}
	
	ph->heapArr[idx] = newElem;
	ph->numOfData+=1;
}

HData HDelete(Heap *ph){
	HData tempData = ph->heapArr[1].data;
	HeapElem lastElem = ph->heapArr[ph->numOfData];
	
	int parentIdx = 1;
	int childIdx;
	
	while(childIdx = GetHiPriChildIDX(ph, parentIdx)){
		if(lastElem.pr <= ph->heapArr[childIdx].pr)
			break;
		ph->heapArr[parentIdx]=ph->heapArr[childIdx];
		parentIdx = childIdx;
	}
	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData-=1;
	return tempData;
}
