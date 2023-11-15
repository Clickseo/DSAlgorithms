/*
    이진 검색 트리(BST): 알고리즘 구현(C++) -- 이중연결리스트
        파일명: LinkedBSTree(demo).cpp
            - main: 데이터 삽입, 삭제, 검색 그리고 전체 원소 출력
                - 데이터 삽입: InsertBST
                - 데이터 삭제: DeleteBST
                - 데이터 검색: SearchBST
                - 전체 원소 출력: printBSTAll
*/

#include <iostream>
#include <algorithm>        // max
#include "LinkedBSTree.h"   // LinkedBSTree
using namespace std;

// 전체 원소 출력, 데이터 검색, 삽입, 삭제
template <typename E>   void    printBSTAll(LinkedBSTree<E> &bst);
template <typename E>   void	SearchBST(LinkedBSTree<E> &bst);
template <typename E>   void	InsertBST(LinkedBSTree<E> &bst);
template <typename E>   void	DeleteBST(LinkedBSTree<E> &bst);

int main(void)
{
    int                  num;
    LinkedBSTree<int>    bst;

    while (true) {
        system("cls");
        cout << "\n ##### 이진 검색 트리 ##### \n" << endl;
        cout << "1) 데이터 삽입" << endl;
        cout << "2) 데이터 삭제" << endl;
        cout << "3) 데이터 검색" << endl;
        cout << "4) 전체 원소 출력" << endl;
        cout << "5) 프로그램 종료" << endl;
        cout << "\n메뉴 선택: ";
        cin >> num;

        switch (num) {
            case 1: InsertBST(bst);	    break;
            case 2: DeleteBST(bst);	    break;
            case 3: SearchBST(bst);	    break;
            case 4: printBSTAll(bst);   break;
            case 5: cout << "프로그램 종료!!!\n" << endl;
                    return 0;
            default: cout << "메뉴를 잘못 선택하셨습니다." << endl;
        }
        system("pause");
    }
    return 0;
}

// 이진 검색 트리(BST): 전체 노드 출력(전위 순회)
template <typename E>
void    printBSTAll(LinkedBSTree<E> &bst) {
    cout << "\n이진 검색 트리: 전체 원소 출력" << endl;
    bst.Preorder(bst.getRoot());
    cout << "\n" << endl;
}

// 이진 검색 트리(BST): 데이터 검색
template <typename E>
void	SearchBST(LinkedBSTree<E> &bst) {
    int          num;
    DNode<E>    *tNode = nullptr;

    cout << "\n이진 검색 트리: 데이터 검색" << endl;
    while (true) {
        cout << "임의의 정수 입력(종료: 0): ";
        cin >> num;
        if (num == 0)
            break;

        // 데이터 검색
        tNode = bst.searchBST(bst.getRoot(), num);
        if (tNode)	cout << tNode->getData() << " 키를 찾았습니다!!!" << endl;
        else		cout << "키를 찾지 못했습니다." << endl;
    }
}

// 이진 검색 트리(BST): 데이터 삽입
template <typename E>
void	InsertBST(LinkedBSTree<E> &bst) {
    int	        num;
    DNode<E>    *root = nullptr;

    cout << "\n이진 검색 트리: 데이터 삽입" << endl;
    while (true) {
        cout << "임의의 정수 입력(종료: 0): ";
        cin >> num;
        if (num == 0)
            break;

        // 데이터 삽입
        root = bst.insertBST(bst.getRoot(), num);
        if(root != bst.getRoot())
            bst.setRoot(root);
    }
}

// 이진 검색 트리(BST): 데이터 삭제
template <typename E>
void	DeleteBST(LinkedBSTree<E> &bst) {
    int	        num;
    DNode<E>    *root = nullptr;

    cout << "\n이진 검색 트리: 데이터 삭제" << endl;
    while (true) {
        cout << "임의의 정수 입력(종료: 0): ";
        cin >> num;
        if (num == 0)
            break;

        // 데이터 삭제
        root = bst.deleteBST(bst.getRoot(), num);
        if (root != bst.getRoot())
            bst.setRoot(root);
    }
}
