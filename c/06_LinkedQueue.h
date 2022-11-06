/*
	큐: 알고리즘 구현(C) -- 단순 연결 리스트
		파일명: LinkedQueue.h
			- 큐의 생성.소멸      : queueCreate, queueDestroy
			- 데이터 삽입.삭제    : enQueue, deQueue
			- 데이터 확인(peek)   : front, back
			- 빈 스택 여부 판단   : queueEempty
			- 큐의 크기          : stackSize
			- 큐의 전체 원소 출력	: printStack
*/

// #pragma once
#include "LinkedSNode.h"		// SNode
typedef		int			element;

// 큐 생성: LinkedQueue
#ifndef __LinkdedQueue_H__
#define __LinkdedQueue_H__
typedef struct __LinkedQueue {
	SNode*	__front, *__rear;
	int		__count;
}LinkedQueue;
#endif

// 큐 구현(C):: 큐 생성 및 활용
LinkedQueue*	queueCreate(void);
void			    queueDestroy(LinkedQueue* LQ);
void			    enQueue(LinkedQueue* LQ, element data);
void			    deQueue(LinkedQueue* LQ);
element		    front(LinkedQueue* LQ);
element		    back(LinkedQueue* LQ);
_Bool			    queueEempty(LinkedQueue* LQ);
int				    queueSize(LinkedQueue* LQ);
void			    printQueue(LinkedQueue* LQ);
