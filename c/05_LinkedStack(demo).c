/*
	스택(연결 자료구조): 알고리즘 구현(C)
		파일명: LinkedStack(demo).c
			- main	: 데이터 삽입.삭제, 전체 출력
*/

#include <stdio.h>
#include <stdlib.h>		// system
#include <stdbool.h>		// bool, true, false
#include "LinkedStack.h"	// LinkedStack, SNode
// #include "LinkedNode.h"	// SNode

int main(void)
{
	int			num, choice;
	LinkedStack	*Stack = stackCreate();

	while (true) {
		system("cls");
		printf("\n\t### 스택 구현: 단순연결리스트 ### \n\n");
		printf("1) 데이터 삽입: push \n");
		printf("2) 데이터 삭제: pop \n");
		printf("3) 데이터 전체 출력 \n");
		printf("4) 프로그램 종료 \n\n");
		printf("메뉴 선택: ");
		scanf_s("%d%*c", &choice);		// scanf("%d", &choice);		
		// while (getchar() != '\n');

		switch (choice) {
			case 1: 
				while (true) {
					printf("데이터 입력(종료: 0): ");
					scanf_s("%d%*c", &num);	// scanf("%d", &num);
					// while (getchar() != '\n');
					if (num == 0)
						break;
					push(Stack, num);
				}
				break;
			case 2: printf("삭제 된 데이터: %3d \n", top(Stack));
				pop(Stack);
				break;
			case 3: printStack(Stack);
				break;
			case 4: printf("프로그램 종료!!!\n");
				exit(0);	// return 0;
			default: printf("잘못 선택 하셨습니다!!!\n");
		}
		// print("계속하려면 아무 키나 누르십시오...");
		// _getch();
		system("pause");
	}
	// stackDestroy(Stack);
	return 0;
}
