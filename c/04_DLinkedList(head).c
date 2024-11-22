/*
	이중 연결 리스트: 알고리즘 구현(C)
		파일명: DLinkedList(head).c
			- 리스트 성생 및 삭제	: dListCreate, dListDestroy
			- 노드 탐색		: dListEmpty, countDNode, frontDNode, rearDNode
			- 노드 삽입 및 삭제	: dListAddRear, dListRemoveFront
			- 전체 원소 출력		: printDLinkedList
*/

#include <stdio.h>
#include <stdlib.h>			// exit, malloc, free
#include <stdbool.h>			// bool, true, false
#include "DLinkedList(head).h"		// DLinkedList >> head
// #include "DLinkedList.h"		// DLinkedList >> head, tail, count
// #include "LinkedNode.h"		// DNode, makeDNode

// 빈 리스트 생성
DLinkedList *dListCreate(void) {
	DLinkedList *dList = (DLinkedList *)malloc(sizeof(DLinkedList));
	if (dList == NULL) {
		printf("메모리 할당 실패!!! \n");
		exit(1);
	}
	dList->head = NULL;
	return dList;
}

// 리스트 삭제: 리스트의 전체 노드 삭제
DLinkedList *dListDestroy(DLinkedList *dList) {
	// while (!dListEmpty(dList))
	//	dListRemoveFront(dList);
	// free(dList);
	DNode	*tNode, *old;
	tNode = dList->head;
	while (tNode) {
		old = tNode;
		tNode = tNode->Llink;
		free(old);
	}
	free(dList);
	return NULL;
}

// 빈 리스트 여부 판단
_Bool	dListEmpty(DLinkedList *dList) {
	return dList->head == NULL;
}

// 탐색: 노드의 총 개수
int	countDNode(DLinkedList *dList) {
	if (dListEmpty(dList)) {
		return 0;
	}

	int	count = 0;
	DNode* rNode = dList->head;
	while (rNode) {
		count++;
		rNode = rNode->Rlink;
	}
	return count;
}

// 탐색: 리스트의 첫 번째 노드(head)
DNode *frontDNode(DLinkedList *dList) {
	return dList->head;
}

// 탐색: 리스트의 맨 마지막 노드
DNode *rearDNode(DLinkedList *dList) {
	if (dListEmpty(dList)) {
		return NULL;
	}

	DNode *rNode = dList->head;
	while (rNode->Rlink) {
		rNode = rNode->Rlink;
	}
	return rNode;
}

// 삽입: 리스트의 맨 마지막 노드로...
void dListAddRear(DLinkedList *dList, DNode *newNode) {
	if (dListEmpty(dList)) {
		dList->head = newNode;
	}
	else {
		DNode *rNode = rearDNode(dList);
		rNode->Rlink = newNode;
		newNode->Llink = rNode;
	}
}

// 삭제: 리스트에서 첫 번째 노드를...
void	dListRemoveFront(DLinkedList *dList) {
	if (dListEmpty(dList)) {
		return;
	}

	DNode *old = dList->head;
	dList->head = old->Rlink;
	if (dList->head != NULL) {
		dList->head->Llink = NULL;
	}
	free(old);
}

// 리스트의 전체 노드 출력(순방향)
void	printDLinkedList(DLinkedList *dList) {
	if (dListEmpty(dList)) {
		printf("입력된 데이터가 없습니다... \n");
		return;
	}

	printf("\n ### 입력된 데이터(순방향) ### \n");
	DNode *tNode = dList->head;
	while (tNode) {
		printf("%3d ->>", tNode->data);
		tNode = tNode->Rlink;
	}
	printf(" NULL\n");
}

// 리스트의 전체 노드 출력(역방향)
void	printRevDLinkedList(DLinkedList *dList) {
	if (dListEmpty(dList)) {
		printf("입력된 데이터가 없습니다... \n");
		return;
	}

	printf("\n ### 입력된 데이터(역방향) ### \n");
	DNode *tNode = rearDNode(dList);
	while (tNode) {
		printf("%3d ->>", tNode->data);
		tNode = tNode->Llink;
	}
	printf(" NULL\n");
}
