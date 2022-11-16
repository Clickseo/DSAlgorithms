#pragma once
#include <iostream>
#include <algorithm>    // max
using namespace std;

// class DNode
class DNode {
    int     __data;
    DNode* __Llink;
    DNode* __Rlink;
    int    __height;
    friend class AVLTree;
public:
    DNode(const int& data);
    int getData(void) const;
};

// 새로운 노드(data, link) 생성
DNode::DNode(const int& data) :
    __data(data), __Llink(nullptr), __Rlink(nullptr) {}
int DNode::getData(void) const { return __data; }

// class AVLTree
class AVLTree {
private:
    DNode* __root;
public:
    AVLTree();
    ~AVLTree();
    DNode*  getRoot(void) const;
    int     getHeight(DNode* root);
    DNode*  search(const int& data);
    void    insert(const int& data);
    void    remove(const int& data);
    DNode*  transPlant(DNode*& root);
    void    balance(DNode*& root, int data);
    DNode*  leftRotate(DNode* root);
    DNode*  rightRotate(DNode* root);
    void    Preorder(DNode* root) const;
    void    Inorder(DNode* root) const;
    void    Postorder(DNode* root) const;
};

AVLTree::AVLTree() : __root(nullptr) {}
AVLTree::~AVLTree() {}
DNode* AVLTree::getRoot(void) const { return __root; }

// 노드의 높이(__height) 계산
int AVLTree::getHeight(DNode* root) {
    if (root == nullptr)
        return 0;
    return root->__height;
}

// 데이터 검색
DNode* AVLTree::search(const int& data) {
    DNode* root = __root;
    while (root) {
        if (root->__data == data)       return root;
        else if (root->__data > data)   root = root->__Llink;
        else                            root = root->__Rlink;
    }
    return nullptr;
}

// 데이터 삽입
void    AVLTree::insert(const int& data) {
    if (__root == nullptr) {
        __root = new DNode(data);
        return;
    }

    if (__root->__data == data)
        return;

    DNode* root = __root;
    DNode* parent = nullptr;
    while (root) {
        parent = root;
        if (data < parent->__data)  root = root->__Llink;
        else                        root = root->__Rlink;
    }
    if (data < parent->__data)      parent->__Llink = new DNode(data);
    else if (data > parent->__data) parent->__Rlink = new DNode(data);

    // 균형 맞추기
}

// 데이터 삭제
void    AVLTree::remove(const int& data) {
    // 삭제할 노드가 없는 경우
    if (__root == nullptr) {
        return;
    }

    // 삭제할 노드의 위치 탐색
    DNode* parent = nullptr, * child = nullptr;
    DNode* root = __root;
    while (root->__data != data) {
        parent = root;
        if (data < root->__data)    root = root->__Llink;
        else                        root = root->__Rlink;
    }

    // 1) 삭제할 노드가 단말 노드인 경우
    if ((root->__Llink == nullptr) && (root->__Rlink == nullptr)) {
        if (parent != nullptr) {
            if (parent->__Llink == root)    parent->__Llink = nullptr;
            else                            parent->__Rlink = nullptr;
        }
        else __root = nullptr;
    }
    // 2) 삭제할 노드가 자식 노드를 한 개 가진 경우
    else if ((root->__Llink == nullptr) || (root->__Rlink == nullptr)) {
        if (root->__Llink != nullptr)   child = root->__Llink;
        else                            child = root->__Rlink;
        if (parent == nullptr)  __root = child;
        else {
            if (parent->__Llink == root)	parent->__Llink = child;
            else				            parent->__Rlink = child;
        }
    }
    // 3) 삭제할 노드가 자식 노드를 두 개 가진 경우
    else {
        // 왼쪽 서브 트리에서 후계자 찾기
        DNode* succParent = root;
        DNode* succ = root->__Llink;
        while (succ->__Rlink != nullptr) {
            succParent = succ;
            succ = succ->__Rlink;
        }

        if (succParent->__Llink == succ)
            succParent->__Llink = succ->__Llink;
        else
            succParent->__Rlink = succ->__Llink;
        root->__data = succ->__data;
        root = succ;
    }
    delete root;

    // 균형 맞추기
}

DNode* AVLTree::transPlant(DNode*& root) {
    DNode* parent = root;
    DNode* RChild = root->__Rlink;

    if (root->__Llink == nullptr)       root = root->__Rlink;
    else if (root->__Rlink == nullptr)    root = root->__Llink;
    else {
        // 오른쪽 서브 트리에서 가장 작은 값
        while (RChild->__Llink != nullptr) {
            parent = RChild;
            RChild = RChild->__Llink;
        }
        // root <-- RChild
        root->__data = RChild->__data;
        if (parent == root) root->__Rlink = RChild->__Rlink;
        else                parent->__Llink = RChild->__Rlink;
        root = RChild;
    }
    delete RChild;
    return root;
}

// 균형 맞추기: LL, LR, RR, RL 유형
void AVLTree::balance(DNode*& root, int data) {
}

// 왼쪽(left) 회전
DNode* AVLTree::leftRotate(DNode* root) {
}

// 오른쪽(right) 회전
DNode* AVLTree::rightRotate(DNode* root) {
}

// 깊이 우선 순회: 전위 순회
void AVLTree::Preorder(DNode* root) const {
    if (root == nullptr)
        return;
    cout << root->__data << " ";
    Preorder(root->__Llink);
    Preorder(root->__Rlink);
}

// 깊이 우선 순회: 중위 순회
void AVLTree::Inorder(DNode* root) const {
    if (root == nullptr)
        return;
    Inorder(root->__Llink);
    cout << root->__data << " ";
    Inorder(root->__Rlink);
}

// 깊이 우선 순회: 후위 순회
void AVLTree::Postorder(DNode* root) const {
    if (root == nullptr)
        return;
    Postorder(root->__Llink);
    Postorder(root->__Rlink);
    cout << root->__data << " ";
}
