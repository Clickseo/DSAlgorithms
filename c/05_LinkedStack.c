/*
	스택: 알고리즘 구현(C) -- 단순연결리스트
		파일명: LinkedStack.c
			- 스택 생성.소멸		: stackCreate, stackDestroy
			- 데이터 삽입.삭제	: push, pop
			- 데이터 확인(peek)	: top
			- 빈 스택 여부 판단	: stackEempty
			- 스택 크기		: stackSize
			- 스택의 전체 원소 출력	: printStack
*/

#include <stdio.h>
#include <stdlib.h>			// malloc, free
#include "LinkedStack.h"		// LinkedStack, SNode
// #include "LinkedNode.h"		// SNode, DNode

// stackCreate : 빈 스택 생성
LinkedStack*	stackCreate(void) {
	LinkedStack* S = (LinkedStack*)malloc(sizeof(LinkedStack));
	if (S == NULL) {
		printf("스택 생성 실패!!! \n");
		exit(100);
	}
	S->__top = NULL;
	S->__count = 0;
	return S;
}

// stackDestroy : 스택 삭제 -- 모든 노드 삭제
void	stackDestroy(LinkedStack* S) {
	SNode* temp = S->__top;
	while (temp) {
		S->__top = temp->__link;
		free(temp);
		temp = S->__top;
	}
	free(S);
	return;
}

// push : 스택의 데이터 삽입
void	push(LinkedStack* S, element data) {
	SNode* newSNode = makeSNode(data);
	newSNode->__link = S->__top;
	S->__top = newSNode;
	S->__count++;
}

// pop : 스택에서 데이터 삭제
void	pop(LinkedStack* S) {
	if (stackEempty(S))	return;
	SNode* temp = S->__top;
	S->__top = temp->__link;
	free(temp);
	S->__count--;
}

// top(peek) : 스택 맨 위의 원소 확인
element	top(LinkedStack* S) {
	if (stackEempty(S))	return EOF;		// return NULL;
	return  S->__top->__data;
}

// stackEempty : 스택의 공백 상태
_Bool	stackEempty(LinkedStack* S) {
	return S->__top == NULL;
}

// stackSize: 스택의 크기
int	stackSize(LinkedStack* S) {
	return S->__count;

}

// printStack : 스택의 전체 원소 출력
void	printStack(LinkedStack* S) {
	SNode* temp = S->__top;
	printf("\n STACK [");
	while (temp) {
		printf("%3d", temp->__data);
		temp = temp->__link;
	}
	printf(" ]\n");
}
