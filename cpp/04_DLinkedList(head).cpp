/*
	이중 연결 리스트: 알고리즘 구현
		파일명: DLinkedList(head).cpp
			- 클래스: DNode
			- 클래스: DLinkedList
				생성자와 소멸자: DLinkedList, ~DLinkedList
				노드 확인: isEmpty, countSNode
				노드 탐색: frontSNode, rearSNode
				노드 삽입.삭제: addRear, removeFront
				전체 원소(노드) 출력: printSLinkedList
*/

#include <iostream>
using namespace std;

// DNode class
class DNode {
public:
	DNode(const int& data);
private:
	int	__data;
	DNode*	__Llink;
	DNode*	__Rlink;
	friend class DLinkedList;
};

// DNode: 생성자
DNode::DNode(const int& data) :
	__data(data), __Llink(nullptr), __Rlink(nullptr) {}

// DLinkedList class
class DLinkedList {
public:
	DLinkedList(void);				// 생성자
	~DLinkedList(void);				// 소멸자: 전체 노드 삭제
	bool	isEmpty(void) const;			// 빈 리스트 여부 판단
	int		countDNode(void) const;		// 탐색: 노드의 총 개수(count)
	DNode*	frontDNode(void) const;			// 탐색: 첫 번째 노드(head)
	DNode*	rearDNode(void) const;			// 탐색: 맨 마지막 노드(tail)
	void	addRear(const int& e);			// 삽입: 맨 마지막 노드(tail)
	void	removeFront(void);			// 삭제: 첫 번째 노드(head)
	void	printSLinkedList(void) const;		// 리스트의 전체 원소(노드) 출력: 순방향
	void	revPrintSLinkedList(void) const;	// 리스트의 전체 원소(노드) 출력: 역방향
private:
	DNode*		__head;		// 첫 번째 노드
	// DNode*	__tail;		// 맨 마지막 노드
	// int		__count;	// 노드의 총 개수
};

// DLinkedList: 생성자
DLinkedList::DLinkedList(void)
	: __head(nullptr) { }

DLinkedList::~DLinkedList(void) {
	// while (!isEmpty()) removeFront();
	DNode* tNode = __head;
	while (tNode) {
		__head = tNode->__Rlink;
		delete tNode;
		tNode = __head;
	}
}

// 빈 리스트 여부 판단
bool DLinkedList::isEmpty(void) const {
	return __head == nullptr;
}

// 탐색: 노드의 총 개수(count)
int	DLinkedList::countDNode(void) const {
	// if (isEmpty()) return 0;
	int	count = 0;
	DNode*	rNode = __head;
	while (rNode) {		// while (rNode != nullptr)
		count++;
		rNode = rNode->__Rlink;
	}
	return count;
}

// 탐색: 첫 번째 노드(head)
DNode* DLinkedList::frontDNode(void) const {
	// if (isEmpty()) return nullptr;
	return __head;
}

// 탐색: 맨 마지막 노드(tail)
DNode* DLinkedList::rearDNode(void) const {
	// if (isEmpty()) return nullptr;
	DNode* rNode = __head;
	while (rNode->__Rlink)
		rNode = rNode->__Rlink;
	return rNode;
}

// 삽입: 맨 마지막 노드(tail)
void DLinkedList::addRear(const int& e) {
	DNode* nNode = new DNode(e);
	if (isEmpty()) __head = nNode;
	else {
		DNode* rNode = rearDNode();
		rNode->__Rlink = nNode;
		nNode->__Llink = rNode;
	}
}

// 삭제: 첫 번째 노드(head)
void DLinkedList::removeFront(void) {
	if (isEmpty()) return;
	DNode* old = __head;
	__head = old->__Rlink;
	if (__head != nullptr)
		old->__Llink = nullptr;
	delete old;
}

// 출력(순방향): 리스트의 전체 원소(노드) 출력
void DLinkedList::printSLinkedList(void) const {
	if (isEmpty()) {
		cout << "\n입력된 데이터가 없습니다..." << endl;
		return;
	}

	cout << "\n\t### 입력된 데이터: 순방향 ###" << endl;
	DNode* temp = __head;
	while (temp) {
		cout.width(3);
		cout << temp->__data << " ->>";
		temp = temp->__Rlink;
	}
	cout << " NULL" << endl;
}

// 출력(역방향): 리스트의 전체 원소(노드) 출력
void DLinkedList::revPrintSLinkedList(void) const {
	if (isEmpty()) {
		cout << "\n입력된 데이터가 없습니다..." << endl;
		return;
	}

	cout << "\n\t### 입력된 데이터: 역방향 ###" << endl;
	DNode* temp = rearDNode();
	while (temp) {
		cout.width(3);
		cout << temp->__data << " ->>";
		temp = temp->__Llink;
	}
	cout << " NULL" << endl;
}

int main(void)
{
	int	num;
	DLinkedList	dList = DLinkedList();	// dList.SLinkedList();
						// __head = __tail = nullptr;
	while (true) {
		cout << "임의의 정수 입력(종료: 0): ";
		cin >> num;
		if (num == 0)
			break;
		dList.addRear(num);		// 맨 마지막 노드로 삽입
	}

	// 전체 원소 출력
	dList.printSLinkedList();
	dList.revPrintSLinkedList();
	return 0;	// dList.~DLinkedList();
}
