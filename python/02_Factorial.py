'''
	계승(Factorial) 구하기
		1) 재귀적 용법
		2) 비재귀적 용법
'''

'''
# Factorial: 반복적 용법
def Factorial(num) :
    res = 1
    for i in range(1, num+1) :
        res = res * i
    return  res
'''

# Factorial: 재귀적 용법
def Factorial(num) :
    if num==0 :		# 재귀 함수 탈출(종료) 조건
        return 1
    return num * Factorial(num-1) 

if __name__ == "__main__" :
    num = int(input('임의의 정수: '))
    print(f'Factorial {num}: {Factorial(num)}')
