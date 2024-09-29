/*
	단순 연결 리스트: 알고리즘 구현(C)
		파일명: SLinkedList(head).c
			- 리스트 성생 및 삭제	: sListCreate, sListDestroy
			- 노드 탐색		: sListEmpty, countSNode, frontSNode, rearSNode
			- 노드 삽입 및 삭제	: sListAddRear, sListRemoveFront
			- 전체 원소 출력	: printSLinkedList
*/

#include <stdio.h>
#include <stdlib.h>		// exit, malloc, free
#include <stdbool.h>		// bool, true, false
#include "SLinkedList(head).h"	// SLinkedList, SNode, makeSNode
// #include "LinkedNode.h"	// SNode, makeSNode

// 빈 리스트 생성
SLinkedList* sListCreate(void) {
	SLinkedList* sList = (SLinkedList*)malloc(sizeof(SLinkedList));
	if (sList == NULL) {
		printf("메모리 할당 실패!!! \n");
		exit(1);
	}
	sList->head = NULL;
	return sList;
}

// 리스트 삭제: 리스트의 전체 노드 삭제
SLinkedList* sListDestroy(SLinkedList* sList) {
	//	while (!sListEmpty(sList))
	//		sListRemoveFront(sList);
	SNode	*tNode, *old;	
	tNode = sList->head;
	while (tNode) {
		old = tNode;
		tNode = tNode->link;
		free(old);
	}
	free(sList);
	return NULL;
}

// 탐색: 첫 번째 노드
SNode* frontSNode(SLinkedList* sList) {
	return sList->head;
}

// 탐색: 맨 마지막 노드(tail)
SNode* rearSNode(SLinkedList* sList) {
	if (sListEmpty(sList))
		return NULL;

	SNode* rNode = sList->head;
	while (rNode->link)
		rNode = rNode->link;
	return rNode;
}

// 노드 삽입: 맨 마지막 노드로...
void sListAddRear(SLinkedList* sList, SNode* newNode) {
	if (sListEmpty(sList)) {
		sList->head = newNode;
	}
	else {
		SNode* rNode = rearSNode(sList);
		rNode->link = newNode;
	}
}

// 노드 삭제: 첫 번째 노드를...
void	sListRemoveFront(SLinkedList* sList) {
	if (sListEmpty(sList))
		return;

	SNode* old = sList->head;
	sList->head = old->link;
	free(old);
}

// 빈 리스트 여부 판단
_Bool	sListEmpty(SLinkedList* sList) {
	return sList->head == NULL;
}

// 탐색: 노드의 총 개수(count)
int	countSNode(SLinkedList* sList) {
	if (sListEmpty(sList))
		return 0;

	int	count = 0;
	SNode* rNode = sList->head;
	while (rNode->link) {
		count++;
		rNode = rNode->link;
	}
	return count;
}

// 리스트의 전체 노드 출력
void	printSLinkedList(SLinkedList* sList) {
	if (sListEmpty(sList)) {
		printf("입력된 데이터가 없습니다... \n");
		return;
	}

	printf("\n ### 입력된 데이터 ### \n\n");
	SNode* tNode = sList->head;
	while (tNode) {
		printf("%3d ->>", tNode->data);
		tNode = tNode->link;
	}
	printf(" NULL\n");
}
