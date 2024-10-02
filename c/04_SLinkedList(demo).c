/*
	단순 연결 리스트: 알고리즘 구현(c)
		파일명: SLinkedList(head)(demo).c
			- main	: 데이터 삽입.삭제, 전체 출력
*/

#include <stdio.h>
#include <stdlib.h>			// exit, malloc, free
#include <stdbool.h>			// bool, true, false
#include "SLinkedList(head).h" 		// SLinkedList >> head	
// #include "SLinkedList.h"		// SLinkedList >> head, tail, count
// #include "LinkedNode.h"		// SNode, makeSNode

int main(void)
{
	int		num;
	SLinkedList*	sList = sListCreate();		// head = NULL;
	
	while (true) {
		printf("임의의 정수 입력(종료: 0) : ");
		scanf_s("%d", &num);
		// scanf("%d", &num);
		if (num == 0)
			break;
		
		SNode* newNode = makeSNode(num);	// 새로운 노드 생성
		sListAddRear(sList, newNode);		// 맨 마지막 노드로 삽입
	}

	// 전체 원소 출력
	printSLinkedList(sList);
	
	// sList = sListDestroy(sList);	
	return 0;
}
