/*
	큐: 알고리즘 구현 -- 연결자료구조(단순연결리스트)
		파일명: LinkedQueue.c
			- 큐의 생성.소멸		: queueCreate, queueDestroy
			- 데이터 삽입.삭제		: enQueue, deQueue
			- 데이터 확인(peek)		: front, back
			- 빈 스택 여부 판단		: queueEempty
			- 큐의 전체 원소 개수	: queueSize
			- 큐의 전체 원소 출력	: printQueue
*/

#include <stdio.h>
#include <stdlib.h>			// malloc, free
#include "LinkedQueue.h"	// LinkedQueue, SNode
// #include "LinkedNode.h"	// SNode, DNode

// queueCreate : 빈 큐 생성
LinkedQueue* queueCreate(void) {
	LinkedQueue* Queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	if (Queue == NULL) {
		printf("스택 생성 실패!!! \n");
		return NULL;
	}
	Queue->__front = NULL;
	Queue->__rear = NULL;
	return Queue;
}

// queueDestroy : 큐 삭제 -- 모든 노드 삭제
void queueDestroy(LinkedQueue* Q) {
	SNode* temp = Queue->__front;
	while (temp) {
		Queue->__front = temp->__link;
		free(temp);
		temp = Queue->__front;
	}
	free(Queue);
	return;
}

// enQueue : 큐에 데이터 삽입
void enQueue(LinkedQueue *Queue, element  data) {
	SNode* newSNode = makeSNode(data);
	if (Queue->__front == NULL) {
		Queue->__front = newSNode;
		Queue->__rear = newSNode;
	}
	else {
		Queue->__rear->__link = newSNode;
		Queue->__rear = newSNode;
	}
	Queue->__count++;
}

// deQueue : 큐에서 데이터 삭제
void	deQueue(LinkedQueue *Queue) {
	if (queueEempty(Queue))	return;
	SNode* temp = Queue->__front;
	Queue->__front = temp->__link;
	if (Queue->__front == NULL)
		Queue->__rear = NULL;
	free(temp);
	Queue->__count--;
}

// front : 큐에서 첫 번째 원소 확인
element front(LinkedQueue *Queue) {
	if (queueEempty(Queue))	return EOF;	// return NULL;	
	return  Queue->__front->__data;
}

// back : 큐에서 맨 마지막 원소 확인
element back(LinkedQueue *Queue) {
	if (queueEempty(Queue))	return EOF;	// return NULL;
	return  Queue->__rear->__data;
}

// queueEempty : 큐의 공백 상태 여부 판단
_Bool queueEempty(LinkedQueue *Queue) {
	return Queue->__front == NULL;
}

// queueSize: 큐의 크기
int	queueSize(LinkedQueue *Queue) {
	return Queue->__count;

}

// printQueue : 큐의 전체 원소 출력
void printQueue(LinkedQueue *Queue) {
	SNode	*temp = Queue->__front;
	printf("\n Queue [");
	while (temp) {
		printf("%3d", temp->__data);
		temp = temp->__link;
	}
	printf(" ]\n");
}
