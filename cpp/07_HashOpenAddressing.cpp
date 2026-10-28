/*
    해시 테이블(개방 주소 방법): 알고리즘 구현(C++) -- 순차자료구조
        파일명: HashOpenAddressing.cpp
        클래스: HashOpenAddressing
            - 생성자.소멸자          : HashOpenAddressing
            - 데이터 삽입.삭제.검색  : insert, remove, search
            - 전체 원소 출력        : print
*/

#include <iostream>
#include <vector>
using namespace std;

// #pragma once
#ifndef __HashOpenAddressing_H__
#define __HashOpenAddressing_H__

// 클래스 설계: HashOpenAddressing
template <typename T>
class HashOpenAddressing {
public:
    HashOpenAddressing(T num);      // 생성자
    T     insert(T num);            // 데이터 삽입
    T     remove(T num);            // 데이터 삭제
    T     search(T num);            // 데이터 검색
    void    print(void);            // 전체 원소 출력
private:
    vector<T>   table_;
    int         count_;
    const int   DELETED = -54321;

    // 해시 함수
    int Hash_(int i, T num) {
        return (num + i) % table_.size();           // 선형 조사
        // return (num + i*i) % __table.size();     // 이차 조사
    }
};

// 생성자
template <typename T>
HashOpenAddressing<T>::HashOpenAddressing(T num): count_(0) {
    table_ = vector<T>(num, -1);
}

// 데이터 삽입
template <typename T>
T HashOpenAddressing<T>::insert(T num) {
}

// 데이터 삭제
template <typename T>
T HashOpenAddressing<T>::remove(T num) {
}

// 데이터 검색
template <typename T>
T HashOpenAddressing<T>::search(T num) {
}

// 전체 원소 출력
template <typename T>
void HashOpenAddressing<T>::print(void) {
    cout << "count(" << count_ << "): ";
    for (int i = 0; i < table_.size(); ++i) {
        cout.width(3);
        cout << table_[i];
    }
    cout << endl;
}

#endif

int main(void) {
    HashOpenAddressing<int>     h(13);
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
