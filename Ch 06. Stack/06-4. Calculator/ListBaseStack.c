#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack)
{
	pstack->head = NULL;            // 포인터 변수 head를 NULL로 초기화
}

int SIsEmpty(Stack * pstack)
{
	if(pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack * pstack, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));   // 새로운 노드 생성

	newNode->data = data;               // 새로운 노드에 데이터 저장
	newNode->next = pstack->head;       // 새로운 노드가 최근에 추가된 노드를 가리킨다

	pstack->head = newNode;             //  포인터 변수 head가 새 노드를 가리킨다
}

Data SPop(Stack * pstack)
{
	Data rdata;
	Node * rnode;

	if(SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;         // 삭제할 노드의 데이터를 임시 저장
	rnode = pstack->head;               // 삭제할 노드의 주소값을 임시로 저장

	pstack->head = pstack->head->next;  // 삭제할 노드의 다음 노드를 head가 가리키도록 한다.
	free(rnode);    // 노드를 삭제

	return rdata;   // 삭제한 노드의 데이터를 return 
}

Data SPeek(Stack * pstack)
{
	if(SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;  // head가 가리키는 노드에 저장된 데이터를 반환한다.
}