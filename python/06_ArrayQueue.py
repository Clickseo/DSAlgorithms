'''
	큐: 알고리즘 구현(Python) -- 순차 자료구조
		파일명: ArrayQueue.py
			- 큐 생성.소멸		: __init__, __del__
			- 큐 상태			: empty
			- 큐 크기			: size
			- 데이터 삽입.삭제	: push, pop
			- 데이터 확인(peek)	: front, back
			- 전체 데이터 출력	: printStack
'''

class ArrayQueue:
    # 빈 큐 생성
    def __init__(self):
        self.__queue = []        

    # 큐 삭제
    def __del__(self):
        self.__queue.clear()

    # 빈 큐 여부
    def empty(self) -> bool:
        if not self.__queue:
            return True
        return False

    # 큐의 원소 개수
    def size(self) -> int:
        return len(self.__queue)

    # 데이터 삽입: 맨 마지막으로 새로운 데이터 추가
    def push(self, num) -> None:
        self.__queue.append(num)
        
    # 데이터 삭제: 첫 번째 데이터 삭제
    def pop(self) -> None:
        if self.empty():
            return
        self.__queue.pop(0)

    # 큐에서 첫 번째 데이터 확인
    def front(self):
        if not self.__queue:
            return None
        return self.__queue[0]
    
    # 큐에서 맨 마지막 데이터 확인
    def back(self):
        if not self.__queue:
            return None
        return self.__queue[-1]    

    # 큐의 전체 원소 출력
    def printQueue(self):
        if self.empty():
            print('입력된 데이터가 없습니다!!!')
            return

        print('\n Queue [', end = ' ')
        for i in range(len(self.__queue)):
            print(self.__queue[i], end = ' ')
        print(']\n')
        
if __name__ == '__main__':
    import os		# system
    import sys  	# exit

    q = ArrayQueue()
    while (True):
        os.system('cls')
        print('\n ### 큐 구현: 1차원 배열 ###')
        print('1) 데이터 삽입: push')
        print('2) 데이터 삭제: pop')
        print('3) 전체 출력')
        print('4) 프로그램 종료\n')
        print('메뉴 선택: ', end='')
        choice = int(input())

        match choice:
            case 1:
                while True:
                    num = int(input('삽입 할 데이터 입력(종료: 0): '))
                    if num == 0:
                        break
                    q.push(num)
            case 2:
                if not q.empty():
                    print(f'\n삭제 된 데이터: {q.front()}')
                    q.pop()
            case 3:
                q.printQueue()
            case 4:
                sys.exit("\n프로그램 종료!!!")
            case _: print('\n잘못 선택 하셨습니다. \n')
        os.system('pause')

    # del s
    # s.__del__
