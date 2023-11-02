/*
	이진 트리: 알고리즘 구현 -- 단순연결리스트
		파일명: LinkedBTree(demo).cpp
			- main: 이진 트리 구성과 순회
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
	cout << "\nPreorder  : ";	BT.Preorder(root);		// 전위 순회
	cout << "\nInorder   : ";	BT.Inorder(root);		  // 중위 순회
	cout << "\nPostorder : ";	BT.Postorder(root);		// 후위 순회

	// 너비 우선 순회
	cout << "\nLevelorder : ";	BT.Levelorder(root);
	cout << endl;

	return 0;
}
