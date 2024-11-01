/*
	스택(순차 자료구조): 알고리즘 구현(C++)
		파일명: ArrayQueue(demo).cpp
			- main	: 데이터 삽입.삭제, 전체 출력
*/

#include <iostream>
#include "06_ArrayQueue.cpp"
// #include <conio.h>				// _getch, _getche
using namespace std;

int main(void)
{
	int					num, choice;
	ArrayQueue<int>		q = ArrayQueue<int>();

	while (true) {
		system("cls");
		cout << "\n\t### 큐 구현: 1차원 배열 ### \n\n" << endl;
		cout << "1) 데이터 삽입: push" << endl;
		cout << "2) 데이터 삭제: pop" << endl;
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
				q.push(num);
			}
			break;
		case 2: cout << "삭제 된 데이터: " << q.front() << endl;
			q.pop();
			break;
		case 3: q.printQueue();
			break;
		case 4: cout << "프로그램 종료!!!" << endl;
			exit(0);	// return 0;
		default: cout << "잘못 선택 하셨습니다!!!" << endl;
		}
		// print("계속하려면 아무 키나 누르십시오...");
		// _getch();
		system("pause");
	}

	// q.~ArrayStack();
	return 0;
}
