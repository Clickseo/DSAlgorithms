/*
    이진 탐색 트리(BST): 알고리즘 구현
        파일명: BSTree.h
        클래스: DNode
        클래스: BSTree
            - 생성자.소멸자		: BSTree, ~BSTree
            - 데이터 삽입.삭제.검색	: insertBST, deleteBST, searchBST
*/

#pragma once
#include <iostream>
#include <queue>
#include <algorithm>    // max
using namespace std;

template <typename E>
class BSTree;

// class DNode
template <typename E>
class DNode {
public:
    DNode(const E &data);
    E getData(void) const;
    DNode<E>* getLlink(void) const;
    DNode<E>* getRlink(void) const;
private:
    E           __data;
    DNode<E>    *__Llink;
    DNode<E>    *__Rlink;
    template <typename E> friend class BSTree;
};

// DNode: 생성자와 멤버 함수 정의
template <typename E>
DNode<E>::DNode(const E &data) : 
    __data(data), __Llink(nullptr), __Rlink(nullptr) {}

template <typename E>
E   DNode<E>::getData(void) const { return __data; }

template <typename E>
DNode<E>* DNode<E>::getLlink(void) const { return __Llink; }

template <typename E>
DNode<E>* DNode<E>::getRlink(void) const { return __Rlink; }

// class BSTree
template <typename E>
class BSTree {
public:
    BSTree();
    ~BSTree();
    DNode<E>    *getRoot(void) const;
    DNode<E>    *searchBST(DNode<E> *root, const E &data) const;
    DNode<E>    *insertBST(DNode<E>* root, const E& data) const;
    void        deleteBST(DNode<E> *root, const E &data);
private:
    DNode<E>    *__root;
};

// BSTree: 생성자와 소멸자 정의
template <typename E>
BSTree<E>::BSTree() :
    __root(nullptr) {}

// 소멸자: 모든 노드 삭제(큐 구조 활용)
template <typename E>
BSTree<E>::~BSTree() {
    if (__root == nullptr)
        return;

    DNode<E>            *tNode = nullptr;
    queue<DNode<E>*>	Q;
    Q.push(__root);
    while (!Q.empty()) {
        tNode = Q.front();
        Q.pop();
        if (tNode->__Llink) Q.push(tNode->__Llink);
        if (tNode->__Rlink) Q.push(tNode->__Rlink);
        delete tNode;
    }
}

// BSTree: 멤버 함수 정의
template <typename E>
DNode<E>* BSTree<E>::getRoot(void) const { return __root; }

// 이진 검색 트리(BST): 데이터 검색 -- 재귀적 용법
template <typename E>
DNode<E>* BSTree<E>::searchBST(DNode<E> *root, const E &data) const {
}

// 이진 검색 트리(BST): 데이터 삽입 -- 재귀적 용법
template <typename E>
DNode<E>* BSTree<E>::insertBST(DNode<E> *root, const E &data) const {
}

// 이진 검색 트리(BST): 데이터 삭제 -- 비재귀적 용법
template <typename E>
void BSTree<E>::deleteBST(DNode<E> *root, const E &data) {
    // 삭제할 노드의 위치 탐색
    // 삭제할 데이터가 존재하지 않을 경우...
    if (tNode == nullptr) {
        cout << "키를 찾지 못했습니다." << endl;
        return;
    }
    // 1) 삭제할 노드가 단말 노드인 경우
    // 2) 삭제할 노드가 자식 노드를 한 개 가진 경우
    // 3) 삭제할 노드가 자식 노드를 두 개 가진 경우
    else {
        // 왼쪽 서브 트리에서 후계자 찾기
    delete tNode;
}
