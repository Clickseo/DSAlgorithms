/*
    이진 탐색 트리(BST): 알고리즘 구현
        파일명: BSTree(demo).cpp
            - main	: 삽입(Insert), 삭제(Remove), 검색(Search), 전체 출력
*/

#include <iostream>
#include <algorithm>    // max
#include "BSTree.h"     // BSTree
using namespace std;

template <typename E>   void	Insert(BSTree<E>& bst);
template <typename E>   void	Remove(BSTree<E>& bst);
template <typename E>   void	Search(BSTree<E>& bst);

int main(void)
{
    int           num;
    BSTree<int>   bst;
    while (true) {
        system("cls");
        cout << "\n ### 이진 탐색 트리: BST ### \n" << endl;
        cout << "1) 데이터 삽입" << endl;
        cout << "2) 데이터 삭제" << endl;
        cout << "3) 데이터 검색" << endl;
        cout << "4) 전체 출력" << endl;
        cout << "5) 프로그램 종료" << endl;
        cout << "\n메뉴 선택: ";
        cin >> num;
        switch (num) {
            case 1: Insert<int>(bst);	break;
            case 2: Remove(bst);	break;
            case 3: Search(bst);	break;
            case 4: bst.Inorder(bst.getRoot());             break;
            case 5: cout << "프로그램 종료!!!\n" << endl;     return 0;
            default: cout << "메뉴를 잘못 선택하셨습니다." << endl;
        }
        system("pause");
    }
    return 0;
}

// 데이터 입력
template <typename E>
void Insert(BSTree<E>& bst) {
    int	num;
    while (true) {
        cout << "임의의 정수 입력(종료: 0): ";
        cin >> num;
        if (num == 0)   break;
        bst.insert(num);
    }
}

// 데이터 삭제
template <typename E>
void  Remove(BSTree<E>& bst) {
    int	num;
    while (true) {
        cout << "\n삭제할 임의의 정수 값을 입력하세요(종료: 0): ";
        cin >> num;
        if (num == 0)   break;
        bst.remove(num);
    }
}

// 데이터 검색
template <typename E>
void  Search(BSTree<E>& bst) {
    int		    num;
    DNode<E>*   temp = nullptr;
    while (true) {
        cout << "\n찾을 임의의 정수 값을 입력하세요(종료: 0): ";
        cin >> num;
        if (num == 0)   break;
        temp = bst.search(num);
        if (temp)	cout << temp->getData() << " 키를 찾았습니다!!!" << endl;
        else		cout << "키를 찾지 못했습니다." << endl;
    }
}
