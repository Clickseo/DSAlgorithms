#include <iostream>
#include <random>       // C++ 11에서 추가
using namespace std;    // C++11 이전: C 스타일 난수 생성(srand와 rand 함수)

#define arrMAXSIZE 15

template <typename T> void HeapSort(T *pArr, const int num);
template <typename T> void buildHeap(T *pArr, const int num);
template <typename T> void downHeap(T *pArr, const int root, const int num);
template <typename T> void SWAP(T *pa, T *pb);
template <typename T> void PRINT(T *pArr, const int num);

int main(void)
{
    int			arr[arrMAXSIZE] = { 5, 2, 3, 9, 6, 1, 8, 4, 7 };
    // int		arr[arrMAXSIZE];

    // C++ 스타일 난수 생성
    random_device rd;		// 시드 설정: random_device 생성
    mt19937 gen(rd());	    	// 난수 생성 엔진(mt19937) 초기화
    uniform_int_distribution<int> dis(0, 99);	// 균등 분포 정의: 범위 지정
    for (int i = 0; i < arrMAXSIZE; i++)
        *(arr + i) = dis(gen);

    cout << "정렬 전: ";       PRINT(arr, arrMAXSIZE);
    HeapSort(arr, arrMAXSIZE);
    cout << "정렬 후: ";       PRINT(arr, arrMAXSIZE);
    return 0;
}

// HeapSort: 힙 정렬
template <typename T>
void HeapSort(T *pArr, const int num) {
    buildHeap(pArr, num);

    // deleteMax();
    // downHeap();
}

// buildHeap: 최대 힙 구성
template <typename T>
void buildHeap(T *pArr, const int num) {
}

// downHeap: 최대 힙으로 재구성
template <typename T>
void downHeap(T *pArr, const int root, const int end) {
}

template <typename T>
void SWAP(T *pa, T *pb) {
    T	temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

template <typename T>
void PRINT(T *pArr, const int num) {
    for (int i = 0; i < num; ++i)
        cout << pArr[i] << " ";
    cout << endl;
}
