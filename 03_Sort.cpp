#include <iostream>
#include <random>		// C++ 11���� �߰�
using namespace std;		// C++11 ���� ���: C ��Ÿ�� ���� ����(srand�� rand �Լ�)

#define arrMAXSIZE 15

void	selectionSort(int* pArr, int num);	// ���� ����
# void	bubbleSort(int* pArr, int num);	// ���� ����
# void	insertionSort(int* pArr, int num);	// ���� ����
# void	shellSort(int* pArr, int num);		// �� ����
# void	intervalSort(int* pArr, int num, int start, int interval);

void	SWAP(int* pa, int* pb);
void	PRINT(int* pArr, int num);

int main(void)
{
	int	arr[arrMAXSIZE] = { 0 };

	/* C ��Ÿ�� ���� ����(srand�� rand �Լ�)
		srand(static_cast<unsigned int>(time(nullptr)));
		static_cast<int>(rand() % (99 + 1UL - 0)) + 0;
	*/

	// C++ ��Ÿ�� ���� ����
	random_device rd;			// 1) �õ� ����: random_device(������� ���� ������) ����
	mt19937	gen(rd());			// 2) ���� ���� ����(mt19937) �ʱ�ȭ
	uniform_int_distribution<int>	dis(0, 99);		// �յ� ���� ����: ���� ����
	for (int i = 0; i < arrMAXSIZE; i++)
		*(arr + i) = dis(gen);

	cout << "���� ��: ";
	PRINT(arr, arrMAXSIZE);

	selectionSort(arr, arrMAXSIZE);
	// bubbleSort(arr, arrMAXSIZE);
	// insertionSort(arr, arrMAXSIZE);
	// shellSort(arr, arrMAXSIZE);

	cout << "���� ��: ";
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

// ���� ����: ��������
void   selectionSort(int* pArr, int  num) {
	int* pSm;
	for (int i = 0; i < num; i++) {
		pSm = pArr + i;
		for (int j = i; j < num; j++)
			if (*pSm > *(pArr + j))
				pSm = pArr + j;
		// ���� ���� ���� ����: ���� ���� ��ȯ
		SWAP(pSm, pArr + i);
		PRINT(pArr, num);
	}
	return;
}
