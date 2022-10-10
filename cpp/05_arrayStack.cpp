#include <iostream>
#define stackMAXSIZE 100
using namespace std;
inline void error(const char* message);

template <typename E>
class arrayStack {
private:
	E	  stack[stackMAXSIZE];
	int	top;
public:
	arrayStack();
	~arrayStack();
	void	push(const E& e);
	E	    pop(void);
	E	    peek(void) const;
	bool	isEmpty(void) const;
	bool	isFull(void) const;
	void	printStack(void) const;
};

inline void error(const char* message) {
	cout << message;
	exit(100);
}

int main(void)
{
	int			        num, choice;
	arrayStack<int>	s = arrayStack<int>();

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
