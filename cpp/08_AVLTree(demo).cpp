/*
    균형 탐색 트리(AVL 트리): 알고리즘 구현
        파일명: AVLTree(demo).cpp
            - main	: 삽입(Insert), 삭제(Remove), 검색(Search), 전체 출력
*/

#include <iostream>
#include <algorithm>    // max
#include "AVLTree.h"    // AVLTree
using namespace std;

void	Insert(AVLTree* avl);
void	Remove(AVLTree* avl);
void	Search(AVLTree* avl);

int main(void)
{
    int         num;
    AVLTree*    avl = new AVLTree();
    while (true) {
        system("cls");
        cout << "\n ### 균형 이진 탐색 트리: AVL ### \n" << endl;
        cout << "1) 데이터 삽입" << endl;
        cout << "2) 데이터 삭제" << endl;
        cout << "3) 데이터 검색" << endl;
        cout << "4) 전체 출력" << endl;
        cout << "5) 프로그램 종료" << endl;
        cout << "\n메뉴 선택: ";
        cin >> num;
        switch (num) {
          case 1: Insert(avl);	break;
          case 2: Remove(avl);	break;
          case 3: Search(avl);	break;
          case 4: avl->Inorder(avl->getRoot());         break;
          case 5: cout << "프로그램 종료!!!\n" << endl;   return 0;
          default: cout << "메뉴를 잘못 선택하셨습니다." << endl;
        }
        system("pause");
    }
    return 0;
}

// 데이터 입력
void Insert(AVLTree* avl) {
    int	    num;
    while (true) {
        cout << "임의의 정수 입력(종료: 0): ";
        cin >> num;
        if (num == 0)   break;
        avl->insert(num);
    }
}

// 데이터 삭제
void  Remove(AVLTree* avl) {
    int	    num;
    while (true) {
        cout << "\n삭제할 임의의 정수 값을 입력하세요(종료: 0): ";
        cin >> num;
        if (num == 0)   break;
        avl->remove(num);
    }
}

// 데이터 검색
void  Search(AVLTree* avl) {
    int		num;
    AVLNode* temp = nullptr;
    while (true) {
        cout << "\n찾을 임의의 정수 값을 입력하세요(종료: 0): ";
        cin >> num;
        if (num == 0)   break;
        temp = avl->search(num);
        if (temp)	cout << temp->getData() << " 키를 찾았습니다!!!" << endl;
        else		cout << "키를 찾지 못했습니다." << endl;
    }
}
