'''
    * 정렬: 알고리즘 구현
    
    1) 기초적인 정렬 알고리즘: 선택.버블.삽입.쉘 정렬
    2) 고급 정렬 알고리즘: 퀵.병합 정렬
    3) 특수 정렬 알고리즘: 계수.기수.버킷 정렬
'''

import random

# 선택 정렬: 오름차순
def selectionSort(S) -> None:
    for i in range(len(S)) :
        smIndex = i;
        for j in range(i, len(S)) :
            if S[smIndex] > S[j] :
                smIndex = j
        S[smIndex], S[i] = S[i], S[smIndex]
        # print(S)

# 버블 정렬: 오름차순
def bubbleSort(S) -> None:
    for i in range(len(S)) :
        for j in range(len(S)-1, 0, -1) :
            if S[j] < S[j-1] :
                S[j], S[j-1] = S[j-1], S[j]
        # print(S)

'''
# 버블 정렬: 오름차순 -- 알고리즘 개선 #01
def bubbleSort(S) :
    num = len(S)
    for i in range(num) :
        state = True
        for j in range(num-1, 0, -1) :
            if S[j] < S[j-1] :
                S[j], S[j-1] = S[j-1], S[j]
                state = False
        if state : break
        # print(S)
'''

# 삽입 정렬: 오름차순
def insertionSort(S) -> None:
    for i in range(1, len(S)) :
        temp, j = S[i], i-1
        while j>=0 and temp<S[j] :
            S[j+1] = S[j]
            j-=1
        S[j+1] = temp
        # print(S)

# 쉘 정렬: 오름차순
def  shellSort(S) -> None:
    interval = len(S)
    while interval >= 1 :
        interval //= 2
        for i in range(interval) :
            intervalSort(S, i, interval)
            # print(S)
        # print(f'interval: {interval} {S} \n')

# 쉘 정렬에 쓰이는 삽입 정렬: interval 간격만큼 삽입 정렬
def  intervalSort(S, start:int, interval: int) -> None:
    for i in range(start, len(S), interval):
        temp, j = S[i], i-interval
        while j>=0 and temp<S[j] :
            S[j+interval] = S[j]
            j-=interval
        S[j+interval] = temp

# 퀵 정렬: 오름차순
def  quickSort(S, first:int, last:int) -> None:
    # 재귀 함수 탈출 조건
    if(first >= last) :
        return
    
    # 분할: 기준 값의 왼쪽(작은 값)과 오른쪽(큰 값) 부분 집합
    pivot, i = S[last], first          # pivoit: 기준 값(S[last])
    for j in range(first, last):
        if(S[j] <= pivot):             # 기준 값(pivot): 마지막 원소
            S[i], S[j] = S[j], S[i]
            i += 1
    S[i], S[last] = S[last], S[i]	# 기준 값을 가운데로
    quickSort(S, first, i - 1)      # 왼쪽 부분 정렬
    quickSort(S, i + 1, last)	      # 오른쪽 부분 정렬
    
# 병합 정렬: 오름차순
def  mergeSort(S, first:int, last:int) -> None:
    # 재귀 함수 탈출 조건
    if (first >= last):
        return

    # 중간 원소의 위치(주소) 계산: pFirst와 pLast 범위에서...
    mid = (first + last) // 2
    mergeSort(S, first, mid)	      # 왼쪽 부분집합 정렬
    mergeSort(S, mid + 1, last)	   # 오른쪽 부분집합 정렬

    # 병합(merge): 정렬된 두 부분집합 병합
    i, j, t = first, mid + 1, 0    # 시작 위치: 왼쪽 부분집합, 오른쪽 부분집합
    temp = [0 for i in range(len(S))]
    while i <= mid and j <= last :
        if S[i] <= S[j] :
            temp[t] = S[i]
            t+=1; i+=1
        else :
            temp[t] = S[j]
            t+=1; j+=1
    while i <= mid :
        temp[t] = S[i]
        t+=1; i+=1
    while j <= last :
        temp[t] = S[j]
        t+=1; j+=1

    # 정렬된 데이터(temp)로 원본 데이터(S) 재구성
    i, t = first, 0
    while i <= last :
        S[i] = temp[t]
        t+=1; i+=1

# 3) 특수 정렬 알고리즘: 계수.기수.버킷 정렬
# 계수 정렬: 오름차순
def countingSort(S) -> None:
    k = max(S)    
    # C(countList) : 원본 데이터(S)에서 각 항목들의 발생 횟수를 저장한다.
    #                  단, 원본 데이터(S)의 값 자체가 C(countList) 의 index가 된다.
    C = [ 0 for _ in range(k+1) ]
    for i in range(len(S)):	C[S[i]] += 1
    for j in range(1, k+1):	C[j] = C[j] + C[j-1]
    
    # B : C(countList)의 값을 index로 하여 원본 데이터(S)를 정렬된 데이터(B)로 구성한다.
    B = [ 0 for _ in range(len(S)) ]
    for i in range(len(S)-1, -1, -1):
        B[ C[S[i]]-1 ] = S[i]
        C[S[i]] -= 1
    
    # 정렬된 데이터(B)로 원본 데이터(S)를 재구성한다.
    i, t = 0, 0
    while i < len(B) :
        sList[i] = B[t]
        t+=1; i+=1

if __name__ == '__main__' :
    sList = []
    while len(sList)<=15 :
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
