/*
	단순.이중 연결 리스트 : 알고리즘 구현(cpp)
		파일명: LinkedNode(template).cpp
			- 클래스: SNode<T> / 단순 연결 리스트(노드)	: SNode(data, link)
			- 클래스: DNode<T> / 이중 연결 리스트(노드)	: DNode(data, Llink, Rlink)
*/

// #pragma once
#ifndef __SNode_Template_H__
#define __SNode_Template_H__

template <typename T>	class LinkedStack;
template <typename T>	class LinkedQueue;

// 클래스 설계: SNode class
// 노드: SNode(data, Llink, Rlink)
template <typename T>
class SNode {
public:
	SNode(const T &data);
	T	getData(void) const;
private:
	T		data_;
	SNode<T>	*link_;
	template <typename T> friend class LinkedStack;
	template <typename T> friend class LinkedQueue;
};

// SNode class: 노드 생성 및 조작 함수
template <typename T>
SNode<T>::SNode(const T &data) :
	data_(data), link_(nullptr) {}

template <typename T>
T   SNode<T>::getData(void) const {
	return data_;
}

#endif


#ifndef __DNode_Template_H__
#define __DNode_Template_H__

// 클래스 설계: DNode class
// 노드: DNode(data, Llink, Rlink)
template <typename T>
class DNode {
public:
	DNode(const T& data);
	T	getData(void) const;
private:
	T		data_;
	DNode<T>	*Llink_;
	DNode<T>	*Rlink_;
};

// DNode class: 노드 생성 및 조작 함수
template <typename T>
DNode<T>::DNode(const T& data) :
	data_(data), Llink_(nullptr), Rlink_(nullptr) {}

template <typename T>
T   DNode<T>::getData(void) const {
	return data_;
}

#endif
