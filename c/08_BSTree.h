/*
	이진 검색 트리(BST): 알고리즘 구현(C) -- 단순연결리스트
			파일명: BSTree.h
*/

// 이중 연결 리스트 구현(C)
// 노드: DNode(data, Llink, Rlink)
// #pragma once
#include "LinkedNode.h"		// DNode

// 이진 검색 트리(BST) 구현
DNode	*searchBST(DNode* root, element data);
DNode	*insertBST(DNode* root, element data);
void	deleteBST(DNode* root, element key);
