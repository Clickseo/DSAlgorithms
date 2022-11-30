/*
	* 정렬: 알고리즘 구현

	1) 기초적인 정렬 알고리즘 : 선택.버블.삽입.쉘 정렬
	2) 고급 정렬 알고리즘 : 퀵.병합 정렬
	3) 특수 정렬 알고리즘 : 계수.기수.버킷 정렬
*/

#include <iostream>
#include <random>	// C++ 11에서 추가
using namespace std;	// C++11 이전: C 스타일 난수 생성(srand와 rand 함수)

#define arrMAXSIZE 15

void	selectionSort(int* pArr, int num);	// 선택 정렬
void	bubbleSort(int* pArr, int num);		// 버블 정렬
void	insertionSort(int* pArr, int num);	// 삽입 정렬
void	shellSort(int* pArr, int num);		// 쉘 정렬
void	intervalSort(int* pArr, int num, int start, int interval);

// 3) 특수 정렬 알고리즘: 계수.기수.버킷 정렬
void	contingSort(int* pArr, int num);

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
	random_device rd;		// 시드 설정: random_device 생성
	mt19937 gen(rd());		// 난수 생성 엔진(mt19937) 초기화
	uniform_int_distribution<int> dis(0, 99);	// 균등 분포 정의: 범위 지정
	for (int i = 0; i < arrMAXSIZE; i++)
		*(arr + i) = dis(gen);

	cout << "정렬 전: ";
	PRINT(arr, arrMAXSIZE);

	selectionSort(arr, arrMAXSIZE);
	// bubbleSort(arr, arrMAXSIZE);
	// insertionSort(arr, arrMAXSIZE);
	// shellSort(arr, arrMAXSIZE);
	// quickSort(arr, arr, arr+arrMAXSIZE-1);
	// mergeSort(arr, arr, arr + arrMAXSIZE - 1);
	// contingSort(arr, arrMAXSIZE);

	cout << "정렬 후: ";
	PRINT(arr, arrMAXSIZE);

	return 0;
}

void  SWAP(int* pa, int* pb) {
	int	temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void  PRINT(int* pArr, int  num) {
	for (int i = 0; i < num; i++) {
		cout.width(3);
		cout << *(pArr + i);
	}
	cout << endl;
}

// 선택 정렬: 오름차순
void   selectionSort(int* pArr, int  num) {
	int* pSm;
	for (int i = 0; i < num; i++) {
		// 가장 작은 값을 가진 원소의 위치(주소) 탐색
		pSm = pArr + i;
		for (int j = i; j < num; j++)
			if (*pSm > *(pArr + j))
				pSm = pArr + j;
		// 가장 작은 값을 선택: 현재 값과 교환
		SWAP(pSm, pArr + i);
		// PRINT(pArr, num);
	}
}

// 버블 정렬: 오름차순
void  bubbleSort(int* pArr, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = num - 1; j > 0; j--)
			if (*(pArr + j) < *(pArr + j - 1))
				SWAP(pArr + j, pArr + j - 1);
		// PRINT(pArr, num);
	}
}

// 삽입 정렬: 오름차순
void  insertionSort(int* pArr, int num) {
	int	i, j, temp;
	for (i = 1; i < num; i++) {
		temp = *(pArr + i);
		// temp 가 들어갈 공간 확보
		for (j = i - 1; j >= 0 && *(pArr + j) > temp; j--)
			*(pArr + j + 1) = *(pArr + j);
		*(pArr + j + 1) = temp;
		// PRINT(pArr, num);
	}
}

// 쉘 정렬: 오름차순
void  shellSort(int* pArr, int num) {
	int	interval = num;
	while (interval >= 1) {
		interval /= 2;
		for (int i = 0; i < interval; i++)
			intervalSort(pArr, num, i, interval);
		// printf("interval: %d, ", interval);
		// PRINT(pArr, num);
	}
}

// 쉘 정렬에 쓰이는 삽입 정렬: interval 간격만큼 삽입 정렬
void  intervalSort(int* pArr, int num, int start, int interval) {
	int	i, j, temp;
	for (i = start; i < num; i += interval) {
		temp = *(pArr + i);
		for (j = i - interval; j >= 0 && *(pArr + j) > temp; j -= interval)
			*(pArr + j + interval) = *(pArr + j);
		*(pArr + j + interval) = temp;
	}
	// PRINT(pArr, num);
}

