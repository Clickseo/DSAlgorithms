/*
	이진 트리(Binary Tree): 알고리즘 구현(C++) -- 이중연결리스트
		파일명: LinkedBTree.h
		클래스: DNode
		클래스: BTree
			- 생성자.소멸자: LinkedBTree, ~LinkedBTree
			- 깊이 우선 순회: Preorder, Inorder, Postorder
			- 너비 우선 순회: Levelorder
*/

#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

// 연산자 여부를 판단
int  isOperator(int  op) {
	return op == '+' || op == '-' || op == '*' || op == '/';
}

template <typename E>
class LinkedBTree;

// class DNode
template <typename E>
class DNode {
public:
	DNode(const E& data);
private:
	E         __data;
	DNode<E>* __Llink;
	DNode<E>* __Rlink;
	template <typename E> friend class LinkedBTree;
};

template <typename E>
DNode<E>::DNode(const E& data) :
	__data(data), __Llink(nullptr), __Rlink(nullptr) {}

// class LinkedBTree
template <typename E>
class LinkedBTree {
public:
	LinkedBTree();
	~LinkedBTree();
	DNode<E>* makeLinkedBTree(const string str);
	void	Preorder(DNode<E>* root) const;
	void	Inorder(DNode<E>* root) const;
	void	Postorder(DNode<E>* root) const;
	void	Levelorder(DNode<E>* root) const;
private:
	DNode<E>* __root;
};

template <typename E>
LinkedBTree<E>::LinkedBTree()
	: __root(nullptr) { }

// 소멸자: 모든 노드 삭제(큐 구조 활용)
template <typename E>
LinkedBTree<E>::~LinkedBTree() {
	if (__root == nullptr)
		return;

	DNode<E>* tNode = nullptr;
	queue<DNode<E>*>	Q;
	Q.push(__root);
	while (!Q.empty()) {
		tNode = Q.front();
		Q.pop();
		if (tNode->__Llink) Q.push(tNode->__Llink);
		if (tNode->__Rlink) Q.push(tNode->__Rlink);
		delete tNode;
	}
}

// 이진 트리(수식 트리) 생성: 스택 구조 활용
template <typename E>
DNode<E>* LinkedBTree<E>::makeLinkedBTree(const string str) {
	stack<DNode<E>*>	S;
	DNode<E>		*tNode;
	for (int i = 0; i < str.length(); i++) {
		// 공백 제거
		while (str[i] == ' ')
			i++;

		// 새로운 노드를 생성
		tNode = new DNode<E>(str[i]);

		// 연산자 일 경우...
		if (isOperator(str[i])) {
			tNode->__Rlink = S.top();    S.pop();
			tNode->__Llink = S.top();    S.pop();
		}
		S.push(tNode);
	}
	tNode = S.top();
	S.pop();

	// 루트 노드 설정
	__root = tNode;
	return  tNode;
}

// 깊이 우선 순회: 전위 순회(재귀적 용법)
template <typename E>
void	LinkedBTree<E>::Preorder(DNode<E>* root) const {
	if (root) {
		cout.width(3);	 cout << root->__data;
		Preorder(root->__Llink);
		Preorder(root->__Rlink);
	}
}

// 깊이 우선 순회: 중위 순회(재귀적 용법)
template <typename E>
void	LinkedBTree<E>::Inorder(DNode<E>* root) const {
	if (root) {
		Inorder(root->__Llink);
		cout.width(3);	 cout << root->__data;
		Inorder(root->__Rlink);
	}
}

// 깊이 우선 순회: 후위 순회(재귀적 용법)
template <typename E>
void	LinkedBTree<E>::Postorder(DNode<E>* root) const {
	if (root) {
		Postorder(root->__Llink);
		Postorder(root->__Rlink);
		cout.width(3);	 cout << root->__data;
	}
}

// 너비 우선 순회: 비재귀적 용법(큐 구조 활용)
template <typename E>
void LinkedBTree<E>::Levelorder(DNode<E>* root) const {
	if (root == nullptr)
		return;

	queue<DNode<E>*>	Q;
	Q.push(root);
	while (!Q.empty()) {
		DNode<E>* tNode = Q.front();
		Q.pop();
		cout.width(3);
		cout << tNode->__data;
		if (tNode->__Llink) Q.push(tNode->__Llink);
		if (tNode->__Rlink) Q.push(tNode->__Rlink);
	}
	cout << endl;
}
