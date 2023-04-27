/*
	단순 연결 리스트: 알고리즘 구현
		파일명: SLinkedList(head).cpp
			- 클래스: SNode
			- 클래스: SLinkedList
				생성자와 소멸자		: SLinkedList, ~SLinkedList
				노드 삽입.삭제		: addRear, removeFront
				노드 탐색		: frontSNode, rearSNode
				노드 확인		: isEmpty, countSNode
				전체 원소(노드) 출력	: printSLinkedList
*/

#include <iostream>
using namespace std;

// SNode class
class SNode {
private:
	int	__data;
	SNode*	__link;
	friend class SLinkedList;
public:
	SNode(const int& data);
};

// SNode: 생성자와 메소드 정의
SNode::SNode(const int& data) :
	__data(data), __link(nullptr) {}

// SLinkedList class
class SLinkedList {
private:
	SNode*		__head;		// 첫 번째 노드
	// SNode*	__tail;		// 맨 마지막 노드
	// int	  	__count;	// 노드의 총 개수
public:
	SLinkedList();					// 생성자
	~SLinkedList();					// 소멸자: 전체 노드 삭제
	void	addRear(const int& e);			// 삽입: 맨 마지막 노드
	void	removeFront();				// 삭제: 첫 번째 노드
	SNode*	frontSNode() const;			// 탐색: 첫 번째 노드
	SNode*	rearSNode() const;			// 탐색: 맨 마지막 노드
	bool	isEmpty() const;			// 빈 리스트 여부 판단
	int	countSNode() const;			// 탐색: 노드의 총 개수(count)
	void	printSLinkedList() const;		// 리스트의 전체 원소(노드) 출력
};

// LinkedStack: 생성자(소멸자)와 메소드 정의
SLinkedList::SLinkedList()
	: __head(nullptr) { }

SLinkedList::~SLinkedList() {
	// while (!isEmpty()) removeFront();	
	SNode* tNode = __head;
	while (tNode) {
		__head = tNode->__link;
		delete tNode;
		tNode = __head;
	}
}

// 삽입: 맨 마지막 노드
void SLinkedList::addRear(const int& e) {
	SNode* nNode = new SNode(e);
	if (isEmpty()) __head = nNode;
	else {
		SNode* rNode = rearSNode();
		rNode->__link = nNode;
	}
}

// 삭제: 첫 번째 노드
void SLinkedList::removeFront() {
	if (isEmpty()) return;
	SNode* old = __head;
	__head = old->__link;
	delete old;
}

// 탐색: 첫 번째 노드
SNode* SLinkedList::frontSNode() const {
	return __head;
}

// 탐색: 맨 마지막 노드
SNode* SLinkedList::rearSNode() const {
	if (isEmpty()) return nullptr;
	SNode* rNode = __head;
	while (rNode->__link)
		rNode = rNode->__link;
	return rNode;
}

// 빈 리스트 여부 판단
bool SLinkedList::isEmpty() const {
	return __head == nullptr;
}

// 탐색: 노드의 총 개수(count)
int	SLinkedList::countSNode() const {
	if (isEmpty()) return 0;
	int	count = 0;
	SNode* rNode = __head;
	while (rNode->__link) {
		count++;
		rNode = rNode->__link;
	}
	return count;
}

// 리스트의 전체 원소(노드) 출력
void SLinkedList::printSLinkedList() const {
	if (isEmpty()) {
		cout << "입력된 데이터가 없습니다..." << endl;
		return;
	}

	cout << "\n ### 입력된 데이터 ### \n" << endl;
	SNode* temp = __head;
	while (temp) {
		cout.width(3);
		cout << temp->__data << " ->>";
		temp = temp->__link;
	}
	cout << " NULL" << endl;
}

int main(void)
{
	int		num;
	SLinkedList	sList = SLinkedList();
	while (true) {
		cout << "임의의 정수 입력(종료: 0): ";
		cin >> num;
		if (num == 0)	break;
		sList.addRear(num); 	// 맨 마지막 노드로 삽입
	}
	sList.printSLinkedList();
	return 0;			// sList.~SLinkedList();
}
