/*
	이진 트리: 알고리즘 구현(C++) -- 이중연결리스트
		파일명: LinkedBTree.cpp
		클래스: DNode<T>
		클래스: BTree<T>
			- 생성자.소멸자: LinkedBTree, ~LinkedBTree
			- 깊이 우선 순회: Preorder, Inorder, Postorder
			- 너비 우선 순회: Levelorder
			- 이진 트리(수식 트리) 생성: makeLinkedBTree
*/

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include "LinkedNode(template).cpp"		// SNode<T>
using namespace std;

// #pragma once
#ifndef __LinkedBTree_Template_H__
#define __LinkedBTree_Template_H__

// 클래스 설계: LinkedBTree<T>
template <typename T>
class LinkedBTree {
public:
	LinkedBTree();
	~LinkedBTree();
	void		Preorder(DNode<T> *root) const;
	void		Inorder(DNode<T> *root) const;
	void		Postorder(DNode<T> *root) const;
	void		Levelorder(DNode<T> *root) const;
	DNode<T>	*makeLinkedBTree(const string str);
	int			isOperator(int op);
private:
	DNode<T>	*root_;
};

// 이진 트리 생성
template <typename T>
LinkedBTree<T>::LinkedBTree()
	: root_(nullptr) { }

// 이진 트리(수식 트리) 생성: 스택 활용
template <typename T>
DNode<T>* LinkedBTree<T>::makeLinkedBTree(const string str) {
    stack<DNode<T>*>	s;
    DNode<T>			*tNode = nullptr;	
}

// 연산자 여부 판단
template <typename T>
int  LinkedBTree<T>::isOperator(int op) {
	return op == '+' || op == '-' || op == '*' || op == '/';
}


// 깊이 우선 순회: 전위 순회(재귀적 용법)
template <typename T>
void	LinkedBTree<T>::Preorder(DNode<T> *root) const {
	if (root) {
		cout.width(3);	 cout << root->data_;
		Preorder(root->Llink_);
		Preorder(root->Rlink_);
	}
}

// 깊이 우선 순회: 중위 순회(재귀적 용법)
template <typename T>
void	LinkedBTree<T>::Inorder(DNode<T> *root) const {
	if (root) {
		Inorder(root->Llink_);
		cout.width(3);	 cout << root->data_;
		Inorder(root->Rlink_);
	}
}

// 깊이 우선 순회: 후위 순회(재귀적 용법)
template <typename T>
void	LinkedBTree<T>::Postorder(DNode<T> *root) const {
	if (root) {
		Postorder(root->Llink_);
		Postorder(root->Rlink_);
		cout.width(3);	 cout << root->data_;
	}
}

// 너비 우선 순회: 비재귀적 용법
template <typename T>
void LinkedBTree<T>::Levelorder(DNode<T>* root) const {
    if (root_ == nullptr)
        return;

    queue<DNode<T>*>	q;
    DNode<T>			*tNode = nullptr;

    // 너비 우선 순회: 전체 노드 방문
}

// 소멸자: 이진 트리 삭제 -- 너비 우선 순회
template <typename T>
LinkedBTree<T>::~LinkedBTree() {
    if (root_ == nullptr)
        return;

    queue<DNode<T>*>	q;
    DNode<T>			*tNode = nullptr;

    // 너비 우선 순회: 전체 노드 삭제
}

#endif
