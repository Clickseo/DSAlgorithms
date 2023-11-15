/*
	이진 검색 트리(BST): 알고리즘 구현(C) -- 이중연결리스트
		파일명: LinkedBSTree.h
			- 데이터 검색, 삽입, 삭제: searchBST, insertBST, deleteBST
			- 깊이 우선 순회: 전위 순회(재귀적 용법): Preorder
*/

// 이중 연결 리스트 구현(C)
// 노드: DNode(data, Llink, Rlink)
// #pragma once
#include "LinkedNode.h"		// DNode

// 이진 검색 트리(BST) 구현
DNode	*insertBST(DNode* root, element data);
DNode	*deleteBST(DNode* root, element data);
DNode	*searchBST(DNode* root, element data);
void	Preorder(DNode* root);
