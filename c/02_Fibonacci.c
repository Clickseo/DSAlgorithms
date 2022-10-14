'''	
  피보나치 수열: 성능 평가
	  1) 재귀적 용법
	  2) 비재귀적 용법
'''

#include <stdio.h>
#include <time.h>     // clock, clock_t, CLOCKS_PER_SEC
// clock 함수: 프로그램에 의해 프로세서가 소비된 시간을 반환하는 함수
// CLOCKS_PER_SEC: 초당 clock ticks의 수를 나타낸 매크로 상수(시스템에 따라 기본값이 다름)

int  Fibo(int num);

int main(void)
{
	int	num;

	printf("### 피보나치 수열 ### \n\n");
	printf("몇 번째 수열까지 출력할까요: ");
	scanf_s("%d", &num);
	// scanf("%d", &num);

	clock_t	start, finish;
	double	seconds;

	start = clock();	// 시작 시간
	for(int i=1; i<=num; i++) {
		if (i%5)	printf("%8d", Fibo(i) );
		else		printf("%8d\n", Fibo(i) );
	}
	printf("\n");
	finish = clock();	// 종료 시간

	seconds = (double)(finish - start) / CLOCKS_PER_SEC;  	// CPU 시간
	printf("%d 번째 피보나치 수열 계산 시간: %lf 초 \n", num, seconds);

	return 0;
}

// 재귀적 용법: 피보나치 수열
int  Fibo(int  num) {
	// 재귀 함수: 탈출 조건
	if(num == 1 || num == 2)
		return 1;
	return Fibo(num - 1) + Fibo(num - 2);
}

/* 비재귀적 용법: 피보나치 수열
int  Fibo(int  num) {
	if(num == 0 || num == 1)
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
