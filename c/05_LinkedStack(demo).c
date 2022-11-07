/*
	스택: 알고리즘 구현 -- 연결자료구조(단순연결리스트)
		- main	: 데이터 삽입.삭제, 전체 원소 출력
*/

#include <stdio.h>
#include <stdlib.h>		// system
#include <stdbool.h>		// bool, true, false
#include "LinkedStack.h"	// LinkedStack, SNode
// #include "LinkedSNode.h"	// SNode

int main(void)
{
	int		num, choice;
	LinkedStack*	LS = stackCreate();

	while (true) {
		system("cls");
		printf("\n ### 스택 구현: 단순연결리스트 ### \n\n");
		printf("1) 데이터 삽입(push) \n");
		printf("2) 데이터 삭제(pop) \n");
		printf("3) 전체 원소 출력 \n");
		printf("4) 프로그램 종료 \n\n");
		printf("메뉴 선택: ");
		scanf_s("%d", &choice);
		// scanf("%d", &choice);

		switch (choice) {
		case 1: printf("\n삽입 할 데이터 입력: ");
			scanf_s("%d", &num);
			// scanf("%d", &num);
			push(LS, num);
			break;
		case 2: printf("삭제 된 데이터: %3d \n", top(LS));
				pop(LS);	break;
		case 3: printStack(LS);
			break;
		case 4: printf("프로그램 종료... \n");
			return 0;
		default: printf("잘못 선택 하셨습니다. \n");
		}
		system("pause");
	}
	stackDestroy(LS);
	return 0;
}