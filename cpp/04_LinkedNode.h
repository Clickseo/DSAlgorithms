/*
	단순.이중 연결 리스트 : 알고리즘 구현(cpp)
		파일명: LinkedNode.h
			- 단순 연결 리스트(노드)	: SNode(data, link)
			- 이중 연결 리스트(노드)	: DNode(data, Llink, Rlink)
*/

// 단순 연결 리스트 구현(CPP)
// 노드: SNode(data, link)
// #pragma once
#ifndef __SNode_H__
#define __SNode_H__

// SNode class
class SNode {
public:
	SNode(const int& data);
private:
	int		data_;
	SNode*	link_;
	friend class SLinkedList;
};

#endif

// 이중 연결 리스트 구현(CPP)
// 노드: DNode(data, Llink, Rlink)
#ifndef __DNode_H__
#define __DNode_H__

// DNode class
class DNode {
public:
	DNode(const int& data);
private:
	int		data_;
	DNode*	Llink_;
	DNode*	Rlink_;
	friend class DLinkedList;
};

#endif
