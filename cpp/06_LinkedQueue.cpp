/*
	큐: 알고리즘 구현(C++) -- 단순연결리스트
		파일명: LinkedQueue.cpp
			- 스택 생성.소멸	: LinkedQueue, ~LinkedQueue
			- 스택 상태			: empty
			- 스택 크기			: size
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
	LinkedQueue();						// 빈 큐 생성
	~LinkedQueue();						// 큐 삭제
	bool	empty(void) const;			// 빈 큐 여부
	int		size(void) const;			// 큐의 원소 개수
	void	push(const T &data);		// 데이터 삽입
	void	pop(void);					// 데이터 삭제
	T		front(void) const;			// 첫번째 노드의 데이터 반환
	T		back(void) const;			// 마지막 노드의 데이터 반환
	void	printQueue(void) const;		// 전체 데이터 출력
private:
	SNode<T>	*front_;
	SNode<T>	*rear_;
	int			count_;
};


// 빈 큐 생성
template <typename T>
LinkedQueue<T>::LinkedQueue()
	: front_(nullptr), rear_(nullptr), count_(0) {}

// 큐 삭제 : 모든 노드 삭제
template <typename T>
LinkedQueue<T>::~LinkedQueue() {
	SNode<T>	*tNode = front_;
	while (tNode) {
		front_ = tNode->link_;
		delete tNode;
		tNode = front_;
	}
}

// 빈 큐 여부
template <typename T>
bool	LinkedQueue<T>::empty(void) const {
	return front_ == nullptr;
}

// 원소 개수
template <typename T>
int	LinkedQueue<T>::size(void) const {
	return count_;
}

// 데이터 삽입: 큐에 새로운 데이터 추가
template <typename T>
void	LinkedQueue<T>::push(const T &data) {
	SNode<T>	*newNode = new SNode<int>(data);
	if (front_)	rear_->link_ = newNode;
	else		front_ = newNode;
	rear_ = newNode;
	++count_;
}

// 데이터 삭제: 큐에서 맨 위의 데이터 삭제
template <typename T>
void	LinkedQueue<T>::pop(void) {
	if (empty()) {
		return;
	}

	SNode<int>	*tNode = front_;
	front_ = tNode->link_;
	if (!front_)
		rear_ = nullptr;
	delete tNode;
	--count_;
}

// 첫번째 노드의 데이터 반환
template <typename T>
T	LinkedQueue<T>::front(void) const {
	if (empty()) {
		return T();
	}
	return  front_->data_;
}

// 마지막 노드의 데이터 반환
template <typename T>
T	LinkedQueue<T>::back(void) const {
	if (empty()) {
		return T();
	}
	return  rear_->data_;
}

// 전체 데이터 출력
template <typename T>
void	LinkedQueue<T>::printQueue(void) const {
	if (empty()) {
		cout << "입력된 데이터가 없습니다!!!" << endl;
		return;
	}

	cout << "\n\t##### 입력된 데이터 #####\n" << endl;
	cout << "QUEUE [";
	SNode<T>	*tNode = front_;
	while (tNode) {
		cout.width(3);
		cout << tNode->data_;
		tNode = tNode->link_;
	}
	cout << " ]" << endl;
}

#endif
