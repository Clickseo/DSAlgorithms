/*
	이중 연결 리스트: 알고리즘 구현
		- DNode		: 노드(data, Llink, Rlink)
		- DLinkedList	: head
*/

#include <stdio.h>
#include <stdlib.h>	// exit
#include <stdbool.h>	// bool, true, false

// 노드: 데이터, 링크
typedef struct _DNode {
	int		data;
	struct  _DNode* Llink;
	struct  _DNode* Rlink;
}DNode;

// 단순 연결 리스트
typedef struct _DLinkedList {
	DNode*		head;	  	// 첫 번째 노드
	// SNode*	tail;	  	// 맨 마지막 노드
	// int		count;		// 노드의 총 개수
}DLinkedList;

// 단순 연결 리스트: 함수 원형
_Bool	isEmpty(DLinkedList* dList);			// 빈 리스트 여부 판단
int	countDNode(DLinkedList* dList);			// 탐색: 노드의 총 개수(count)
DNode*	frontDNode(DLinkedList* dList);			// 탐색: 첫 번째 노드
DNode*	rearDNode(DLinkedList* dList);			// 탐색: 맨 마지막 노드(tail)
DNode*	makeDNode(int num);				// 새로운 노드 생성
void    addRear(DLinkedList* dList, DNode* nNode);	// 노드 삽입: 맨 마지막 노드로...
void	removeFront(DLinkedList* dList);		// 노드 삭제: 첫 번째 노드를...
void	printDLinkedList(DLinkedList* dList);		// 리스트의 전체 노드 출력
void	revPrintDLinkedList(DLinkedList* dList);	// 리스트의 전체 노드 출력

int main(void)
{
	// 빈 리스트 생성
	DLinkedList* dList = (DLinkedList*)malloc(sizeof(DLinkedList));
	if (dList == NULL) {
		printf("메모리 할당 실패!!! \n");
		exit(100);
	}
	dList->head = NULL;

	int	num;
	while (true) {
		printf("임의의 정수 입력 (종료 : 0) : ");
		scanf_s("%d", &num);
		// scanf("%d", &num);
		if (num == 0)
			break;

		DNode* newDNode = makeDNode(num);	// 새로운 노드 생성		
		addRear(dList, newDNode);		// 맨 마지막 노드로 삽입
	}

	// 전체 원소 출력
	if (isEmpty(dList)) {
		printf("입력된 데이터가 없습니다... \n");
		return 0;
	}
	printf("\n ### 입력된 데이터 ### \n\n");
	printDLinkedList(dList);		// 순방향 출력
	revPrintDLinkedList(dList);		// 역방향 출력

	// 전체 원소 삭제
	while (!isEmpty(dList))
		removeFront(dList);
	// printDLinkedList(dList);
	free(dList);
	return 0;
}

// 빈 리스트 여부 판단
_Bool	isEmpty(DLinkedList* dList) {
	return dList->head == NULL;
}

// 탐색: 노드의 총 개수(count)
int		countDNode(DLinkedList* dList) {
	if (isEmpty(dList))
		return 0;

	int	count = 0;
	DNode* rNode = dList->head;
	while (rNode->Rlink) {
		count++;
		rNode = rNode->Rlink;
	}
	return count;
}

// 탐색: 첫 번째 노드
DNode* frontDNode(DLinkedList* dList) {
	return dList->head;
}

// 탐색: 맨 마지막 노드(tail)
DNode* rearDNode(DLinkedList* dList) {
	if (isEmpty(dList))
		return NULL;

	DNode* rNode = dList->head;
	while (rNode->Rlink)
		rNode = rNode->Rlink;
	return rNode;
}

// 새로운 노드 생성
DNode* makeDNode(int num) {
	DNode* newDNode = (DNode*)malloc(sizeof(DNode));
	if (newDNode == NULL) {
		printf("메모리 할당 실패!!! \n");
		exit(100);
	}
	newDNode->data = num;
	newDNode->Llink = NULL;
	newDNode->Rlink = NULL;
	return newDNode;
}

// 노드 삽입: 맨 마지막 노드로...
void addRear(DLinkedList* dList, DNode* nNode) {
	if (isEmpty(dList))	dList->head = nNode;
	else {
		DNode* rNode = rearDNode(dList);
		rNode->Rlink = nNode;
		nNode->Llink = rNode;
	}
}

// 노드 삭제: 첫 번째 노드를...
void	removeFront(DLinkedList* dList) {
	DNode* old;
	while (dList->head) {
		old = dList->head;
		dList->head = old->Rlink;
		if (old->Rlink != NULL)
			old->Rlink->Llink = NULL;
		free(old);
	}
}

// 리스트의 전체 노드 출력(순방향)
void	printDLinkedList(DLinkedList* dList) {
	DNode* temp = dList->head;
	while (temp) {
		printf("%3d ->>", temp->data);
		temp = temp->Rlink;
	}
	printf(" NULL\n");
}

// 리스트의 전체 노드 출력(역방향)
void	revPrintDLinkedList(DLinkedList* dList) {
	DNode* temp = rearDNode(dList);
	while (temp) {
		printf("%3d ->>", temp->data);
		temp = temp->Llink;
	}
	printf(" NULL\n");
}
