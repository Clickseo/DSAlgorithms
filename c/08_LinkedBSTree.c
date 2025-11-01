/*
	이진 검색 트리(BST): 알고리즘 구현(C) -- 이중연결리스트
		파일명: LinkedBSTree.c
			- 데이터 검색, 삽입, 삭제: searchBST, insertBST, deleteBST
			- 깊이 우선 순회: 전위 순회(재귀적 용법): Preorder
*/

#include <stdio.h>
#include <stdlib.h>			// malloc
#include <stdbool.h>		// bool, true, false
#include "LinkedBSTree.h"	// DNode
// #include "LinkedDNode.h"	// DNode

// 깊이 우선 순회: 전위 순회(재귀적 용법)
void	Preorder(DNode *root) {
	if (root) {
		printf("%3d", root->data);
		Preorder(root->Llink);
		Preorder(root->Rlink);
	}
}

// 이진 검색 트리(BST): 데이터검색 -- 재귀적 용법
DNode	*searchBST(DNode *root, element data) {
	// 탐색 실패 또는 탐색 성공
	if (root == NULL || data == root->data)
		return root;

	DNode	*tNode = NULL;
	if (data < root->data)	tNode = searchBST(root->Llink, data);
	else if (data > root->data)	tNode = searchBST(root->Rlink, data);
	return tNode;
}

// 이진 검색 트리(BST): 데이터 삽입 -- 재귀적 용법
DNode	*insertBST(DNode *root, element data) {
	// 탐색 실패: 새로운 노드 생성
	if(root == NULL) {
		DNode	*newNode = makeDNode(data);
		return newNode;
	}
	
	// 중복된 데이터가 존재할 경우 데이터 삽입 불가능!!!
	if(data == root->data)
		printf("이미 같은 키가 있습니다!!! \n");
	else if(data < root->data)
		root->Llink = insertBST(root->Llink, data);
	else if(data > root->data)
		root->Rlink = insertBST(root->Rlink, data);
	
	return root;
}

// 이진 검색 트리(BST): 데이터 삭제 -- 비재귀적 용법
DNode	*deleteBST(DNode *root, element data) {
	// 삭제할 노드가 없는 경우
	if (root == NULL) {
		printf("\n키를 찾지 못했습니다.");
		return root;
	}

	DNode	*pParent = NULL;	// 삭제할 노드의 부모 노드
	DNode	*tNode = root;		// 삭제할 노드
	DNode	*pChild;			// 삭제할 노드의 자식 노드

	// 삭제할 노드의 위치 탐색
	while (data != tNode->data) {
		pParent = tNode;
		if (data < tNode ->data) tNode = tNode ->Llink;
		else tNode = tNode ->Rlink;
	}

	// 1) 삭제할 노드가 단말 노드인 경우
	if ((tNode->Llink == NULL) && (tNode->Rlink == NULL)) {
		if (pParent == NULL)	root = NULL;
		else if (pParent != NULL) {
			if (pParent->Llink == tNode)	pParent->Llink = NULL;
			else							pParent->Rlink = NULL;
		}
	}

	// 2) 삭제할 노드가 자식 노드를 한 개 가진 경우
	else if ((tNode->Llink == NULL) || (tNode->Rlink == NULL)) {
		// pChild : (후계자) 삭제할 노드의 자식 노드
		if (tNode->Llink != NULL)	pChild = tNode->Llink;
		else						pChild = tNode->Rlink;

		if (pParent == NULL)	root = pChild;
		else {
			if (pParent->Llink == tNode) pParent->Llink = pChild;
			else                         pParent->Rlink = pChild;
		}
	}
	// 3) 삭제할 노드가 자식 노드를 두 개 가진 경우
	else {	
		// 왼쪽 서브 트리에서 후계자(최댓값) 찾기
		DNode	*sParent = tNode;
		DNode	*sNode = tNode->Llink;
		while (sNode->Rlink != NULL) {
			sParent = sNode;
			sNode = sNode->Rlink;
		}

		if (sParent->Llink == sNode)
			sParent->Llink = sNode->Llink;
		else
			sParent->Rlink = sNode->Llink;

		tNode->data = sNode->data;
		tNode = sNode;
	}
	free(tNode);

	return root;
}
