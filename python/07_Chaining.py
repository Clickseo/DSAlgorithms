'''
	해시 테이블: 알고리즘 구현(Python) -- 개방 주소 방법
		파일명: Chaining.py
        	- __main__: 데이터 삽입.삭제.검색, 전체 원소 출력
			- 클래스: Chaining
					데이터 삽입: insert
					데이터 삭제: remove
					데이터 검색: search
					전체 출력: output
'''

# 클래스 설계: Chaining
class Chaining: 
    class SNode:
        def __init__(self, data):
            self.data = data
            self.link = None

    def __init__(self, n:int):
        self.__table = [None] * n

    # 해시 함수
    def __Hash(self, num):
        return num % len(self.__table)
    
    # 데이터 삽입
    def insert(self, num):
    
    # 데이터 삭제
    def remove(self, num):

    # 데이터 검색
    def search(self, num):

    # 전체 원소 출력
    def output(self):
        for i in range(len(self.__table)):
            print(f'{i:3}', end = '')
            tNode = self.__table[i]
            while tNode :
                print(f' --> {tNode.data}', end='')
                tNode = tNode.link
            print('')

if __name__ == '__main__':       
    import os		# system
    import sys  	# exit

    h = Chaining(13)

    while (True):
        print('\n ### 해시 테이블 ###')
        print('1) 데이터 삽입')
        print('2) 데이터 삭제')
        print('3) 데이터 검색')
        print('4) 전체 출력')
        print('5) 프로그램 종료\n')
        print('메뉴 선택 : ', end=' ')
        choice = int(input())

        match choice:
            case 1:
                while True:
                    num = int(input('임의의 정수 입력(종료: 0): '))
                    if num == 0: break
                    h.insert(num)
            case 2:
                while True:
                    num = int(input('임의의 정수 입력(종료: 0): '))
                    if num == 0: break
                    h.remove(num)
            case 3:
                while True:
                    num = int(input('임의의 정수 입력(종료: 0): '))
                    if num == 0: break
                    searched = h.search(num)
                    if searched: print(f'검색된 데이터: {searched}')
                    else: print(f'데이터가 존재하지 않습니다.')
            case 4: h.output()
            case 5:
                sys.exit("\n프로그램 종료!!!")
            case _: print('\n잘못 선택 하셨습니다. \n')
        os.system('pause')
