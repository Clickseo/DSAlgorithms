/*
	스택: 알고리즘 구현 -- 연결자료구조(단순연결리스트)
		- 스택 생성 및 삭제    : stackCreate, stackDestroy
		- 원소 삽입.삭제.확인  : push, pop, peek
		- 빈 스택 여부 판단    : isEmpty
		- 전체 원소 출력       : printStack
*/

#include <stdio.h>
#include <stdlib.h>		// malloc, free
#include "LinkedStack.h"	// ListStack, stackNode

// 빈 스택 생성
LinkedStack* stackCreate(void) {
	LinkedStack* s = (LinkedStack*)malloc(sizeof(LinkedStack));
	if (s == NULL) {
		printf("스택 생성 실패!!! \n");
		return NULL;
	}
	s->top = NULL;
	return s;
}

// 스택 메모리 해제
void stackDestroy(LinkedStack* s) {
	stackNode* temp = s->top;
	while (temp) {
		s->top = temp->link;
		free(temp);
		temp = s->top;
	}
	free(s);
	return;
}

// 새로운 노드(data, link) 생성
stackNode* makeStackNode(int num) {
	stackNode* newSNode = (stackNode*)malloc(sizeof(stackNode));
	if (newSNode == NULL) {
		printf("메모리 할당 실패!!! \n");
		exit(100);
	}
	newSNode->data = num;
	newSNode->link = NULL;
	return newSNode;
}

// PUSH : 스택에 데이터 삽입
void push(LinkedStack* s, element  data) {
	stackNode* newSNode = makeStackNode(data);
	newSNode->link = s->top;
	s->top = newSNode;
}

// POP : 스택에서 데이터 삭제
element pop(LinkedStack* s) {
	if (isEmpty(s))	return EOF;
	stackNode* temp = s->top;
	element	data = temp->data;
	s->top = temp->link;
	free(temp);
	return  data;
}

// PEEK : 스택 맨 위의 원소 확인
element peek(LinkedStack* s) {
	if (isEmpty(s))	return EOF;
	return  s->top->data;
}

// 스택의 공백 상태 여부 판단
_Bool isEmpty(LinkedStack* s) {
	return s->top == NULL;
}

// 스택의 전체 원소 출력
void printStack(LinkedStack* s) {
	stackNode* temp = s->top;
	printf("\n STACK [");
	while (temp) {
		printf("%3d", temp->data);
		temp = temp->link;
	}
	printf(" ]\n");
}
