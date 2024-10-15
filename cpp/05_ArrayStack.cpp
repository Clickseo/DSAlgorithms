/*
	스택: 알고리즘 구현(CPP) -- 순차 자료구조
		파일명: ArrayStack.cpp
			- 스택 생성.소멸	: ArrayStack, ~ArrayStack
			- 스택 상태			: empty, full
			- 스택 크기			: size
			- 데이터 삽입.삭제	: push, pop
			- 데이터 확인(peek)	: top
			- 전체 데이터 출력	: printStack
*/

#include <iostream>
using namespace std;

// ArrayStack class
template <typename T>
class ArrayStack {
public:
	ArrayStack(int size = 10);				// 빈 스택 생성
	~ArrayStack(void);						// 스택 삭제
	bool	empty(void) const;				// 빈 스택 여부 확인
	bool	full(void) const;				// 스택의 포화 상태 여부 확인
	int		size(void) const;				// 스택의 원소 개수
	void	push(const T& data);			// 데이터 삽입
	void	pop(void);						// 데이터 삭제
	T		top(void) const;				// 스택에서 맨 위의 데이터 확인(peek)
	void	printStack(void) const;			// 스택의 전체 데이터 출력
private:
	int		top_;
	int		maxSize_;
	T		*stack_;
};

// 빈 스택 생성
template <typename T>
ArrayStack<T>::ArrayStack(int size)
	: top_(-1), maxSize_(size) {
	stack_ = new T[maxSize_];
}

// 스택 삭제
template <typename T>
ArrayStack<T>::~ArrayStack(void) {
	delete[] stack_;
}

// 빈 스택 여부 확인
template <typename T>
bool	ArrayStack<T>::empty(void) const {
	return top_ == -1;
}

// 스택의 포화 상태 여부 확인
template <typename T>
bool	ArrayStack<T>::full(void) const {
	return top_ == maxSize_ - 1;
}

// 스택의 원소 개수
template <typename T>
int		ArrayStack<T>::size(void) const {
	return top_ + 1;
}

// 데이터 삽입: 스택에 새로운 데이터 추가
template <typename T>
void	ArrayStack<T>::push(const T &data) {
	if (full()) {
		return;
	}
	stack_[++top_] = data;
}

// 데이터 삭제: 스택에서 맨 위의 데이터 삭제
template <typename T>
void	ArrayStack<T>::pop(void) {
	if (empty()) {
		return;
	}
	--top_;
}

// 스택에서 맨 위의 데이터 반환(peek)
template <typename T>
T	ArrayStack<T>::top(void) const {
	if (empty()) {
		return T();
	}
	return stack_[top_];
}

// 스택의 전체 데이터 출력
template <typename T>
void	ArrayStack<T>::printStack(void) const {
	if (empty()) {
		cout << "입력된 데이터가 없습니다!!!" << endl;
		return;
	}

	cout << "\n\t##### 입력된 데이터 #####\n" << endl;
	cout << "STACK [";
	for (int i = top_; i >= 0; --i) {
		cout.width(3);
		cout << stack_[i];
	}
	cout << " ]" << endl;
}
