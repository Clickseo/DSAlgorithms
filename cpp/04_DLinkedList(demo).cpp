/*
	이중 연결 리스트: 알고리즘 구현(CPP)
		파일명: DLinkedList(demo).cpp
			- main	: 데이터 삽입.삭제, 전체 출력
*/

#include <iostream>
#include "DLinkedList(head).h"		// DLinkedList >> head
// #include "DLinkedList.h"			// DLinkedList >> head, count, tail
// #include "LinkedNode.h"			// DNode
using namespace std;

int main(void)
{
	int		num;
	DLinkedList	dList = DLinkedList();	// head_ = nullptr;

	while (true) {
		cout << "임의의 정수 입력(종료: 0): ";
		cin >> num;
		if (num == 0)
			break;
		// 맨 마지막 노드로 삽입
		dList.addRear(num);
	}

	// 전체 원소 출력
	dList.printLinkedList();	// 순방향 출력
	dList.printRevLinkedList();	// 역방향 출력
	
	return 0;	// dList.~DLinkedList();
}
