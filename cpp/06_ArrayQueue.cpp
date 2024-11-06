/*
	큐: 알고리즘 구현(C++) -- 순차 자료구조
		파일명: ArrayQueue.cpp
			- 스택 생성.소멸		: ArrayQueue, ~ArrayQueue
			- 스택 상태		: empty, full
			- 스택 크기		: size
			- 데이터 삽입.삭제	: push, pop
			- 데이터 확인(peek)	: front, back
			- 전체 데이터 출력	: printQueue
*/

#include <iostream>
using namespace std;

// #pragma once
#ifndef __ArrayQueue_H__
#define __ArrayQueue_H__

// 클래스 설계: ArrayQueue<T>
template <typename T>
class ArrayQueue {
public:
	ArrayQueue(int size = 10);		// 빈 큐 생성
	~ArrayQueue(void);			// 큐 삭제
	bool	empty(void) const;		// 빈 큐 여부
	bool	full(void) const;		// 포화 상태 여부
	int	size(void) const;		// 원소 개수
	void	push(const T &data);		// 데이터 삽입
	void	pop(void);			// 데이터 삭제
	T	front(void) const;		// 첫번째 노드의 데이터 반환
	T	back(void) const;		// 마지막 노드의 데이터 반환
	void	printQueue(void) const;		// 전체 데이터 출력
private:
	int	front_;
	int	rear_;
	int	maxSize_;
	T	*queue_;
};

// 빈 큐 생성
template <typename T>
ArrayQueue<T>::ArrayQueue(int size)
	: front_(-1), rear_(-1), maxSize_(size) {
	queue_ = new T[maxSize_];
}

// 큐 삭제
template <typename T>
ArrayQueue<T>::~ArrayQueue(void) {
	delete[] queue_;
}

// 빈 큐 여부
template <typename T>
bool	ArrayQueue<T>::empty(void) const {
	return front_ == rear_;
}

// 포화 상태 여부
template <typename T>
bool	ArrayQueue<T>::full(void) const {
	return rear_ == maxSize_ - 1;
}

// 원소 개수
template <typename T>
int	ArrayQueue<T>::size(void) const {
	return rear_ - front_ + 1;
}

// 데이터 삽입: 큐에 새로운 데이터 추가
template <typename T>
void	ArrayQueue<T>::push(const T &data) {
	if (full()) {
		return;
	}
	queue_[++rear_] = data;
}

// 데이터 삭제: 큐에서 맨 위의 데이터 삭제
template <typename T>
void	ArrayQueue<T>::pop(void) {
	if (empty()) {
		return;
	}
	++front_;
}

// 첫번째 데이터 반환
template <typename T>
T	ArrayQueue<T>::front(void) const {
	if (empty()) {
		return T();
	}
	return queue_[front_ + 1];
}

// 마지막 데이터 반환
template <typename T>
T	ArrayQueue<T>::back(void) const {
	if (empty()) {
		return T();
	}
	return queue_[rear_];
}

// 전체 데이터 출력
template <typename T>
void	ArrayQueue<T>::printQueue(void) const {
	if (empty()) {
		cout << "입력된 데이터가 없습니다!!!" << endl;
		return;
	}

	cout << "\n\t##### 입력된 데이터 #####\n" << endl;
	cout << "QUEUE [";
	for (int i = front_ +  1; i <= rear_; ++i) {
		cout.width(3);
		cout << queue_[i];
	}
	cout << " ]" << endl;
}

#endif
