'''
	스택: 알고리즘 구현(Python) --단순연결리스트
		파일명: LinkedStack.py
		클래스: SNode
		클래스: LinkedStack
			- 생성자.소멸자          : __init__, __del__
			- 스택 데이터 삽입.삭제  : push, pop, top
			- 스택 데이터 확인(peek) : top
			- 빈 스택 여부 판단      : empty
			- 스택 크기             : size
			- 스택의 전체 원소 출력  : printStack
'''

# SNode class
class SNode :
    def __init__ (self, data, link=None):
        self.data = data
        self.link = link

# LinkedStack class
class LinkedStack :
    # 생성자: 빈 스택 생성
    def __init__(self):
        self.__top = None
        self.__count = 0

    # 소멸자 : 스택 삭제 -- 모든 노드 삭제
    def __del__(self):
        temp = self.__top
        while temp :
            self.__top = temp.link
            del temp
            temp = self.__top
        del self
        
    # push : 스택의 데이터 삽입
    def push(self, data) -> None :
        nSNode = SNode(data, self.__top)
        self.__top = nSNode

    # pop : 스택에서 데이터 삭제
    def pop(self) -> None :
        if self.__top == None :
            return None
        temp = self.__top
        self.__top = temp.link

    # top(peek) : 스택 맨 위의 원소 확인
    def top(self):
        if self.__top == None :
            return None
        return self.__top.data

    # empty : 스택의 공백 상태
    def empty(self) -> bool :
        return self.__top == None
    
    # size : 스택의 크기
    def size(self) -> int :
        return self.__count
    
    # 스택의 전체 원소 출력
    def printStack(self) -> None :
        temp = self.__top
        print('\n STACK [', end = ' ')
        while temp :
            print(temp.data, end = ' ')
            temp = temp.link
        print(']\n')
