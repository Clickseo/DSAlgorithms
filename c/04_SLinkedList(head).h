/*
	단순 연결 리스트: 알고리즘 구현(C)
		파일명: SLinkedList(head).h
			구조체: SLinkedList
				- 스택 생성.소멸	: sListCreate, sListDestroy
				- 데이터 삽입.삭제	: sListAddRear, sLIstRemoveFront
				- 데이터 확인(탐색)	: frontSNode, rearSNode
				- 빈 리스트 여부 판단	: sListEmpty
				- 리스트의 총 개수	: countSNode
				- 리스트의 전체 출력	: printSLinkedList
*/

// #pragma once
#include "LinkedNode.h"		// SNode, makeSNode

// 구조체: SLinkedList
#ifndef __SLinkedList_H__
#define __SLinkedList_H__
typedef struct __SLinkedList {
	SNode*		__head;		// 첫 번째 노드
	// SNode*	__tail;		// 맨 마지막 노드
	// int		__count;	// 노드의 총 개수
}SLinkedList;
#endif

// 단순 연결 리스트 구현(C): 리스트 생성 및 활용
SLinkedList*	sListCreate(void);				// 빈 리스트 생성
SLinkedList*	sListDestroy(SLinkedList* sList);		// 리스트 삭제: 리스트의 전체 노드 삭제	
SNode*	frontSNode(SLinkedList* sList);				// 탐색: 리스트의 첫 번째 노드(__head)
SNode*	rearSNode(SLinkedList* sList);				// 탐색: 리스트의 맨 마지막 노드
void	sListAddRear(SLinkedList* sList, SNode* nNode);		// 삽입: 리스트의 맨 마지막 노드로...
void	sListRemoveFront(SLinkedList* sList);			// 삭제: 리스트에서 첫 번째 노드를...
_Bool	sListEmpty(SLinkedList* sList);				// 빈 리스트 여부 판단
int		countSNode(SLinkedList* sList);			// 탐색: 노드의 총 개수(__count)
void	printSLinkedList(SLinkedList* sList);			// 리스트의 전체 노드 출력
