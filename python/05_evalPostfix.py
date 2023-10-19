'''
	스택 활용: 후위 표기법을 이용한 수식 계산
		- evalPostfix		: 후위 표기법으로 수식 계산
		- InfixToPostfix	: 중위 표기법을 후위 표기법으로 변환
			중위 표기: (A + B) - C
			후위 표기: A B + C -
			전위 표기: - + A B C
'''

# 연산자 여부를 판별
def isOperator(op: str) -> bool :
    return op == '+' or op == '-' or op == '*' or op == '/'

# 연산자 우선순위를 수치로 변환
def precedence(op: str) -> int :
	if op == '(' : return 0
	elif op == '+' or op == '-' : return 1
	elif op == '*' or op == '/' : return 2
	else : return 3

# 중위 표기법을 후위표기법으로 변환
def InfixToPostfix(infix:str) -> str :
    S = []
    # split을 위해 연산자 앞 뒤에 공백을 넣어준다.
    infix = infix.replace('(', ' ( ')
    infix = infix.replace(')', ' ) ')
    infix = infix.replace('+', ' + ')
    infix = infix.replace('-', ' - ')
    infix = infix.replace('*', ' * ')
    infix = infix.replace('/', ' / ')
    infix = infix.split()

    postfix = []
    for st in infix :
        # 1) '(' 는 스택에 push
        if st == '(' :
            S.append(st)
        # 2) ')'를 만나면 '('가 나올 때까지 pop 한 후에 '('는 버린다.
        elif st == ')' :
            while S[-1] != '(' :
                postfix.append(S[-1])
                S.pop()
            S.pop()     # '(' 를 버린다.
        # 3) 연산자인 경우...
        elif isOperator(st):
            while len(S) and precedence(S[-1]) >= precedence(st):
                # 자신보다 높은 우선순위의 연산자는 스택에서 pop
                postfix.append(S[-1])
                S.pop()
            S.append(st) # 자신을 push
        # 4) 피연산자인 경우...
        elif str.isdigit(st):
            postfix.append(st)
        elif st == ' ' : continue
        else :
            print('잘못된 수식!!!')
            return    
    # 스택에 남은 연산자를 모두 pop 한다.
    while len(S) :
        postfix.append(S[-1])
        S.pop()
    return postfix

def  evalPostfix(postfix: str) -> int :
    S = []
    for st in postfix :
        # 1) 피연산자 일 경우...
        if str.isdigit(st):
            S.append(st)
        # 2) 연산자 일 경우...
        elif isOperator(st) :
            op2 = int(S[-1]);   S.pop()
            op1 = int(S[-1]);   S.pop()
            if st == '+': S.append(op1 + op2)
            elif st == '-': S.append(op1 - op2)
            elif st == '*': S.append(op1 * op2)
            elif st == '/': S.append(op1 / op2)
            elif st == ' ' : continue
            else:
                print('잘못된 수식!!!')
                return            
    # 스택에 남은 최종 결과 값
    if len(S):
        res = S[-1]
        S.pop()
    return res

if __name__ == '__main__':
	infix = input('수식 입력: ')
	postfix = InfixToPostfix(infix)
	print(f'후위표기법 변환: {postfix}')

	res = evalPostfix(postfix)
	print(f'연산결과: {res}')
