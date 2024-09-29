/*
	단순.이중 연결 리스트 : 알고리즘 구현(C)
		파일명: LinkedNode.h
			- 단순 연결 리스트(노드)	: SNode(data, link)
			- 이중 연결 리스트(노드)	: DNode(data, Llink, Rlink)
*/

// #pragma once
typedef	int		element;

// 단순 연결 리스트 구현(C)
// 노드: SNode(data, link)
#ifndef __SNode_H__
#define __SNode_H__
typedef struct _SNode {
	element			data;
	struct _SNode*	link;
}SNode;
#endif

SNode* makeSNode(element data);

// 이중 연결 리스트 구현(C)
// 노드: DNode(data, Llink, Rlink)
#ifndef __DNode_H__
#define __DNode_H__
typedef struct _DNode {
	element			data;
	struct _DNode*	Llink;
	struct _DNode*	Rlink;
}DNode;
#endif

DNode* makeDNode(element data);
