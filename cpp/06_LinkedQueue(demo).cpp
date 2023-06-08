/*
	큐: 알고리즘 구현 -- 단순연결리스트
		- main	: 데이터 삽입(push, enQueue).삭제(pop, deQueue), 전체 원소 출력
*/

#include <iostream>
#include "LinkedQueue.h"
using namespace std;

int main(void)
{
	int	num, choice;
	LinkedQueue<int>	Q;	// 빈 큐 생성

	while (true) {
		system("cls");
		cout << "### 큐 구현: 단순 연결 리스트 ###\n" << endl;
		cout << "1) 데이터 삽입(push, enQueue)" << endl;
		cout << "2) 데이터 삭제(pop, deQueue)" << endl;
		cout << "3) 전체 출력" << endl;
		cout << "4) 프로그램 종료 \n" << endl;
		cout << "메뉴 선택: ";
		cin >> choice;

		switch (choice) {
			case 1: cout << "\n삽입 할 데이터 입력: ";
				cin >> num;
				Q.push(num);
				break;
			case 2: cout << "삭제 된 데이터: " << Q.front() << endl;
				Q.pop();
				break;
			case 3: Q.printQueue();
				break;
			case 4: cout << "프로그램 종료..." << endl;
				return 0;
			default: cout << "잘못 선택 하셨습니다." << endl;
		}
		system("pause");
	}
	return 0;	// Q.~LinkedQueue();
}
