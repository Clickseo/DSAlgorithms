/*
	큐: 알고리즘 구현(C++) -- 단순연결리스트
		파일명: LinkedQueue.cpp
			- 스택 생성.소멸		: LinkedQueue, ~LinkedQueue
			- 스택 상태		: empty
			- 스택 크기		: size
			- 데이터 삽입.삭제	: push, pop
			- 데이터 확인		: front, back
			- 전체 데이터 출력	: printQueue
*/

#include <iostream>
#include "LinkedNode(template).cpp"		// SNode<T>
using namespace std;

// #pragma once
#ifndef __LinkedQueue_Template_H__
#define __LinkedQueue_Template_H__

// 클래스 설계: LinkedQueue
template <typename T>
class LinkedQueue {
public:
	LinkedQueue();				// 빈 큐 생성
	~LinkedQueue();				// 큐 삭제
	bool	empty(void) const;		// 빈 큐 여부
	int	size(void) const;		// 큐의 원소 개수
	void	push(const T &data);		// 데이터 삽입
	void	pop(void);			// 데이터 삭제
	T	front(void) const;		// 첫번째 노드의 데이터 반환
	T	back(void) const;		// 마지막 노드의 데이터 반환
	void	printQueue(void) const;		// 전체 데이터 출력
private:
	SNode<T>	*front_;
	SNode<T>	*rear_;
	int		count_;
};

#endif
