#pragma once
#include <iostream>
#include <vector>
using namespace std;

// HashOpenAddressed class 
template <typename E>
class HashOpenAddressing {
public:
    HashOpenAddressing(int num);
    int     insert(int num);
    int     remove(int num);
    int     search(int num);
    void    output(void);
private:
    vector<E>   __table;
    int         __count;
    const int   DELETED = -54321;
    int __Hash(int i, int num) {    // 해시 함수
        return (num + i) % __table.size();       // 선형 조사
        // return (num + i*i) % __table.size();     // 이차 조사
    }
};

template <typename E>
HashOpenAddressing<E>::HashOpenAddressing(int num) : __count(0) {
    __table = vector<int>(num, NULL);
}

// 데이터 삽입
template <typename E>
int HashOpenAddressing<E>::insert(int num) {
    if (__count < __table.size()) {
        for (int i = 0; i < __table.size(); i++) {
            int slot = __Hash(i, num);
            if (__table[slot] == NULL || __table[slot] == DELETED) {
                __table[slot] = num;
                __count++;
                return num;
            }
        }
    }
    return NULL;
}

// 데이터 삭제
template <typename E>
int HashOpenAddressing<E>::remove(int num) {
    for (int i = 0; i < __table.size(); i++) {
        int slot = __Hash(i, num);
        if (__table[slot] == NULL)
            return NULL;
        else if (__table[slot] == num) {
            __table[slot] = DELETED;
            __count--;
            return num;
        }
    }
    return NULL;
}

// 데이터 검색
template <typename E>
int HashOpenAddressing<E>::search(int num) {
    for (int i = 0; i < __table.size(); i++) {
        int slot = __Hash(i, num);
        if (__table[slot] == NULL)      return NULL;
        else if (__table[slot] == num)  return __table[slot];
    }
    return NULL;
}

// 전체 원소 출력
template <typename E>
void HashOpenAddressing<E>::output(void) {
    cout << "count(" << __count << "): ";
    for (int i = 0; i < __table.size(); i++) {
        cout.width(3);
        cout << __table[i];
    }
    cout << endl;
}
