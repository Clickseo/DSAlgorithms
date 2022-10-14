'''	
  피보나치 수열: 성능 평가
	  1) 재귀적 용법
	  2) 비재귀적 용법
'''

import time

# 비재귀적 용법: 피보나치 수열
'''
def Fibo(num:int) -> int:
    if num==1 or num==2 :
        return 1
    first, second = 1, 1
    for i in range(3, num+1) :
        first, second = second, first + second
    return second
'''

# 재귀적 용법: 피보나치 수열
def Fibo(num:int) -> int:
    if num==1 or num==2 :
        return 1
    return Fibo(num-1) + Fibo(num-2)

if __name__ == '__main__' :
    print('### 피보나치 수열 구하기 ###')
    num = int(input('몇 번째 수열까지 출력할까요: '))
    
    # 현재 시간을 시작 시간으로 지정
    startTime = time.time()	
    for i in range(1, num+1) :
        if i%5 : print(f'{Fibo(i):8}', end='')
        else : print(f'{Fibo(i):8}')
    else : print('')
    finishTime = time.time()

    print(f'수행시간: {finishTime - startTime}초')
