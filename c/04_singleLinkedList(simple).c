#include <stdio.h>
#include <stdlib.h>	// exit
#include <stdbool.h>	// bool, true, false

// 노드: 데이터, 링크
typedef struct _SNode {
	int		data;
	struct  _SNode* link;
}SNode;

// 단순 연결 리스트
typedef struct _SLinkedList {
	SNode*    	head;		// 첫 번째 노드
	// SNode*	tail;		// 맨 마지막 노드
	// int		count;		// 노드의 총 개수
}SLinkedList;

// 단순 연결 리스트: 함수 정의
_Bool	isEmpty(SLinkedList* sList);			// 빈 리스트 여부 판단
int	countSNode(SLinkedList* sList);			// 탐색: 노드의 총 개수(count)
SNode*	frontSNode(SLinkedList* sList);			// 탐색: 첫 번째 노드
SNode*	rearSNode(SLinkedList* sList);			// 탐색: 맨 마지막 노드(tail)
SNode*	makeSNode(int num);				// 새로운 노드 생성
void	addRear(SLinkedList* sList, SNode* node);	// 노드 삽입: 맨 마지막 노드로...
void	removeFront(SLinkedList* sList);		// 노드 삭제: 첫 번째 노드를...
void	printSLinkedList(SLinkedList* sList);		// 리스트의 전체 노드 출력

int main(void)
{
	// 빈 리스트 생성
	SLinkedList* sList = (SLinkedList*)malloc(sizeof(SLinkedList));
	if (sList == NULL) {
		printf("메모리 할당 실패!!! \n");
		exit(100);
	}
	sList->head = NULL;

	int	num;
	while (true) {
		printf("임의의 정수 입력 (종료 : 0) : ");
		scanf_s("%d", &num);
		// scanf("%d", &num);
		if (num == 0)
			break;

		SNode* newSNode = makeSNode(num);	// 새로운 노드 생성		
		addRear(sList, newSNode);		// 맨 마지막 노드로 삽입
	}

	// 전체 원소 출력
	if (isEmpty(sList)) {
		printf("입력된 데이터가 없습니다... \n");
		return 0;
	}
	printf("\n ### 입력된 데이터 ### \n\n");
	printSLinkedList(sList);

	// 전체 원소 삭제
	while (!isEmpty(sList))
		removeFront(sList);
	free(sList);
	return 0;
}

// 빈 리스트 여부 판단
_Bool	isEmpty(SLinkedList* sList) {
	return sList->head == NULL;
}

// 탐색: 노드의 총 개수(count)
int		countSNode(SLinkedList* sList) {
	if (isEmpty(sList))
		return 0;

	int	count = 0;
	SNode* rNode = sList->head;
	while (rNode->link) {
		count++;
		rNode = rNode->link;
	}
	return count;
}

// 탐색: 첫 번째 노드
SNode* frontSNode(SLinkedList* sList) {
	return sList->head;
}

// 탐색: 맨 마지막 노드(tail)
SNode* rearSNode(SLinkedList* sList) {
	if (isEmpty(sList))
		return NULL;
	// 맨 마지막 노드 탐색
	SNode* rNode = sList->head;
	while (rNode->link)
		rNode = rNode->link;
	return rNode;
}

// 새로운 노드 생성
SNode* makeSNode(int num) {
	SNode* newSNode = (SNode*)malloc(sizeof(SNode));
	if (newSNode == NULL) {
		printf("메모리 할당 실패!!! \n");
		exit(100);
	}
	newSNode->data = num;
	newSNode->link = NULL;
	return newSNode;
}

// 노드 삽입: 맨 마지막 노드로...
void addRear(SLinkedList* sList, SNode* nNode) {
	if (isEmpty(sList))	sList->head = nNode;
	else {
		SNode* rNode = rearSNode(sList);
		rNode->link = nNode;
	}
}

// 노드 삭제: 첫 번째 노드를...
void	removeFront(SLinkedList* sList) {
	SNode* old;
	while (sList->head) {
		old = sList->head;
		sList->head = sList->head->link;
		free(old);
	}
}

// 리스트의 전체 노드 출력
void	printSLinkedList(SLinkedList* sList) {
	SNode* temp = sList->head;
	while (temp) {
		printf("%3d ->>", temp->data);
		temp = temp->link;
	}
	printf(" NULL\n");
}
