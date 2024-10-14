/*
	스택: 알고리즘 구현(C) -- 순차 자료구조
		파일명: ArrayStack.c
			- 스택 생성.소멸		: stackCreate, stackDestroy
			- 스택 상태		: stackEmpty, stackFull
			- 스택 크기		: stackSize
			- 데이터 삽입.삭제	: push, pop
			- 데이터 확인(peek)	: top
			- 전체 데이터 출력	: printStack
*/

#include <stdio.h>
#include <stdbool.h>		// bool, true, false
#include <stdlib.h>		// malloc, free
#include "ArrayStack.h"		// ArrayStack

// 빈 스택 생성
ArrayStack	*stackCreate(void) {
	ArrayStack	*Stack = (ArrayStack *)malloc(sizeof(ArrayStack));
	if (Stack == NULL) {
		printf("스택 생성 실패!!! \n");
		return NULL;
	}
	Stack->top = -1;
	return Stack;
}

// 스택 삭제
void	stackDestroy(ArrayStack *Stack) {
	free(Stack);
}

// 빈 스택 여부(top)
_Bool	stackEmpty(ArrayStack *Stack) {
	if (Stack->top == -1)
		return true;
	return false;
}

// 스택의 포화 상태 여부(top)
_Bool	stackFull(ArrayStack *Stack) {
	if (Stack->top + 1 == StackMAXSIZE)
		return true;
	return false;
}

// 스택의 원소 개수(top)
int	stackSize(ArrayStack *Stack) {
	return Stack->top + 1;
}

// 데이터 삽입
void	push(ArrayStack *Stack, element data) {
	// if (stackFull(Stack))	return;
	if (Stack->top + 1 == StackMAXSIZE)
		return;

	Stack->stack[++Stack->top] = data;
}

// 데이터 삭제
void	pop(ArrayStack *Stack) {
	// if (stackEmpty(Stack))	return;
	if (Stack->top == -1)
		return;

	--Stack->top;
}

// 데이터 확인(peek)
element	top(ArrayStack *Stack) {
	// if (stackEmpty(Stack))	return -1;
	if (Stack->top == -1)
		return -1;

	return Stack->stack[Stack->top];
}

// 스택의 전체 데이터 출력
void	printStack(ArrayStack *Stack) {
	// if (stackEmpty(Stack)) {
	if (Stack->top == -1) {
		printf("입력된 데이터가 없습니다!!!\n");
		return;
	}

	printf("\n\t##### 입력된 데이터 #####\n\n");
	printf("STACK [");
	for (int i = 0; i <= Stack->top; ++i)
		printf("%3d", Stack->stack[i]);
	printf(" ]\n");
}
