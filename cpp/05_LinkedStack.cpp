/*
	스택: 알고리즘 구현(CPP) -- 단순연결리스트
		파일명: LinkedStack.cpp
			- 스택 생성.소멸	: LinkedStack, ~LinkedStack
			- 스택 상태		: empty
			- 스택 크기		: size
			- 데이터 삽입.삭제	: push, pop
			- 데이터 확인(peek)	: top
			- 전체 데이터 출력	: printStack
*/

#include <iostream>
using namespace std;

template <typename T>
class LinkedStack;

// SNode class
template <typename T>
class SNode {
public:
	SNode(const T& data);
	T	getData(void) const;
private:
	T		data_;
	SNode<T>	*link_;
	template <typename T> friend class LinkedStack;
};	

// SNode class: 노드 생성 및 조작 함수
template <typename T>
SNode<T>::SNode(const T& data) :
	data_(data), link_(nullptr) {}

template <typename T>
T   SNode<T>::getData(void) const {
	return data_;
}

// LinkedStack class
template <typename T>
class LinkedStack {
public:
	LinkedStack();				// 빈 스택 생성
	~LinkedStack();				// 스택 삭제: 모든 노드 삭제	
	bool	empty(void) const;		// 빈 스택 여부 확인
	int	size(void) const;		// 스택의 원소 개수
	void	push(const T &data);		// 데이터 삽입
	void	pop(void);			// 데이터 삭제
	T	top(void) const;		// 스택에서 맨 위의 데이터 반환(peek)
	void	printStack(void) const;		// 스택의 전체 데이터 출력
private:
	SNode<T>	*top_;
	int		count_;
};
