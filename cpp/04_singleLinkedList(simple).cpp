/*
	단순 연결 리스트: 알고리즘 구현
		- SNode 	: 노드(data, link)
		- SLinkedList	: head
*/

#include <iostream>
using namespace std;

// 노드 클래스: 데이터, 링크
class SNode {
private:
	int	data;
	SNode*	link;
    friend class SLinkedList;
};

// 단순 연결 리스트
class SLinkedList {
private:
	SNode*	  	head;
	// SNode*	tail;	// 맨 마지막 노드
	// int	  	count;	// 노드의 총 개수
public:
	SLinkedList();					// 생성자
	~SLinkedList();					// 소멸자: 전체 노드 삭제
	bool	isEmpty() const;			// 빈 리스트 여부 판단
	int	countSNode() const;			// 탐색: 노드의 총 개수(count)
	SNode*	frontSNode() const;			// 탐색: 첫 번째 노드
	SNode*	rearSNode() const;			// 탐색: 맨 마지막 노드
	SNode*	makeSNode(const int& e) const;		// 새로운 노드 생성
	void	addRear(const int& e);			// 삽입: 맨 마지막 노드
	void	removeFront();				// 삭제: 첫 번째 노드
	void	printSLinkedList();			// 리스트의 전체 노드 출력
};

// 생성자
SLinkedList::SLinkedList()
	: head(NULL) { }

// 빈 리스트 여부 판단
bool SLinkedList::isEmpty() const {
	return head == NULL;
}

// 탐색: 노드의 총 개수(count)
int	SLinkedList::countSNode() const {
	if(isEmpty()) return 0;
	int	count = 0;
	SNode*	rNode = head;
	while(rNode->link)
		rNode = rNode->link;
	return count;
}

// 탐색: 첫 번째 노드
SNode* SLinkedList::frontSNode() const {
	return head;
}

// 탐색: 맨 마지막 노드
SNode* SLinkedList::rearSNode() const {
    if(isEmpty()) return NULL;
    SNode* rNode = head;
    while(rNode->link)
        rNode = rNode->link;
    return rNode;
}

// 새로운 노드 생성
SNode* SLinkedList::makeSNode(const int& e) const {
    SNode* nNode = new SNode;
    nNode->data = e;
    nNode->link = NULL;
    return nNode;
}

// 삽입: 맨 마지막 노드
void SLinkedList::addRear(const int& e) {
    SNode* nNode = makeSNode(e);
    if(isEmpty()) head = nNode;
    else {
        SNode* rNode = rearSNode();
        rNode->link = nNode;
    }
}

// 삭제: 첫 번째 노드
void SLinkedList::removeFront() {
	if(isEmpty()) return;
	SNode* old = head;
	head = old->link;
	delete old;
}

// 소멸자: 전체 노드 삭제
SLinkedList::~SLinkedList() {
	while(!isEmpty()) removeFront();
}

// 리스트의 전체 노드 출력
void SLinkedList::printSLinkedList() {
    if(isEmpty()) return;
    SNode* temp = head;
    while(temp) {
        cout.width(3);
        cout << temp->data << " ->>";
        temp = temp->link;
    }
    cout << " NULL" << endl;
}

int main(void)
{
	int	num;
	SLinkedList	sList = SLinkedList();
	while(true) {
		cout << "임의의 정수 입력(종료: 0): ";
		cin >> num;
		if(num == 0)	break;        
		 sList.addRear(num); 	// 맨 마지막 노드로 삽입
	}

	// 전체 원소 출력
	if(sList.isEmpty()) {
		cout << "입력된 데이터가 없습니다..." << endl;        
		return 0;   // s.~SLinkedList();
	}
	cout << "\n ### 입력된 데이터 ### \n";
	sList.printSLinkedList();    
	// s.~SLinkedList();	// 소멸자: 전체 원소 삭제
	return 0;
}
