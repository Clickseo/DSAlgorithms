'''
	큐: 알고리즘 구현(Python) -- 단순연결리스트
		파일명: LinkedStack.py
			- 큐 생성.소멸	    : __init__, __del__
			- 큐 상태	    : empty
			- 큐 크기	    : size
			- 데이터 삽입.삭제  : push, pop
			- 데이터 확인(peek) : front, back
			- 전체 데이터 출력  : printQueue
'''

# LinkedQueue class: SNode, front, rear, count
class LinkedQueue:
    class SNode:
        def __init__ (self, data, link=None):
            self.data = data
            self.link = link
            
    # 빈 큐 생성
    def __init__(self):
        self.__front = None
        self.__rear = None
        self.__count = 0

    # 스택 삭제: 모든 노드 삭제
    def __del__(self):
        pass

    # 빈 큐 여부 확인
    def empty(self) -> bool:
        pass

    # 큐의 원소 개수
    def size(self) -> int:
        pass
        
    # 데이터 삽입: 큐의 맨 마지막에 새로운 데이터 추가
    def push(self, data) -> None:
        pass

    # 데이터 삭제: 큐의 첫 번째 데이터 삭제
    def pop(self):
        pass

    # 큐에서 첫번째 데이터 반환(peek)
    def front(self):
        pass
    
    # 큐에서 맨 마지막 데이터 반환(peek)
    def back(self):
        pass
    
    # 큐의 전체 데이터 출력
    def printQueue(self):
        pass

if __name__ == '__main__':
    import os		# system
    import sys  	# exit

    # "SNode" is not defined
    # tNode = SNode(10, None)

    q = LinkedQueue()
    while True:
        os.system('cls')
        print('\n ### 큐 구현: 단순연결리스트 ###')
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
