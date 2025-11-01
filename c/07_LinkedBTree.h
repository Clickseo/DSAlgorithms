/*
	이진 트리: 알고리즘 구현(C) -- 단순연결리스트
			파일명: LinkedBTree.h
*/

// #pragma once
#include "LinkedNode.h"		// DNode, makeDNode

// 이진 트리 생성
DNode	*makeLinkedBTree(char *pStr);
int	isOperator(int ch);
int	isLegal(char *pStr);

// 이진 트리 순회: 깊이 우선 순회(전위.중위.후위 순회)
void	Preorder(DNode *root);
void	Inorder(DNode *root);
void	Postorder(DNode *root);

// 이진 트리 순회: 너비 우선 순회
void	Levelorder(DNode *root);
