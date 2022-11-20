/*
	단순 연결 리스트: 알고리즘 구현(C)
		파일명: singleLinkedList(head).c
			- 리스트 성생 및 삭제	: sListCreate, sListDestroy
			- 노드 탐색				: isEmpty, countSNode, frontSNode, rearSNode
			- 노드 삽입 및 삭제		: addRear, removeFront
			- 전체 원소 출력		: printSLinkedList
*/

#include <stdio.h>
#include <stdlib.h>						// exit, malloc, free
#include <stdbool.h>					// bool, true, false
#include "singleLinkedList(head).h"		// SLinkedList, SNode, makeSNode
// #include "LinkedNode.h"				// SNode, makeSNode

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

// 리스트 삭제: 리스트의 전체 노드 삭제
SLinkedList* sListDestroy(SLinkedList* sList) {
	//	while (!isEmpty(sList))
	//		removeFront(sList);
	SNode* tNode, * old;	
	tNode = sList->__head;
	while (tNode) {
		old = tNode;
		tNode = tNode->__link;
		free(old);
	}
	return NULL;
}

// 탐색: 첫 번째 노드
SNode* frontSNode(SLinkedList* sList) {
	return sList->__head;
}

// 탐색: 맨 마지막 노드(tail)
SNode* rearSNode(SLinkedList* sList) {
	if (isEmpty(sList))
		return NULL;

	SNode* rNode = sList->__head;
	while (rNode->__link)
		rNode = rNode->__link;
	return rNode;
}

// 노드 삽입: 맨 마지막 노드로...
void addRear(SLinkedList* sList, SNode* nNode) {
	if (isEmpty(sList)) {
		sList->__head = nNode;
	}
	else {
		SNode* rNode = rearSNode(sList);
		rNode->__link = nNode;
	}
}

// 노드 삭제: 첫 번째 노드를...
void	removeFront(SLinkedList* sList) {
	if (isEmpty(sList))
		return;

	SNode* old = sList->__head;
	sList->__head = sList->__head->__link;	
	free(old);
}

// 빈 리스트 여부 판단
_Bool	isEmpty(SLinkedList* sList) {
	return sList->__head == NULL;
}

// 탐색: 노드의 총 개수(count)
int	countSNode(SLinkedList* sList) {
	if (isEmpty(sList))
		return 0;

	int	count = 0;
	SNode* rNode = sList->__head;
	while (rNode->__link) {
		count++;
		rNode = rNode->__link;
	}
	return count;
}

// 리스트의 전체 노드 출력
void	printSLinkedList(SLinkedList* sList) {
	if (isEmpty(sList)) {
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
