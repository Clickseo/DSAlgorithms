/*
	스택: 알고리즘 구현 -- 순차자료구조(배열)
		- arrayStack : stack, top
*/

#include <iostream>
#define stackMAXSIZE 100
using namespace std;
inline void error(const char* message);

// 배열 스택: arrayStack -- 클래스 설계
template <typename E>
class arrayStack {
private:
	E	stack[stackMAXSIZE];
	int	top;
public:
	arrayStack();
	~arrayStack();
	void	push(const E& e);
	E	pop(void);
	E	peek(void) const;
	bool	isEmpty(void) const;
	bool	isFull(void) const;
	void	printStack(void) const;
};

/*
	배열 스택: arrayStack -- 메소드 정의
		- 스택 성생 및 삭제: arrayStack, ~arrayStack
		- 원소 삽입과 삭제 : push, pop
		- 데이터 확인      : peek
		- 스택 상태 판단   : isEmpty, isFull
		- 전체 원소 출력   : printStack
*/
// 생성자: 빈 스택 생성
template <typename E>
arrayStack<E>::arrayStack() : top(-1) {}

// 소멸자
template <typename E>
arrayStack<E>::~arrayStack() {}

// PUSH : 스택에 데이터 삽입 
template <typename E>
void	arrayStack<E>::push(const E& e) {
	if (isFull()) error("스택 포화 에러");	// throw "ERROR::STACK IS FULL";
	stack[++top] = e;
}

// POP : 스택에서 데이터 삭제
template <typename E>
E	arrayStack<E>::pop(void) {
	if (isEmpty()) error("스택 공백 에러");	// throw "ERROR::STACK IS EMPTY";
	return stack[top--];
}

// PEEK : 스택 맨 위의 원소 확인
template <typename E>
E	arrayStack<E>::peek(void) const {
	if (isEmpty()) error("스택 공백 에러");	// throw "ERROR::STACK IS EMPTY";
	return stack[top];
}

// 스택의 공백 상태 여부 판단
template <typename E>
bool	arrayStack<E>::isEmpty(void) const {
	return top == -1;
}

// 스택의 포화 상태 여부 판단
template <typename E>
bool	arrayStack<E>::isFull(void) const {
	return top == stackMAXSIZE - 1;
}

// 스택의 전체 원소 출력
template <typename E>
void	arrayStack<E>::printStack(void) const {
	cout << "\n STACK [";
	for (int i = 0; i <= top; i++) {
		cout.width(3);
		cout << stack[i];
	}
	cout << " ]" << endl;
}

inline void error(const char* message) {
	cout << message;
	exit(100);
}

int main(void)
{
	int	num, choice;
	arrayStack<int>	s = arrayStack<int>();		// 빈 스택 생성

	while (true) {
		system("cls");
		cout << "\n ### 스택 구현: 1차원 배열 ### \n" << endl;
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
	// s.~ArrayStack();
	return 0;
}
