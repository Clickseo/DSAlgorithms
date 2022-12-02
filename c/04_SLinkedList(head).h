/*
	단순 연결 리스트: 알고리즘 구현(C)
		파일명: SLinkedList(head).h
			구 조 체: SLinkedList
			함수원형:
				- 스택 생성.소멸	: sListCreate, sListDestroy
				- 데이터 삽입.삭제	: sListAddRear, sLIstRemoveFront
				- 노드 검색(head, tail) : frontSNode, rearSNode
				- 노드의 총 개수(count)	: countSNode
				- 빈 리스트 여부 판단	: sListEmpty				
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
SLinkedList*	sListDestroy(SLinkedList* sList);		// 리스트 삭제: 전체 노드 삭제	
void	sListAddRear(SLinkedList* sList, SNode* nNode);		// 삽입: 리스트의 맨 마지막 노드로...
void	sListRemoveFront(SLinkedList* sList);			// 삭제: 리스트의 첫 번째 노드를...
SNode*	frontSNode(SLinkedList* sList);				// 검색: 첫 번째 노드(head)
SNode*	rearSNode(SLinkedList* sList);				// 검색: 맨 마지막 노드(tail)
int	countSNode(SLinkedList* sList);				// 검색: 노드의 총 개수(count)
_Bool	sListEmpty(SLinkedList* sList);				// 빈 리스트 여부 판단
void	printSLinkedList(SLinkedList* sList);			// 리스트 전체 출력
