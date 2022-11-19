/*
	스택: 알고리즘 구현(C++) --단순연결리스트
		파일명: LinkedStack.h
		클래스: SNode
		클래스: LinkedStack
			- 생성자.소멸자			: LinkedStack, ~LinkedStack
			- 데이터 삽입.삭제		: push, pop
			- 데이터 확인(peek)		: top
			- 빈 스택 여부 판단		: empty
			- 스택 크기				: size
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
	E			__data;
	SNode<E>*	__link;
	template <typename E> friend class LinkedStack;
public:
	SNode(const E& data);
	E	getData(void) const;
};

// SNode: 생성자와 메소드 정의
template <typename E>
SNode<E>::SNode(const E& data) :
	__data(data), __link(nullptr) {}

template <typename E>
E   SNode<E>::getData(void) const { return __data; }

// LinkedStack class
template <typename E>
class LinkedStack {
private:
	SNode<E>*	__top;
	int			__count;
public:
	LinkedStack();
	~LinkedStack();
	void	push(const E& e);
	void	pop(void);
	E&		top(void) const;
	bool	empty(void) const;
	int		size(void) const;
	void	printStack(void) const;
};

// LinkedStack: 생성자(소멸자)와 메소드 정의
template <typename E>
LinkedStack<E>::LinkedStack() : 
	__top(nullptr), __count(0) {}

template <typename E>
LinkedStack<E>::~LinkedStack() {
	SNode<E>* temp = __top;
	while (temp) {
		__top = temp->__link;
		free(temp);
		temp = __top;
	}
}

// push : 스택의 데이터 삽입
template <typename E>
void	LinkedStack<E>::push(const E& e) {
	SNode<E>* newSNode = new SNode<int>(e);
	// newSNode->__data = e;
	newSNode->__link = __top;
	__top = newSNode;
	__count++;
}

// pop : 스택에서 데이터 삭제
template <typename E>
void	LinkedStack<E>::pop(void) {
	if (empty()) error("ERROR::STACK IS EMPTY");	// throw "ERROR::STACK IS EMPTY";
	SNode<int>* temp = __top;
	if (temp) {
		__top = temp->__link;
		free(temp);
		__count--;
	}
}

// top(peek) : 스택 맨 위의 원소 확인
template <typename E>
E& LinkedStack<E>::top(void) const {
	if (empty()) error("STACK IS EMPTY");			// throw "ERROR::STACK IS EMPTY";
	return  __top->__data;
}

// empty : 스택의 공백 상태
template <typename E>
bool	LinkedStack<E>::empty(void) const {	return __top == nullptr;	}

// size : 스택의 크기
template <typename E>
int	LinkedStack<E>::size(void) const { return __count; }

// 스택의 전체 원소 출력
template <typename E>
void	LinkedStack<E>::printStack(void) const {
	SNode<E>* temp = __top;
	cout << "\n STACK [";
	while (temp) {
		cout.width(3);
		cout << temp->__data;
		temp = temp->__link;
	}
	cout << " ]" << endl;
}
