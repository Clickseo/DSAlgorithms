/*
	스택: 알고리즘 구현 -- 단순연결리스트
		- main	: 데이터 삽입(push).삭제(pop), 전체 원소 출력
*/

#include <iostream>
#include "LinkedStack.h"
using namespace std;

int main(void)
{
	int	num, choice;
	LinkedStack<int>	S;	// 빈 스택 생성

	while (true) {
		system("cls");
		cout << "### 스택 구현: 단순 연결 리스트 ###\n" << endl;
		cout << "1) 데이터 삽입(push)" << endl;
		cout << "2) 데이터 삭제(pop)" << endl;
		cout << "3) 전체 출력" << endl;
		cout << "4) 프로그램 종료 \n" << endl;
		cout << "메뉴 선택 : ";
		cin >> choice;

		switch (choice) {
			case 1: cout << "\n삽입 할 데이터 입력: ";
				cin >> num;
				S.push(num);
				break;
			case 2: cout << "삭제 된 데이터: " << S.top() << endl;
				S.pop();
				break;
			case 3: S.printStack();
				break;
			case 4: cout << "프로그램 종료..." << endl;
				return 0;
			default: cout << "잘못 선택 하셨습니다." << endl;
		}
		system("pause");
	}	
	return 0;	// S.~ListStack();
}
