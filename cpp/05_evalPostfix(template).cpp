/*
	스택 활용: 후위 표기법을 이용한 수식 계산
		- evalPostfix		: 후위 표기법으로 수식 계산
		- InfixToPostfix	: 중위 표기법을 후위 표기법으로 변환
			중위 표기: (A + B) - C
			후위 표기: A B + C -
			전위 표기: - + A B C
*/

#include <iostream>
using namespace std;
inline void error(const char* message);

template <typename E>
class stackNode {
private:
	E			        data;
	stackNode<E>*	link;
	template <typename E> friend class LinkedStack;
};

template <typename E>
class LinkedStack {
private:
	stackNode<E>* top;
public:
	LinkedStack();
	~LinkedStack();
	stackNode<E>* makeStackNode(const int& num) const;
	void		push(const E& e);
	E		    pop(void);
	E		    peek(void) const;
	bool		isEmpty(void) const;
	void		printStack(void) const;
};

template <typename E>
LinkedStack<E>::LinkedStack() : top(NULL) {}

template <typename E>
LinkedStack<E>::~LinkedStack() {}

template <typename E>
stackNode<E>* LinkedStack<E>::makeStackNode(const int& num) const {
	stackNode<E>* nNode = new stackNode<int>;
	nNode->data = num;
	nNode->link = NULL;
	return nNode;
}

template <typename E>
void	LinkedStack<E>::push(const E& e) {
	stackNode<E>* newSNode = makeStackNode(e);
	newSNode->link = top;
	top = newSNode;
}

template <typename E>
E	LinkedStack<E>::pop(void) {
	if (isEmpty()) error("스택 공백 에러");	// throw "ERROR::STACK IS EMPTY";
	stackNode<int>* temp = top;
	E data = temp->data;
	top = temp->link;
	free(temp);
	return  data;
}

template <typename E>
E	LinkedStack<E>::peek(void) const {
	if (isEmpty()) error("스택 공백 에러");	// throw "ERROR::STACK IS EMPTY";
	return  top->data;
}

template <typename E>
bool	LinkedStack<E>::isEmpty(void) const {
	return top == NULL;
}

template <typename E>
void	LinkedStack<E>::printStack(void) const {
	stackNode<E>* temp = top;
	cout << "\n STACK [";
	while (temp) {
		cout.width(3);
		cout << temp->data;
		temp = temp->link;
	}
	cout << " ]" << endl;
}

inline void error(const char* message) {
	cout << message;
	exit(100);
}

#include <iostream>
using namespace std;

#define	 bufferMAXSIZE	 1024

int 	evalPostfix(char* str);
void	InfixToPostfix(char* postfix, char* infix);
int	  isOperator(int op);
int	  precedence(int op);

int main(void)
{
	int	res;
	char	infixStr[bufferMAXSIZE], postfixStr[bufferMAXSIZE];

	cout << "수식 입력: ";
	cin.getline(infixStr, bufferMAXSIZE);	// getline(cin, infixStr);

	InfixToPostfix(postfixStr, infixStr);
	cout << "\n후위표기법 변환: " << postfixStr << endl;

	res = evalPostfix(postfixStr);
	cout << "연산결과: " << res << endl;

	return 0;
}

int  evalPostfix(char* str) {
	int	op1, op2, res;
	char	temp[bufferMAXSIZE], *p;
	LinkedStack<int>	s;
	while (*str) {
		// 피연산자 일 경우...
		if (*str >= '0' && *str <= '9') {
			p = temp;	// 한 자리 이상을 처리 하기 위해...
			while (*str >= '0' && *str <= '9')
				*p++ = *str++;
			*p = '\0';
			s.push(atoi(temp));		// atoi(temp.c_str());
		}
		else if (isOperator(*str)) {	// 연산자 일 경우...
			op2 = s.pop();
			op1 = s.pop();
			switch (*str) {
        case '+': s.push(op1 + op2);	break;
        case '-': s.push(op1 - op2);	break;
        case '*': s.push(op1 * op2);	break;
        case '/': s.push(op1 / op2);	break;
			}
			str++;
		}
		else if (*str == ' ')	 str++;
		else {
			printf("잘못된 수식!!! \n");
			// s.~LinkedStack();
			return 0;
		}
	}

	// 스택에 남은 최종 결과 값
	if (!s.isEmpty())
		res = s.pop();

	// s.~LinkedStack();
	return res;
}

// 중위 표기법을 후위표기법으로 변환
void  InfixToPostfix(char* postfix, char* infix) {
	LinkedStack<int>	s;
	while (*infix) {
		// 1) '(' 는 스택에 push
		if (*infix == '(')
			s.push(*infix++);
		// 2) ')'를 만나면 '('가 나올 때까지 pop 한 후에 '('는 버린다.
		else if (*infix == ')') {
			while (s.peek() != '(') {
				*postfix++ = s.pop();
				*postfix++ = ' ';
			}
			s.pop();	// '(' 를 버린다.
			infix++;
		}
		// 3) 연산자인 경우...
		else if (isOperator(*infix)) {
			while (!s.isEmpty() &&
				precedence(s.peek()) >= precedence(*infix))
			{	// 자신보다 높은 우선순위의 연산자는 스택에서 pop
				*postfix++ = s.pop();
				*postfix++ = ' ';
			}
			s.push(*infix++);	// 자신을 push
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
			// s.~LinkedStack();
			return;
		}
	}
	// 스택에 남은 연산자를 모두 pop 한다.
	while (!s.isEmpty()) {
		*postfix++ = s.pop();
		*postfix++ = ' ';
	}
	postfix--;
	*postfix = '\0';

	// s.~LinkedStack();
	return;
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
