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
class SNode:
    def __init__(self, data, link=None):
        self.data = data
        self.link = link

# LinkedStack class
class LinkedStack:

if __name__ == '__main__':
    S = LinkedStack()
    while(True):
        print('### 스택 구현: 단순 연결 리스트 ###')
        print('1) 데이터 삽입(push)')
        print('2) 데이터 삭제(pop)')
        print('3) 전체 출력')
        print('4) 프로그램 종료')
        choice = int(input('메뉴 선택: '))

        if choice == 1: num = int(input('삽입 할 데이터 : '));  S.push(num)
        elif choice == 2: print(f'삭제 된 데이터: {S.top()} '); S.pop()
        elif choice == 3: S.printStack()
        elif choice == 4: print('프로그램 종료...')
        else: print('잘못 선택 하셨습니다.')
