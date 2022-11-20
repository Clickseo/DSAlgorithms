'''
	이진 트리: 알고리즘 구현
		파일명: LinkedBinaryTree.py
			클래스: TreeNode
			클래스: LinkedBinaryTree
				- 이진 트리 생성					: makeLinkedBinaryTree
				- 깊이 우선 순회(전위.중위.후위 순회)	: Preorder, Inorder, Postorder
				- 너비 우선 순회					: Levelorder
'''

from LinkedStack import LinkedStack
from LinkedQueue import LinkedQueue

# 연산자 여부 판단
def isOperator(op) -> bool :
    return op == '+' or op == '-' or op == '*' or op == '/'

class TreeNode :
    def __init__ (self, data, Llink=None, Rlink=None):
        self.data = data
        self.Llink = Llink
        self.Rlink = Rlink

class LinkedBinaryTree :
    def __init__(self):
        self.__root = None

    def makeLinkedBinaryTree(self, postfix) -> TreeNode:
        # split을 위해 연산자 앞 뒤에 공백을 넣어준다.
        postfix = postfix.replace('+', ' + ')
        postfix = postfix.replace('-', ' - ')
        postfix = postfix.replace('*', ' * ')
        postfix = postfix.replace('/', ' / ')
        postfix = postfix.split()
        
        s = LinkedStack()
        for st in postfix :
            temp = TreeNode(st)
            
        # 연산자일 경우: 스택에서 자식 노드를 구성할 주소를 pop
        if isOperator(st) :
                temp.Rlink = s.pop()
                temp.Llink = s.pop()
        s.push(temp)
        self.__root = s.pop()    # 루트 노드
        
    # 깊이 우선 순회: 전위 순회
    def Preorder(self):
        def _Preorder(tNode):
            if tNode :
                print(tNode.data, end=' ')
                _Preorder(tNode.Llink)
                _Preorder(tNode.Rlink)        
        _Preorder(self.__root)

    # 깊이 우선 순회: 중위 순회
    def Inorder(self) :
        def _Inorder(tNode):
            if tNode :                
                _Inorder(tNode.Llink)
                print(tNode.data, end=' ')
                _Inorder(tNode.Rlink)
        _Inorder(self.__root)

    # 깊이 우선 순회: 후위 순회
    def Postorder(self) :
        def _Postorder(tNode):
            if tNode :                
                _Postorder(tNode.Llink)
                _Postorder(tNode.Rlink)
                print(tNode.data, end=' ')
        _Postorder(self.__root)

    def Levelorder(self) :
	    q = LinkedQueue()
	    q.push(self.__root)
	    while not q.empty() :
		    temp = q.front();  q.pop()
		    print(f'{temp.data}', end= ' ')
		    if temp.Llink :	q.push(temp.Llink)
		    if temp.Rlink :	q.push(temp.Rlink)
