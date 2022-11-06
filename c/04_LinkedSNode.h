/*
	단순 연결 리스트 : 알고리즘 구현(C)
		파일명: LinkedSNode.h
			- 노드		: SNode(data, link)
*/

#pragma once

typedef	int		element;

// 노드: SNode(data, link)
#ifndef __SNode_H__
#define __SNode_H__
typedef struct __SNode {
	element			__data;
	struct __SNode* __link;
}SNode;
#endif

// 단순 연결 리스트 구현(C): SNode(data, link)
SNode* makeSNode(element data);
