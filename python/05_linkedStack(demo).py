'''
	스택: 알고리즘 구현 -- 단순연결리스트
		- main	: 데이터 삽입.삭제, 전체 원소 출력
'''

from LinkedStack import LinkedStack

if __name__ == '__main__':
    LS = LinkedStack()
    while(True):
        print('### 스택 구현: 단순 연결 리스트 ###')
        print('1) 데이터 삽입(push)')
        print('2) 데이터 삭제(pop)')
        print('3) 전체 출력')
        print('4) 프로그램 종료')
        choice = int(input('메뉴 선택: '))

        if choice == 1: num = int(input('삽입 할 데이터 : '));  LS.push(num)
        elif choice == 2: print(f'삭제 된 데이터: {LS.top()}'); LS.pop()
        elif choice == 3: LS.printStack()
        elif choice == 4: print('프로그램 종료...')
        else: print('잘못 선택 하셨습니다.')
