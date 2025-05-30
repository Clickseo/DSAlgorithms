/*
	* 정렬: 알고리즘 구현
		파일명: Sort.c
			- 기초적인 정렬 알고리즘: 선택.버블.삽입 정렬
			- 고급 정렬 알고리즘	: 쉘.퀵.병합 정렬
			- 특수 정렬 알고리즘	: 계수 정렬
*/

#include <stdio.h>
#include <stdlib.h>	// srand, rand
#include <stdbool.h>	// bool, true, false
#include <time.h>	// time

// 1) 기초적인 정렬 알고리즘
void	selectionSort(int *pArr, int num);	// 선택 정렬
void	bubbleSort(int *pArr, int num);		// 버블 정렬
void	insertionSort(int *pArr, int num);	// 삽입 정렬

// 2) 고급 정렬 알고리즘
void	shellSort(int *pArr, int num);					// 쉘 정렬
void	intervalSort(int *pArr, int num, int start, int interval);
void	quickSort(int *pArr, int *pFirst, int *pLast);			// 퀵 정렬
void	mergeSort(int *pArr, int *pFirst, int *pLast);			// 병합 정렬

// 3) 특수 정렬 알고리즘: 계수 정렬
void  contingSort(int *pArr, int num);

// 배열의 원소 교환 및 전체 데이터 출력
void	SWAP(int *pa, int *pb);
void	PRINT(int *pArr, int num);

// 배열 원소의 최대 크기
#define arrMAXSIZE 10

int main(void)
{
	// int	*pArr = (int*)realloc(NULL, arrMAXSIZE * (int)sizeof(int));
	// int	*pArr = (int*)malloc(arrMAXSIZE * (int)sizeof(int));
	// int	*pArr = (int*)calloc(arrMAXSIZE, (int)sizeof(int));
	int	arr[arrMAXSIZE] = { 0 };

	// 임의의 난수 생성: 0 ~ 99사이의 정수
	srand((unsigned int)time(NULL));
	for (int i = 0; i < arrMAXSIZE; ++i)
		*(arr + i) = rand() % 100;
		// arr[i] = rand() % 100;

	printf("정렬 전: ");
	PRINT(arr, arrMAXSIZE);

	selectionSort(arr, arrMAXSIZE);
	// bubbleSort(arr, arrMAXSIZE);
	// insertionSort(arr, arrMAXSIZE);
	// shellSort(arr, arrMAXSIZE);
	// quickSort(arr, arr, arr+arrMAXSIZE-1);
	// mergeSort(arr, arr, arr + arrMAXSIZE - 1);
	// contingSort(arr, arrMAXSIZE);

	printf("정렬 후: ");
	PRINT(arr, arrMAXSIZE);

	return 0;
}

