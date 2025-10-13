/*
	단순 연결 리스트: 알고리즘 구현(C++)
		파일명: SLinkedList(demo).cpp
			- main	: 데이터 삽입.삭제, 전체 출력
*/
#include <iostream>
// #include "SLinkedList(head).h"	// SLinkedList >> head
#include "SLinkedList(tail).h"		// SLinkedList >> head, count, tail
// #include "LinkedNode.h"			// SNode
using namespace std;

int main(void)
{
	int			num;	
	SLinkedList	sList = SLinkedList();		// head_ = nullptr;

	while (true) {
		cout << "임의의 정수 입력(종료: 0): ";
		cin >> num;
		if (num == 0)
			break;

		// 맨 마지막 노드로 삽입
		sList.addRear(num);
	}

	// 리스트 전체 노드의 데이터 출력
	sList.printLinkedList();

	// 노드의 총 개수
	cout << "노드의 총 개수: " << sList.countNode() << endl;

	// 빈 리스트 여부 판단
	if (sList.isEmpty()) {
		cout << "입력된 데이터가 없습니다!!!\n" << endl;
	}
	else {
		// 첫 번째 노드와 마지막 노드의 데이터
		cout << "첫 번째 노드의 데이터: " << sList.frontNode()->getData() << endl;
		cout << "마지막 노드의 데이터 : " << sList.rearNode()->getData() << endl;
	}
	cout << endl;

	// sList.~SLinkedList();
	return 0;
}
