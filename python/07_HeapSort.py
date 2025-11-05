# HeapSort: 힙 정렬
def heapSort(sList) -> None:
    buildHeap(A)
    # deleteMax();
    # downHeap();

# buildHeap: 최대 힙 구성
def buildHeap(sList) -> None:

# downHeap: 최대 힙으로 재구성
def downHeap(sList, k:int, end:int) ->None:

if __name__ == '__main__' :
    import random

    # sList = [5,2,3,9,6,1,8,4,7]
    sList = []
    while len(sList)<15:
        num = random.randint(0, 99)
        sList.append(num)
    
    print(f'정렬 전: {sList}')
    heapSort(sList)
    print(f'정렬 후: {sList}')
