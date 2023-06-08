/*
	큐: 알고리즘 구현 --단순연결리스트
		파일명: LinkedQueue.h
		클래스: SNode
		클래스: LinkedQueue
			- 생성자.소멸자: LinkedQueue, ~LinkedQueue
			- 데이터 항목 삽입.삭제: push, pop		// enQueue, deQueue
			- 데이터 항목 확인(peek): front, back	// peek
			- 빈 큐 여부 판단: empty
			- 큐 크기(데이터 항목 개수): size
			- 큐의 전체 데이터 항목 출력: printQueue
*/

#include <iostream>
using namespace std;

inline void error(const char* message) {
	cout << message;
	exit(100);
}

template <typename E>
class LinkedQueue;

// SNode class
template <typename E>
class SNode {
public:
	SNode(const E& data);
	E	getData(void) const;
private:
	E			    __data;
	SNode<E>*	__link;
	template <typename E> friend class LinkedQueue;
};

// SNode class: 멤버 함수 외부 정의
template <typename E>
SNode<E>::SNode(const E& data) :
	__data(data), __link(nullptr) {}

template <typename E>
E   SNode<E>::getData(void) const { return __data; }

// LinkedQueue class
template <typename E>
class LinkedQueue {
public:
	LinkedQueue();
	~LinkedQueue();
	void	push(const E& e);		// enQueue
	void	pop(void);				// deQueue
	E&		front(void) const;
	E&		back(void) const;
	bool	empty(void) const;
	int		size(void) const;
	void	printQueue(void) const;
private:
	SNode<E>*	__front;
	SNode<E>*	__rear;
	int			  __count;
};

// LinkedStack class: 생성자(소멸자)와 소멸자
template <typename E>
LinkedQueue<E>::LinkedQueue()
	: __front(nullptr), __rear(nullptr), __count(0) {}

template <typename E>
LinkedQueue<E>::~LinkedQueue() {
	SNode<E>* temp = __front;
	while (temp) {
		__front = temp->__link;
		delete temp;
		temp = __front;
	}
}

// push(enQueue): 큐에 데이터 항목 삽입(맨 마지막 원소)
template <typename E>
void	LinkedQueue<E>::push(const E& e) {
	SNode<E>* newSNode = new SNode<int>(e);
	// newSNode->__data = e;
	if (__front)	__rear->__link = newSNode;
	else			    __front = newSNode;
	__rear = newSNode;
}

// pop(deQueue): 큐에서 맨 첫 번째로 삽입된 데이터 항목 삭제
template <typename E>
void	LinkedQueue<E>::pop(void) {
	if (empty()) error("STACK IS EMPTY");		// throw "ERROR::STACK IS EMPTY";
	SNode<int>* temp = __front;
	E data = temp->__data;
	__front = temp->__link;
	if (!__front)
		__rear = nullptr;
	delete temp;
}

// front(peek): 큐에서 맨 첫 번째로 삽입된 데이터 항목 확인
template <typename E>
E& LinkedQueue<E>::front(void) const {
	if (empty()) error("STACK IS EMPTY");	// throw "ERROR::STACK IS EMPTY";
	return  __front->__data;
}

// back(peek): 큐에서 맨 마지막에 삽입된 데이터 항목 확인
template <typename E>
E& LinkedQueue<E>::back(void) const {
	if (empty()) error("STACK IS EMPTY");	// throw "ERROR::STACK IS EMPTY";
	return  __rear->__data;
}

// empty: 스택의 공백 여부 확인
template <typename E>
bool	LinkedQueue<E>::empty(void) const {
	return __front == nullptr;
}

// size: 큐의 크기(항목의 개수)
template <typename E>
int		LinkedQueue<E>::size(void) const {
	return __count;
}

// printQueue: 큐의 전체 데이터 항목 출력
template <typename E>
void	LinkedQueue<E>::printQueue(void) const {
	SNode<E>* temp = __front;
	cout << "\n QUEUE [";
	while (temp) {
		cout.width(3);
		cout << temp->__data;
		temp = temp->__link;
	}
	cout << " ]" << endl;
}