// 퀵 정렬: 오름차순
void  quickSort(int* pArr, int* pFirst, int* pLast) {
	// 재귀 함수 탈출 조건
	if (pFirst >= pLast)
		return;

	// 분할: 기준 값의 왼쪽(작은 값)과 오른쪽(큰 값) 부분 집합
	int* pi = pFirst - 1;
	for (int* pj = pFirst; pj < pLast; pj++)
		if (*pj <= *pLast)		// 기준 값(pivot): 마지막 원소
			SWAP(++pi, pj);
	SWAP(pi + 1, pLast);			// 기준 값을 가운데로 위치 시킨다.
	// PRINT(pFirst, (int)(pLast - pFirst) + 1);

	int* mid = pi + 1;				// 기준 값의 위치(주소)
	quickSort(pArr, pFirst, mid - 1);		// 왼쪽 부분 정렬
	quickSort(pArr, mid + 1, pLast);		// 오른쪽 부분 정렬
}

// 병합 정렬: 오름차순
void  mergeSort(int* pArr, int* pFirst, int* pLast) {
	// 재귀 함수 탈출 조건
	if (pFirst >= pLast)
		return;

	// 중간 원소의 위치(주소) 계산: pFirst와 pLast 범위에서...
	int* pMid = pFirst + (int)(pLast - pFirst) / 2;
	mergeSort(pArr, pFirst, pMid);			// 왼쪽 부분집합 정렬
	mergeSort(pArr, pMid + 1, pLast);		// 오른쪽 부분집합 정렬

	// 각각의 부분집합을 병합(merge)할 메모리 공간 확보
	int	num = (int)(pLast - pFirst) + 1;
	int* pTemp = new (nothrow) int[num];
	if (pTemp == nullptr) {
		cout << "동적 메모리 공간 할당 실패!!!" << endl;
		exit(100);
	}

	// 병합(merge): 정렬된 두 부분집합 병합
	int* pi = pFirst;	// 시작 위치: 왼쪽 부분집합
	int* pj = pMid + 1;	// 시작 위치: 오른쪽 부분집합
	int* pt = pTemp;
	while (pi <= pMid && pj <= pLast) {
		if (*pi <= *pj) 	*pt++ = *pi++;
		else *pt++ = *pj++;
	}
	while (pi <= pMid)	*pt++ = *pi++;
	while (pj <= pLast)	*pt++ = *pj++;

	// 정렬된 데이터로 원본 데이터 재구성
	pi = pFirst;
	pt = pTemp;
	while (pi <= pLast)
		*pi++ = *pt++;
	delete[] pTemp;
	// PRINT(pFirst, (int)(pLast - pFirst) + 1);
}

void	contingSort(int* pArr, int num) {
	int* countArr, * sortArr;
	int	maxNum = 0;
	for (int i = 0; i < num; i++)
		if (maxNum < pArr[i])
			maxNum = pArr[i];

	// countArr : 원본 데이터에서 각 항목들의 발생 횟수를 저장한다.
	//		  단, 원본 데이터의 값 자체가 countArr의 첨자가 된다.
	countArr = new (nothrow) int[maxNum + 1]{ 0 };
	if (countArr == nullptr) {
		cout << "동적 메모리 공간 할당 실패!!!" << endl;
		return;
	}
	for (int i = 0; i < num; i++)		countArr[pArr[i]]++;
	for (int i = 1; i <= maxNum; i++)	countArr[i] += countArr[i - 1];

	// sortArr : countArr의 값을 첨자로 하여 원본 데이터를 정렬된 데이터로 구성한다.
	sortArr = new (nothrow) int[num] {0};
	if (countArr == nullptr) {
		cout << "동적 메모리 공간 할당 실패!!!" << endl;
		exit(100);
	}
	for (int i = num - 1; i >= 0; i--) {
		sortArr[countArr[pArr[i]] - 1] = pArr[i];
		countArr[pArr[i]]--;
		// PRINT(sort, num);
	}

	// 정렬된 데이터(sortArr)로 원본 데이터(pArr)를 재구성한다.
	for (int i = 0; i < num; i++)
		pArr[i] = sortArr[i];

	delete[] countArr;
	delete[] sortArr;
}
