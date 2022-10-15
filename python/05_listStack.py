'''
	스택: 알고리즘 구현 -- 순차자료구조(리스트)
	파일명: listStack.py
		- 스택 생성 및 삭제
		- 삽입, 삭제, 확인   : push, pop, popAll, peek
		- 빈 스택 여부 판단  : isEmpty
		- 전체 원소 출력     : printStack
'''

class ListStack:
    # 빈 스택 생성
    def __init__(self):
        self.__stack = []
        
    # PUSH : 스택에 데이터 삽입 
    def push(self, num):
        self.__stack.append(num)       
        
    # POP : 스택에서 데이터 삭제
    def pop(self):
        return self.__stack.pop()

    # PEEK : 스택 맨 위의 원소 확인
    def peek(self):
        if self.isEmpty():
            return None
        else:
            return self.__stack[-1]

    # 스택의 공백 상태 여부 판단
    def isEmpty(self) -> bool:
        return not bool(self.__stack)

    # 스택의 전체 원소 삭제
    def popAll(self):
        self.__stack.clear()

    # 스택의 전체 원소 출력
    def printStack(self):
        print('\n STACK [', end = ' ')
        for i in range(len(self.__stack)-1, -1, -1):
            print(self.__stack[i], end = ' ')
        print(']\n')

if __name__ == '__main__':
    s = ListStack()
    while (True):
        print('\n ### 스택 구현: 1차원 배열 ###');
        print('1) 데이터 삽입: PUSH');
        print('2) 데이터 삭제: POP');
        print('3) 전체 출력');
        print('4) 프로그램 종료\n');
        print('메뉴 선택 : ');
        choice = int(input())

        if choice == 1: num = input('삽입 할 데이터 입력: '); s.push(num)
        elif choice == 2: print(f'삭제 된 데이터: {s.pop()}\n')
        elif choice == 3: s.printStack()
        elif choice == 4: print('프로그램 종료... \n'); break
        else: print('잘못 선택 하셨습니다. \n')
