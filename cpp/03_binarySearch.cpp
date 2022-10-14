/*	
	이진 탐색: 알고리즘 구현
	
	1) 재귀적 용법
	2) 비재귀적 용법
*/

#include <iostream>
using namespace std;

#define arrMAXSIZE 10

#if 1
// 이진 탐색 -- 알고리즘 구현 / 재귀적 용법
int	binarySearch(int* pArr, int  first, int  last, int  key);
void	PRINT(int* pArr, int  num);

int main(void)
{
	int	arr[arrMAXSIZE] = { 5, 9, 13, 17, 21, 28, 37, 46, 55, 88 };
	cout << "원시 데이터: ";
	PRINT(arr, arrMAXSIZE);

	int	key;
	while (true) {
		cout << "검색 데이터 입력(검색 종료: 0) : ";
		cin >> key;
		if (key == 0)
			break;

		int index = binarySearch(arr, 0, arrMAXSIZE - 1, key);
		if (index == EOF) cout << "없다고!!!" << endl;
		else cout << "검색 데이터: " << arr[index] << "번째 위치 " << index + 1 << endl;
	}
	return 0;
}

// 이진탐색: 재귀적용법
int	binarySearch(int* pArr, int  first, int  last, int  key) {
	// 재귀함수의 탈출 조건
	if (first > last)
		return  EOF;

	// 중간 원소의 위치(첨자) 계산: first ~ last 범위에서...
	int	index, mid = (first + last) / 2;
	
	if (*(pArr + mid) == key)		return  mid;
	else if (*(pArr + mid) < key)	index = binarySearch(pArr, mid + 1, last, key);
	else if (*(pArr + mid) > key)	index = binarySearch(pArr, first, mid - 1, key);
	return index;
}

#elif 0
// 이진 탐색 -- 알고리즘 구현 / 비재귀적 용법
int*	binarySearch(int* pArr, int* pFirst, int* pLast, int key);
void	PRINT(int* pArr, int num);

int main(void)
{
	int	arr[arrMAXSIZE] = { 5, 9, 13, 17, 21, 28, 37, 46, 55, 88 };
	cout << "원시 데이터: ";
	PRINT(arr, arrMAXSIZE);

	int	key;
	while (true) {
		cout << "검색 데이터 입력(검색 종료: 0) : ";
		cin >> key;
		if (key == 0)
			break;

		int* pIndex = binarySearch(arr, arr, arr + arrMAXSIZE - 1, key);
		if (pIndex == NULL) cout << "없다고!!!" << endl;
		else cout << "검색 데이터: " << *pIndex << "번째 위치 " << pIndex - arr + 1 << endl;
	}
	return 0;
}

// 이진탐색: 비재귀적용법
int* binarySearch(int* pArr, int* pFirst, int* pLast, int key) {
	while (pFirst <= pLast) {
		// 중간 원소의 위치(주소) 계산: pFirst ~ pLast 범위에서...
		int* pMid = pFirst + (pLast - pFirst) / 2;

		if (*pMid == key)	return  pMid;
		else if (*pMid < key)	pFirst = pMid + 1;
		else if (*pMid > key)	pLast = pMid - 1;
	}
	return NULL;
}

#endif

void  PRINT(int* pArr, int  num) {
	for (int i = 0; i < num; i++) {
		cout.width(3);
		cout << *(pArr + i);
	}
	cout << endl;
}
