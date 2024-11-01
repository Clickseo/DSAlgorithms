/*
	스택: 알고리즘 구현(C++) -- 단순연결리스트
		파일명: LinkedStack.cpp
			- 스택 생성.소멸		: LinkedStack, ~LinkedStack
			- 스택 상태		: empty
			- 스택 크기		: size
			- 데이터 삽입.삭제	: push, pop
			- 데이터 확인		: top
			- 전체 데이터 출력	: printStack
*/

#include <iostream>
#include "LinkedNode(template).cpp"	// SNode<T>
using namespace std;

// #pragma once
#ifndef __LinkedStack_Template_H__
#define __LinkedStack_Template_H__

// 클래스 설계: LinkedStack
template <typename T>
class LinkedStack {
public:
	LinkedStack();				// 빈 스택 생성
	~LinkedStack();				// 스택 삭제
	bool	empty(void) const;		// 빈 스택 여부
	int	size(void) const;		// 원소 개수
	void	push(const T &data);		// 데이터 삽입
	void	pop(void);			// 데이터 삭제
	T	top(void) const;		// 맨 위의 데이터 반환
	void	printStack(void) const;		// 전체 데이터 출력
private:
	SNode<T>	*top_;
	int		count_;
};

#endif
