'''
	이진 트리: 알고리즘 구현
        파일명: LinkedBTree.py
        		- main: 데이터 삽입.삭제, 전체 원소 출력
			클래스: DNode
			클래스: LinkedBinaryTree
				- 이진 트리 생성                    : makeLinkedBinaryTree
				- 깊이 우선 순회(전위.중위.후위 순회) : Preorder, Inorder, Postorder
				- 너비 우선 순회
'''

# 연산자 여부 판단
def isOperator(op) -> bool :
    return op == '+' or op == '-' or op == '*' or op == '/'

class DNode :
    def __init__ (self, data, Llink=None, Rlink=None):
        self.data = data
        self.Llink = Llink
        self.Rlink = Rlink

class LinkedBTree :
    def __init__(self):
        self.__root = None
	    
    # 이진 트리(수식 트리) 생성: 스택 구조 활용    
    def makeLinkedBTree(self, postfix) -> DNode:
	    
    # 깊이 우선 순회: 전위.중위.후위 순회    
    def Preorder(self):
    def Inorder(self):
    def Postorder(self):
	    
    # 너비 우선 순회: 비재귀적 용법(큐 구조 활용)
    def Levelorder(self):
    def __del__(self):      # 소멸자: 이진 트리의 모든 노드 삭제
      
# from LinkedBTree import LinkedBTree
if __name__ == '__main__':     
    postfix = input('트리를 구성할 후위 수식: ')
    BT = LinkedBTree()
    BT.makeLinkedBTree(postfix)
    # root = BT.makeLinkedBTree(postfix)

    # 이진 트리 깊이 우선 순회: 전위.중위.후위 순회
    print('Preorder  : ', end=' ');     BT.Preorder();    print('')
    print('Inorder   : ', end=' ');     BT.Inorder();     print('')
    print('Postorder : ', end=' ');     BT.Postorder();   print('')

    # 이진 트리 너비 우선 순회
    print('Levelorder : ', end=' ');    BT.Levelorder();  print('')
