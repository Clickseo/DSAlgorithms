/*
	스택 활용: 후위 표기법을 이용한 수식 계산
		- evalPostfix		: 후위 표기법으로 수식 계산
		- InfixToPostfix	: 중위 표기법을 후위 표기법으로 변환
			중위 표기: (A + B) - C
			후위 표기: A B + C -
			전위 표기: - + A B C
*/

#include <stdio.h>
#include <stdlib.h>		// atoi
#include "LinkedStack.h"	// LinkedStack, SNode
// #include "LinkedNode.h"	// SNode
#include "Operators.h"		// isOperator,precedence

#define	bufferMAXSIZE	1024

// 후위 표기법: 수식 계산과 변환(중위표기-> 후위 표기)
element	evalPostfix(char* exp);
void	InfixToPostfix(char* postfix, char* infix);


int main(void)
{
	int	res;
	char	infixStr[bufferMAXSIZE], postfixStr[bufferMAXSIZE];

	printf("수식 입력: ");
	gets_s(infixStr, sizeof(infixStr));

	InfixToPostfix(postfixStr, infixStr);
	printf("\n후위표기법 변환: %s \n", postfixStr);

	res = evalPostfix(postfixStr);
	printf("연산결과: %d \n", res);

	return 0;
}

// 후위 표기법: 수식 계산
element  evalPostfix(char* exp) {
	int	op1, op2, res;
	char	temp[bufferMAXSIZE], *p;
	LinkedStack* S = stackCreate();		// 빈 스택 생성
	while (*exp) {
		// 1) 피연산자 일 경우...
		if (*exp >= '0' && *exp <= '9') {
			p = temp;	// 한 자리 이상을 처리 하기 위해...
			while (*exp >= '0' && *exp <= '9')
				*p++ = *exp++;
			*p = '\0';
			push(S, atoi(temp));
		}
		// 2) 연산자일 경우...
		else if (isOperator(*exp)) {
			op2 = top(S);	pop(S);
			op1 = top(S);	pop(S);
			switch (*exp) {
			case '+': push(S, op1 + op2);	break;
			case '-': push(S, op1 - op2);	break;
			case '*': push(S, op1 * op2);	break;
			case '/': push(S, op1 / op2);	break;
			}
			exp++;
		}
		else if (*exp == ' ')	exp++;
		else {
			printf("잘못된 수식!!! \n");
			stackDestroy(S);
			return 0;
		}
	}

	// 스택에 남은 최종 결과 값
	if (!stackEempty(S))
		res = top(S);	pop(S);

	stackDestroy(S);
	return res;
}

// 후위표기법 변환(중위 표기 -> 후위 표기)
void  InfixToPostfix(char* postfix, char* infix) {
	LinkedStack* S = stackCreate();
	while (*infix) {
		// 1) '(' 는 스택에 push
		if (*infix == '(')
			push(S, *infix++);
		// 2) ')'를 만나면 '('가 나올 때까지 pop 한후에 '('는 버린다.
		else if (*infix == ')') {
			while (top(S) != '(') {
				*postfix++ = top(S);	pop(S);
				*postfix++ = ' ';
			}
			pop(S);		// '(' 를 버린다.
			infix++;
		}
		// 3) 연산자이면...
		else if (isOperator(*infix)) {
			while (!stackEempty(S) &&
				precedence(top(S)) >= precedence(*infix))
			{	// 자신보다 높은 우선순위의 연산자는 스택에서 pop
				*postfix++ = top(S);	pop(S);
				*postfix++ = ' ';
			}
			push(S, *infix++);	// 자신을 push
		}
		// 4) 피연산자인 경우...
		else if (*infix >= '0' && *infix <= '9') {
			while (*infix >= '0' && *infix <= '9')
				*postfix++ = *infix++;
			*postfix++ = ' ';
		}
		else if (*infix == ' ')	infix++;
		else {
			printf("잘못된 수식!!! \n");
			stackDestroy(S);
			return;
		}
	}

	// 스택에 남은 연산자를 모두 pop 한다.
	while (!stackEempty(S)) {
		*postfix++ = top(S);	pop(S);
		*postfix++ = ' ';
	}
	postfix--;
	*postfix = '\0';

	stackDestroy(S);
	return;
}

/* 
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
*/
