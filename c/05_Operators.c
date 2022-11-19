#include "Operators.h"

// 연산자 여부를 판단
int  isOperator(int  op) {
	return op == '+' || op == '-' || op == '*' || op == '/';
}

// 연산자 우선순위를 수치로 변환
int  precedence(int op) {
	if (op == '(') return 0;
	else if (op == '+' || op == '-') return 1;
	else if (op == '*' || op == '/') return 2;
	else return 3;
}

// 수식 구성 평가
int  isLegal(char* pStr) {
	int	count = 0;
	for (; *pStr; pStr++) {
		while (*pStr == ' ')	pStr++;		// 공백 제거
		if (isOperator(*pStr))	count--;	// 연산자이면 감소
		else count++;						// 피연산자이면 증가

		// "피연산자 수 - 연산자 수 = 1"이 되어야 한다.
		if (count < 1)
			break;
	}
	return count == 1;
}
