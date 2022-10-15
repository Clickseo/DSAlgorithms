/*
	스택: 알고리즘 구현 -- 연결자료구조(단순연결리스트)
	파일명: linkedStack.cpp
		- 스택 생성 및 삭제   : LinkedStack, ~LinkedStack
		- 원소 삽입.삭제.확인 : push, pop, peek
		- 빈 스택 여부 판단   : isEmpty
		- 전체 원소 출력      : printStack
*/

#include <iostream>
#define stackMAXSIZE 100
using namespace std;
inline void error(const char* message);

template <typename E>
class stackNode {
private:
	E		data;
	stackNode<E>*	link;
	template <typename E> friend class LinkedStack;
};

template <typename E>
class LinkedStack {
private:
	stackNode<E>* top;
public:
	LinkedStack();
	~LinkedStack();
	stackNode<E>* makeStackNode(const int& num) const;
	void		push(const E& e);
	E		pop(void);
	E		peek(void) const;
	bool		isEmpty(void) const;
	void		printStack(void) const;
};

template <typename E>
LinkedStack<E>::LinkedStack() : top(NULL) {}

template <typename E>
LinkedStack<E>::~LinkedStack() {}

template <typename E>
stackNode<E>* LinkedStack<E>::makeStackNode(const int& num) const {
	stackNode<E>* nNode = new stackNode<int>;
	nNode->data = num;
	nNode->link = NULL;
	return nNode;
}

template <typename E>
void	LinkedStack<E>::push(const E& e) {
	stackNode<E>* newSNode = makeStackNode(e);
	newSNode->link = top;
	top = newSNode;
}

template <typename E>
E	LinkedStack<E>::pop(void) {
	if (isEmpty()) error("스택 공백 에러");	// throw "ERROR::STACK IS EMPTY";
	stackNode<int>* temp = top;
	E data = temp->data;
	top = temp->link;
	free(temp);
	return  data;
}

template <typename E>
E	LinkedStack<E>::peek(void) const {
	if (isEmpty()) error("스택 공백 에러");	// throw "ERROR::STACK IS EMPTY";
	return  top->data;
}

template <typename E>
bool	LinkedStack<E>::isEmpty(void) const {
	return top == NULL;
}

template <typename E>
void	LinkedStack<E>::printStack(void) const {
	stackNode<E>* temp = top;
	cout << "\n STACK [";
	while (temp) {
		cout.width(3);
		cout << temp->data;
		temp = temp->link;
	}
	cout << " ]" << endl;
}

inline void error(const char* message) {
	cout << message;
	exit(100);
}

int main(void)
{
	int   num, choice;
	LinkedStack<int>	s;

	while (true) {
		system("cls");
		cout << "\n ### 스택 구현: 단순 연결 리스트 ### \n" << endl;
		cout << "1) 데이터 삽입: PUSH" << endl;
		cout << "2) 데이터 삭제: POP" << endl;
		cout << "3) 전체 출력" << endl;
		cout << "4) 프로그램 종료 \n" << endl;
		cout << "메뉴 선택 : ";
		cin >> choice;

		switch (choice) {
		      case 1: cout << "\n삽입 할 데이터 입력: ";
			cin >> num;
			s.push(num);
			break;
		      case 2: cout << "삭제 된 데이터: " << s.pop() << endl;
			break;
		      case 3: s.printStack();
			break;
		      case 4: cout << "프로그램 종료..." << endl;
			return 0;
		      default: cout << "잘못 선택 하셨습니다." << endl;
		}
		system("pause");
	}
	// s.~ListStack();
	return 0;
}
