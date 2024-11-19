'''
	해시 테이블: 알고리즘 구현(Python) -- 개방형 주소 방식
		파일명: HashOpenAddressing.py
        	- __main__: 데이터 삽입.삭제.검색, 전체 출력
			- 클래스: HashOpenAddressing
					데이터 삽입: insert
					데이터 삭제: delete
					데이터 검색: search
					전체 출력: output
'''

# 클래스 설계: HashOpenAddressing
class HashOpenAddressing: 
    def __init__(self, n:int):
        self.__table = [ None for i in range(n) ]
        self.__count = 0
        self.__DELETED = -54321

    # 해시 함수
    def __Hash(self, i:int, num) -> int:
        return (num + i) % len(self.__table)        # 선형 조사
        # return (num + i*i) % len(self.__table)    # 이차 조사

    # 데이터 삽입.삭제.검색
    def insert(self, num):
    def delete(self, num):
    def search(self, num):
    
    # 전체 출력
    def output(self) -> None:
        print(f'count({self.__count}): {self.__table}')

if __name__ == '__main__':
    import os		# system
    import sys  	# exit

    h = HashOpenAddressing(13)
    while (True):
        os.system('cls')
        print('\n ### 해시 테이블 ###')
        print('1) 데이터 삽입')
        print('2) 데이터 삭제')
        print('3) 데이터 검색')
        print('4) 전체 출력')
        print('5) 프로그램 종료\n')
        choice = int(input('메뉴 선택: '))

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
                    h.delete(num)
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

    # del h
    # h.__del__
