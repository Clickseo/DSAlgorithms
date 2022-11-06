/*
	스택: 알고리즘 구현(C) --단순연결리스트
		파일명: LinkedStack.h
		클래스: SNode
		클래스: LinkedStack
			- 스택 생성.소멸       : stackCreate, stackDestroy
			- 데이터 삽입.삭제     : push, pop
			- 데이터 확인          : top				// peek
			- 빈 스택 여부 판단    : stackEempty
			- 스택 크기            : stackSize
			- 스택의 전체 원소 출력 : printStack
*/

// #pragma once
#ifndef __LinkedStack_H__
#define __LinkedStack_H__
typedef	int		element;

// 노드: SNode(data, link)
typedef struct __SNode {
	element		__data;
	struct __SNode*	__link;
}SNode;

// 스택 생성: LinkedStack, stackNode
typedef struct __LinkedStack {
	SNode*	__top;
	int	__count;
}LinkedStack;
#endif

// 스택 구현(C): 스택 생성 및 활용
SNode*		makeSNode(element data);
LinkedStack*	stackCreate(void);
void		stackDestroy(LinkedStack* s);
void		push(LinkedStack* s, element data);
void		pop(LinkedStack* s);
element		top(LinkedStack* s);
_Bool		stackEempty(LinkedStack* s);
int		stackSize(LinkedStack* s);
void		printStack(LinkedStack* s);
