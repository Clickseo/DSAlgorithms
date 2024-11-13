/*
    이진 검색 트리: 알고리즘 구현(C++) -- 이중연결리스트
        파일명: LinkedBSTree(demo).cpp
            - main: 이진 검색 트리 생성
                - 데이터 삽입: insertBST
                - 데이터 삭제: deleteBST
                - 데이터 검색: searchBST
                - 전체 원소 출력: printBSTAll
*/

#include <iostream>
#include "LinkedBSTree.cpp"  // LinkedBTree<T>, DNode<T>
using namespace std;

int main(void)
{
    int                    num;
    LinkedBSTree<int>    bst;

    while (true) {
        system("cls");
        cout << "\n##### 이진 검색 트리 ##### \n" << endl;
        cout << "1) 데이터 삽입" << endl;
        cout << "2) 데이터 삭제" << endl;
        cout << "3) 데이터 검색" << endl;
        cout << "4) 전체 원소 출력" << endl;
        cout << "5) 프로그램 종료" << endl;
        cout << "\n메뉴 선택: ";
        cin >> num;

        switch (num) {
            case 1: bst.insertBST();	    break;
            case 2: bst.deleteBST();	    break;
            case 3: bst.searchBST();        break;
            case 4: bst.printBSTAll();    break;
            case 5: cout << "프로그램 종료!!!\n" << endl;
                    return 0;
            default: cout << "메뉴를 잘못 선택하셨습니다." << endl;
        }
        system("pause");
    }
    return 0;
}
