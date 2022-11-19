/*
	큐: 알고리즘 구현 -- 연결자료구조(단순연결리스트)
		파일명: LinkedQueue.c
			- 큐의 생성.소멸		: queueCreate, queueDestroy
			- 데이터 삽입.삭제	: enQueue, deQueue
			- 데이터 확인(peek)	: front, back
			- 빈 스택 여부 판단	: queueEempty
			- 큐의 크기		: queueSize
			- 큐의 전체 원소 출력	: printQueue
*/

#include <stdio.h>
#include <stdlib.h>		// malloc, free
#include "LinkedQueue.h"	// LinkedQueue, SNode
// #include "LinkedNode.h"	// SNode, DNode

// queueCreate : 빈 큐 생성
LinkedQueue* queueCreate(void) {
	LinkedQueue* Q = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	if (Q == NULL) {
		printf("스택 생성 실패!!! \n");
		return NULL;
	}
	Q->__front = NULL;
	Q->__rear = NULL;
	return Q;
}

// queueDestroy : 큐 삭제 -- 모든 노드 삭제
void queueDestroy(LinkedQueue* Q) {
	SNode* temp = Q->__front;
	while (temp) {
		Q->__front = temp->__link;
		free(temp);
		temp = Q->__front;
	}
	free(Q);
	return;
}

// enQueue : 큐에 데이터 삽입
void enQueue(LinkedQueue* Q, element  data) {
	SNode* newSNode = makeSNode(data);
	if (Q->__front == NULL) {
		Q->__front = newSNode;
		Q->__rear = newSNode;
	}
	else {
		Q->__rear->__link = newSNode;
		Q->__rear = newSNode;
	}
}

// deQueue : 큐에서 데이터 삭제
void	deQueue(LinkedQueue* Q) {
	if (queueEempty(Q))	return;
	SNode* temp = Q->__front;
	Q->__front = temp->__link;
	if (Q->__front == NULL)
		Q->__rear = NULL;
	free(temp);
}

// front : 큐에서 첫 번째 원소 확인
element front(LinkedQueue* Q) {
	if (queueEempty(Q))	return EOF;	// return NULL;	
	return  Q->__front->__data;
}

// back : 큐에서 맨 마지막 원소 확인
element back(LinkedQueue* Q) {
	if (queueEempty(Q))	return EOF;	// return NULL;
	return  Q->__rear->__data;
}

// queueEempty : 큐의 공백 상태 여부 판단
_Bool queueEempty(LinkedQueue* Q) {
	return Q->__front == NULL;
}

// queueSize: 큐의 크기
int	queueSize(LinkedQueue* Q) {
	return Q->__count;

}

// printQueue : 큐의 전체 원소 출력
void printQueue(LinkedQueue* Q) {
	SNode* temp = Q->__front;
	printf("\n Queue [");
	while (temp) {
		printf("%3d", temp->__data);
		temp = temp->__link;
	}
	printf(" ]\n");
}
