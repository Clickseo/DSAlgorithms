class ListStack:
	def __init__(self):       
	def push(self, num):       
	def pop(self):
	def top(self):
	def isEmpty(self) -> bool:
	def popAll(self):
	def printStack(self):

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