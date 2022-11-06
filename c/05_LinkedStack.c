/*
	스택: 알고리즘 구현(C) -- 단순연결리스트
		파일명: LinkedStack.c
			- 스택 생성.소멸       : stackCreate, stackDestroy
			- 데이터 삽입.삭제     : push, pop
			- 데이터 확인(peek)    : top
			- 빈 스택 여부 판단     : stackEempty
			- 스택 크기            : stackSize
			- 스택의 전체 원소 출력 : printStack
*/

#include <stdio.h>
#include <stdlib.h>		// malloc, free
#include "LinkedStack.h"	// LinkedStack, SNode
// #include "LinkedSNode.h"	// SNode

// stackCreate : 빈 스택 생성
LinkedStack*	stackCreate(void) {
	LinkedStack* s = (LinkedStack*)malloc(sizeof(LinkedStack));
	if (s == NULL) {
		printf("스택 생성 실패!!! \n");
		exit(100);
	}
	s->__top = NULL;
	s->__count = 0;
	return s;
}

// stackDestroy : 스택 삭제 -- 모든 노드 삭제
void	stackDestroy(LinkedStack* s) {
	SNode* temp = s->__top;
	while (temp) {
		s->__top = temp->__link;
		free(temp);
		temp = s->__top;
	}
	free(s);
	return;
}

// push : 스택의 데이터 삽입
void	push(LinkedStack* s, element data) {
	SNode* newSNode = makeSNode(data);
	newSNode->__link = s->__top;
	s->__top = newSNode;
	s->__count++;
}

// pop : 스택에서 데이터 삭제
void	pop(LinkedStack* s) {
	if (stackEempty(s))	return;
	SNode* temp = s->__top;
	s->__top = temp->__link;
	free(temp);
	s->__count--;
}

// top(peek) : 스택 맨 위의 원소 확인
element	top(LinkedStack* s) {
	if (stackEempty(s))	return EOF;
	return  s->__top->__data;
}

// stackEempty : 스택의 공백 상태
_Bool	stackEempty(LinkedStack* s) {
	return s->__top == NULL;
}

// stackSize: 스택의 크기
int		stackSize(LinkedStack* s) {
	return s->__count;

}

// 스택의 전체 원소 출력
void	printStack(LinkedStack* s) {
	SNode* temp = s->__top;
	printf("\n STACK [");
	while (temp) {
		printf("%3d", temp->__data);
		temp = temp->__link;
	}
	printf(" ]\n");
}
