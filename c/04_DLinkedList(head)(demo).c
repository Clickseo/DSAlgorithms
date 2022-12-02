/*
	이중 연결 리스트: 알고리즘 구현
		파일명: DLinkedList(head)(demo).c
			- main	: 데이터 삽입.삭제, 전체 출력
*/

#include <stdio.h>
#include <stdlib.h>			// exit, malloc, free
#include <stdbool.h>			// bool, true, false
#include "DLinkedList(head).h"		// DLinkedList, DNode, makeDNode
// #include "LinkedNode.h"		// DNode, makeDNode

int main(void)
{
	int		num;
	DLinkedList*	dList = dListCreate();
	while (true) {
		printf("임의의 정수 입력(종료: 0) : ");
		scanf_s("%d", &num);
		// scanf("%d", &num);
		if (num == 0)
			break;

		DNode* newDNode = makeDNode(num);	// 새로운 노드 생성		
		dListAddRear(dList, newDNode);		// 맨 마지막 노드로 삽입
	}
	printDLinkedList(dList);		// 순방향 출력
	revPrintDLinkedList(dList);		// 역방향 출력

	// 리스트 삭제: 전체 노드 삭제
	dList = dListDestroy(dList);
	
	return 0;
}
