#include <iostream>
#include <random>		// C++ 11에서 추가
using namespace std;		// C++11 이전 방법: C 스타일 난수 생성(srand와 rand 함수)

#define arrMAXSIZE 15

void	selectionSort(int* pArr, int num);	// 선택 정렬
# void	bubbleSort(int* pArr, int num);	// 버블 정렬
# void	insertionSort(int* pArr, int num);	// 삽입 정렬
# void	shellSort(int* pArr, int num);		// 쉘 정렬
# void	intervalSort(int* pArr, int num, int start, int interval);

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
	random_device rd;			// 1) 시드 설정: random_device(비결정적 난수 생성기) 생성
	mt19937	gen(rd());			// 2) 난수 생성 엔진(mt19937) 초기화
	uniform_int_distribution<int>	dis(0, 99);		// 균등 분포 정의: 범위 지정
	for (int i = 0; i < arrMAXSIZE; i++)
		*(arr + i) = dis(gen);

	cout << "정렬 전: ";
	PRINT(arr, arrMAXSIZE);

	selectionSort(arr, arrMAXSIZE);
	// bubbleSort(arr, arrMAXSIZE);
	// insertionSort(arr, arrMAXSIZE);
	// shellSort(arr, arrMAXSIZE);

	cout << "정렬 후: ";
	PRINT(arr, arrMAXSIZE);

	return 0;
}

void  SWAP(int* pa, int* pb) {
	int	temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
	return;
}

void  PRINT(int* pArr, int  num) {
	for (int i = 0; i < num; i++) {
		cout.width(3);
		cout << *(pArr + i);
	}
	cout << endl;
	return;
}

// 선택 정렬: 오름차순
void   selectionSort(int* pArr, int  num) {
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
