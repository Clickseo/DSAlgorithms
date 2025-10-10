/*
	단순 연결 리스트: 알고리즘 구현(cpp)
		파일명: SLinkedList(head).cpp
			- 클래스: SLinkedList
				생성자와 소멸자		: SLinkedList, ~SLinkedList
				노드 확인			: isEmpty, countNode
				노드 탐색			: frontNode, rearNode
				노드 삽입.삭제		: addRear, removeFront
				전체 원소(노드) 출력	: printLinkedList
*/

#include <iostream>
#include "SLinkedList(head).h"		// SLinkedList, SNode
// #include "LinkedNode.h"			// SNode
using namespace std;

// LinkedStack: 생성자와 소멸자
SLinkedList::SLinkedList(void)
	: head_(nullptr) { }

SLinkedList::~SLinkedList(void) {
	// while (!isEmpty())
	//	removeFront();
	SNode* tNode = head_;
	while (tNode) {
		head_ = tNode->link_;
		delete tNode;
		tNode = head_;
	}
}

// 빈 리스트 여부 판단
bool SLinkedList::isEmpty(void) const {
	return head_ == nullptr;
}

// 탐색: 노드의 총 개수(count)
int	SLinkedList::countNode(void) const {
	// if (isEmpty()) return 0;
	int	count = 0;
	SNode* rNode = head_;
	while (rNode) {		// while (rNode != nullptr)
		count++;
		rNode = rNode->link_;
	}
	return count;
}

// 탐색: 첫 번째 노드(head)
SNode* SLinkedList::frontNode(void) const {
	// if (isEmpty()) return nullptr;
	return head_;
}

// 탐색: 맨 마지막 노드(tail)
SNode* SLinkedList::rearNode(void) const {
	// if (isEmpty()) return nullptr;
	SNode* rNode = head_;
	while (rNode->link_)
		rNode = rNode->link_;
	return rNode;
}

// 삽입: 맨 마지막 노드(tail)
void SLinkedList::addRear(const int& e) {
	SNode* newNode = new SNode(e);
	if (isEmpty()) head_ = newNode;
	else {
		SNode* rNode = rearNode();
		rNode->link_ = newNode;
	}
}

// 삭제: 첫 번째 노드(head)
void SLinkedList::removeFront(void) {
	if (isEmpty()) return;
	SNode* old = head_;
	head_ = old->link_;
	delete old;
}

// 출력: 리스트의 전체 노드의 데이터
void SLinkedList::printLinkedList(void) const {
	if (isEmpty()) {
		cout << "\n입력된 데이터가 없습니다..." << endl;
		return;
	}

	cout << "\n\t### 입력된 데이터 ###" << endl;
	SNode* tNode = head_;
	while (tNode) {
		cout.width(3);
		cout << tNode->data_ << " ->>";
		tNode = tNode->link_;
	}
	cout << " NULL" << endl;
}
