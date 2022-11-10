/*
	단순.이중 연결 리스트 : 알고리즘 구현(C)
		파일명: LinkedNode.h
			- 노드		: SNode(__data, __link)
			- 노드		: DNode(__data, __Llink, __Rlink)
*/

// #pragma once
typedef	int		element;

// 노드: SNode(data, link)
#ifndef __SNode_H__
#define __SNode_H__
typedef struct __SNode {
	element			    __data;
	struct __SNode* __link;
}SNode;
#endif

// 노드: DNode(data, Llink, Rlink)
#ifndef __DNode_H__
#define __DNode_H__
typedef struct __DNode {
	element			    __data;
	struct __DNode* __Llink;
	struct __DNode* __Rlink;
}DNode;
#endif

// 단순 연결 리스트 구현(C): SNode(data, link)
// 이중 연결 리스트 구현(C): DNode(data, Llink, Rlink)
SNode* makeSNode(element data);
DNode* makeDNode(element data);
