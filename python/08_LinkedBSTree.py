'''
	이진 검색 트리(BST): 알고리즘 구현(Python) -- 이중연결리스트
		파일명: LinkedBSTree.py
			- 클래스: DNode
			- 클래스: LinkedBSTree
					데이터 삽입: InsertBST
					데이터 삭제: DeleteBST
					데이터 검색: SearchBST
					전체 원소 출력: printBSTAll
'''

# DNode: data, Llink, Rlink
class DNode :
    def __init__ (self, data, Llink=None, Rlink=None):
        self.data = data
        self.Llink = Llink
        self.Rlink = Rlink

# 이진 검색 트리(BST): LinkedBSTree
class LinkedBSTree:
    def __init__(self):
        self.__root = None

    # 소멸자: 너비 우선 순회
    def __del__(self) :
        if not self.__root : return
        Q = [self.__root]
        while Q :
            tNode = Q.pop(0)
            if tNode.Llink :	Q.append(tNode.Llink)
            elif tNode.Rlink :	Q.append(tNode.Rlink)
            del tNode
			
    # 전체 노드 출력
    def printBSTAll(self) -> None:
    # 깊이 우선 순회: 전위 순회
        def _preorder(root):
            if root :
                print(root.data, end=' ')
                _preorder(root.Llink)
                _preorder(root.Rlink)

        if not self.__root :
            print("\n데이터가 존재하지 않습니다.")
            return
		
        print("\n이진 검색 트리: 전체 원소 출력")
        _preorder(self.__root)

    # 데이터 검색
    def SearchBST(self) -> None:
        # 데이터 검색: 재귀적 용법
        def _searchBST(root, data) -> DNode:
            if root == None : return None
            elif data == root.data : return tNode
            elif data < root.data :
                return _searchBST(root.Llink, data)
            else :
                return _searchBST(root.Rlink, data)
			
        if not self.__root :
            print("\n데이터가 존재하지 않습니다.")
            return
		
        print("\n이진 검색 트리: 데이터 검색")
        while True :
            num = int(input('임의의 정수 입력(종료: 0): '))
            if num == 0 : break
            tNode = _searchBST(self.__root, num)
            if tNode : print(f'{tNode.data} 키를 찾았습니다!!!')
            else : print('키를 찾지 못했습니다.')

    # 데이터 삽입
    def InsertBST(self) -> None:
        # 데이터 삽입 -- 재귀적 용법
        def _insertBST(root, data) -> DNode:
            if root == None : root = DNode(data)
            elif data < root.data :
                root.Llink = _insertBST(root.Llink, data)
            else:
               root.Rlink = _insertBST(root.Rlink, data)
            return root
        
        print("\n이진 검색 트리: 데이터 삽입")
        while True :
            num = int(input('임의의 정수 입력(종료: 0): '))
            if num == 0 : break
            self.__root = _insertBST(self.__root, num)

	# 이진 검색 트리(BST): 데이터 삭제 -- 비재귀적 용법
    def DeleteBST(self) -> None:
        # 데이터 삭제 -- 비재귀적 용법
        def _deleteBST(root, data) -> DNode:
	        # 삭제할 노드가 없는 경우
            if not root :
                print("\n키를 찾지 못했습니다.")
                return tNode

            pParent = None	# 삭제할 노드의 부모 노드
            tNode = root	# 삭제할 노드

	        # 삭제할 노드의 위치 탐색
            while data != tNode.data :
                pParent = tNode
                if data < tNode.data : tNode = tNode.Llink
                elif data < tNode.data :tNode = tNode.Rlink

            # 1) 삭제할 노드가 단말 노드인 경우
            if tNode.Llink == None and tNode.Rlink == None :
                if pParent == None : root = None
                elif pParent != None :
                    if pParent.Llink == tNode : pParent.Llink = None
                    else : pParent.Rlink = None
                    
            # 2) 삭제할 노드가 자식 노드를 한 개 가진 경우
            elif tNode.Llink == None or tNode.Rlink == None :
                # pChild : (후계자) 삭제할 노드의 자식 노드
                if tNode.Llink != None : pChild = tNode.Llink
                else : pChild = tNode.Rlink
                
                if pParent == None: root = pChild
                else :
                    if pParent.Llink == tNode : pParent.Llink = pChild
                    else : pParent.Rlink = pChild

            # 3) 삭제할 노드가 자식 노드를 두 개 가진 경우
            else :	
                # 왼쪽 서브 트리에서 후계자(최댓값) 찾기
                sParent = tNode
                sNode = tNode.Llink
                while sNode.Rlink != None :
                    sParent = sNode
                    sNode = sNode.Rlink
                    
                if sParent.Llink == sNode :
                   sParent.Llink = sNode.Llink
                else :
                    sParent.Rlink = sNode.Llink
                
                tNode.data = sNode.data
                tNode = sNode
            del tNode
            return root
        
        print("\n이진 검색 트리: 데이터 삭제")
        while True :
            num = int(input('임의의 정수 입력(종료: 0): '))
            if num == 0 : break
            self.__root = _deleteBST(self.__root, num)

# from LinkedBSTree import *
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
