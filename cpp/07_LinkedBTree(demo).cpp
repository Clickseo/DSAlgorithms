/*
	이진 트리: 알고리즘 구현(C++) -- 이중연결리스트
		파일명: LinkedBTree(demo).cpp
			- main: 이진 트리 생성과 순회
*/

#include <iostream>
#include <string>
#include "LinkedBTree.cpp"	// LinkedBTree<T>, DNode<T>
using namespace std;

int main(void)
{
	string	postfix;

	cout << "트리를 구성할 후위 수식: ";
	getline(cin, postfix);

	// 이진 트리 생성
	LinkedBTree<char>	BTree;
	DNode<char>		*root = BTree.makeLinkedBTree(postfix);

	// 깊이 우선 순회: 전위.중위.후위 순회
	cout << "\nPreorder  : ";	BTree.Preorder(root);		// 전위 순회
	cout << "\nInorder   : ";	BTree.Inorder(root);		// 중위 순회
	cout << "\nPostorder : ";	BTree.Postorder(root);		// 후위 순회

	// 너비 우선 순회
	cout << "\nLevelorder : ";	BTree.Levelorder(root);

	return 0;
}
