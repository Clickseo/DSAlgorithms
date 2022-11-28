/*
	이중 연결 리스트: 알고리즘 구현
		파일명: DLinkedList(head).cpp
			- 클래스: DNode
			- 클래스: DLinkedList
				생성자와 소멸자		: DLinkedList, ~DLinkedList
				노드 삽입.삭제		: addRear, removeFront
				노드 탐색		: frontSNode, rearSNode
				노드 확인		: isEmpty, countSNode
				전체 원소(노드) 출력	: printSLinkedList
*/

#include <iostream>
using namespace std;

// DNode class
class DNode {
private:
	int	__data;
	DNode*	__Llink;
	DNode*	__Rlink;
	friend class DLinkedList;
public:
	DNode(const int& data);
};

// DNode: 생성자와 메소드 정의
DNode::DNode(const int& data) :
	__data(data), __Llink(nullptr), __Rlink(nullptr) {}

// DLinkedList class
class DLinkedList {
private:
	DNode*		__head;		// 첫 번째 노드
	// DNode*	__tail;		// 맨 마지막 노드
	// int		__count;	// 노드의 총 개수
public:
	DLinkedList();				// 생성자
	~DLinkedList();				// 소멸자: 전체 노드 삭제
	void	addRear(const int& e);		// 삽입: 맨 마지막 노드
	void	removeFront();			// 삭제: 첫 번째 노드
	DNode*	frontDNode() const;		// 탐색: 첫 번째 노드
	DNode*	rearDNode() const;		// 탐색: 맨 마지막 노드
	bool	isEmpty() const;		// 빈 리스트 여부 판단
	int		countDNode() const;	// 탐색: 노드의 총 개수(count)
	void	printSLinkedList() const;	// 리스트의 전체 원소(노드) 출력: 순방향
	void	revPrintSLinkedList() const;	// 리스트의 전체 원소(노드) 출력: 역방향
};

// DLinkedList: 생성자(소멸자)와 메소드 정의
DLinkedList::DLinkedList()
	: __head(nullptr) { }

DLinkedList::~DLinkedList() {
	// while (!isEmpty()) removeFront();
	DNode* tNode = __head;
	while (tNode) {
		__head = tNode->__Rlink;
		delete tNode;
		tNode = __head;
	}
}

// 노드 삽입: 맨 마지막 노드로...
void DLinkedList::addRear(const int& e) {
	DNode* nNode = new DNode(e);
	if (isEmpty()) __head = nNode;
	else {
		DNode* rNode = rearDNode();
		rNode->__Rlink = nNode;
		nNode->__Llink = rNode;
	}
}

// 노드 삭제: 첫 번째 노드를...
void DLinkedList::removeFront() {
	DNode* old;
	while (__head) {
		old = __head;
		__head = old->__Rlink;
		if (__head != nullptr)
			__head->__Llink = nullptr;
		delete old;
	}
}

// 탐색: 첫 번째 노드
DNode* DLinkedList::frontDNode() const {
	return __head;
}

// 탐색: 맨 마지막 노드(tail)
DNode* DLinkedList::rearDNode() const {
	if (isEmpty()) return nullptr;
	DNode* rNode = __head;
	while (rNode->__Rlink)
		rNode = rNode->__Rlink;
	return rNode;
}

// 빈 리스트 여부 판단
bool DLinkedList::isEmpty() const {
	return __head == nullptr;
}

// 탐색: 노드의 총 개수(count)
int	DLinkedList::countDNode() const {
	if (isEmpty()) return 0;
	int		count = 0;
	DNode* rNode = __head;
	while (rNode->__Rlink)
		rNode = rNode->__Rlink;
	return count;
}

// 리스트의 전체 원소(노드) 출력: 순방향
void DLinkedList::printSLinkedList() const {
	DNode* temp = __head;
	while (temp) {
		cout.width(3);
		cout << temp->__data << " ->>";
		temp = temp->__Rlink;
	}
	cout << " NULL" << endl;
}

// 리스트의 전체 원소(노드) 출력: 역방향
void DLinkedList::revPrintSLinkedList() const {
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
	DLinkedList	dList = DLinkedList();
	while (true) {
		cout << "임의의 정수 입력(종료: 0): ";
		cin >> num;
		if (num == 0)   break;

		// 맨 마지막 노드로 삽입
		dList.addRear(num);
	}

	// 전체 원소 출력
	if (dList.isEmpty()) {
		cout << "입력된 데이터가 없습니다..." << endl;
		return 0;       // dList.~DLinkedList();
	}
	printf("\n ### 입력된 데이터 ### \n\n");
	dList.printSLinkedList();
	dList.revPrintSLinkedList();

	return 0;			// dList.~DLinkedList();
}
