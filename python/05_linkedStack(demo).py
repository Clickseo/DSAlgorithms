'''
	스택: 알고리즘 구현 -- 연결자료구조(단순연결리스트)
		- main	: 데이터 삽입.삭제, 전체 원소 출력
'''

from LinkedStack import LinkedStack

if __name__ == '__main__':
    s = LinkedStack()
    while(True):
        print('\n ### 스택 구현: 단순 연결 리스트 ###');
        print('1) 데이터 삽입: PUSH');
        print('2) 데이터 삭제: POP');
        print('3) 전체 출력');
        print('4) 프로그램 종료\n');
        print('메뉴 선택: ', end=' ');
        choice = int(input())

        if choice == 1: num = input('삽입 할 데이터 입력: '); s.push(num)
        elif choice == 2: print(f'삭제 된 데이터: {s.pop()}\n')
        elif choice == 3: s.printStack()
        elif choice == 4: print('프로그램 종료... \n'); break
        else: print('잘못 선택 하셨습니다. \n')
