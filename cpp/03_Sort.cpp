/*
    * 정렬: 알고리즘 구현
        파일명: Sort.cpp
            - 기초적인 정렬 알고리즘: 선택.버블.삽입 정렬
            - 고급 정렬 알고리즘	: 쉘.퀵.병합 정렬
            - 특수 정렬 알고리즘	: 계수 정렬
*/

#include <iostream>
#include <vector>       // vector
#include <algorithm>    // swap, copy, max_element
#include <random>       // C++ 11에서 추가
// C++11 이전: C 스타일 난수 생성(srand와 rand 함수)

using namespace std;

// 1) 기초적인 정렬 알고리즘
void selectionSort(vector<int>& vArr);
void bubbleSort(vector<int>& vArr);
void insertionSort(vector<int>& vArr);

// 2) 고급 정렬 알고리즘
void shellSort(vector<int>& vArr);
void intervalSort(vector<int>& vArr, int start, int interval);
void quickSort(vector<int>& vArr, int first, int last);
void mergeSort(vector<int>& vArr, int first, int last);

// 3) 특수 정렬 알고리즘: 계수 정렬
void countingSort(vector<int>& vArr);

// 동적 배열(vector)의 전체 데이터 출력
void PRINT(const vector<int>& vArr);

// 동적 배열 원소의 크기
#define arrMAXSIZE 10

int main(void) {
    vector<int>     vArr(arrMAXSIZE);

    // C++ 스타일 난수 생성
    random_device   rd;
    mt19937         gen(rd());
    uniform_int_distribution<int> dis(0, 99);
    for (int& num : vArr) {
        num = dis(gen);
    }

    cout << "정렬 전: ";
    PRINT(vArr);

    // selectionSort(vArr);
    // bubbleSort(vArr);
    // insertionSort(vArr);
    // shellSort(vArr);
    // quickSort(vArr, 0, (int)vArr.size() - 1);
    // mergeSort(vArr, 0, (int)vArr.size() - 1);
    countingSort(vArr);

    cout << "정렬 후: ";
    PRINT(vArr);

    return 0;
}

void PRINT(const vector<int>& vArr) {
    for (int num : vArr) {
        cout.width(3);
        cout << num;
    }
    cout << endl;
}

// 선택 정렬: 오름차순
void selectionSort(vector<int>& vArr) {
    int     num = (int)vArr.size();
    for (int i = 0; i < num; ++i) {
        // 가장 작은 값을 가진 원소의 위치 탐색
        int iSm = i;
        for (int j = i + 1; j < num; ++j)
            if (vArr[j] < vArr[iSm])
                iSm = j;
        // 가장 작은 값을 선택: 현재 값과 교환
        swap(vArr[i], vArr[iSm]);
        // PRINT(vArr);
    }
}

// 버블 정렬: 오름차순
void bubbleSort(vector<int>& vArr) {
    int     num = (int)vArr.size();
    for (int i = 0; i < num - 1; ++i) {
        for (int j = 0; j < num - 1 - i; ++j)
            if (vArr[j] > vArr[j + 1])
                swap(vArr[j], vArr[j + 1]);
        // PRINT(vArr);
    }
}

// 삽입 정렬: 오름차순
void insertionSort(vector<int>& vArr) {
    int     num = (int)vArr.size();
    int	    i, j, temp;
    for (i = 1; i < num; ++i) {
        temp = vArr[i];
        // temp 가 들어갈 공간 확보
        for (j = i - 1; j >= 0 && vArr[j] > temp; --j)
            vArr[j + 1] = vArr[j];
        vArr[j + 1] = temp;
        // PRINT(vArr);
    }
}

// 쉘 정렬: 오름차순
void shellSort(vector<int>& vArr) {
    int     num = (int)vArr.size();
    for (int interval = num / 2; interval > 0; interval /= 2)
        intervalSort(vArr, 0, interval);
}

// 쉘 정렬에 쓰이는 삽입 정렬: interval 간격만큼 삽입 정렬
void intervalSort(vector<int>& vArr, int start, int interval) {
    int     num = (int)vArr.size();
    int	    i, j, temp;
    for (i = start + interval; i < num; i += interval) {
        temp = vArr[i];
        for (j = i - interval; j >= 0 && vArr[j] > temp; j -= interval)
            vArr[j + interval] = vArr[j];
        vArr[j + interval] = temp;
    }
    // PRINT(pArr, num);
}

// 퀵 정렬: 오름차순
void quickSort(vector<int>& vArr, int first, int last) {
    // 재귀 함수 탈출 조건
    if (first >= last)
        return;

    // 분할: 기준 값의 왼쪽(작은 값)과 오른쪽(큰 값) 부분 집합
    int     pivot = vArr[last];
    int     i = first - 1;
    for (int j = first; j < last; j++)
        if (vArr[j] <= pivot)
            swap(vArr[++i], vArr[j]);
    swap(vArr[i + 1], vArr[last]);      // 기준 값을 가운데로 위치 시킨다.

    int     pi = i + 1;                 // 기준 값의 위치
    quickSort(vArr, first, pi - 1);     // 왼쪽 부분 정렬
    quickSort(vArr, pi + 1, last);      // 오른쪽 부분 정렬
}

// 병합 정렬: 오름차순
void mergeSort(vector<int>& vArr, int first, int last) {
    // 재귀 함수 탈출 조건
    if (first >= last)
        return;

    // 중간 원소의 위치 계산: first와 last 범위에서...
    int     mid = first + (last - first) / 2;
    mergeSort(vArr, first, mid);                // 왼쪽 부분집합 정렬
    mergeSort(vArr, mid + 1, last);             // 오른쪽 부분집합 정렬

    // 각각의 부분집합을 병합(merge)할 메모리 공간 확보
    vector<int>     temp(last - first + 1);

    // 병합(merge): 정렬된 두 부분집합 병합
    int     i = first, j = mid + 1, t = 0;
    while (i <= mid && j <= last) {
        if (vArr[i] <= vArr[j]) temp[t++] = vArr[i++];
          else                  temp[t++] = vArr[j++];
    }
    while (i <= mid)    temp[t++] = vArr[i++];
    while (j <= last)   temp[t++] = vArr[j++];

    // 정렬된 데이터로 원본 데이터 재구성
    copy(temp.begin(), temp.end(), vArr.begin() + first);
}

// 계수 정렬: 오름차순
void countingSort(vector<int>& vArr) {
    int     num = (int)vArr.size();
    if (num == 0)
        return;

    // 원본 데이터에서 최대값
    int maxNum = *max_element(vArr.begin(), vArr.end());

    // countArr : 원본 데이터에서 각 항목들의 발생 횟수를 저장한다.
    //				단, 원본 데이터의 값 자체가 countArr의 첨자가 된다.
    vector<int>     countArr(maxNum + 1, 0);
    for (int num : vArr)
        countArr[num]++;

    int     index = 0;
    for (int i = 0; i <= maxNum; ++i) {
        while (countArr[i]-- > 0) {
            vArr[index++] = i;
        }
    }
}
