/*
	이진 트리: 알고리즘 구현
		파일명: LinkedBTree.c
			- 이진 트리 생성					: makeLinkedBTree
			- 깊이 우선 순회(전위.중위.후위)	: Preorder, Inorder, Postorder
			- 너비 우선 순회					: Levelorder
*/

#include <stdio.h>
#include <stdlib.h>				// malloc
#include "LinkedStack.h"		// LinkedStack
#include "LinkedQueue.h"		// LinkedQueue
#include "LinkedBTree.h"		// DNode
// #include "LinkedNode.h"		// SNode, DNode
#include "Operators.h"			// isOperator,precedence, isLegal

// 이진 트리 생성
DNode* makeLinkedBTree(char* pStr) {
	DNode*			temp;
	LinkedStack*	S = stackCreate();
	while (*pStr) {
		// 공백 제거
		while (*pStr == ' ')
			pStr++;

		temp = makeDNode(*pStr);

		// 연산자일 경우: 스택에서 자식 노드를 구성할 주소를 pop
		if (isOperator(*pStr)) {
			temp->__Rlink = (DNode*)top(S);		pop(S);
			temp->__Llink = (DNode*)top(S);		pop(S);
		}
		push(S, (long long)temp);
		pStr++;
	}
	// 루트 노드
	temp = (DNode*)top(S);
	pop(S);

	stackDestroy(S);
	return  temp;
}

// 깊이 우선 순회: 전위 순회(재귀적 용법)
void  Preorder(DNode* root) {
	if (root) {
		printf("%3c", root->__data);
		Preorder(root->__Llink);
		Preorder(root->__Rlink);
	}
}

// 깊이 우선 순회: 중위 순회(재귀적 용법)
void  Inorder(DNode* root) {
	if (root) {
		Inorder(root->__Llink);
		printf("%3c", root->__data);
		Inorder(root->__Rlink);
	}
}

// 깊이 우선 순회: 후위 순회(재귀적 용법)
void  Postorder(DNode* root) {
	if (root) {
		Postorder(root->__Llink);
		Postorder(root->__Rlink);
		printf("%3c", root->__data);
	}
}

// 너비 우선 순회: 비재귀적 용법
void  Levelorder(DNode* root) {
	DNode*			temp;
	LinkedQueue*	Q = queueCreate();

	enQueue(Q, (long long)root);
	while (!queueEempty(Q))	{
		temp = (DNode*)front(Q);	deQueue(Q);
		printf("%3c", temp->__data);
		if (temp->__Llink)	enQueue(Q, temp->__Llink);
		if (temp->__Rlink)	enQueue(Q, temp->__Rlink);
	}
	queueDestroy(Q);
}
