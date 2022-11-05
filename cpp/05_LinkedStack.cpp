/*
	스택: 알고리즘 구현 --단순연결리스트

		파일명: LinkedStack.h

		클래스: SNode
		클래스: LinkedStack
			- 생성자.소멸자			: LinkedStack, ~LinkedStack
			- 데이터 삽입.삭제		: push, pop, top
			- 데이터 확인			: top
			- 스택 크기				: size
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
	template <typename E> friend class LinkedStack;
public:
	SNode();
};

template <typename E>
SNode<E>::SNode() : __data(__data), __link(NULL) {}

// LinkedStack class
template <typename E>
class LinkedStack {
private:
	SNode<E>*	__top;
	int		__count;
public:
	LinkedStack();
	~LinkedStack();
	void		push(const E& e);
	void		pop(void);
	E&		top(void) const;
	bool		empty(void) const;
	int		size(void) const;
	void		printStack(void) const;
};

template <typename E>
LinkedStack<E>::LinkedStack() : __top(NULL), __count(0) {}

template <typename E>
LinkedStack<E>::~LinkedStack() {
	SNode<E>* temp = __top;
	while (temp) {
		__top = temp->__link;
		free(temp);
		temp = __top;
	}
}

template <typename E>
void	LinkedStack<E>::push(const E& e) {
	SNode<E>* newSNode = new SNode<int>;
	newSNode->__data = e;
	newSNode->__link = __top;
	__top = newSNode;
	__count++;
}

template <typename E>
void	LinkedStack<E>::pop(void) {
	// if (empty()) error("스택 공백 에러");	// throw "ERROR::STACK IS EMPTY";
	SNode<int>* temp = __top;
	if (temp) {
		__top = temp->__link;
		free(temp);
		__count--;
	}
}

template <typename E>
E&		LinkedStack<E>::top(void) const {
	// if (empty()) error("스택 공백 에러");	// throw "ERROR::STACK IS EMPTY";
	return  __top->__data;
}

template <typename E>
bool	LinkedStack<E>::empty(void) const {
	// return !__count;
	return __top == NULL;
}

template <typename E>
int		LinkedStack<E>::size(void) const {
	return __count;
}

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
