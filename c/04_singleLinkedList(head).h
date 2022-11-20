/*
	단순 연결 리스트: 알고리즘 구현(C)
		파일명: singleLinkedList(head).h
			구조체: SLinkedList
				- 스택 생성.소멸		: stackCreate, stackDestroy
				- 데이터 삽입.삭제	: addRear, removeFront
				- 데이터 확인(peek)	: frontSNode, rearSNode
				- 빈 리스트 여부 판단	: isEmpty
				- 리스트의 총 개수	: countSNode
				- 리스트의 전체 출력	: printSLinkedList
*/

// #pragma once
#include "LinkedNode.h"		// SNode, makeSNode

// 구조체: SLinkedList
#ifndef __singleLinkedList_H__
#define __singleLinkedList_H__
typedef struct _SLinkedList {
	SNode*		__head;			// 첫 번째 노드
	// SNode*	__tail;			// 맨 마지막 노드
	// int		__count;		// 노드의 총 개수
}SLinkedList;
#endif

// 단순 연결 리스트 구현(C): 리스트 생성 및 활용
SLinkedList*  sListCreate(void);
SLinkedList*  sListDestroy(SLinkedList* sList);
SNode*  frontSNode(SLinkedList* sList);
SNode*  rearSNode(SLinkedList* sList);
void    addRear(SLinkedList* sList, SNode* node);
void    removeFront(SLinkedList* sList);
_Bool   isEmpty(SLinkedList* sList);
int     countSNode(SLinkedList* sList);
void    printSLinkedList(SLinkedList* sList);
