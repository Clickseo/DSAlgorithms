/*
    이진 검색 트리(BST): 알고리즘 구현(C++) -- 이중연결리스트
        파일명: LinkedBSTree.cpp
        클래스: DNode
        클래스: BSTree
            - 생성자.소멸자               : LinkedBSTree, ~LinkedBSTree
            - 데이터 검색.삽입.삭제.검색   : searchBST, insertBST, deleteBST
            - 전체 출력                     : printBSTAll
*/

#pragma once
#include <iostream>
#include <queue>
#include "LinkedNode(template).cpp"		// SNode<T>
using namespace std;

// #pragma once
#ifndef __LinkedBSTree_Template_H__
#define __LinkedBSTree_Template_H__

// 클래스 설계: LinkedBSTree<T>
template <typename T>
class LinkedBSTree {
public:
    LinkedBSTree();
    ~LinkedBSTree();
    void    insertBST(void);
    void    deleteBST(void);
    void    searchBST(void);
    void    printBSTAll(void);
    DNode<T>    *_insertBST(DNode<T> *root, const T &data) const;
    DNode<T>    *_deleteBST(DNode<T> *root, const T &data) const;
    DNode<T>    *_searchBST(DNode<T> *root, const T& data) const;
private:
    DNode<T>    *root_;
};

// 이진 검색 트리 생성
template <typename T>
LinkedBSTree<T>::LinkedBSTree() :
    root_(nullptr) {}

// 이진 검색 트리 삭제: 모든 노드 삭제
template <typename T>
LinkedBSTree<T>::~LinkedBSTree() {
    if (root_ == nullptr)
        return;

    DNode<T>            *tNode = nullptr;
    queue<DNode<T>*>	q;
    q.push(root_);
    while (!q.empty()) {
        tNode = q.front();
        q.pop();
        if (tNode->Llink_) q.push(tNode->Llink_);
        if (tNode->Rlink_) q.push(tNode->Rlink_);
        delete tNode;
    }
}

// 전체 출력
template <typename T>
void    LinkedBSTree<T>::printBSTAll(void) {
    if (root_ == nullptr) {
        cout << "\n데이터가 존재하지 않습니다." << endl;
        return;
    }

    cout << "\n이진 검색 트리: 전체 원소 출력" << endl;
    queue<DNode<T>*>	q;
    DNode<T>            *tNode = nullptr;

    q.push(root_);
    while (!q.empty()) {
        tNode = q.front();		q.pop();
        cout.width(3);
        cout << tNode->data_;
        if (tNode->Llink_)	q.push(tNode->Llink_);
        if (tNode->Rlink_)	q.push(tNode->Rlink_);
    }
    cout << endl;
}

// 데이터 검색: 입출력
template <typename T>
void	LinkedBSTree<T>::searchBST(void) {
    if (root_ == nullptr) {
        cout << "\n데이터가 존재하지 않습니다." << endl;
        return;
    }

    int		    num;
    DNode<T>    *tNode = nullptr;

    cout << "\n이진 검색 트리: 데이터 검색" << endl;
    while (true) {
        cout << "임의의 정수 입력(종료: 0): ";
        cin >> num;
        if (num == 0)
            break;

        // 데이터 검색
        tNode = _searchBST(root_, num);
        if (tNode)	cout << tNode->data_ << " 키를 찾았습니다!!!" << endl;
        else		cout << "키를 찾지 못했습니다." << endl;
    }
}

// 데이터 검색: 재귀적 용법,  비재귀적 용법
template <typename T>
DNode<T>    *LinkedBSTree<T>::_searchBST(DNode<T> *root, const T &data) const {

}

// 데이터 삽입: 입출력
template <typename T>
void	LinkedBSTree<T>::insertBST(void) {
    int	        num;

    cout << "\n이진 검색 트리: 데이터 삽입" << endl;
    while (true) {
        cout << "임의의 정수 입력(종료: 0): ";
        cin >> num;
        if (num == 0)
            break;

        // 데이터 삽입
        root_ = _insertBST(root_, num);
    }
}

// 데이터 삽입: 재귀적 용법, 비재귀적 용법
template <typename T>
DNode<T>    *LinkedBSTree<T>::_insertBST(DNode<T> *root, const T &data) const {

}

// 데이터 삭제: 입출력
template <typename T>
void	LinkedBSTree<T>::deleteBST(void) {
    if (root_ == nullptr) {
        cout << "\n데이터가 존재하지 않습니다." << endl;
        return;
    }

    int     num;

    cout << "\n이진 검색 트리: 데이터 삭제" << endl;
    while (true) {
        cout << "임의의 정수 입력(종료: 0): ";
        cin >> num;
        if (num == 0)
            break;

        // 데이터 삭제
        root_ = _deleteBST(root_, num);
    }
}

// 데이터 삭제: 비재귀적 용법
template <typename T>
DNode<T>    *LinkedBSTree<T>::_deleteBST(DNode<T> *root, const T &data) const {

}

#endif
