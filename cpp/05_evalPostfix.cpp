/*
	스택 활용: 후위 표기법 수식 계산
		- evalPostfix		: 후위 표기법으로 수식 계산
		- InfixToPostfix	: 중위 표기법을 후위 표기법으로 변환
			중위 표기: (A + B) - C
			후위 표기: A B + C -
			전위 표기: - + A B C
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int	evalPostfix(string& str);
string	InfixToPostfix(string& infix);
int	isOperator(int op);
int	precedence(int op);

int main(void)
{
	int	res;
	string	infixStr, postfixStr;

	cout << "수식 입력: ";
	getline(cin, infixStr);		// cin.getline(infixStr, bufferMAXSIZE);

	postfixStr = InfixToPostfix(infixStr);
	cout << "\n후위표기법 변환: " << postfixStr << endl;

	res = evalPostfix(postfixStr);
	cout << "연산 결과: " << res << endl;

	return 0;
}

int  evalPostfix(string& str) {	
	stack<char>	s;
	string		temp;
	int		op1, op2, res = 0;
	for (int i = 0; i < str.length(); i++) {
		// 피연산자 일 경우...
		if (str[i] >= '0' && str[i] <= '9') {
			// 한 자리 이상을 처리 하기 위해...
			temp.clear();
			for (; str[i] >= '0' && str[i] <= '9'; i++)
				temp += str[i];
			s.push(stoi(temp));
			i--;
		}
		else if (isOperator(str[i])) {	// 연산자 일 경우...
			op2 = s.top();	s.pop();
			op1 = s.top();	s.pop();
			switch (str[i]) {
				case '+': s.push(op1 + op2);	break;
				case '-': s.push(op1 - op2);	break;
				case '*': s.push(op1 * op2);	break;
				case '/': s.push(op1 / op2);	break;
			}
		}
		else if (str[i] == ' ')	 continue;
		else {
			cout << "잘못된 수식!!!" << endl;
			exit(100);
		}
	}
	// 스택에 남은 최종 결과 값
	if (!s.empty())
		res = s.top();
	return res;
}

// 중위 표기법을 후위표기법으로 변환
string  InfixToPostfix(string& infix) {
	stack<char>	s;
	string		postfix;
	for (int i = 0; i < infix.length(); i++) {
		// 1) '(' 는 스택에 push
		if (infix[i] == '(')
			s.push(infix[i]);
		// 2) ')'를 만나면 '('가 나올 때까지 pop 한 후에 '('는 버린다.
		else if (infix[i] == ')') {
			while (s.top() != '(') {
				postfix += s.top();	s.pop();
				postfix += ' ';
			}
			s.pop();		// '(' 를 버린다.
		}
		// 3) 연산자인 경우...
		else if (isOperator(infix[i])) {
			while (!s.empty() &&
				precedence(s.top()) >= precedence(infix[i]))
			{	// 자신보다 높은 우선순위의 연산자는 스택에서 pop
				postfix += s.top();	s.pop();
				postfix += ' ';
			}
			s.push(infix[i]);	// 자신을 push
		}
		// 4) 피연산자인 경우...
		else if (infix[i] >= '0' && infix[i] <= '9') {
			for (; infix[i] >= '0' && infix[i] <= '9'; i++)
				postfix += infix[i];
			postfix += ' ';
			i--;
		}
		else if (infix[i] == ' ')	continue;
		else {
			cout << "잘못된 수식!!!" << endl;
			exit(100);
		}
	}

	// 스택에 남은 연산자를 모두 pop 한다.
	while (!s.empty()) {
		postfix += s.top();	s.pop();
		postfix += ' ';
	}
	return postfix;
}

// 연산자 여부를 판별한다.
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
