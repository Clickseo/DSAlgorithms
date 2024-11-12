'''
	이진 검색 트리(BST): 알고리즘 구현(Python) -- 이중연결리스트
		파일명: LinkedBSTree.py
			- 클래스: DNode
			- 클래스: LinkedBSTree
					데이터 삽입: InsertBST(_insertBST)
					데이터 삭제: DeleteBST(_deleteBST)
					데이터 검색: SearchBST(_searchBST)
					전체 원소 출력: printBSTAll(Preorder)
'''

# DNode: data, Llink, Rlink
class DNode:
    def __init__ (self, data, Llink=None, Rlink=None):
        self.data = data
        self.Llink = Llink
        self.Rlink = Rlink

# 이진 검색 트리(BST): LinkedBSTree
class LinkedBSTree:
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
        # 깊이 우선 순회: 전위 순회
        def _preorder(root):
            if root:
                print(root.data, end=' ')
                _preorder(root.Llink)
                _preorder(root.Rlink)

        if not self.__root :
            print("\n데이터가 존재하지 않습니다.")
            return
		
        print("\n이진 검색 트리: 전체 원소 출력")
        _preorder(self.__root)

    def SearchBST(self) -> None:
    def InsertBST(self) -> None:
    def DeleteBST(self) -> None:

if __name__ == '__main__':
    bst = LinkedBSTree()
    while (True):
        print('\n##### 이진 검색 트리 ###')
        print('1) 데이터 삽입')
        print('2) 데이터 삭제')
        print('3) 데이터 검색')
        print('4) 전체 출력')
        print('5) 프로그램 종료\n')
        print('메뉴 선택 : ', end=' ')
        choice = int(input())

        if choice == 1 :	bst.InsertBST()
        elif choice == 2 :	bst.DeleteBST()
        elif choice == 3 :	bst.SearchBST()
        elif choice == 4 :	bst.printBSTAll()
        elif choice == 5 :
            print('프로그램 종료... \n')
            break
        else: print('잘못 선택 하셨습니다. \n')
