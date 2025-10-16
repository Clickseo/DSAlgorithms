#include <iostream>
#include "DLinkedList(head).h"	// DLinkedList >> head
// #include "DLinkedList.h"		// DLinkedList >> head, count, tail
// #include "LinkedNode.h"		// DNode
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

    // 리스트 전체 노드의 데이터 출력
    dList.printLinkedList();			// 순방향 출력
    dList.printRevLinkedList();		// 역방향 출력

    // 노드의 총 개수
    cout << "노드의 총 개수: " << dList.countNode() << endl;

    // 빈 리스트 여부 판단
    if (dList.isEmpty()) {
	  cout << "입력된 데이터가 없습니다!!!\n" << endl;
    }
    else {
	  // 첫 번째 노드와 마지막 노드의 데이터
	  cout << "첫 번째 노드의 데이터: " << dList.frontNode()->getData() << endl;
	  cout << "마지막 노드의 데이터 : " << dList.rearNode()->getData() << endl;
    }
    cout << endl;

    // dList.~DLinkedList();
    return 0;
}
