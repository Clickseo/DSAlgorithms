/*
	큐: 알고리즘 구현 -- 단순연결리스트
		- main	: 데이터 삽입.삭제, 전체 원소 출력
*/

#include <stdio.h>
#include <stdlib.h>				// system
#include <stdbool.h>			// bool, true, false
#include "LinkedQueue.h"		// LinkedQueue, SNode
// #include "LinkedNode.h"		// SNode

int main(void)
{
	int		num, data;
	LinkedQueue*	Q = queueCreate();

	while (true) {
		system("cls");
		printf("\n ### 큐 구현: 단순 연결 리스트 ### \n\n");
		printf("1) 데이터 삽입(enQueue) \n");
		printf("2) 데이터 삭제(deQueue) \n");
		printf("3) 전체 출력 \n");
		printf("4) 프로그램 종료 \n\n");
		printf("메뉴 선택: ");
		scanf_s("%d", &num);
		// scanf("%d", &num);

		switch (num) {
			case 1: printf("\n 삽입 할 데이터 입력 : ");
				scanf_s("%d", &data);		// scanf("%d", &data);
				enQueue(Q, data);
				break;
			case 2: printf("삭제 된 데이터 : %3d \n", front(Q));
				deQueue(Q);
				break;
			case 3:printQueue(Q);
				break;
			case 4: printf("프로그램 종료... \n");
				return 0;
			default: printf("잘못 선택 하셨습니다. \n");
		}
		system("pause");
	}
	queueDestroy(Q);
	return 0;
}
