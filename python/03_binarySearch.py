'''	
	이진 탐색: 알고리즘 구현
	
	1) 재귀적 용법
	2) 비재귀적 용법
'''

# 이진탐색: 재귀적용법
def binarySearch(S, first:int, last:int, key) -> int:
    if first > last :
        return None

    mid = (first + last) // 2

    if S[mid] == key : return mid
    elif S[mid] < key : index = binarySearch(S, mid + 1, last, key)
    elif S[mid] > key : index = binarySearch(S, first, mid - 1, key)
    return index

'''
# 이진탐색: 비재귀적용법
def binarySearch(S, first:int, last:int, key:int) -> int:
    while first <= last :
        mid = (first + last) // 2
        if S[mid] == key : return mid
        elif S[mid] < key : first = mid + 1
        elif S[mid] > key : last = mid - 1
    return None
'''

if __name__ == '__main__' :
    sList = [5, 9, 13, 17, 21, 28, 37, 46, 55, 88]
    print(f"원시 데이터: {sList}")

    while True :
        key = int(input("검색 데이터 입력(검색 종료: 0) : "))
        if key == 0 : break

        index = binarySearch(sList, 0, len(sList)-1, key)
        if index == None : print("없다고!!!")
        else : print(f"검색된 데이터: {index+1}번째 {sList[index]}")
