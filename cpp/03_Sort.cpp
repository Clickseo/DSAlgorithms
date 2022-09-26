/*	
	정렬: 알고리즘 구현

	1) 기초적인 정렬 알고리즘: 선택.버블.삽입.쉘 정렬
	2) 고급 정렬 알고리즘: 퀵.병합 정렬
	3) 특수 정렬 알고리즘: 계수.기수.버킷 정렬
*/

#include <iostream>
#include <random>       // C++ 11에서 추가
using namespace std;    // C++11 이전 방법: C 스타일 난수 생성(srand와 rand 함수)

#define arrMAXSIZE 15

// 기초적인 정렬 알고리즘
void	selectionSort(int* pArr, int num);	// 선택 정렬
// void	bubbleSort(int* pArr, int num);		// 버블 정렬
// void	insertionSort(int* pArr, int num);	// 삽입 정렬
// void	shellSort(int* pArr, int num);		// 쉘 정렬
// void	intervalSort(int* pArr, int num, int start, int interval);

// 고급 정렬 알고리즘
// void	quickSort(int* pArr, int* pFirst, int* pLast);	// 퀵 정렬
// void	mergeSort(int* pArr, int* pFirst, int* pLast);	// 병합 정렬

// 3) 특수 정렬 알고리즘: 계수.기수.버킷 정렬
// void  contingSort(int* pArr, int num);

void	SWAP(int* pa, int* pb);
void	PRINT(int* pArr, int num);

int main(void)
{
  int	arr[arrMAXSIZE] = { 0 };

	/* C 스타일 난수 생성(srand와 rand 함수)
		srand(static_cast<unsigned int>(time(nullptr)));
		static_cast<int>(rand() % (99 + 1UL - 0)) + 0;
	*/

	// C++ 스타일 난수 생성
	random_device rd;       // 1) 시드 설정: random_device(비결정적 난수 생성기) 생성
	mt19937	gen(rd());      // 2) 난수 생성 엔진(mt19937) 초기화
	uniform_int_distribution<int>	dis(0, 99);   // 균등 분포 정의: 범위 지정
	for (int i = 0; i < arrMAXSIZE; i++)
		*(arr + i) = dis(gen);

	cout << "정렬 전: ";
	PRINT(arr, arrMAXSIZE);

	selectionSort(arr, arrMAXSIZE);
	// bubbleSort(arr, arrMAXSIZE);
	// insertionSort(arr, arrMAXSIZE);
	// shellSort(arr, arrMAXSIZE);
	// quickSort(arr, arr, arr + arrMAXSIZE - 1);
	// mergeSort(arr, arr, arr + arrMAXSIZE - 1);
	// contingSort(arr, arrMAXSIZE);
	
	cout << "정렬 후: ";
	PRINT(arr, arrMAXSIZE);

	return 0;
}

// 선택 정렬: 오름차순
void   selectionSort(int* pArr, int num) {
	int* pSm;
	for (int i = 0; i < num; i++) {
		pSm = pArr + i;
		for (int j = i; j < num; j++)
			if (*pSm > *(pArr + j))
				pSm = pArr + j;
		// 가장 작은 값을 선택: 현재 값과 교환
		SWAP(pSm, pArr + i);
		PRINT(pArr, num);
	}
	return;
}

void  SWAP(int* pa, int* pb) {
	int	temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
	return;
}

void  PRINT(int* pArr, int num) {
	for (int i = 0; i < num; i++) {
		cout.width(3);
		cout << *(pArr + i);
	}
	cout << endl;
	return;
}
