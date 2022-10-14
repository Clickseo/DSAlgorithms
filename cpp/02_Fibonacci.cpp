/*	
	피보나치(Fibonacci) 수열: 성능 평가
		1) 재귀적 용법
		2) 비재귀적 용법
*/

#include <iostream>
#include <ctime>		// clock, clock_t, CLOCKS_PER_SEC
// clock 함수: 프로그램에 의해 프로세서가 소비된 시간을 반환하는 함수
// CLOCKS_PER_SEC: 초당 clock ticks의 수를 나타낸 매크로 상수(시스템에 따라 기본값이 다름)
using namespace std;

int  Fibo(int  num);

int main(void)
{
	int	num;

	cout << "### 피보나치 수열 구하기 ### \n" << endl;
	cout << "몇 번째 수열까지 출력할까요: ";
	cin >> num;

	clock_t		start, finish;
	double		seconds;

	start = clock();		// 시작 시간
	for(int i=1; i<=num; i++ ) {
		cout.width(8);
		if(i%5)	cout << Fibo(i);
		else	cout << Fibo(i) << endl;
	}
	finish = clock();		// 종료 시간

	seconds = (double)(finish - start) / CLOCKS_PER_SEC;  	// CPU 시간
	cout << num << "번째 피보나치 수열 계산 시간: " << seconds << endl;

	return 0;
}

// 재귀적 용법: 피보나치(Fibonacci) 수열
int  Fibo(int  num) {
	// 재귀 함수: 탈출 조건
	if(num == 1 || num == 2)
		return 1;
	return Fibo(num - 1) + Fibo(num - 2);
}

/* 비재귀적 용법: 피보나치(Fibonacci) 수열
int  Fibo(int  num) {
	if(num == 1 || num == 2)
		return 1;

	int	first, second, res = 0;
	first  =  second  =  1;    
	for(int i=3; i<=num; i++) {
		res  =  first  +  second;
		first = second;
		second  =  res;
	}
	return res;
}
*/
