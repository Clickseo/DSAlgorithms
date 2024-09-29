/*
	단순 연결 리스트: 알고리즘 구현(cpp)
		파일명: SLinkedList(head).h
			- 클래스: SNode
			- 클래스: SLinkedList
				- 스택 생성.소멸	: SLinkedList, ~SLinkedList
				- 데이터 삽입.삭제	: addRear, removeFront
				- 데이터 확인(탐색)	: frontNode, rearNode
				- 빈 리스트 여부 판단	: isEmpty
				- 리스트의 총 개수	: countNode
				- 리스트의 전체 출력	: printLinkedList
*/

// #pragma once
#include "LinkedNode.h"		// SNode

#ifndef __SLinkedList_H__
#define __SLinkedList_H__

// SLinkedList class
class SLinkedList {
public:
	SLinkedList(void);				// 생성자
	~SLinkedList(void);				// 소멸자: 전체 노드 삭제
	bool	isEmpty(void) const;			// 빈 리스트 여부 판단
	int		countNode(void) const;		// 탐색: 노드의 총 개수(count_)
	SNode*	frontNode(void) const;			// 탐색: 첫 번째 노드(head_)
	SNode*	rearNode(void) const;			// 탐색: 맨 마지막 노드(tail_)
	void	addRear(const int& e);			// 삽입: 맨 마지막 노드(tail_)
	void	removeFront(void);			// 삭제: 첫 번째 노드(head_)
	void	printLinkedList(void) const;		// 리스트의 전체 원소(노드) 출력
private:
	SNode*		head_;		// 첫 번째 노드
	// SNode*	tail_;		// 맨 마지막 노드
	// int	  	count_;		// 노드의 총 개수
};

#endif
