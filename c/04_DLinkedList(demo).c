/*
	이중 연결 리스트: 알고리즘 구현(C)
		파일명: DLinkedList(demo).c
			- main	: 데이터 삽입.삭제, 전체 출력
*/

#include <stdio.h>
#include <stdlib.h>					// exit, malloc, free
#include <stdbool.h>				// bool, true, false
#include "DLinkedList(head).h"		// DLinkedList >> head	
// #include "DLinkedList(tail).h"	// DLinkedList >> head, tail, count
// #include "LinkedNode.h"			// DNode, makeDNode

int main(void)
{
	int				num;

	// head = NULL, tail = NULL, count = 0
	DLinkedList		*dList = dListCreate();

	while (true) {
		printf("임의의 정수 입력(종료: 0) : ");
		scanf_s("%d", &num);
		// scanf("%d", &num);
		if (num == 0)
			break;

		DNode	*newDNode = makeDNode(num);	// 새로운 노드 생성		
		dListAddRear(dList, newDNode);		// 맨 마지막 노드로 삽입
	}

	// 리스트 전체 노드의 데이터 출력
	printDLinkedList(dList);		// 순방향 출력
	printRevDLinkedList(dList);		// 역방향 출력

	// 노드의 총 개수
	printf("노드의 총 개수: %d\n", countDNode(dList));

	// 빈 리스트 여부 판단
	if (dListEmpty(dList)) {
		printf("입력된 데이터가 없습니다!!!\n");
	}
	else {
		// 첫 번째 노드와 마지막 노드의 데이터
		printf("첫 번째 노드의 데이터: %d\n", frontDNode(dList)->data);
		printf("마지막 노드의 데이터 : %d\n", rearDNode(dList)->data);
	}

	// dList = dListDestroy(dList);
	return 0;
}
