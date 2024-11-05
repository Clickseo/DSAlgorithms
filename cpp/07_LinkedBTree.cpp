/*
	이진 트리: 알고리즘 구현(C++) -- 이중연결리스트
		파일명: LinkedBTree.cpp
		클래스: DNode<T>
		클래스: BTree<T>
			- 생성자.소멸자: LinkedBTree, ~LinkedBTree
			- 깊이 우선 순회: Preorder, Inorder, Postorder
			- 비비 우선 순회: Levelorder
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
	int		isOperator(int op);
private:
	DNode<T>	*root_;
};

// 이진 트리 생성
template <typename T>
LinkedBTree<T>::LinkedBTree()
	: root_(nullptr) { }

// 연산자 여부 판단
template <typename T>
int  LinkedBTree<T>::isOperator(int op) {
	return op == '+' || op == '-' || op == '*' || op == '/';
}

#endif
