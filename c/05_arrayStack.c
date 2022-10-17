/*
	스택: 알고리즘 구현 -- 순차자료구조(배열)
		- arrayStack : stack, top
*/

#include <stdio.h>
#include <stdlib.h>	// malloc, free
#include <stdbool.h>	// bool, true, false

#define stackMAXSIZE 100

// 배열 스택: arrayStack -- 구조체 설계
typedef int element;
typedef struct _arrayStack {
	element	stack[stackMAXSIZE];
	int	top;
}arrayStack;

// 배열 스택: arrayStack -- 함수 원형
arrayStack* 	stackCreate(void);
void		stackDestroy(arrayStack*);
void		push(arrayStack*, element);
element		pop(arrayStack*);
element		peek(arrayStack*);
_Bool		isEmpty(arrayStack*);
_Bool		isFull(arrayStack*);
void		printStack(arrayStack*);

int main(void)
{
	int		num, choice;
	arrayStack*	s = stackCreate();

	while (true) {
		system("cls");
		printf("\n ### 스택 구현: 1차원 배열 ### \n\n");
		printf("1) 데이터 삽입: PUSH \n");
		printf("2) 데이터 삭제: POP \n");
		printf("3) 전체 출력 \n");
		printf("4) 프로그램 종료 \n\n");
		printf("메뉴 선택 : ");
		scanf_s("%d", &choice);
		// scanf("%d", &choice);

		switch (choice) {
			case 1: printf("\n삽입 할 데이터 입력: ");
				scanf_s("%d", &num);
				// scanf("%d", &num);
				push(s, num);
				break;
			case 2: printf("삭제 된 데이터: %3d \n", pop(s));
				break;
			case 3: rintStack(s);
				break;
			case 4: printf("프로그램 종료... \n");
				return 0;
			default: printf("잘못 선택 하셨습니다. \n");
		}
		system("pause");
	}
	stackDestroy(s);
	return 0;
}

/*
	배열 스택: arrayStack -- 함수 정의
		- 스택 성생 및 삭제: stackCreate, stackDestroy
		- 원소 삽입과 삭제 : push, pop
		- 데이터 확인      : peek
		- 스택 상태 판단   : isEmpty, isFull
		- 전체 원소 출력   : printStack
*/
// 빈 스택 생성
arrayStack* stackCreate(void) {
	arrayStack* s = (arrayStack*)malloc(sizeof(arrayStack));
	if (s == NULL) {
		printf("스택 생성 실패!!! \n");
		exit(100);
	}
	s->top = -1;
	return s;
}

// 스택 메모리 해제
void stackDestroy(arrayStack* s) {
	free(s);
}

// PUSH : 스택에 데이터 삽입
void push(arrayStack* s, element  data) {
	if (isFull(s))	return;
	s->stack[++s->top] = data;
}

// POP : 스택에서 데이터 삭제
element pop(arrayStack* s) {
	if (isEmpty(s))	return EOF;
	return  s->stack[s->top--];
}

// PEEK : 스택 맨 위의 원소 확인
element peek(arrayStack* s) {
	if (isEmpty(s))	return EOF;
	return  s->stack[s->top];
}

// 스택의 공백 상태 여부 판단
_Bool isEmpty(arrayStack* s) {
	return s->top == -1;
}

// 스택의 포화 상태 여부 판단
_Bool isFull(arrayStack* s) {
	return s->top + 1 == stackMAXSIZE;
}

// 스택의 전체 원소 출력
void printStack(arrayStack* s) {
	printf("\n STACK [");
	for (int i = 0; i <= s->top; i++)
		printf("%3d", s->stack[i]);
	printf("]\n");
}
