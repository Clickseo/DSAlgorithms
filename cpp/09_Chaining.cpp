/*
    해시 테이블(폐쇄형 주소 방식): 알고리즘 구현(C++) -- 이중연결리스트
        파일명: Chaining.cpp
        클래스: Chaining
            - 생성자.소멸자        : Chaining
            - 데이터 삽입.삭제.검색: insert, remove, search
            - 전체 출력            : print
*/

#include <iostream>
#include <vector>
#include "LinkedNode(template).cpp"		// DNode<T>
using namespace std;

// #pragma once
#ifndef __Chaining_H__
#define __Chaining_H__

// 클래스 설계: Chaining
template<typename T>
class Chaining {
public:
    Chaining(int num);
    ~Chaining(void);
    T       insert(T num);
    T       remove(T num);
    T       search(T num);
    void    print(void);
private:
    vector<SNode<T> *>     table_;

    // 해시 함수
    int Hash_(int num) {
        return num % table_.size();
    }
};

// 생성자
template<typename T>
Chaining<T>::Chaining(int num)
    : table_(num, nullptr) {}

// 소멸자: 모든 노드 삭제
template<typename T>
Chaining<T>::~Chaining(void) {
    for (auto tNode: table_) {
        while (tNode) {
            SNode<T>   *old = tNode;
            tNode = tNode->link_;
            delete  old;
        }
    }
}

// 데이터 삽입
template<typename T>
T   Chaining<T>::insert(T num) {
}

// 데이터 삭제
template<typename T>
T   Chaining<T>::remove(T num) {
}

// 데이터 검색
template<typename T>
T   Chaining<T>::search(T num) {
}

// 전체 원소 출력
template<typename T>
void Chaining<T>::print(void) {
    for (int i = 0; i < table_.size(); ++i) {
        cout << i << " ";
        SNode<T>    *tNode = table_[i];
        while (tNode) {
            cout << " --> " << tNode->data_;
            tNode = tNode->link_;
        }
        cout << endl;
    }
}

#endif

int main(void) {
    Chaining<int>     h(13);
    int     choice, num;

    while (true) {
        system("cls");
        cout << "\n##### 해시 테이블 ##### \n" << endl;
        cout << "1) 데이터 삽입" << endl;
        cout << "2) 데이터 삭제" << endl;
        cout << "3) 데이터 검색" << endl;
        cout << "4) 전체 원소 출력" << endl;
        cout << "5) 프로그램 종료" << endl;
        cout << "\n메뉴 선택: ";
        cin >> choice;

        switch (choice) {
        case 1:
        case 2:
        case 3:
            while (true) {
                cout << "임의의 정수 입력(종료 : 0): ";
                cin >> num;
                if (num == 0)
                    break;

                // 선택한 메뉴별 실행: 삽입.삭제.검색
                if (choice == 1)        h.insert(num);
                else if (choice == 2)   h.remove(num);
                else if (choice == 3) {
                    int searched = h.search(num);
                    if (searched != -1) {
                        cout << "검색된 데이터: " << searched << endl;
                    }
                    else {
                        cout << "데이터가 존재하지 않습니다." << endl;
                    }
                }
            }
            break;
        case 4: h.print();  break;
        case 5: cout << "프로그램 종료!!!\n" << endl;
            return 0;
        default: cout << "메뉴를 잘못 선택하셨습니다." << endl;
        }
        system("pause");
    }
    return 0;
}
