/*
	큐: 알고리즘 구현 -- 연결자료구조(단순연결리스트)
		파일명: LinkedQueue.c
			- 큐의 생성.소멸		: queueCreate, queueDestroy
			- 데이터 삽입.삭제		: enQueue, deQueue
			- 데이터 확인(peek)		: front, back
			- 빈 스택 여부 판단		: queueEempty
			- 큐의 크기				: stackSize
			- 큐의 전체 원소 출력	: printStack
*/

#include <stdio.h>
#include <stdlib.h>			// malloc, free
#include "LinkedQueue.h"	// LinkedQueue, SNode
// #include "LinkedSNode.h"	// SNode

// queueCreate : 빈 큐 생성
LinkedQueue* queueCreate(void) {
	LinkedQueue* LQ = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	if (LQ == NULL) {
		printf("스택 생성 실패!!! \n");
		return NULL;
	}
	LQ->__front = NULL;
	LQ->__rear = NULL;
	return LQ;
}

// queueDestroy : 큐 삭제 -- 모든 노드 삭제
void queueDestroy(LinkedQueue* LQ) {
	SNode* temp = LQ->__front;
	while (temp) {
		LQ->__front = temp->__link;
		free(temp);
		temp = LQ->__front;
	}
	free(LQ);
	return;
}

// enQueue : 큐에서 데이터 삽입
void enQueue(LinkedQueue* LQ, element  data) {
	SNode* newSNode = makeSNode(data);
	if (LQ->__front == NULL) {
		LQ->__front = newSNode;
		LQ->__rear = newSNode;
	}
	else {
		LQ->__rear->__link = newSNode;
		LQ->__rear = newSNode;
	}
}

// deQueue : 큐에서 데이터 삭제
void	deQueue(LinkedQueue* LQ) {
	if (queueEempty(LQ))	return;
	SNode* temp = LQ->__front;
	LQ->__front = temp->__link;
	if (LQ->__front == NULL)
		LQ->__rear = NULL;
	free(temp);
}

// front : 첫 번째 원소 확인
element front(LinkedQueue* LQ) {
	if (queueEempty(LQ))	return EOF;	// return NULL;	
	return  LQ->__front->__data;
}

// back : 맨 마지막 원소
element back(LinkedQueue* LQ) {
	if (queueEempty(LQ))	return EOF;	// return NULL;
	return  LQ->__rear->__data;
}

// queueEempty : 공백 상태 여부 판단
_Bool queueEempty(LinkedQueue* LQ) {
	return LQ->__front == NULL;
}

// queueSize: 큐의 크기
int		queueSize(LinkedQueue* LQ) {
	return LQ->__count;

}

// printQueue : 스택의 전체 원소 출력
void printQueue(LinkedQueue* LQ) {
	SNode* temp = LQ->__front;
	printf("\n Queue [");
	while (temp) {
		printf("%3d", temp->__data);
		temp = temp->__link;
	}
	printf(" ]\n");
}
