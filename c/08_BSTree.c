#include <stdio.h>
#include <stdlib.h>			// malloc
#include "BSTree.h"			// DNode
// #include "LinkedDNode.h"		// DNode

// 이진 검색 트리(BST): 데이터검색 -- 재귀적 용법
DNode	*searchBST(DNode *root, element data) {
	if (root == NULL || root->__data == data)
		return root;

	DNode	*pTemp = NULL;
	if (data < root->__data)	pTemp = searchBST(root->__Llink, data);
	else if (data > root->__data)	pTemp = searchBST(root->__Rlink, data);
	return pTemp;
}

// 이진 검색 트리(BST): 데이터 삽입 -- 재귀적 용법
DNode	*insertBST(DNode *root, element data) {
	DNode	*newNode = NULL;
	if (root == NULL) {
		newNode = makeDNode(data);
		return newNode;
	}
	else if (data < root->__data) {
		root->__Llink = insertBST(root->__Llink, data);
		return  root;
	}
	else if (data > root->__data) {
		root->__Rlink = insertBST(root->__Rlink, data);
		return root;
	}
	else {
		printf("\n 이미 같은 키가 있습니다!!! \n");
		return NULL;
	}
	return root;
}

// 이진 검색 트리(BST): 데이터 삭제 -- 비재귀적 용법
void deleteBST(DNode* root, element key) {
	// 삭제할 노드가 없는 경우
	if (root == NULL) {
		printf("\n 삭제할 키가 이진 트리에 없습니다!!");
		return;
	}

	DNode	*pTemp = root, *pParent = NULL, *pChild;

	// 삭제할 노드의 위치 탐색
	while (pTemp->__data != key) {
		pParent = pTemp;
		if (key < pTemp->__data) pTemp = pTemp->__Llink;
		else pTemp = pTemp->__Rlink;
	}

	// 1) 삭제할 노드가 단말 노드인 경우
	if ((pTemp->__Llink == NULL) && (pTemp->__Rlink == NULL)) {
		if (pParent != NULL) {
			if (pParent->__Llink == pTemp) pParent->__Llink = NULL;
			else pParent->__Rlink = NULL;
		}
		else root = NULL;
	}
	// 2) 삭제할 노드가 자식 노드를 한 개 가진 경우
	else if ((pTemp->__Llink == NULL) || (pTemp->__Rlink == NULL)) {
		if (pTemp->__Llink != NULL)	pChild = pTemp->__Llink;
		else                        pChild = pTemp->__Rlink;

		if (pParent == NULL)	root = pChild;
		else {
			if (pParent->__Llink == pTemp)	pParent->__Llink = pChild;
			else                            pParent->__Rlink = pChild;
		}
	}
	// 3) 삭제할 노드가 자식 노드를 두 개 가진 경우
	else {
		DNode	*succParent = pTemp;
		DNode	*succ = pTemp->__Llink;

		// 왼쪽 서브 트리에서 후계자 찾기
		while (succ->__Rlink != NULL) {
			succParent = succ;
			succ = succ->__Rlink;
		}
		if (succParent->__Llink == succ)
			succParent->__Llink = succ->__Llink;
		else succParent->__Rlink = succ->__Llink;
		pTemp->__data = succ->__data;
		pTemp = succ;
	}
	free(pTemp);
}
