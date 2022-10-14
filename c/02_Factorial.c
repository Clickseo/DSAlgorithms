/*
	계승(Factorial) 구하기
		1) 재귀적 용법
		2) 비재귀적 용법
*/

#include <stdio.h>
int  Factorial(int num);
int main(void)
{
	int	num;

	printf("임의의 정수: ");
	scanf_s("%d", &num);
	// scanf("%d", &num);
	
	printf("%d Factorial: %d \n", num, Factorial(num) );
	return 0;
}

# 재귀적 용법: 계승(Factorial) 구하기
int  Factorial(int num)	{
	if(num == 0)
		return 1;
	return num * Factorial (num - 1);
}

/*
# 반복적 용법: 계승(Factorial) 구하기
int  Factorial(int num)	{
	int	res = 1;
	for (int i = 1; i <= num; i++)
		res  =  res  *  i;
	return  res;
}
*/
