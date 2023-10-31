'''
	큐: 알고리즘 구현 -- 단순연결리스트
		파일명: LinkedQueue.py
			- 큐의 생성.소멸자  :  __init__, __del__
			- 데이터 삽입.삭제  : push, pop     # enQueue, deQueue
			- 데이터 확인(peek) : front, back   # peek
			- 빈 스택 여부 판단 : empty
			- 큐의 크기         : size
			- 큐의 전체 원소 출력: printQueue
'''

# LinkedQueue class
class LinkedQueue :
    # SNode class
    class SNode :
        def __init__ (self, data, link=None):
            self.data = data
            self.link = link
            
    # 생성자: 빈 큐 생성
    def __init__(self):
        self.__front = None
        self.__rear = None
        self.__count = 0

    # 소멸자: 큐 삭제 -- 모든 노드 삭제
    def __del__(self):
        temp = self.__front
        while temp :
            self.__front = temp.link
            del temp
            temp = self.__front
        del self
        
    # push(enQueue): 큐에 데이터 삽입
    def push(self, data) -> None:
        nNode = self.SNode(data, None)
        if not self.__front :
            self.__front = nNode            
        else :
            self.__rear.link = nNode
        self.__rear = nNode
        self.__count += 1

    # pop(deQueue): 큐에서 데이터 삭제
    def pop(self):
        if self.__front == None :
            return None
        temp = self.__front
        self.__front = temp.link
        del temp
        self.__count -= 1

    # front(peek): 큐에서 첫 번째 원소 확인
    def front(self):
        if self.__front == None :
            return None
        return self.__front.data
    
    # back(peek): 큐에서 맨 마지막 원소 확인
    def back(self):
        if self.__rear == None :
            return None
        return self.__rear.data    

    # empty: 큐의 공백 상태 여부 판단
    def empty(self) -> bool:
        return self.__front == None

    # size: 큐의 크기
    def size(self) -> int :
        return self.__count
    
    # printQueue: 큐의 전체 원소 출력
    def printQueue(self):
        temp = self.__front
        print('\n QUEUE [', end = ' ')
        while temp :
            print(temp.data, end = ' ')
            temp = temp.link
        print(']\n')

# from LinkedQueue import LinkedQueue
if __name__ == '__main__':
    Q = LinkedQueue()
    while(True):
        print('\n### 큐 구현: 단순 연결 리스트 ###')
        print('1) 데이터 삽입(push, enQueue)')
        print('2) 데이터 삭제(pop, deQueue)')
        print('3) 전체 출력')
        print('4) 프로그램 종료')
        choice = int(input('메뉴 선택: '))

        if choice == 1: num = int(input('삽입 할 데이터 : '));      Q.push(num)
        elif choice == 2: print(f'삭제 된 데이터: {Q.front()}');   Q.pop()
        elif choice == 3: Q.printQueue()
        elif choice == 4: print('프로그램 종료...');   break
        else: print('잘못 선택 하셨습니다.')
