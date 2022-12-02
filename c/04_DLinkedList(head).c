/*
	이중 연결 리스트: 알고리즘 구현(C)
		파일명: DLinkedList(head).c
		함수원형:
			- 리스트 성생 및 삭제	: dListCreate, dListDestroy
			- 노드 삽입.삭제	: dListAddRear, dListRemoveFront
			- 노드 탐색		: dListEmpty, countDNode, frontDNode, rearDNode			
			- 전체 원소 출력	: printDLinkedList
*/

#include <stdio.h>
#include <stdlib.h>		// exit, malloc, free
#include <stdbool.h>		// bool, true, false
#include "DLinkedList(head).h"	// DLinkedList, DNode, makeDNode
// #include "LinkedNode.h"	// DNode, makeDNode

// 빈 리스트 생성
DLinkedList* dListCreate(void) {
	DLinkedList* dList = (DLinkedList*)malloc(sizeof(DLinkedList));
	if (dList == NULL) {
		printf("메모리 할당 실패!!! \n");
		exit(1);
	}
	dList->__head = NULL;
	return dList;
}

// 리스트 삭제: 전체 노드 삭제
DLinkedList* dListDestroy(DLinkedList* dList) {
	//	while (!dListEmpty(sList))
	//		dListRemoveFront(sList);
	//	free(dList);
	DNode* tNode, * old;
	tNode = dList->__head;
	while (tNode) {
		old = tNode;
		tNode = tNode->__Llink;
		free(old);
	}
	free(dList);
	return NULL;
}

// 삽입: 리스트의 맨 마지막 노드로...
void dListAddRear(DLinkedList* dList, DNode* nNode) {
	if (dListEmpty(dList))	dList->__head = nNode;
	else {
		DNode* rNode = rearDNode(dList);
		rNode->__Rlink = nNode;
		nNode->__Llink = rNode;
	}
}

// 삭제: 리스트에서 첫 번째 노드를...
void	dListRemoveFront(DLinkedList* dList) {
	if (dListEmpty(dList))
		return;

	DNode* old = dList->__head;
	dList->__head = old->__Rlink;
	if (dList->__head != NULL)
		dList->__head->__Llink = NULL;
	free(old);
}

// 검색: 첫 번째 노드(head)
DNode* frontDNode(DLinkedList* dList) {
	return dList->__head;
}

// 검색: 맨 마지막 노드(tail)
DNode* rearDNode(DLinkedList* dList) {
	if (dListEmpty(dList))
		return NULL;

	DNode* rNode = dList->__head;
	while (rNode->__Rlink)
		rNode = rNode->__Rlink;
	return rNode;
}

// 검색: 노드의 총 개수(count)
int	countDNode(DLinkedList* dList) {
	if (dListEmpty(dList))
		return 0;

	int	count = 0;
	DNode* rNode = dList->__head;
	while (rNode->__Rlink) {
		count++;
		rNode = rNode->__Rlink;
	}
	return count;
}

// 빈 리스트 여부 판단
_Bool	dListEmpty(DLinkedList* dList) {
	return dList->__head == NULL;
}

// 리스트 전체 출력(순방향)
void	printDLinkedList(DLinkedList* dList) {
	if (dListEmpty(dList)) {
		printf("입력된 데이터가 없습니다... \n");
		return;
	}

	printf("\n ### 입력된 데이터(순방향) ### \n\n");
	DNode* tNode = dList->__head;
	while (tNode) {
		printf("%3d ->>", tNode->__data);
		tNode = tNode->__Rlink;
	}
	printf(" NULL\n");
}

// 리스트 전체 출력(역방향)
void	revPrintDLinkedList(DLinkedList* dList) {
	if (dListEmpty(dList)) {
		printf("입력된 데이터가 없습니다... \n");
		return;
	}

	printf("\n ### 입력된 데이터(역방향) ### \n\n");
	DNode* tNode = rearDNode(dList);
	while (tNode) {
		printf("%3d ->>", tNode->__data);
		tNode = tNode->__Llink;
	}
	printf(" NULL\n");
}
