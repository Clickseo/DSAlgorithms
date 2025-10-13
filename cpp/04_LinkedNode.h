/*
	단순.이중 연결 리스트 : 알고리즘 구현(C++)
		파일명: LinkedNode.h
			- 클래스: SNode(data, link)			/ 단순 연결 리스트(노드)	: 
			- 클래스: DNode(data, Llink, Rlink)	/ 이중 연결 리스트(노드)	: 
*/

// #pragma once

#ifndef __SNode_H__
#define __SNode_H__

// 클래스 설계: SNode class
// 노드: SNode(data, link)
class SNode {
public:
	SNode(const int &data);
	int	getData(void) const;
private:
	int		data_;
	SNode	*link_;
	friend class SLinkedList;
};

#endif


#ifndef __DNode_H__
#define __DNode_H__

// 클래스 설계: DNode class
// 노드: DNode(data, Llink, Rlink)
class DNode {
public:
	DNode(const int &data);
	int	getData(void) const;
private:
	int		data_;
	DNode	*Llink_;
	DNode	*Rlink_;
	friend class DLinkedList;
};

#endif
