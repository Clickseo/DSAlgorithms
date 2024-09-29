/*
	단순.이중 연결 리스트 : 알고리즘 구현(C)
		파일명: LinkedNode.c
			- 노드		: SNode(data, link)
			- 노드		: DNode(data, Llink, Rlink)
*/

#include <stdio.h>
#include <stdlib.h>		// malloc, free
#include "LinkedNode.h"		// SNode, DNode

// 단순 연결 리스트 구현(C)
// 새로운 노드(SNode: data, link) 생성
SNode* makeSNode(element num) {
	SNode* newNode = (SNode*)malloc(sizeof(SNode));
	if (newNode == NULL) {
		printf("노드 생성 실패!!! \n");
		exit(1);
	}
	newNode->data = num;
	newNode->link = NULL;
	return newNode;
}

// 이중 연결 리스트 구현(C)
// 새로운 노드(DNode: data, Llink, Rlink) 생성
DNode* makeDNode(element num) {
	DNode* newNode = (DNode*)malloc(sizeof(DNode));
	if (newNode == NULL) {
		printf("노드 생성 실패!!! \n");
		exit(1);
	}
	newNode->data = num;
	newNode->Llink = NULL;
	newNode->Rlink = NULL;
	return newNode;
}
