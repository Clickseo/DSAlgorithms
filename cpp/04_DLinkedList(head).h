/*
	단순 연결 리스트: 알고리즘 구현(CPP)
		파일명: DLinkedList(head).h
			- 클래스: DLinkedList
				- 스택 생성.소멸		: DLinkedList, ~DLinkedList
				- 데이터 삽입.삭제		: addRear, removeFront
				- 데이터 확인(탐색)		: frontNode, rearNode
				- 빈 리스트 여부 판단	: isEmpty
				- 리스트의 총 개수		: countNode
				- 리스트의 전체 출력	: printLinkedList
*/

// #pragma once
#include "LinkedNode.h"			// DNode

#ifndef __DLinkedList_H__
#define __DLinkedList_H__

// 이중 연결 리스트 : DLinkedList(head)
class DLinkedList {
public:
	DLinkedList(void);							// 생성자
	~DLinkedList(void);							// 소멸자: 전체 노드 삭제
	bool	isEmpty(void) const;				// 빈 리스트 여부 판단
	int		countNode(void) const;				// 탐색: 노드의 총 개수(count_)
	DNode*	frontNode(void) const;				// 탐색: 첫 번째 노드(head_)
	DNode*	rearNode(void) const;				// 탐색: 맨 마지막 노드(tail_)
	void	addRear(const int& e);				// 삽입: 맨 마지막 노드(tail_)
	void	removeFront(void);					// 삭제: 첫 번째 노드(head)
	void	printLinkedList(void) const;		// 리스트의 전체 원소(노드) 출력: 순방향
	void	printRevLinkedList(void) const;		// 리스트의 전체 원소(노드) 출력: 역방향
private:
	DNode*		head_;		// 첫 번째 노드
	// DNode*	tail_;		// 맨 마지막 노드
	// int		count_;		// 노드의 총 개수
};

#endif
