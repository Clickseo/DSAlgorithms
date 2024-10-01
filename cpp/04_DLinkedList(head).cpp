/*
	이중 연결 리스트: 알고리즘 구현(CPP)
		파일명: DLinkedList(head).cpp
			- 클래스: DNode
			- 클래스: DLinkedList
				생성자와 소멸자			: DLinkedList, ~DLinkedList
				노드 확인				: isEmpty, countNode
				노드 탐색				: frontNode, rearNode
				노드 삽입.삭제			: addRear, removeFront
				전체 원소(노드) 출력	: printLinkedList
*/

#include <iostream>
#include "DLinkedList(head).h"		// DLinkedList >> head
// #include "LinkedNode.h"			// DNode
using namespace std;

// 생성자: head_, tail_, count_
DLinkedList::DLinkedList(void)
	: head_(nullptr) { }

// 소멸자: 전체 노드 삭제
DLinkedList::~DLinkedList(void) {
	// while (!isEmpty()) removeFront();
	DNode* tNode = head_;
	while (tNode) {
		head_ = tNode->Rlink_;
		delete tNode;
		tNode = head_;
	}
}

// 빈 리스트 여부 판단
bool DLinkedList::isEmpty(void) const {
	return head_ == nullptr;
}

// 탐색: 노드의 총 개수(count)
int	DLinkedList::countNode(void) const {
	// if (isEmpty()) return 0;
	int		count = 0;
	DNode* rNode = head_;
	while (rNode) {		// while (rNode != nullptr)
		count++;
		rNode = rNode->Rlink_;
	}
	return count;
}

// 탐색: 첫 번째 노드(head)
DNode* DLinkedList::frontNode(void) const {
	// if (isEmpty()) return nullptr;
	return head_;
}

// 탐색: 맨 마지막 노드
DNode* DLinkedList::rearNode(void) const {
	// if (isEmpty()) return nullptr;
	DNode* rNode = head_;
	while (rNode->Rlink_)
		rNode = rNode->Rlink_;
	return rNode;
}

// 삽입: 맨 마지막 노드
void DLinkedList::addRear(const int& e) {
	DNode* nNode = new DNode(e);
	if (isEmpty()) head_ = nNode;
	else {
		DNode* rNode = rearNode();
		rNode->Rlink_ = nNode;
		nNode->Llink_ = rNode;
	}
}

// 삭제: 첫 번째 노드(head)
void DLinkedList::removeFront(void) {
	if (isEmpty()) return;
	DNode* old = head_;
	head_ = old->Rlink_;
	if (head_ != nullptr)
		old->Llink_ = nullptr;
	delete old;
}

// 출력(순방향): 리스트의 전체 원소(노드) 출력
void DLinkedList::printLinkedList(void) const {
	if (isEmpty()) {
		cout << "\n입력된 데이터가 없습니다..." << endl;
		return;
	}

	cout << "\n\t### 입력된 데이터: 순방향 ###" << endl;
	DNode* temp = head_;
	while (temp) {
		cout.width(3);
		cout << temp->data_ << " ->>";
		temp = temp->Rlink_;
	}
	cout << " NULL" << endl;
}

// 출력(역방향): 리스트의 전체 원소(노드) 출력
void DLinkedList::printRevLinkedList(void) const {
	if (isEmpty()) {
		cout << "\n입력된 데이터가 없습니다..." << endl;
		return;
	}

	cout << "\n\t### 입력된 데이터: 역방향 ###" << endl;
	DNode* temp = rearNode();
	while (temp) {
		cout.width(3);
		cout << temp->data_ << " ->>";
		temp = temp->Llink_;
	}
	cout << " NULL" << endl;
}
