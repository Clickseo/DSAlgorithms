class HashOpenAddressing: 
    def __init__(self, n:int):
        self.__table = [None for i in range(n)]
        self.__count = 0
        self.__DELETED = -54321

    # 해시 함수
    def __Hash(self, i:int, num):
        return (num + i) % len(self.__table)        # 선형 조사
        # return (num + i*i) % len(self.__table)    # 이차 조사

    def insert(self, num):
    def delete(self, num):
    def search(self, num):
    
    # 전체 원소 출력
    def output(self):
        print(f'count({self.__count}): {self.__table}')

if __name__ == '__main__':       
    h = HashOpenAddressing(13)

    while (True):
        print('\n ### 해시 테이블 ###')
        print('1) 데이터 삽입')
        print('2) 데이터 삭제')
        print('3) 데이터 검색')
        print('4) 전체 출력')
        print('5) 프로그램 종료\n')
        print('메뉴 선택 : ', end=' ')
        choice = int(input())

        if choice == 1:
            num = int(input('삽입 할 데이터 입력: '))
            inserted = h.insert(num)
            if inserted: print(f'삽입 된 데이터: {inserted}')
            else: print(f'데이터 삽입에 실패하였습니다.')
        elif choice == 2:
            num = int(input('삭제 할 데이터 입력: '))
            deleted = h.delete(num)
            if deleted: print(f'삭제 된 데이터: {deleted}')
            else: print(f'데이터가 존재하지 않습니다.')
        elif choice == 3:
            num = int(input('검색 할 데이터 입력: '))
            searched = h.search(num)
            if searched: print(f'검색된 데이터: {searched}')
            else: print(f'데이터가 존재하지 않습니다.')
        elif choice == 4: h.output()
        elif choice == 5:
            print('프로그램 종료!!!')
            break
        else: print('잘못 선택 하셨습니다.')
