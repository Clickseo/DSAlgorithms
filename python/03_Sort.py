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

# 버블 정렬: 오름차순
# def bubbleSort(S) -> None:

# 삽입 정렬: 오름차순
# def insertionSort(S) -> None:

# 쉘 정렬: 오름차순
# def  shellSort(S) -> None:
# def  intervalSort(S, start:int , interval:int ) -> None:

# 2) 고급 정렬 알고리즘: 퀵.병합 정렬
# 퀵 정렬: 오름차순
# def  quickSort(S, first:int, last:int) -> None:

# 병합 정렬: 오름차순
# def  mergeSort(S, first:int, last:int) -> None:

# 3) 특수 정렬 알고리즘: 계수.기수.버킷 정렬
# 계수 정렬: 오름차순
# def countingSort(S) -> None:

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
