/*
	이진 트리: 알고리즘 구현 -- 단순연결리스트
		파일명: LinkedBinaryTree(demo).c
			- main	: 이진 트리 구성과 순회
*/

#include <stdio.h>
#include <stdlib.h>					    // exit
#include "LinkedBinaryTree.h"		// DNode
#define bufferMAXSIZE 1024

int main(void)
{
	DNode*	root;
	char	postfix[bufferMAXSIZE];

	printf("트리를 구성할 후위 수식: ");
	gets_s(postfix, sizeof(postfix));

	if (!isLegal(postfix)) {
		printf("\n잘못된 수식... \n\n");
		exit(100);
	}

	// 이진 트리 구성
	root = makeLinkedBinaryTree(postfix);

	// 이진 트리 깊이 우선 순회 : 전위.중위.후위 순회
	printf("\nPreorder  : ");	Preorder(root);			// 전위 순회
	printf("\nInorder   : ");	Inorder(root);			// 중위 순회
	printf("\nPostorder : ");	Postorder(root);		// 후위 순회

	// 이진 트리 너비 우선 순회
	printf("\n Levelorder : ");	Levelorder(root);
	printf("\n");

	return 0;
}
