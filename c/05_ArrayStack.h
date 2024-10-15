/*
	스택: 알고리즘 구현(C) -- 순차 자료구조
		파일명: ArrayStack.h
			- 스택 생성.소멸	: stackCreate, stackDestroy
			- 스택 상태		: stackEmpty, stackFull
			- 스택 크기		: stackSize
			- 데이터 삽입.삭제	: push, pop
			- 데이터 확인(peek)	: top
			- 전체 데이터 출력	: printStack
*/

// #pragma once
#define			StackMAXSIZE 1024
typedef	int		element;

// 스택(순차 자료구조): ArrayStack
#ifndef __ArrayStack_H__
#define __ArrayStack_H__

// 구조체 설계: ArrayStack
typedef struct _ArrayStack {
	int		top;
	element		stack[StackMAXSIZE];
} ArrayStack;

#endif

// ArrayStack: 스택 생성 및 조작 함수
ArrayStack	*stackCreate(void);				// 빈 스택 생성
void		stackDestroy(ArrayStack *Stack);		// 스택 삭제: 모든 노드 삭제
_Bool		stackEmpty(ArrayStack *Stack);			// 빈 스택 여부 확인
_Bool		stackFull(ArrayStack *Stack);			// 스택의 포화 상태 여부 확인
int		stackSize(ArrayStack *Stack);			// 스택의 원소 개수
void		push(ArrayStack *Stack, element data);		// 데이터 삽입
void		pop(ArrayStack *Stack);				// 데이터 삭제
element		top(ArrayStack *Stack);				// 스택에서 맨 위의 데이터 확인(peek)
void		printStack(ArrayStack *Stack);			// 스택의 전체 데이터 출력
