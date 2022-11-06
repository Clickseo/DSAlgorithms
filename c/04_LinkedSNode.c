/*
	단순 연결 리스트 : 알고리즘 구현(C)
		파일명: LinkedSNode.c
			- 노드		: SNode(data, link)
*/

#include <stdio.h>
#include <stdlib.h>			  // malloc, free
#include "LinkedSNode.h"	// SNode

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
