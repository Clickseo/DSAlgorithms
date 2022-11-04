/*
	스택: 알고리즘 구현 -- 단순연결리스트
		- main	: 데이터 삽입(push).삭제(pop), 전체 원소 출력
*/

#include <iostream>
#include "LinkedStack.h"
using namespace std;

int main(void)
{
	LinkedStack<int>	s;
	int			num, choice;

	while (true) {
		system("cls");
		cout << "\n ### 스택 구현: 단순 연결 리스트 ### \n" << endl;
		cout << "1) 데이터 삽입(PUSH)" << endl;
		cout << "2) 데이터 삭제(POP)" << endl;
		cout << "3) 전체 출력" << endl;
		cout << "4) 프로그램 종료 \n" << endl;
		cout << "메뉴 선택 : ";
		cin >> choice;

		switch (choice) {
			case 1: cout << "\n삽입 할 데이터 입력: ";
				cin >> num;	  s.push(num);	  break;
			case 2: cout << "삭제 된 데이터: " << s.top() << endl;
				s.pop();	break;
			case 3: s.printStack(); break;
			case 4: cout << "프로그램 종료..." << endl;
				return 0;
			default: cout << "잘못 선택 하셨습니다." << endl;
		}
		system("pause");
	}	
	return 0;	// s.~ListStack();
}
