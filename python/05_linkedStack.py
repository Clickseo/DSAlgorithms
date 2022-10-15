'''
	스택: 알고리즘 구현 -- 연결자료구조(단순연결리스트)
	파일명: linkedStack.py
		- 스택 생성 및 삭제
		- 원소 삽입.삭제.확인  : push, pop, peek
		- 빈 스택 여부 판단    : isEmpty
		- 전체 원소 출력       : printStack
'''

class Node :
    def __init__ (self, data, link=None):
        self.data = data
        self.link = link

class LinkedStack :
    # 빈 스택 생성
    def __init__(self):
        self.__top = None

    # PUSH : 스택에 데이터 삽입
    def push(self, data) -> None:
        nNode = Node(data, self.__top)
        self.__top = nNode

    # POP : 스택에서 데이터 삭제
    def pop(self):
        if self.__top == None :
            return None
        temp = self.__top
        self.__top = temp.link
        return temp.data

    # PEEK : 스택 맨 위의 원소 확인
    def peek(self):
        if self.__top == None :
            return None
        return self.__top.data

    # 스택의 공백 상태 여부 판단
    def isEmpty(self) -> bool:
        return self.__top == None
    
    # 스택의 전체 원소 출력
    def printStack(self):
        temp = self.__top
        print('\n STACK [', end = ' ')
        while temp :
            print(temp.data, end = ' ')
            temp = temp.link()
        print(']\n')
