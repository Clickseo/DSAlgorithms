/*
	큐: 알고리즘 구현(CPP) -- 단순연결리스트
		파일명: LinkedQueue.cpp
			- 스택 생성.소멸		: LinkedQueue, ~LinkedQueue
			- 스택 상태		: empty
			- 스택 크기		: size
			- 데이터 삽입.삭제	: push, pop
			- 데이터 확인(peek)	: front, back
			- 전체 데이터 출력	: printQueue
*/

#include <iostream>
using namespace std;

template <typename T>
class LinkedQueue;

// SNode class
template <typename T>
class SNode {
public:
	SNode(const T &data);
	T	getData(void) const;
private:
	T		data_;
	SNode<T>	*link_;
	template <typename T> friend class LinkedQueue;
};

// SNode class: 노드 생성 및 조작 함수
template <typename T>
SNode<T>::SNode(const T &data) :
	data_(data), link_(nullptr) {}

template <typename T>
T   SNode<T>::getData(void) const {
	return data_;
}

// LinkedQueue class
template <typename T>
class LinkedQueue {
public:
	LinkedQueue();				// 빈 큐 생성
	~LinkedQueue();				// 큐 삭제: 모든 노드 삭제
	bool	empty(void) const;		// 빈 큐 여부
	int	size(void) const;		// 큐의 원소 개수
	void	push(const T &data);		// 데이터 삽입
	void	pop(void);			// 데이터 삭제
	T	front(void) const;		// 큐의 첫번째 데이터 반환
	T	back(void) const;		// 큐의 맨 마지막 데이터 반환
	void	printQueue(void) const;		// 큐의 전체 데이터 출력
private:
	SNode<T>	*front_;
	SNode<T>	*rear_;
	int		count_;
};
