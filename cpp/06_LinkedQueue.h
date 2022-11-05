/*
	큐: 알고리즘 구현 --단순연결리스트
		파일명: LinkedQueue.h
		클래스: SNode
		클래스: LinkedQueue
			- 생성자.소멸자			: LinkedQueue, ~LinkedQueue
			- 데이터 삽입.삭제		: push, pop		// enQueue, deQueue
			- 데이터 확인			: front, back
			- 큐 크기				: size
			- 빈 스택 여부 판단		: empty
			- 스택의 전체 원소 출력	: printStack
*/

#include <iostream>
using namespace std;

inline void error(const char* message) {
	cout << message;
	exit(100);
}

// SNode class
template <typename E>
class SNode {
private:
	E		__data;
	SNode<E>*	__link;
	template <typename E> friend class LinkedQueue;
public:
	SNode();
};

template <typename E>
SNode<E>::SNode() : __data(__data), __link(NULL) {}

// LinkedQueue class
template <typename E>
class LinkedQueue {
private:
	SNode<E>*	__front, *__rear;
	int		__count;
public:
	LinkedQueue();
	~LinkedQueue();
	void	push(const E& e);		// enQueue
	void	pop(void);			// deQueue
	E&		front(void) const;
	E&		back(void) const;
	bool	empty(void) const;
	int		size(void) const;
	void	printQueue(void) const;
};

template <typename E>
LinkedQueue<E>::LinkedQueue() : __front(NULL), __rear(NULL) {}

template <typename E>
LinkedQueue<E>::~LinkedQueue()	{
	SNode<E>* temp = __front;
	while (temp) {
		__front = temp->__link;
		free(temp);
		temp = __front;
	}
}

template <typename E>
void	LinkedQueue<E>::push(const E& e) {		// enQueue
	SNode<E>* newSNode = new SNode<int>;
	newSNode->__data = e;
	if (__front)	__rear->__link = newSNode;
	else        __front = newSNode;
	__rear = newSNode;
}

template <typename E>
void	LinkedQueue<E>::pop(void) {				// deQueue
	if (empty()) error("STACK IS EMPTY");		// throw "ERROR::STACK IS EMPTY";
	SNode<int>* temp = __front;
	E data = temp->__data;
	__front = temp->__link;
	if (!__front)
		__rear = NULL;
	free(temp);
}

template <typename E>
E& LinkedQueue<E>::front(void) const {
	if (empty()) error("STACK IS EMPTY");		// throw "ERROR::STACK IS EMPTY";
	return  __front->__data;
}

template <typename E>
E& LinkedQueue<E>::back(void) const {
	if (empty()) error("STACK IS EMPTY");		// throw "ERROR::STACK IS EMPTY";
	return  __rear->__data;
}

template <typename E>
bool	LinkedQueue<E>::empty(void) const {
	return __front == NULL;
}

template <typename E>
int		LinkedQueue<E>::size(void) const {
	return __count;
}

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
