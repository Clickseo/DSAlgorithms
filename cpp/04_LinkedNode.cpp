/*
	단순.이중 연결 리스트 : 알고리즘 구현(C++)
		파일명: LinkedNode.cpp
			- 클래스: SNode(data, link)			/ 단순 연결 리스트(노드)
			- 클래스: DNode(data, Llink, Rlink) / 이중 연결 리스트(노드)
*/

#include <iostream>
#include "LinkedNode.h"		// SNode, DNode
using namespace std;

// 클래스 설계: SNode(data, link)
SNode::SNode(const int &data):
	data_(data), link_(nullptr) {}

// 노드의 데이터 반환
int	SNode::getData(void) const {
	return data_;
}


// 클래스 설계: DNode(data, Llink, Rlink)
DNode::DNode(const int &data):
	data_(data), Llink_(nullptr), Rlink_(nullptr) {}

// 노드의 데이터 반환
int	DNode::getData(void) const {
	return data_;
}
