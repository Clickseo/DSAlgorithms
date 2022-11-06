/*
	스택: 알고리즘 구현 -- 연결자료구조(단순연결리스트)
	파일명: LinkedStack.c
		- 스택 생성 및 삭제   : stackCreate, stackDestroy
		- 원소 삽입.삭제.확인 : push, pop
		- 데이터 확인(peek)  : top
		- 빈 스택 여부 판단   : stackEempty
		- 스택 크기          : stackSize
		- 전체 원소 출력     : printStack
*/

#include <stdio.h>
#include <stdlib.h>		// malloc, free
#include "LinkedStack.h"	// LinkedStack, stackNode
				// element

// 새로운 노드(data, link) 생성
SNode*	makeSNode(element num) {
	SNode* newSNode = (SNode*)malloc(sizeof(SNode));
	if (newSNode == NULL) {
		printf("노드 생성 실패!!! \n");
		exit(100);
	}
	newSNode->__data = num;
	newSNode->__link = NULL;
	return newSNode;
}

// 빈 스택 생성
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

// 스택 삭제 -- 모든 노드 삭제
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
int	stackSize(LinkedStack* s) {
	return s->__count;
}

// 스택의 전체 원소 출력
void	printStack(LinkedStack* s) {
	SNode* temp = s->__top;
	printf("\n STACK [");
	while (temp) {
		// printf("%3d", temp->data);
		temp = temp->__link;
	}
	printf(" ]\n");
}
