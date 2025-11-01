/*
	이진 트리: 알고리즘 구현
		파일명: LinkedBTree.c
			- 이진 트리 생성				: makeLinkedBTree
			- 깊이 우선 순회(전위.중위.후위)	: Preorder, Inorder, Postorder
			- 너비 우선 순회				: Levelorder
*/

#include <stdio.h>
#include <stdlib.h>			// malloc
#include "LinkedStack.h"	// LinkedStack
#include "LinkedQueue.h"	// LinkedQueue
#include "LinkedBTree.h"	// DNode
// #include "LinkedNode.h"	// SNode, DNode
#include "Operators.h"		// isOperator,precedence, isLegal

// 이진 트리 생성
DNode* makeLinkedBTree(char *pStr) {
	DNode		*temp;
	LinkedStack	*Stack = stackCreate();
	while (*pStr) {
		// 공백 제거
		while (*pStr == ' ')
			pStr++;

		temp = makeDNode(*pStr);

		// 연산자일 경우: 스택에서 자식 노드를 구성할 주소를 pop
		if (isOperator(*pStr)) {
			temp->Rlink = (DNode*)top(Stack;		pop(Stack);
			temp->Llink = (DNode*)top(Stack);		pop(Stack);
		}
		push(Stack, (long long)temp);
		pStr++;
	}
	// 루트 노드
	temp = (DNode*)top(Stack);
	pop(Stack);

	stackDestroy(Stack);
	return  temp;
}

// 깊이 우선 순회: 전위 순회(재귀적 용법)
void  Preorder(DNode *root) {
	if (root) {
		printf("%3c", root->__data);
		Preorder(root->Llink);
		Preorder(root->Rlink);
	}
}

// 깊이 우선 순회: 중위 순회(재귀적 용법)
void  Inorder(DNode *root) {
	if (root) {
		Inorder(root->Llink);
		printf("%3c", root->data);
		Inorder(root->Rlink);
	}
}

// 깊이 우선 순회: 후위 순회(재귀적 용법)
void  Postorder(DNode *root) {
	if (root) {
		Postorder(root->Llink);
		Postorder(root->Rlink);
		printf("%3c", root->data);
	}
}

// 너비 우선 순회: 비재귀적 용법
void  Levelorder(DNode *root) {
	DNode		*temp;
	LinkedQueue	*Queue = queueCreate();

	enQueue(Queue, (long long)root);
	while (!queueEempty(Queue))	{
		temp = (DNode*)front(Queue);	deQueue(Queue);
		printf("%3c", temp->__data);
		if (temp->Llink)	enQueue(Queue, temp->Llink);
		if (temp->Rlink)	enQueue(Queue, temp->Rlink);
	}
	queueDestroy(Queue);
}
