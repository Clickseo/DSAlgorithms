/*
	이중 연결 리스트: 알고리즘 구현
		- DNode		: 노드(data, Llink, Rlink)
		- DLinkedList	: head
*/

#include <iostream>
using namespace std;

// 노드(DNode): 데이터(data), 링크(Llink, Rlink)
class DNode {
private:
	int	data;
	DNode*  Llink;
	DNode*  Rlink;
	friend class DLinkedList;
};

// 이중 연결 리스트: DLinkedList -- head
class DLinkedList {
private:
	DNode*	  	head;		// 첫 번째 노드
	// DNode*	tail;		// 맨 마지막 노드
	// int		count;		// 노드의 총 개수
public:
	DLinkedList();					// 생성자
	~DLinkedList();					// 소멸자: 전체 노드 삭제
	bool	isEmpty() const;			// 빈 리스트 여부 판단
	int	countDNode() const;			// 탐색: 노드의 총 개수(count)
	DNode*	frontDNode() const;			// 탐색: 첫 번째 노드
	DNode*	rearDNode() const;			// 탐색: 맨 마지막 노드
	DNode*	makeDNode(const int& e) const;		// 새로운 노드 생성
	void	addRear(const int& e);		    	// 삽입: 맨 마지막 노드
	void	removeFront();				// 삭제: 첫 번째 노드
	void	printDLinkedList();			// 리스트의 전체 노드 출력(순방향)
	void	revPrintDLinkedList();			// 리스트의 전체 노드 출력(역방향)
};

/*
	이중 연결 리스트: DLinkedList -- 함수 정의
		- 리스트 성생 및 삭제: DLinkedList, ~DLinkedList
		- 노드 탐색         : isEmpty, countDNode, frontDNode, rearDNode
		- 노드 삽입 및 삭제 : makeDNode, addRear, removeFront
		- 전체 원소 출력    : printDLinkedList, revPrintDLinkedList
*/

// 생성자
DLinkedList::DLinkedList()
	: head(NULL) { }

// 빈 리스트 여부 판단
bool DLinkedList::isEmpty() const {
	return head == NULL;
}

// 탐색: 노드의 총 개수(count)
int	DLinkedList::countDNode() const {
	if (isEmpty()) return 0;
	int	count = 0;
	DNode* rNode = head;
	while (rNode->Rlink)
		rNode = rNode->Rlink;
	return count;
}

// 탐색: 첫 번째 노드
DNode* DLinkedList::frontDNode() const {
	return head;
}

// 탐색: 맨 마지막 노드(tail)
DNode* DLinkedList::rearDNode() const {
	if (isEmpty()) return NULL;
	DNode* rNode = head;
	while (rNode->Rlink)
		rNode = rNode->Rlink;
	return rNode;
}

// 새로운 노드 생성
DNode* DLinkedList::makeDNode(const int& e) const {
	DNode* nNode = new DNode;
	nNode->data = e;
	nNode->Llink = NULL;
	nNode->Rlink = NULL;
	return nNode;
}

// 노드 삽입: 맨 마지막 노드로...
void DLinkedList::addRear(const int& e) {
	DNode* nNode = makeDNode(e);
	if (isEmpty()) head = nNode;
	else {
		DNode* rNode = rearDNode();
		rNode->Rlink = nNode;
		nNode->Llink = rNode;
	}
}

// 노드 삭제: 첫 번째 노드를...
void DLinkedList::removeFront() {
	DNode* old;
	while (head) {
		old = head;
		head = old->Rlink;
		if (old->Rlink != NULL)
			old->Rlink->Llink = NULL;
		delete old;
	}
}

// 소멸자: 전체 노드 삭제
DLinkedList::~DLinkedList() {
	while (!isEmpty()) removeFront();
	// printSLinkedList();
}

// 리스트의 전체 노드 출력(순방향)
void DLinkedList::printDLinkedList() {
	DNode* temp = head;
	while (temp) {
		cout.width(3);
		cout << temp->data << " ->>";
		temp = temp->Rlink;
	}
	cout << " NULL" << endl;
}

// 리스트의 전체 노드 출력(역방향)
void DLinkedList::revPrintDLinkedList() {
	DNode* temp = rearDNode();
	while (temp) {
		cout.width(3);
		cout << temp->data << " ->>";
		temp = temp->Llink;
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
	dList.printDLinkedList();
	dList.revPrintDLinkedList();

	// 소멸자: 전체 원소 삭제
	// dList.~DLinkedList();
	return 0;
}
