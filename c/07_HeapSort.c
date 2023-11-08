#include <stdio.h>
#include <stdlib.h>	    // srand, rand, malloc, calloc, free
#include <stdbool.h>	// bool, true, false
#include <time.h>	    // time

#define arrMAXSIZE 10
typedef int element;

void HeapSort(element *pArr, const int num);
void buildHeap(element* pArr, const int end);
void percolateDown(element *pArr, const int root, const int end);
void SWAP(element *pa, element *pb);
void PRINT(element *pArr, const int num);

int main(void)
{
    int		arr[arrMAXSIZE] = { 0 };

    // 임의의 난수 생성: 0 ~ 99사이의 정수
    srand((unsigned int)time(NULL));
    for (int i = 0; i < arrMAXSIZE; i++)
        *(arr + i) = rand() % 100;

    printf("정렬 전: ");           PRINT(arr, arrMAXSIZE);
    HeapSort(arr, arrMAXSIZE);
    printf("정렬 후: ");           PRINT(arr, arrMAXSIZE);

    return 0;
}

// 힙 정렬
void HeapSort(element* pArr, const int num) {
    buildHeap(pArr, num);
    for (int i = num - 1; i >= 0; i--) {
        // A[i] = deleteMax();
        // i번째 위치에 제일 큰 값을 저장
        SWAP(pArr, pArr + i);

        // pArr[0]의 자료 이동으로 pArr[0:i-1]를 최대 힙으로 재구성
        percolateDown(pArr, 0, i - 1);
    }
}

// buildHeap: 최대 힙 구성
void buildHeap(element* pArr, const int num) {
    for (int i = num / 2; i >= 0; i--)
        percolateDown(pArr, i, num);
    // printf("buildHeap: ");           PRINT(pArr, arrMAXSIZE);
}

void percolateDown(element* pArr, const int root, const int end) {
    int		child = 2 * root + 1;	 // 왼쪽 자식
    int		right = 2 * root + 2;	 // 오른쪽 자식
    if (child <= end) {
        if (right <= end && pArr[child] < pArr[right])
            child = right;
        // child : A[2k + 1]와 A[2k + 2] 중에 큰 원소의 인덱스
        if (pArr[root] < pArr[child]) {
            SWAP(pArr + root, pArr + child);
            percolateDown(pArr, child, end);
        }
    }
}

void SWAP(element* pa, element* pb) {
    element     temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
    return;
}

void PRINT(element* pArr, const int num) {
    for (int i = 0; i < num; i++)
        printf("%3d", *(pArr + i));
    printf("\n");
    return;
}
