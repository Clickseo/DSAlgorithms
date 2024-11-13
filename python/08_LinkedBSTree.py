'''
	이진 검색 트리: 알고리즘 구현(Python) -- 이중연결리스트
		파일명: LinkedBSTree.py
        	- __main__: 데이터 삽입.삭제, 전체 원소 출력
			- 클래스: DNode
			- 클래스: LinkedBSTree
				데이터 삽입: InsertBST(_insertBST)
				데이터 삭제: DeleteBST(_deleteBST)
				데이터 검색: SearchBST(_searchBST)
				전체 원소 출력: printBSTAll(Preorder)
'''

# 클래스 설계: LinkedBSTree
class LinkedBSTree:
    class DNode:
        def __init__ (self, data, Llink=None, Rlink=None):
            self.data = data
            self.Llink = Llink
            self.Rlink = Rlink

    def __init__(self):
        self.__root = None

    # 소멸자: 너비 우선 순회
    def __del__(self):
        if not self.__root : return
        q = [ self.__root ]
        while q:
            tNode = q.pop(0)
            if tNode.Llink:     q.append(tNode.Llink)
            elif tNode.Rlink:   q.append(tNode.Rlink)
            del tNode
			
    # 전체 노드 출력
    def printBSTAll(self) -> None:
        if not self.__root:
            print("\n데이터가 존재하지 않습니다.")
            return
        
        # 너비 우선 순회: 비재귀적 용법
        print("\n이진 검색 트리: 전체 원소 출력")
        q = [ self.__root ]
        while q:
            tNode = q.pop(0)
            print(f'{tNode.data}', end= ' ')
            if tNode.Llink:	q.append(tNode.Llink)
            if tNode.Rlink: q.append(tNode.Rlink)
        print()

    # 데이터 검색
    def searchBST(self) -> None:
        # 데이터 검색: 재귀적 용법,  비재귀적 용법
        def _searchBST(root, data) -> self.DNode:
            pass

        if not self.__root:
            print("\n데이터가 존재하지 않습니다.")
            return
        
        print("\n이진 검색 트리: 데이터 검색")
        while True:
            num = int(input('임의의 정수 입력(종료: 0): '))
            if num == 0:
                break
            tNode = _searchBST(self.__root, num)
            if tNode:   print(f'{tNode.data} 키를 찾았습니다!!!')
            else:       print('키를 찾지 못했습니다.')

    # 데이터 삽입
    def insertBST(self) -> None:
        # 데이터 삽입: 재귀적 용법, 비재귀적 용법
        def _insertBST(root, data) -> self.DNode:
            pass

        print("\n이진 검색 트리: 데이터 삽입")
        while True:
            num = int(input('임의의 정수 입력(종료: 0): '))
            if num == 0:
                break
            self.__root = _insertBST(self.__root, num)

    # 데이터 삭제
    def deleteBST(self) -> None:
        # 데이터 삭제: 비재귀적 용법
        def _deleteBST(root, data) -> self.DNode:
            pass
        
        if not self.__root:
            print("\n데이터가 존재하지 않습니다.")
            return
        
        print("\n이진 검색 트리: 데이터 삭제")
        while True:
            num = int(input('임의의 정수 입력(종료: 0): '))
            if num == 0:
                break
            self.__root = _deleteBST(self.__root, num)

if __name__ == '__main__':
    import os	# system
    import sys  # exit

    bst = LinkedBSTree()
    while True:
        os.system('cls')
        print('\n##### 이진 검색 트리 ###')
        print('1) 데이터 삽입')
        print('2) 데이터 삭제')
        print('3) 데이터 검색')
        print('4) 전체 출력')
        print('5) 프로그램 종료\n')
        choice = int(input('메뉴 선택: '))

        match choice:
            case 1: bst.insertBST()
            case 2: bst.deleteBST()
            case 3: bst.searchBST()
            case 4: bst.printBSTAll()
            case 5:
                sys.exit("\n프로그램 종료!!!")
            case _: print('\n잘못 선택 하셨습니다. \n')
        os.system('pause')

    # del bst
    # bst.__del__
