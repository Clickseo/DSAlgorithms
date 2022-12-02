/*
	단순 연결 리스트: 알고리즘 구현(C)
		파일명: SLinkedList(head).c
		함수원형: 
			- 리스트 성생 및 삭제	: sListCreate, sListDestroy
			- 노드 삽입.삭제	: sListAddRear, sListRemoveFront
			- 노드 검색		: sListEmpty, countSNode, frontSNode, rearSNode
			- 리스트 전체 출력	: printSLinkedList
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
	sList->__head = NULL;
	return sList;
}

// 리스트 삭제: 전체 노드 삭제
SLinkedList* sListDestroy(SLinkedList* sList) {
	//	while (!sListEmpty(sList))
	//		sListRemoveFront(sList);
	SNode* tNode, * old;	
	tNode = sList->__head;
	while (tNode) {
		old = tNode;
		tNode = tNode->__link;
		free(old);
	}
	
	return NULL;
}

// 노드 삽입: 맨 마지막 노드로...
void sListAddRear(SLinkedList* sList, SNode* nNode) {
	if (sListEmpty(sList)) {
		sList->__head = nNode;
	}
	else {
		SNode* rNode = rearSNode(sList);
		rNode->__link = nNode;
	}
}

// 노드 삭제: 첫 번째 노드를...
void	sListRemoveFront(SLinkedList* sList) {
	if (sListEmpty(sList))
		return;

	SNode* old = sList->__head;
	sList->__head = old->__link;
	free(old);
}

// 검색: 첫 번째 노드(head)
SNode* frontSNode(SLinkedList* sList) {
	return sList->__head;
}

// 검색: 맨 마지막 노드(tail)
SNode* rearSNode(SLinkedList* sList) {
	if (sListEmpty(sList))
		return NULL;

	SNode* rNode = sList->__head;
	while (rNode->__link)
		rNode = rNode->__link;
	return rNode;
}

// 검색: 노드의 총 개수(count)
int	countSNode(SLinkedList* sList) {
	if (sListEmpty(sList))
		return 0;

	int	count = 0;
	SNode* rNode = sList->__head;
	while (rNode->__link) {
		count++;
		rNode = rNode->__link;
	}
	return count;
}

// 빈 리스트 여부 판단
_Bool	sListEmpty(SLinkedList* sList) {
	return sList->__head == NULL;
}

// 리스트 전체 출력
void	printSLinkedList(SLinkedList* sList) {
	if (sListEmpty(sList)) {
		printf("입력된 데이터가 없습니다... \n");
		return;
	}

	printf("\n ### 입력된 데이터 ### \n\n");
	SNode* tNode = sList->__head;
	while (tNode) {
		printf("%3d ->>", tNode->__data);
		tNode = tNode->__link;
	}
	printf(" NULL\n");
}