void  SWAP(int *pa, int *pb) {
	int	temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void  PRINT(int *pArr, int num) {
	for (int i = 0; i < num; ++i)
		printf("%3d", *(pArr + i));
	printf("\n");
}

// 선택 정렬: 오름차순
void   selectionSort(int *pArr, int num) {
	int *pSm;
	for (int i = 0; i < num; ++i) {
		// 가장 작은 값을 가진 원소의 위치(주소) 탐색
		pSm = pArr + i;
		for (int j = i; j < num; ++j)
			if (*pSm > *(pArr + j))
				pSm = pArr + j;
		// 가장 작은 값을 선택: 현재 값과 교환
		SWAP(pSm, pArr + i);
		// PRINT(pArr, num);
	}
}

// 버블 정렬: 오름차순
void  bubbleSort(int *pArr, int num) {
	for (int i=0; i<num; ++i) {
		for (int j = num - 1; j>0; --j)
			if (*(pArr + j) < *(pArr + j - 1))
				SWAP(pArr + j, pArr + j - 1);
		// PRINT(pArr, num);
	}
}

/* 버블 정렬: 알고리즘 개선
// 버블 정렬: 오름차순 -- 알고리즘 개선 #01
void  bubbleSort(int *pArr, int num) {
	_Bool	state;	// 상태 변수
	for (int i = 0; i < num; ++i) {
		state = true;
		for (int j = num - 1; j > 0; --j) {
			if (*(pArr + j) < *(pArr + j - 1)) {
				SWAP(pArr + j, pArr + j - 1);
				state = false;
			}
		}
		if (state == true)
			break;
		// PRINT(pArr, num);
	}
}
*/

// 삽입 정렬: 오름차순
void  insertionSort(int *pArr, int num) {
	int	i, j, temp;
	for (i = 1; i < num; ++i) {
		temp = *(pArr + i);
		// temp 가 들어갈 공간 확보
		for (j = i - 1; j >= 0 && *(pArr + j) > temp; --j)
			*(pArr + j + 1) = *(pArr + j);
		*(pArr + j + 1) = temp;
		// PRINT(pArr, num);
	}
}

// 쉘 정렬: 오름차순
void shellSort(int *pArr, int num) {
	for (int interval = num / 2; interval > 0; interval /= 2)
		intervalSort(pArr, num, 0, interval);
}

// 쉘 정렬에 쓰이는 삽입 정렬: interval 간격만큼 삽입 정렬
void  intervalSort(int *pArr, int num, int start, int interval) {
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
void  quickSort(int *pArr, int *pFirst, int *pLast) {
	// 재귀 함수 탈출 조건
	if (pFirst >= pLast)
		return;

	// 분할: 기준 값의 왼쪽(작은 값)과 오른쪽(큰 값) 부분 집합
	int	*pi = pFirst - 1;
	for (int *pj = pFirst; pj < pLast; ++pj)
		if (*pj <= *pLast)			// 기준 값(pivot): 마지막 원소
			SWAP(++pi, pj);
	SWAP(pi + 1, pLast);				// 기준 값을 가운데로 위치 시킨다.
	// PRINT(pFirst, (int)(pLast - pFirst) + 1);

	int	*mid = pi + 1;				// 기준 값의 위치(주소)
	quickSort(pArr, pFirst, mid - 1);		// 왼쪽 부분 정렬
	quickSort(pArr, mid + 1, pLast);		// 오른쪽 부분 정렬
}

// 병합 정렬: 오름차순
void  mergeSort(int *pArr, int *pFirst, int *pLast) {
	// 재귀 함수 탈출 조건
	if (pFirst >= pLast)
		return;

	// 중간 원소의 위치(주소) 계산: pFirst와 pLast 범위에서...
	int	*pMid = pFirst + (int)(pLast - pFirst) / 2;
	mergeSort(pArr, pFirst, pMid);			// 왼쪽 부분집합 정렬
	mergeSort(pArr, pMid + 1, pLast);		// 오른쪽 부분집합 정렬

	// 각각의 부분집합을 병합(merge)할 메모리 공간 확보
	int	num = (int)(pLast - pFirst) + 1;
	int	*pTemp = (int*)malloc(num * (int)sizeof(int));
	if (pTemp == NULL) {
		printf("동적 메모리 공간 할당 실패!!!");
		exit(100);
	}

	// 병합(merge): 정렬된 두 부분집합 병합
	int	*pi = pFirst;				// 시작 위치: 왼쪽 부분집합
	int	*pj = pMid + 1;				// 시작 위치: 오른쪽 부분집합
	int	*pt = pTemp;
	while (pi <= pMid && pj <= pLast) {
		if (*pi <= *pj)	*pt++ = *pi++;
		else		*pt++ = *pj++;
	}
	while (pi <= pMid)	*pt++ = *pi++;
	while (pj <= pLast)	*pt++ = *pj++;

	// 정렬된 데이터로 원본 데이터 재구성
	pi = pFirst;	pt = pTemp;
	while (pi <= pLast)
		*pi++ = *pt++;
	free(pTemp);
	// PRINT(pFirst, (int)(pLast - pFirst) + 1);
}

// 계수 정렬: 오름차순
void	contingSort(int *pArr, int num) {
	// 원본 데이터에서 최대값
	int	maxNum = 0;
	for (int i = 0; i < num; ++i)
		if (maxNum < pArr[i])
			maxNum = pArr[i];

	// countArr : 원본 데이터에서 각 항목들의 발생 횟수를 저장한다.
	//		단, 원본 데이터의 값 자체가 countArr의 첨자가 된다.
	int*	countArr = (int*)calloc(maxNum + 1, sizeof(int));
	if (countArr == NULL) {
		printf("동적 메모리 공간 할당 실패!!!");
		exit(100);
	}
	for (int i = 0; i < num; ++i)		countArr[pArr[i]]++;
	for (int i = 1; i <= maxNum; ++i)	countArr[i] += countArr[i - 1];

	// sortArr : countArr의 값을 첨자로 하여 원본 데이터를 정렬된 데이터로 구성한다.
	int	*sortArr = (int *)calloc(num, sizeof(int));
	if (sortArr == NULL) {
		printf("동적 메모리 공간 할당 실패!!!");
		exit(100);
	}
	for (int i = num - 1; i >= 0; --i) {
		sortArr[countArr[pArr[i]] - 1] = pArr[i];
		countArr[pArr[i]]--;
		// PRINT(sort, num);
	}

	// 정렬된 데이터(sortArr)로 원본 데이터(pArr)를 재구성한다.
	for (int i = 0; i < num; ++i)
		pArr[i] = sortArr[i];

	free(countArr);
	free(sortArr);
}
