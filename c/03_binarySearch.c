/*	
	이진 탐색: 알고리즘 구현
	
	1) 재귀적 용법
	2) 비재귀적 용법
*/

#include <stdio.h>
#include <stdbool.h>	// bool, true, false

#define arrMAXSIZE 10

#if 1

// 이진 탐색: 재귀적 용법
int	binarySearch(int* pArr, int first, int last, int key);
void	PRINT(int* pArr, int num);

int main(void)
{
	int	arr[arrMAXSIZE] = { 5, 9, 13, 17, 21, 28, 37, 46, 55, 88 };
	printf("원시 데이터: ");
	PRINT(arr, arrMAXSIZE);

	int	key;
	while (true) {
		printf("검색 데이터 입력(검색 종료: 0): ");
		scanf_s("%d", &key);	// scanf("%d", &key);
		if (key == 0)	break;

		int	index = binarySearch(arr, 0, arrMAXSIZE - 1, key);
		if (index == EOF)	printf("없다고!!! \n");
		else	printf("검색 데이터: %d 번째 위치 %d \n", arr[index], index + 1);
	}
	return 0;
}

// 이진탐색: 재귀적용법
int	binarySearch(int* pArr, int  first, int  last, int  key) {
	// 재귀함수의 탈출 조건
	if (first > last)
		return  EOF;

	// 중간 원소의 위치(첨자) 계산: 검색 범위(first ~ last)에서...
	int	index, mid = (first + last) / 2;

	if (*(pArr + mid) == key)		return  mid;
	else if (*(pArr + mid) < key)	index = binarySearch(pArr, mid + 1, last, key);
	else if (*(pArr + mid) > key)	index = binarySearch(pArr, first, mid - 1, key);
	return index;
}

#elif 0

// 이진 탐색: 비재귀적 용법
int*	binarySearch(int* pArr, int* pFirst, int* pLast, int key);
void	PRINT(int* pArr, int num);

int main(void)
{
	int	key, * pIndex;
	int	arr[arrMAXSIZE] = { 5, 9, 13, 17, 21, 28, 37, 46, 55, 88 };

	printf("원시 데이터 : ");
	PRINT(arr, arrMAXSIZE);

	while (true) {
		printf("검색 데이터 입력(검색 종료: 0) : ");
		scanf_s("%d", &key);	// scanf("%d", &key);
		if (key == 0)	break;

		pIndex = binarySearch(arr, arr, arr + arrMAXSIZE - 1, key);
		if (pIndex == NULL)	printf("없다고!!! \n");
		else printf("검색 데이터: %d 번째 위치 %lld \n", *pIndex, pIndex - arr + 1);
	}
	return 0;
}

// 이진탐색: 비재귀적용법
int* binarySearch(int* pArr, int* pFirst, int* pLast, int key) {
	while (pFirst <= pLast) {
		// 중간 원소의 위치(주소) 계산: 검색 범위(first ~ last)에서...
		int* pMid = pFirst + (pLast - pFirst) / 2;

		if (*pMid == key)		return  pMid;
		else if (*pMid < key)	pFirst = pMid + 1;
		else if (*pMid > key)	pLast = pMid - 1;
	}
	return NULL;
}

#endif

void	PRINT(int* pArr, int num) {
	for (int i = 0; i < num; i++)
		printf("%3d", *(pArr + i));
	printf("\n");
}
