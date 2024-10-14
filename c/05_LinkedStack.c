/*
	스택: 알고리즘 구현(C) -- 단순연결리스트
		파일명: LinkedStack.c
			- 스택 생성.소멸	: stackCreate, stackDestroy
			- 스택 상태		: stackEmpty
			- 스택 크기		: stackSize
			- 데이터 삽입.삭제	: push, pop
			- 데이터 확인(peek)	: top
			- 전체 데이터 출력	: printStack
*/

#include <stdio.h>
#include <stdlib.h>			// malloc, free
#include "LinkedStack.h"		// LinkedStack, SNode
// #include "LinkedNode.h"		// SNode

// 빈 스택 생성
LinkedStack	*stackCreate(void) {
	LinkedStack	*Stack = (LinkedStack*)malloc(sizeof(LinkedStack));
	if (Stack == NULL) {
		printf("스택 생성 실패!!! \n");
		exit(100);
	}
	Stack->top = NULL;
	Stack->count = 0;
	return Stack;
}

// 스택 삭제: 모든 노드 삭제
void	stackDestroy(LinkedStack *Stack) {
	SNode	*tNode = Stack->top;
	while (tNode) {
		Stack->top = tNode->link;
		free(tNode);
		tNode = Stack->top;
	}
	free(Stack);
	return;
}

// 빈 스택 여부(top)
_Bool	stackEmpty(LinkedStack *Stack) {
	return Stack->top == NULL;
}

// 스택의 원소 개수(top)
int		stackSize(LinkedStack *Stack) {
	return Stack->count;

}

// 데이터 삽입
void	push(LinkedStack *Stack, element data) {
	SNode	*newNode = makeSNode(data);
	newNode->link = Stack->top;

	Stack->top = newNode;
	++Stack->count;
}

// 데이터 삭제
void	pop(LinkedStack *Stack) {
	// if (stackEmpty(Stack))
	if (Stack->top == NULL)
		return;

	SNode	*tNode = Stack->top;
	Stack->top = tNode->link;

	free(tNode);
	--Stack->count;
}

// 데이터 확인(peek)
element	top(LinkedStack *Stack) {
	// if (stackEmpty(Stack))
	if (Stack->top == NULL)
		return EOF;

	return  Stack->top->data;
}

// 스택의 전체 데이터 출력
void	printStack(LinkedStack *Stack) {
	// if (stackEmpty(Stack)) {
	if (Stack->top == NULL) {
		printf("입력된 데이터가 없습니다!!!\n");
		return;
	}

	printf("\n\t##### 입력된 데이터 #####\n\n");
	printf("STACK [");

	SNode	*tNode = Stack->top;
	while (tNode) {
		printf("%3d", tNode->data);
		tNode = tNode->link;
	}
	printf(" ]\n");
}
