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

// 빈 스택 생성
template <typename T>
LinkedStack<T>::LinkedStack()
	: top_(nullptr), count_(0) {}

// 스택 삭제: 모든 노드 삭제
template <typename T>
LinkedStack<T>::~LinkedStack() {
	SNode<T>	*tNode = top_;
	while (tNode) {
		top_ = tNode->link_;
		delete tNode;
		tNode = top_;
	}
}

// 빈 스택 여부
template <typename T>
bool	LinkedStack<T>::empty(void) const {
	return top_ == nullptr;
}

// 원소 개수
template <typename T>
int	LinkedStack<T>::size(void) const {
	return count_;
}

// 데이터 삽입: 스택에 새로운 데이터 추가
template <typename T>
void	LinkedStack<T>::push(const T &data) {
	SNode<T>	*newNode = new SNode<int>(data);
	newNode->link_ = top_;
	top_ = newNode;
	++count_;
}

// 데이터 삭제: 스택에서 맨 위의 데이터 삭제
template <typename T>
void	LinkedStack<T>::pop(void) {
	if (empty()) {
		return;
	}

	SNode<int>	*tNode = top_;
	top_ = tNode->link_;
	delete tNode;
	--count_;
}

// 맨 위의 데이터 반환
template <typename T>
T	LinkedStack<T>::top(void) const {
	if (empty()) {
		return T();
	}
	return  top_->data_;
}

// 전체 데이터 출력
template <typename T>
void	LinkedStack<T>::printStack(void) const {
	if (empty()) {
		cout << "입력된 데이터가 없습니다!!!" << endl;
		return;
	}

	cout << "\n\t##### 입력된 데이터 #####\n" << endl;
	cout << "STACK [";
	SNode<T>	*tNode = top_;
	while (tNode) {
		cout.width(3);
		cout << tNode->data_;
		tNode = tNode->link_;
	}
	cout << " ]" << endl;
}

#endif
