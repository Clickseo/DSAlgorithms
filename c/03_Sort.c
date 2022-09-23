#include <stdio.h>
#include <stdlib.h>	// srand, rand
#include <time.h>		// time

#define arrMAXSIZE 15

void	selectionSort(int* pArr, int num);	// 선택 정렬
// void	bubbleSort(int* pArr, int num);	// 버블 정렬
// void	insertionSort(int* pArr, int num);	// 삽입 정렬
// void	shellSort(int* pArr, int num);		// 쉘 정렬
// void	intervalSort(int* pArr, int num, int start, int interval);

void	SWAP(int*, int*);
void	PRINT(int*, int);

int main(void)
{
	int	arr[arrMAXSIZE] = { 0 };

	// 임의의 난수를 배열에 저장: 0 ~ 99 사이의 정수
	srand((unsigned int)time(NULL));
	for (int i = 0; i < arrMAXSIZE; i++)
		*(arr + i) = rand() % 100;

	printf("정렬 전: ");
	PRINT(arr, arrMAXSIZE);

	selectionSort(arr, arrMAXSIZE);
	// bubbleSort(arr, arrMAXSIZE);
	// insertionSort(arr, arrMAXSIZE);
	// shellSort(arr, arrMAXSIZE);

	printf("정렬 후: ");
	PRINT(arr, arrMAXSIZE);

	return 0;
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

void  SWAP(int* pa, int* pb) {
	int	temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
	return;
}

void  PRINT(int* pArr, int  num) {
	for (int i = 0; i < num; i++)
		printf("%3d", *(pArr + i));
	printf("\n");
	return;
}
