'''
	스택: 알고리즘 구현(Python) -- 단순연결리스트
		파일명: LinkedStack.py
			- 스택 생성.소멸		: __init__, __del__
			- 스택 상태		: empty
			- 스택 크기		: size
			- 데이터 삽입.삭제	: push, pop
			- 데이터 확인(peek)	: top
			- 전체 데이터 출력	: printStack
'''

# LinkedStack class: SNode, top, count
class LinkedStack:
    class SNode:
        def __init__(self, data, link=None):
            self.data = data
            self.link = link

    # 빈 스택 생성
    def __init__(self):
        self.__top = None
        self.__count = 0

    # 스택 삭제: 모든 노드 삭제
    def __del__(self):

    # 빈 스택 여부 확인
    def empty(self) -> bool:
    
    # 스택의 원소 개수
    def size(self) -> int:
    
    # 데이터 삽입: 스택에 새로운 데이터 추가
    def push(self, data) -> None:

    # 데이터 삭제: 스택에서 맨 위의 데이터 삭제
    def pop(self) -> None:

    # 스택에서 맨 위의 데이터 반환(peek)
    def top(self):
    
    # 스택의 전체 데이터 출력
    def printStack(self) -> None:

if __name__ == '__main__':
    import os			# system
    import sys  		# exit

    # "SNode" is not defined
    # tNode = SNode(10, None)

    s = LinkedStack()
    while True:
        os.system('cls')
        print('\n ### 스택 구현: 단순연결리스트 ###')
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
                    s.push(num)
            case 2:
                print(f'\n삭제 된 데이터: {s.top()}')
                s.pop()
            case 3:
                s.printStack()
            case 4:
                sys.exit("\n프로그램 종료!!!")
            case _: print('\n잘못 선택 하셨습니다. \n')
        os.system('pause')

    # del s
    # s.__del__
