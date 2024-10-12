/*
	스택: 알고리즘 구현(C) -- 단순 연결 리스트
		파일명: LinkedStack.h
			- 스택 생성.소멸		: stackCreate, stackDestroy
			- 데이터 삽입.삭제	: push, pop
			- 데이터 확인(peek)	: top
			- 빈 스택 여부 판단	: stackEmpty
			- 스택 크기		: stackSize
			- 스택의 전체 원소 출력	: printStack
*/

// #pragma once
#include "LinkedNode.h"		// SNode, makeSNode

// 스택(순차 자료구조): LinkedStack
#ifndef __LinkedStack_H__
#define __LinkedStack_H__

// 구조체 설계: LinkedStack
typedef struct _LinkedStack {
	SNode	*top;
	int	count;
} LinkedStack;

#endif

// LinkedStack: 스택 생성 및 조작 함수
LinkedStack	*stackCreate(void);				// 빈 스택 생성
void		stackDestroy(LinkedStack *Stack);		// 스택 삭제
_Bool		stackEmpty(LinkedStack *Stack);			// 빈 스택 여부(top)
int		stackSize(LinkedStack *Stack);			// 스택의 원소 개수(top)
void		push(LinkedStack *Stack, element data);		// 데이터 삽입: 스택에 데이터 추가(top)
void		pop(LinkedStack *Stack);			// 데이터 삭제: 스택에서 데이터 제거(top)
element		top(LinkedStack *Stack);			// 데이터 확인(peek): 맨 위에 있는 데이터 확인(top)
void		printStack(LinkedStack* Stack);			// 데이터 출력: 스택의 전체 데이터 출력
