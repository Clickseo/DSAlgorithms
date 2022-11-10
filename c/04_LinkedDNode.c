/*
	이중 연결 리스트 : 알고리즘 구현(C)
		파일명: LinkedDNode.c
			- 노드		: DNode(data, Llink, Rlinke)
*/

#include <stdio.h>
#include <stdlib.h>			  // malloc, free
#include "LinkedDNode.h"	// DNode

// 새로운 노드(data, link) 생성
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
