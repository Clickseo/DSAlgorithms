/*
	파일명: LinkedBtree.h
 	클래스 설계 및 구현: DNode, LinkedBTree
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

// class LinkedBTree
template <typename E>
class LinkedBTree {
public:
	LinkedBTree();
	DNode<E>* makeLinkedBTree(const string str);
	void	Preorder(DNode<E>* root) const;
	void	Inorder(DNode<E>* root) const;
	void	Postorder(DNode<E>* root) const;
	void	Levelorder(DNode<E>* root) const;
 	~LinkedBTree();
private:
	DNode<E>* __root;
};
// DNode, LinkedBTree Class 멤버 함수 정의 생략
