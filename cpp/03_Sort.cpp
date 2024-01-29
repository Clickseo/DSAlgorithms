#include <iostream>
#include <random>			// C++ 11에서 추가
using namespace std;		// C++11 이전: C 스타일 난수 생성(srand와 rand 함수)

#define arrMAXSIZE 15

void	selectionSort(int* pArr, int num);		// 선택 정렬
void	bubbleSort(int* pArr, int num);			// 버블 정렬
void	insertionSort(int* pArr, int num);		// 삽입 정렬
void	shellSort(int* pArr, int num);			// 쉘 정렬
void	intervalSort(int* pArr, int num, int start, int interval);
void	quickSort(int* pArr, int* pFirst, int* pLast);
void	mergeSort(int* pArr, int* pFirst, int* pLast);
void	contingSort(int* pArr, int num);

void	SWAP(int* pArr, int* num);
void	PRINT(int* pArr, int num);

int main(void)
{
	int	arr[arrMAXSIZE] = { 0 };
	/* C 스타일 난수 생성(srand와 rand 함수)
		srand(static_cast<unsigned int>(time(nullptr)));
		static_cast<int>(rand() % (99 + 1UL - 0)) + 0;
	*/
	// C++ 스타일 난수 생성
	random_device rd;	// 시드 설정: random_device 생성
	mt19937 gen(rd());	// 난수 생성 엔진(mt19937) 초기화
	uniform_int_distribution<int> dis(0, 99);	// 균등 분포 정의: 범위 지정
	for (int i = 0; i < arrMAXSIZE; i++)
		*(arr + i) = dis(gen);
	cout << "정렬 전: ";	PRINT(arr, arrMAXSIZE);
	// selectionSort(arr, arrMAXSIZE);
	// bubbleSort(arr, arrMAXSIZE);
	// insertionSort(arr, arrMAXSIZE);
	// shellSort(arr, arrMAXSIZE);
	// quickSort(arr, arr, arr + arrMAXSIZE - 1);
	// mergeSort(arr, arr, arr + arrMAXSIZE - 1);
	contingSort(arr, arrMAXSIZE);

	cout << "정렬 후: ";	PRINT(arr, arrMAXSIZE);
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
	}
	return;
}

// 버블 정렬: 오름차순
void  bubbleSort(int* pArr, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = num - 1; j > 0; j--)
			if (*(pArr + j) < *(pArr + j - 1))
				SWAP(pArr + j, pArr + j - 1);
		// PRINT(pArr, num);
	}
	return;
}

/* 
// 변형된 버블 정렬 알고리즘: 오름차순
void  bubbleSort(int* pArr, int num) {
	bool	state;	// 상태 변수
	for (int i = 0; i < num; i++) {
		state = true;
		for (int j = num - 1; j > 0; j--) {
			if (*(pArr + j) < *(pArr + j - 1)) {
				SWAP(pArr + j, pArr + j - 1);
				state = false;
			}
		}
		if (state == true)
			break;
		// PRINT(pArr, num);
	}
	return;
}

// 변형된 버블 정렬 알고리즘: 내림차순
void  bubbleSort(int* pArr, int num) {
	bool	state;	// 상태 변수
	for (int i = 0; i < num; i++) {
		state = true;
		for (int j = 0; j < num - i; j++) {
			if (*(pArr + j) < *(pArr + j + 1)) {
				SWAP(pArr + j, pArr + j + 1);
				state = false;
			}
		}
		if (state == true)
			break;
		// PRINT(pArr, num);
	}
	return;
}
*/

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
	return;
}

// 쉘 정렬: 오름차순
void  shellSort(int* pArr, int num) {
	int	interval = num;
	while (interval >= 1) {
		interval /= 2;
		for (int i = 0; i < interval; i++)
			intervalSort(pArr, num, i, interval);
	}
	return;
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
	return;
}

// 퀵 정렬: 오름차순
void  quickSort(int* pArr, int* pFirst, int* pLast) {
	// 재귀 함수 탈출 조건
	if (pFirst >= pLast)
		return;

	// 분할: 기준 값의 왼쪽(작은 값)과 오른쪽(큰 값) 부분 집합
	int* mid, * pi, * pj;
	pi = pFirst - 1;
	for (pj = pFirst; pj < pLast; pj++)
		if (*pj <= *pLast)		// 기준 값(pivot): 마지막 원소
			SWAP(++pi, pj);
	SWAP(pi + 1, pLast);		// 기준 값을 가운데로
	mid = pi + 1;				// 기준 값의 위치(주소)
	// PRINT(pFirst, (int)(pLast - pFirst)+1);

	quickSort(pArr, pFirst, mid - 1);	// 왼쪽 부분 정렬 
	quickSort(pArr, mid + 1, pLast);	// 오른쪽 부분 정렬

	return;
}

// 병합 정렬: 오름차순
void  mergeSort(int* pArr, int* pFirst, int* pLast) {
	// 재귀 함수 탈출 조건
	if (pFirst >= pLast)
		return;

	// 중간 원소의 위치(주소) 계산: pFirst와 pLast 범위에서...
	int* pMid = pFirst + (int)(pLast - pFirst) / 2;
	mergeSort(pArr, pFirst, pMid);		// 왼쪽 부분집합 정렬
	mergeSort(pArr, pMid + 1, pLast);	// 오른쪽 부분집합 정렬

	// 각각의 부분집합을 병합(merge)할 메모리 공간 확보
	int   num = (int)(pLast - pFirst) + 1;
	int* pTemp = new int[num];
	if (pTemp == nullptr) {
		cout << "동적 메모리 공간 할당 실패!!!" << endl;
		return;
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
	delete[]	pTemp;

	// PRINT(pFirst, (int)(pLast - pFirst) + 1);
	return;
}

// 계수 정렬: 오름차순
void	contingSort(int* pArr, int num) {
	int* count, * sort;
	int	maxNum = 0;
	for (int i = 0; i < num; i++)
		if (maxNum < pArr[i])
			maxNum = pArr[i];

	count = new int[maxNum + 1] {0};
	for (int i = 0; i < num; i++)		count[pArr[i]]++;
	for (int i = 1; i <= maxNum; i++)	count[i] += count[i - 1];

	sort = new int[num] {0};
	for (int i = num - 1; i >= 0; i--) {
		sort[count[pArr[i]] - 1] = pArr[i];
		count[pArr[i]]--;
		// PRINT(sort, num);
	}

	// 정렬된 데이터로 원본 데이터 재구성
	for (int i = 0; i < num; i++)
		pArr[i] = sort[i];

	delete[] count;
	delete[] sort;
}
