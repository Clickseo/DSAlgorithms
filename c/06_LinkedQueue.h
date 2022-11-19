/*
	큐: 알고리즘 구현(C) -- 단순 연결 리스트
		파일명: LinkedQueue.h
			- 큐의 생성.소멸		: queueCreate, queueDestroy
			- 데이터 삽입.삭제	: enQueue, deQueue
			- 데이터 확인(peek)	: front, back
			- 빈 스택 여부 판단	: queueEempty
			- 큐의 크기		: queueSize
			- 큐의 전체 원소 출력	: printQueue
*/

// #pragma once
#include "LinkedNode.h"		// SNode, DNode

// 큐 생성: LinkedQueue
#ifndef __LinkdedQueue_H__
#define __LinkdedQueue_H__
typedef struct __LinkedQueue {
	SNode*	__front, *__rear;
	int	__count;
}LinkedQueue;
#endif

// 큐 구현(C):: 큐 생성 및 활용
LinkedQueue*	queueCreate(void);
void		queueDestroy(LinkedQueue* Q);
void		enQueue(LinkedQueue* Q, element data);
void		deQueue(LinkedQueue* Q);
element		front(LinkedQueue* Q);
element		back(LinkedQueue* Q);
_Bool		queueEempty(LinkedQueue* Q);
int		queueSize(LinkedQueue* Q);
void		printQueue(LinkedQueue* Q);
