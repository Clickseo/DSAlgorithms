'''
	큐: 알고리즘 구현 -- 단순연결리스트
        파일명: LinkedQueue(demo).py
        		- main	: 데이터 삽입.삭제, 전체 원소 출력
'''

from LinkedQueue import LinkedQueue

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
