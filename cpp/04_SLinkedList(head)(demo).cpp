/*
	단순 연결 리스트: 알고리즘 구현(cpp)
		파일명: SLinkedList(head)(demo).cpp
			- main	: 데이터 삽입.삭제, 전체 출력
*/
#include <iostream>
#include "SLinkedList(head).h"		// SLinkedList, SNode
// #include "LinkedNode.h"		// SNode
using namespace std;

int main(void)
{
	int		num;
	SLinkedList	sList = SLinkedList();
	// head_ = nullptr;
	while (true) {
		cout << "임의의 정수 입력(종료: 0): ";
		cin >> num;
		if (num == 0)
			break;
		// 맨 마지막 노드로 삽입
		sList.addRear(num);
	}

	// 전체 원소 출력
	sList.printLinkedList();
	return 0;		// sList.~SLinkedList();
}
