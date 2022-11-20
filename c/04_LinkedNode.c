/*
	단순.이중 연결 리스트 : 알고리즘 구현(C)
		파일명: LinkedNode.c
			- 노드		: SNode(data, link)
			- 노드		: DNode(data, link)
*/

#include <stdio.h>
#include <stdlib.h>		// malloc, free
#include "LinkedNode.h"		// SNode, DNode

// 단순 연결 리스트 구현(C)
// 새로운 노드(data, link) 생성
SNode* makeSNode(element num) {
	SNode* newSNode = (SNode*)malloc(sizeof(SNode));
	if (newSNode == NULL) {
		printf("노드 생성 실패!!! \n");
		exit(100);
	}
	newSNode->__data = num;
	newSNode->__link = NULL;
	return newSNode;
}

// 이중 연결 리스트 구현(C)
// 새로운 노드(DNode: data, Llink, Rlink) 생성
DNode* makeDNode(element num) {
	DNode* newDNode = (DNode*)malloc(sizeof(DNode));
	if (newDNode == NULL) {
		printf("노드 생성 실패!!! \n");
		exit(100);
	}
	newDNode->__data = num;
	newDNode->__Llink = NULL;
	newDNode->__Rlink = NULL;
	return newDNode;
}
