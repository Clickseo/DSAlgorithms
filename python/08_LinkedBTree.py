'''
	이진 트리: 알고리즘 구현(Python) -- 이중연결리스트
        파일명: LinkedBTree.py
        	- __main__: 데이터 삽입.삭제, 전체 원소 출력
			- 클래스: DNode
			- 클래스: LinkedBTree
				- 이진 트리 생성: makeLinkedBTree
				- 깊이 우선 순회: preorder, inorder, postorder
				- 너비 우선 순회: levelorder
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

    # 이진 트리(수식 트리) 생성: 스택 구조 활용
    def makeLinkedBTree(self, postfix:str) -> None:
        def isOperator(op) -> bool:
            return op == '+' or op == '-' or op == '*' or op == '/'
        
        # 연산자와 피연산자 사이에 공백이 없는 경우를 위해...
        # split을 위해 연산자 앞 뒤에 공백을 넣어준다.
        # postfix = postfix.replace('+', ' + ')
        # postfix = postfix.replace('-', ' - ')
        # postfix = postfix.replace('*', ' * ')
        # postfix = postfix.replace('/', ' / ')
        postfix = postfix.split()
        pass
        
    # 깊이 우선 순회: 전위 순회(재귀적 용법)
    def preorder(self) -> None:
        def _preorder(tNode):
            if tNode:
                print(tNode.data, end=' ')
                _preorder(tNode.Llink)
                _preorder(tNode.Rlink)        
        _preorder(self.__root)

    # 깊이 우선 순회: 중위 순회(재귀적 용법)
    def inorder(self) -> None:
        def _inorder(tNode):
            if tNode:                
                _inorder(tNode.Llink)
                print(tNode.data, end=' ')
                _inorder(tNode.Rlink)
        _inorder(self.__root)

    # 깊이 우선 순회: 후위 순회(재귀적 용법)
    def postorder(self) -> None:
        def _postorder(tNode):
            if tNode: 
                _postorder(tNode.Llink)
                _postorder(tNode.Rlink)
                print(tNode.data, end=' ')
        _postorder(self.__root)   

    # 너비 우선 순회: 비재귀적 용법
    def levelorder(self) -> None:
        pass

    # 이진 트리 삭제: 모든 노드 삭제
    def __del__(self):
        pass

if __name__ == '__main__':     
    postfix = input('트리를 구성할 후위 수식: ')
    BTree = LinkedBTree()
    BTree.makeLinkedBTree(postfix)

    # 깊이 우선 순회: 전위.중위.후위 순회
    print('Preorder : ', end=' ');     BTree.preorder();    print('')
    print('Inorder  : ', end=' ');     BTree.inorder();     print('')
    print('Postorder: ', end=' ');     BTree.postorder();   print('')

    # 너비 우선 순회
    print('Levelorder: ', end=' ');    BTree.levelorder();  print('')
