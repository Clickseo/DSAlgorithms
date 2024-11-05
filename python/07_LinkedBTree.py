'''
	이진 트리: 알고리즘 구현(Python) -- 이중연결리스트
        파일명: LinkedBTree.py
        	- __main__: 데이터 삽입.삭제, 전체 원소 출력
		- 클래스: DNode
		- 클래스: LinkedBTree
			- 이진 트리 생성: makeLinkedBTree
			- 깊이 우선 순회: Preorder, Inorder, Postorder
			- 너비 우선 순회: Levelorder
'''

# 클래스 설계: LinkedBTree
class LinkedBTree:
    class DNode:
        def __init__ (self, data, Llink=None, Rlink=None):
            self.data = data
            self.Llink = Llink
            self.Rlink = Rlink

    def __init__(self):
        self.__root = None

    # 깊이 우선 순회: 전위.중위.후위 순회
    def Preorder(self) -> None:
    def Inorder(self) -> None:
    def Postorder(self) -> None:

    # 너비 우선 순회
    def Levelorder(self) -> None:	    
    def __del__(self):

    # 이진 트리(수식 트리) 생성: 스택 구조
    def makeLinkedBTree(self, postfix) -> None:
        # 연산자 여부 판단
        def isOperator(op) -> bool:
            return op == '+' or op == '-' or op == '*' or op == '/'
        pass
       
if __name__ == '__main__':     
    postfix = input('트리를 구성할 후위 수식: ')

    # 이진 트리(수식 트리) 생성
    BTree = LinkedBTree()
    BTree.makeLinkedBTree(postfix)

    # 깊이 우선 순회: 전위.중위.후위 순회
    print('Preorder  : ', end=' ');     BTree.Preorder();    print('')
    print('Inorder   : ', end=' ');     BTree.Inorder();     print('')
    print('Postorder : ', end=' ');     BTree.Postorder();   print('')

    # 너비 우선 순회
    print('Levelorder: ', end=' ');    BTree.Levelorder();  print('')
