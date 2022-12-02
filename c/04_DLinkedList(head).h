/*
	이중 연결 리스트: 알고리즘 구현(C)
		파일명: DLinkedList(head).h
			구 조 체: DLinkedList
			함수원형:			
				- 스택 생성.소멸	: dListCreate, dListDestroy
				- 데이터 삽입.삭제	: dListAddRear, dListRemoveFront
				- 노드 검색	: frontDNode, rearDNode
				- 리스트의 총 개수	: countDNode
				- 빈 리스트 여부 판단	: dListEmpty				
				- 리스트의 전체 출력	: printDLinkedList, revPrintDLinkedList
*/

// #pragma once
#include "LinkedNode.h"		// DNode, makeDNode

// 구조체: DLinkedList
#ifndef __DLinkedList_H__
#define __DLinkedList_H__
typedef struct __DLinkedList {
	DNode*		__head;	  	// 첫 번째 노드
	// SNode*	__tail;	  	// 맨 마지막 노드
	// int		__count;	// 노드의 총 개수
}DLinkedList;
#endif

// 이중 연결 리스트 구현(C): 리스트 생성 및 활용
DLinkedList* dListCreate(void);
DLinkedList* dListDestroy(DLinkedList* dList);
void	dListAddRear(DLinkedList* dList, DNode* nNode);		// 삽입: 리스트의 맨 마지막 노드로...
void	dListRemoveFront(DLinkedList* dList);			// 삭제: 리스트에서 첫 번째 노드를...
DNode*	frontDNode(DLinkedList* dList);				// 검색: 첫 번째 노드(head)
DNode*	rearDNode(DLinkedList* dList);				// 검색: 맨 마지막 노드(tail)
int	countDNode(DLinkedList* dList);				// 검색: 노드의 총 개수(count)
_Bool	dListEmpty(DLinkedList* dList);				// 빈 리스트 여부 판단
void	printDLinkedList(DLinkedList* dList);			// 리스트의 전체 노드 출력(순방향)
void	revPrintDLinkedList(DLinkedList* dList);		// 리스트의 전체 노드 출력(역방향)
