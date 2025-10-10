/*
	단순.이중 연결 리스트 : 알고리즘 구현(cpp)
		파일명: LinkedNode.h
			- 클래스: SNode(data, link) -- 단순 연결 리스트(노드)
			- 클래스: DNode(data, Llink, Rlink) -- 이중 연결 리스트(노드)
*/

#include <iostream>
#include "LinkedNode.h"		// SNode, DNode
using namespace std;

// 단순 연결 리스트: SNode(data, link)
// SNode 생성자: 새로운 노드 생성
SNode::SNode(const int& data):
	data_(data), link_(nullptr) {}

// 이중 연결 리스트: DNode(data, Llink, Rlink)
// DNode 생성자: 새로운 노드 생성
DNode::DNode(const int& data):
	data_(data), Llink_(nullptr), Rlink_(nullptr) {}
