/*
	이진 검색 트리(BST): 알고리즘 구현(C) -- 이중연결리스트
		파일명: LinkedBSTree.c
			- 데이터 검색, 삽입, 삭제: searchBST, insertBST, deleteBST
			- 깊이 우선 순회: 전위 순회(재귀적 용법): Preorder
*/

#include <stdio.h>
#include <stdlib.h>			// malloc
#include <stdbool.h>			// bool, true, false
#include "LinkedBSTree.h"		// DNode
// #include "LinkedDNode.h"		// DNode

// 이진 검색 트리(BST): 데이터검색 -- 재귀적 용법
DNode	*searchBST(DNode *root, element data) {
	if (root == NULL || data == root->__data)
		return root;

	DNode	*tNode = NULL;
	if (data < root->__data)	tNode = searchBST(root->__Llink, data);
	else if (data > root->__data)	tNode = searchBST(root->__Rlink, data);
	return tNode;
}

// 이진 검색 트리(BST): 데이터 삽입 -- 재귀적 용법
DNode	*insertBST(DNode *root, element data) {
	DNode	*newNode = NULL;
	// 탐색 실패: 새로운 노드 생성
	if (root == NULL) {
		newNode = makeDNode(data);
		return newNode;
	}
	else if (data < root->__data)
		root->__Llink = insertBST(root->__Llink, data);
	else if (data > root->__data)
		root->__Rlink = insertBST(root->__Rlink, data);
	// 중복된 데이터가 존재할 경우 데이터 삽입 불가능!!!
	else printf("이미 같은 키가 있습니다!!! \n");
	return root;
}

// 이진 검색 트리(BST): 데이터 삭제 -- 비재귀적 용법
DNode* deleteBST(DNode* root, element data) {
	// 삭제할 노드가 없는 경우
	if (root == NULL) {
		printf("\n 삭제할 키가 이진 트리에 없습니다!!");
		return root;
	}

	DNode	*pParent = NULL;	// 삭제할 노드의 부모 노드
	DNode	*tNode = root;		// 삭제할 노드
	DNode	*pChild;		// 삭제할 노드의 자식 노드

	// 삭제할 노드의 위치 탐색
	while (tNode -> __data != data) {
		pParent = tNode;
		if (data < tNode ->__data) tNode = tNode -> __Llink;
		else tNode = tNode -> __Rlink;
	}

	// 1) 삭제할 노드가 단말 노드인 경우
	if ((tNode->__Llink == NULL) && (tNode->__Rlink == NULL)) {
		if (pParent == NULL)	root = NULL;
		else if (pParent != NULL) {
			if (pParent->__Llink == tNode)	pParent->__Llink = NULL;
			else				pParent->__Rlink = NULL;
		}
	}

	// 2) 삭제할 노드가 자식 노드를 한 개 가진 경우
	else if ((tNode->__Llink == NULL) || (tNode->__Rlink == NULL)) {
		// pChild : (후계자) 삭제할 노드의 자식 노드
		if (tNode->__Llink != NULL)	pChild = tNode->__Llink;
		else				pChild = tNode->__Rlink;

		if (pParent == NULL)	root = pChild;
		else {
			if (pParent->__Llink == tNode) pParent->__Llink = pChild;
			else                           pParent->__Rlink = pChild;
		}
	}
	// 3) 삭제할 노드가 자식 노드를 두 개 가진 경우
	else {	
		// 왼쪽 서브 트리에서 후계자(최댓값) 찾기
		DNode	*sParent = tNode;
		DNode	*sNode = tNode->__Llink;
		while (sNode->__Rlink != NULL) {
			sParent = sNode;
			sNode = sNode->__Rlink;
		}

		if (sParent->__Llink == sNode)
			sParent->__Llink = sNode->__Llink;
		else
			sParent->__Rlink = sNode->__Llink;

		tNode->__data = sNode->__data;
		tNode = sNode;
	}
	free(tNode);

	return root;
}

// 깊이 우선 순회: 전위 순회(재귀적 용법)
void  Preorder(DNode* root) {
	if (root) {
		printf("%3d", root->__data);
		Preorder(root->__Llink);
		Preorder(root->__Rlink);
	}
}
