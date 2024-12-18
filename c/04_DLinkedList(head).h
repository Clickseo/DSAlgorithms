/*
	이중 연결 리스트: 알고리즘 구현(C)
		파일명: DLinkedList(head).h
			구조체: DLinkedList
				- 스택 생성.소멸	: dListCreate, dListDestroy
				- 데이터 삽입.삭제	: dListAddRear, dListRemoveFront
				- 데이터 확인(탐색)	: frontDNode, rearDNode
				- 빈 리스트 여부 판단	: dListEmpty
				- 리스트의 총 개수	: countDNode
				- 리스트의 전체 출력	: printDLinkedList, revPrintDLinkedList
*/

// #pragma once
#include "LinkedNode.h"		// DNode, makeDNode

// 구조체: DLinkedList
#ifndef __DLinkedList_H__
#define __DLinkedList_H__

typedef struct _DLinkedList {
	DNode		*head;	  	// 첫 번째 노드
	// DNode	*tail;	  	// 맨 마지막 노드
	// int		count;		// 노드의 총 개수
} DLinkedList;

#endif

// 이중 연결 리스트 구현(C): 리스트 생성 및 조작 함수
DLinkedList *dListCreate(void);
DLinkedList *dListDestroy(DLinkedList *dList);
_Bool	dListEmpty(DLinkedList *dList);				// 빈 리스트 여부 판단
int	countDNode(DLinkedList *dList);				// 탐색: 노드의 총 개수(count)
DNode	*frontDNode(DLinkedList *dList);			// 탐색: 리스트의 첫 번째 노드(head)
DNode	*rearDNode(DLinkedList *dList);				// 탐색: 리스트의 맨 마지막 노드
void	dListAddRear(DLinkedList *dList, DNode *newNode);	// 삽입: 리스트의 맨 마지막 노드로...
void	dListRemoveFront(DLinkedList *dList);			// 삭제: 리스트에서 첫 번째 노드를...
void	printDLinkedList(DLinkedList *dList);			// 리스트의 전체 노드 출력(순방향)
void	printRevDLinkedList(DLinkedList *dList);		// 리스트의 전체 노드 출력(역방향)
