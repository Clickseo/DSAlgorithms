/*
    이진 탐색 트리(BST): 알고리즘 구현
        파일명: BSTree.h
        클래스: DNode
        클래스: BSTree
            - 생성자.소멸자			: BSTree, ~BSTree
            - 데이터 삽입.삭제.검색	: insert, remove, search
            - 깊이 우선 순회		: Preorder, Inorder, Postorder
*/

#pragma once
#include <iostream>
#include <algorithm>    // max
using namespace std;

template <typename E>
class BSTree;

// class DNode
template <typename E>
class DNode {
    E         __data;
    DNode<E>* __Llink;
    DNode<E>* __Rlink;
    template <typename E> friend class BSTree;
public:
    DNode(const E& data);
    E getData(void) const;
};

// DNode: 생성자와 메소드 정의
template <typename E>
DNode<E>::DNode(const E& data) : 
    __data(data), __Llink(nullptr), __Rlink(nullptr) {}

template <typename E>
E   DNode<E>::getData(void) const { return __data; }

// class AVLTree
template <typename E>
class BSTree {
private:
    DNode<E>* __root;
public:
    BSTree();
    ~BSTree();
    DNode<E>* getRoot(void) const;
    DNode<E>* search(const E& data) const;
    void    insert(const E& data);
    void    remove(const E& data);
    void    Preorder(DNode<E>* root) const;
    void    Inorder(DNode<E>* root) const;
    void    Postorder(DNode<E>* root) const;
};

// BSTree: 생성자(소멸자)와 메소드 정의
template <typename E>
BSTree<E>::BSTree() :
    __root(nullptr) {}

template <typename E>
BSTree<E>::~BSTree() {}

template <typename E>
DNode<E>* BSTree<E>::getRoot(void) const { return __root; }

// 데이터 검색
template <typename E>
DNode<E>* BSTree<E>::search(const E& data) const {
    DNode<E>* tNode = __root;
    while (tNode) {
        if (tNode->__data == data)      return tNode;
        else if (tNode->__data > data)  tNode = tNode->__Llink;
        else                            tNode = tNode->__Rlink;
    }
    return nullptr;
}

/*
template <typename E>
DNode<E>* BSTree<E>::search(DNode<E>* root, const E& data) const {
    if (!root)
        return nullptr;

    if (root->__data == data)       return root;
    else if (root->__data > data)   return search(root->__Llink, data);
    else                            return search(root->__Rlink, data);
}
*/

// 데이터 삽입
template <typename E>
void    BSTree<E>::insert(const E& data) {
    // 삽입할 노드의 부모 노드 검색
    DNode<E>* parent = nullptr;
    DNode<E>* tNode = __root;
    while (tNode) {
        parent = tNode;
        if (data == tNode->__data)          return;
        else if (data < tNode->__data)      tNode = tNode->__Llink;
        else                                tNode = tNode->__Rlink;
    }

    // 새로운 노드 생성 및 삽입
    if (parent == nullptr)              __root = new DNode<int>(data);
    else if (data < parent->__data)     parent->__Llink = new DNode<int>(data);
    else                                parent->__Rlink = new DNode<int>(data);
}

/*
template <typename E>
void BSTree<E>::insert(DNode* root, const E& data) const {
    if (root == nullptr)            root = new DNode(data);
    else if (data < root->__data)   root.__Llink = insert(root.__Llink, data);
    else                            root.__Rlink = insert(root.__Rlink, data);
}
*/

// 데이터 삭제
template <typename E>
void    BSTree<E>::remove(const E& data) {
    // 삭제할 노드의 위치 탐색
    DNode<E>* parent = nullptr, * child = nullptr;
    DNode<E>* tNode = __root;
    while (tNode) {
        parent = tNode;
        if (data == tNode->__data)    break;
        else if (data < tNode->__data)  tNode = tNode->__Llink;
        else                            tNode = tNode->__Rlink;
    }

    // 삭제할 데이터가 존재하지 않을 경우...
    if (tNode == nullptr) {
        cout << "키를 찾지 못했습니다." << endl;
        return;
    }

    // 1) 삭제할 노드가 단말 노드인 경우
    if ((tNode->__Llink == nullptr) && (tNode->__Rlink == nullptr)) {
        if (parent == nullptr)  __root = nullptr;
        else {
            if (parent->__Llink == tNode)   parent->__Llink = nullptr;
            else                            parent->__Rlink = nullptr;
        }
    }
    // 2) 삭제할 노드가 자식 노드를 한 개 가진 경우
    else if ((tNode->__Llink == nullptr) || (tNode->__Rlink == nullptr)) {
        if (tNode->__Llink)  child = tNode->__Llink;
        else                child = tNode->__Rlink;
        if (parent == nullptr)  __root = child;
        else {
            if (parent->__Llink == tNode)	parent->__Llink = child;
            else                            parent->__Rlink = child;
        }
    }
    // 3) 삭제할 노드가 자식 노드를 두 개 가진 경우
    else {
        // 왼쪽 서브 트리에서 후계자 찾기
        DNode<E>* succParent = tNode;
        DNode<E>* succ = tNode->__Llink;
        while (succ->__Rlink != nullptr) {
            succParent = succ;
            succ = succ->__Rlink;
        }

        if (succParent->__Llink == succ)
            succParent->__Llink = succ->__Llink;
        else
            succParent->__Rlink = succ->__Llink;
        tNode->__data = succ->__data;
        tNode = succ;
    }
    delete tNode;
}

// 깊이 우선 순회: 전위 순회
template <typename E>
void BSTree<E>::Preorder(DNode<E>* root) const {
    if (root == nullptr)
        return;
    cout << root->__data << " ";
    Preorder(root->__Llink);
    Preorder(root->__Rlink);
}

// 깊이 우선 순회: 중위 순회
template <typename E>
void BSTree<E>::Inorder(DNode<E>* root) const {
    if (root == nullptr)
        return;
    Inorder(root->__Llink);
    cout << root->__data << " ";
    Inorder(root->__Rlink);
}

// 깊이 우선 순회: 후위 순회
template <typename E>
void BSTree<E>::Postorder(DNode<E>* root) const {
    if (root == nullptr)
        return;
    Postorder(root->__Llink);
    Postorder(root->__Rlink);
    cout << root->__data << " ";
}
