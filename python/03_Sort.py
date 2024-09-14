'''
	* 정렬: 알고리즘 구현
		파일명: Sort.py
			- 기초적인 정렬 알고리즘: 선택.버블.삽입 정렬
			- 고급 정렬 알고리즘	: 쉘.퀵.병합 정렬
			- 특수 정렬 알고리즘	: 계수 정렬
'''

import random

# 선택 정렬: 오름차순
def selectionSort(sList: list) -> None:
    for i in range(len(sList)) :
        smIndex = i
        for j in range(i, len(sList)) :
            if sList[smIndex] > sList[j] :
                smIndex = j
        sList[smIndex], sList[i] = sList[i], sList[smIndex]
        # print(sList)

# 버블 정렬: 오름차순
def bubbleSort(sList: list) -> None:
    for i in range(len(sList)):
        for j in range(len(sList)-1, 0, -1):
            if sList[j] < sList[j-1]:
                sList[j], sList[j-1] = sList[j-1], sList[j]
        # print(sList)

'''
# 수정(향상)된 버블 정렬 알고리즘: 오름차순
def bubbleSort(sList: list) -> None:
    num = len(sList)
    for i in range(num) :
        state = True
        for j in range(num-1, 0, -1) :
            if sList[j] < sList[j-1] :
                sList[j], sList[j-1] = sList[j-1], sList[j]
                state = False
        if state : break
        # print(sList)
'''

# 삽입 정렬: 오름차순
def insertionSort(sList: list) -> None:
    for i in range(1, len(sList)):
        temp = sList[i] 
        j = i-1
        while j>=0 and temp<sList[j]:
            sList[j+1] = sList[j]
            j-=1
        sList[j+1] = temp
        # print(sList)

# 쉘 정렬: 오름차순
def  shellSort(sList: list) -> None:
    interval = len(sList)
    while interval >= 1:
        interval //= 2
        for i in range(interval):
            intervalSort(sList, i, interval)
            # print(sList)
        # print(f'interval: {interval} {sList} \n')            

# 쉘 정렬에 쓰이는 삽입 정렬: interval 간격만큼 삽입 정렬
def  intervalSort(sList: list, start:int , interval:int ) -> None:
    for i in range(start, len(sList), interval):
        temp, j = sList[i], i-interval
        while j>=0 and temp<sList[j]:
            sList[j+interval] = sList[j]
            j-=interval
        sList[j+interval] = temp

# 퀵 정렬: 오름차순
def  quickSort(sList: list, first:int, last:int) -> None:
    # 재귀 함수 탈출 조건
    if(first >= last):
        return
    
    # 분할: 기준 값의 왼쪽(작은 값)과 오른쪽(큰 값) 부분 집합
    pivot, i = sList[last], first           		# pivoit: 기준 값(S[last])
    for j in range(first, last):
        if(sList[j] <= pivot):              		# 기준 값(pivot): 마지막 원소
            sList[i], sList[j] = sList[j], sList[i]
            i += 1
    sList[i], sList[last] = sList[last], sList[i]       # 기준 값을 가운데로
    # print(sList)
    quickSort(sList, first, i - 1)	        	# 왼쪽 부분 정렬
    quickSort(sList, i + 1, last)    	    		# 오른쪽 부분 정렬

# 병합 정렬: 오름차순
def  mergeSort(sList: list, first:int, last:int) -> None:
    # 재귀 함수 탈출 조건
    if (first >= last):
        return

    # 중간 원소의 위치(주소) 계산: pFirst와 pLast 범위에서...
    mid = (first + last) // 2
    mergeSort(sList, first, mid)        		# 왼쪽 부분집합 정렬
    mergeSort(sList, mid + 1, last)     		# 오른쪽 부분집합 정렬

    # 병합(merge): 정렬된 두 부분집합 병합
    i, j, t = first, mid + 1, 0         		# 시작 위치: 왼쪽 부분집합, 오른쪽 부분집합
    temp = [0 for _ in range(last - first + 1)]
    while i <= mid and j <= last:
        if sList[i] <= sList[j]:
            temp[t] = sList[i]
            t+=1; i+=1
        else:
            temp[t] = sList[j]
            t+=1; j+=1
    while i <= mid:
        temp[t] = sList[i]
        t+=1; i+=1
    while j <= last:
        temp[t] = sList[j]
        t+=1; j+=1

    # 정렬된 데이터로 원본 데이터 재구성
    i, t = first, 0
    while i <= last:
        sList[i] = temp[t]
        t+=1; i+=1
    print(sList)

# 계수 정렬: 오름차순
def countingSort(sList: list) -> None:
    k = max(sList)
    C = [ 0 for _ in range(k+1) ]
    for i in range(len(sList)):	C[sList[i]] += 1
    for j in range(1, k+1):	C[j] = C[j] + C[j-1]
    
    S = [ 0 for _ in range(len(sList)) ]
    for i in range(len(sList)-1, -1, -1):
        S[C[sList[i]]-1] = sList[i]
        C[sList[i]] -= 1
    
    # 정렬된 데이터로 원본 데이터 재구성
    i, t = 0, 0
    while i < len(S):
        sList[i] = S[t]
        t+=1; i+=1

if __name__ == '__main__':
    sList = []
    while len(sList)<10:
        num = random.randint(0, 99)
        sList.append(num)
    
    print(f'정렬 전: {sList}')    
    selectionSort(sList)
    # bubbleSort(sList)
    # insertionSort(sList)
    # shellSort(sList)
    # quickSort(sList, 0, len(sList)-1)
    # mergeSort(sList, 0, len(sList)-1)
    # countingSort(sList)
    print(f'정렬 후: {sList}')
