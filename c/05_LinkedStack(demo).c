#include <stdio.h>
#include <stdlib.h>			  // system
#include <stdbool.h>		  // bool, true, false
#include "LinkedStack.h"	// ListStack, stackNode

int main(void)
{
	int		num, choice;
	LinkedStack*	s = stackCreate();

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
				scanf_s("%d", &num);	// scanf("%d", &num);
				push(s, num);	break;
			case 2: printf("삭제 된 데이터: %3d \n", pop(s));	break;
			case 3: printStack(s);	break;
			case 4: printf("프로그램 종료... \n");	return 0;
			default: printf("잘못 선택 하셨습니다. \n");
		}
		system("pause");
	}
	stackDestroy(s);
	return 0;
}
