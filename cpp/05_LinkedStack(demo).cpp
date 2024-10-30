/*
	스택: 알고리즘 구현(C++) -- 단순연결리스트
		파일명: LinkedStack(demo).cpp
			- main	: 데이터 삽입.삭제, 전체 출력
*/

#include <iostream>
#include "05_LinkedStack.cpp"
// #include <conio.h>				// _getch, _getche
using namespace std;

int main(void)
{
	int					num, choice;
	LinkedStack<int>	s = LinkedStack<int>();

	while (true) {
		system("cls");
		cout << "\n\t### 스택 구현: 단순연결리스트 ### \n\n" << endl;
		cout << "1) 데이터 삽입: push" << endl;
		cout << "2) 데이터 삭제: popo" << endl;
		cout << "3) 전체 출력" << endl;
		cout << "4) 프로그램 종료 \n" << endl;
		cout << "메뉴 선택: ";
		cin >> choice;

		switch (choice) {
		case 1:
			while (true) {
				cout << "데이터 입력(종료: 0): ";
				cin >> num;
				if (num == 0)
					break;
				s.push(num);
			}
			break;
		case 2: cout << "삭제 된 데이터: " << s.top() << endl;
				s.pop();
				break;
		case 3: s.printStack();
				break;
		case 4: cout << "프로그램 종료!!!" << endl;
				exit(0);	// return 0;
		default: cout << "잘못 선택 하셨습니다!!!" << endl;
		}
		// print("계속하려면 아무 키나 누르십시오...");
		// _getch();
		system("pause");
	}

	// s.~LinkedStack();
	return 0;
}
