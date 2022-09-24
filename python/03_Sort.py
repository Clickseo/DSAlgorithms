import random

# 선택 정렬: 오름차순
def selectionSort(S):
    for i in range(len(S)) :
        smIndex = i;
        for j in range(i, len(S)) :
            if S[smIndex] > S[j] :
                smIndex = j
        S[smIndex], S[i] = S[i], S[smIndex]

# 버블 정렬: 오름차순
# def bubbleSort(S):

# 삽입 정렬: 오름차순
# def insertionSort(S):

# 쉘 정렬: 오름차순
# def  shellSort(S):
# def  intervalSort(S, start, interval):

# 퀵 정렬: 오름차순
# def  quickSort(S, first:int, last:int):

# 병합 정렬: 오름차순
# def  mergeSort(S, first:int, last:int):

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

    print(f'정렬 후: {sList}')
