/*	
	이진 탐색: 알고리즘 구현
	
	1) 재귀적 용법
	2) 비재귀적 용법
*/

//이진 탐색 -- 알고리즘 구현(재귀적 용법)
#include <iostream>
using namespace std;

#define arrMAXSIZE 10

// 이진 탐색 -- 알고리즘 구현(재귀적 용법)
int	binarySearch(int* pArr, int  first, int  last, int  key);
void	PRINT(int* pArr, int num);

int main(void)
{
	int	arr[arrMAXSIZE] = { 5, 9, 13, 17, 21, 28, 37, 46, 55, 88 };
	cout << "원시 데이터: ";
	PRINT(arr, arrMAXSIZE);

	int	key;
	while(true) {
		cout << "검색 데이터 입력(검색 종료: 0): ";
		cin >> key;
		if(key == 0)
			break;

		int	index = binarySearch(arr, 0, arrMAXSIZE - 1, key);
		if (index == EOF)	cout << "없다고!!!" << endl;
		else	cout << "검색 데이터: " << arr[index] << ", 위치(index): " << index + 1 << endl;
	}
	return 0;
}

// 이진 탐색 -- 알고리즘 구현(재귀적 용법)
int	binarySearch(int  *pArr,  int  first,  int  last,  int  key) {
	// 재귀함수의 탈출 조건
	if ( first >  last )
		return  EOF;

	 // 검색 범위의 중간 원소의 위치 값 계산 
	int	index, mid = (first + last) / 2;

	if (*(pArr+mid) == key)		return  mid;
	else if (*(pArr+mid)  <  key)	index = binarySearch(pArr, mid + 1, last, key);
	else if (*(pArr+mid)  >  key)	index = binarySearch(pArr, first, mid - 1, key);
	return index;
}

void	PRINT(int* pArr, int num) {
	for (int i=0; i<num; i++)
		printf("%3d", *(pArr+i) );
	printf("\n");
	return;
}
