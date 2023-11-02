/*
	파일명: LinkedBtree.h
 	클래스 설계 및 구현: DNode, LinkedBTree

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
*/

/*
	이진 트리: 알고리즘 구현 -- 단순연결리스트
		파일명: LinkedBTree(demo).cpp
			- main: 이진 트리(수식 트리) 구성 및 순회
*/

#include <iostream>
#include <string>
#include "LinkedBtree.h"	// DNode Class
				// LinkedBTree Class
using namespace std;

int main(void)
{
	string	postfix;

	cout << "트리를 구성할 후위 수식: ";
	getline(cin, postfix);

	// 이진 트리 생성 및 구성
	LinkedBTree<char>	BT;
	DNode<char>*		root = BT.makeLinkedBTree(postfix);

	// 깊이 우선 순회: 전위.중위.후위 순회
	cout << "\nPreorder  : ";	BT.Preorder(root);	// 전위 순회
	cout << "\nInorder   : ";	BT.Inorder(root);	// 중위 순회
	cout << "\nPostorder : ";	BT.Postorder(root);	// 후위 순회

	// 너비 우선 순회
	cout << "\nLevelorder : ";	BT.Levelorder(root);

	return 0;
}
