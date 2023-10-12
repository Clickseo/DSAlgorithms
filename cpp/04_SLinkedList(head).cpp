/*
	단순 연결 리스트: 알고리즘 구현
		파일명: SLinkedList(head).cpp
			- 클래스: SNode
			- 클래스: SLinkedList
				생성자와 소멸자		: SLinkedList, ~SLinkedList
				노드 확인		: isEmpty, countSNode
				노드 탐색		: frontSNode, rearSNode
				노드 삽입.삭제		: addRear, removeFront
				전체 원소(노드) 출력	: printSLinkedList
*/

#include <iostream>
using namespace std;

// SNode class
class SNode {
public:
	SNode(const int& data);
private:
	int	__data;
	SNode*	__link;
	friend class SLinkedList;
};

// SNode: 생성자
SNode::SNode(const int& data) :
	__data(data), __link(nullptr) {}

// SLinkedList class
class SLinkedList {
public:
	SLinkedList(void);				// 생성자
	~SLinkedList(void);				// 소멸자: 전체 노드 삭제
	bool	isEmpty(void) const;			// 빈 리스트 여부 판단
	int		countSNode(void) const;		// 탐색: 노드의 총 개수(count)
	SNode*	frontSNode(void) const;			// 탐색: 첫 번째 노드(head)
	SNode*	rearSNode(void) const;			// 탐색: 맨 마지막 노드(tail)
	void	addRear(const int& e);			// 삽입: 맨 마지막 노드(tail)
	void	removeFront(void);			// 삭제: 첫 번째 노드(head)
	void	printSLinkedList(void) const;		// 리스트의 전체 원소(노드) 출력
private:
	SNode* 		__head;		// 첫 번째 노드
	// SNode*	__tail;		// 맨 마지막 노드
	// int	  	__count;	// 노드의 총 개수
};

// LinkedStack: 생성자와 소멸자
SLinkedList::SLinkedList(void)
	: __head(nullptr) { }

SLinkedList::~SLinkedList(void) {
	// while (!isEmpty()) removeFront();
	SNode* tNode = __head;
	while (tNode) {
		__head = tNode->__link;
		delete tNode;
		tNode = __head;
	}
}

// 빈 리스트 여부 판단
bool SLinkedList::isEmpty(void) const {
	return __head == nullptr;
}

// 탐색: 노드의 총 개수(count)
int	SLinkedList::countSNode(void) const {
	// if (isEmpty()) return 0;
	int	count = 0;
	SNode* rNode = __head;
	while (rNode) {		// while (rNode != nullptr)
		rNode = rNode->__link;
		count++;
	}
	return count;
}

// 탐색: 첫 번째 노드(head)
SNode* SLinkedList::frontSNode(void) const {
	// if (isEmpty()) return nullptr;
	return __head;
}

// 탐색: 맨 마지막 노드(tail)
SNode* SLinkedList::rearSNode(void) const {
	// if (isEmpty()) return nullptr;
	SNode* rNode = __head;
	while (rNode->__link)
		rNode = rNode->__link;
	return rNode;
}

// 삽입: 맨 마지막 노드(tail)
void SLinkedList::addRear(const int& e) {
	SNode* nNode = new SNode(e);
	if (isEmpty()) __head = nNode;
	else {
		SNode* rNode = rearSNode();
		rNode->__link = nNode;
	}
}

// 삭제: 첫 번째 노드(head)
void SLinkedList::removeFront(void) {
	if (isEmpty()) return;
	SNode* old = __head;
	__head = old->__link;
	delete old;
}

// 출력: 리스트의 전체 원소(노드)
void SLinkedList::printSLinkedList(void) const {
	if (isEmpty()) {
		cout << "\n입력된 데이터가 없습니다..." << endl;
		return;
	}

	cout << "\n\t### 입력된 데이터 ###" << endl;
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
	SLinkedList	sList = SLinkedList();		// sList.SLinkedList();
							// __head = nullptr;
	while (true) {
		cout << "임의의 정수 입력(종료: 0): ";
		cin >> num;
		if (num == 0)
			break;
		sList.addRear(num); 	// 맨 마지막 노드로 삽입
	}

	// 전체 원소 출력
	sList.printSLinkedList();
	return 0;	// sList.~SLinkedList();
}
