'''
	이진 트리(BT): 알고리즘 구현(Python) -- 이중연결리스트
        파일명: LinkedBTree.py
        		- main: 데이터 삽입.삭제, 전체 원소 출력
			- 클래스: DNode
			- 클래스: LinkedBTree
				- 이진 트리 생성: makeLinkedBTree
				- 깊이 우선 순회: Preorder, Inorder, Postorder
				- 너비 우선 순회: Levelorder
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

    # 소멸자: 이진 트리의 모든 노드 삭제
    def __del__(self):
        if self.__root : return
        Q = [self.__root]
        while Q :
            tNode = Q.pop(0)
            if tNode.Llink :	Q.append(tNode.Llink)
            elif tNode.Rlink :	Q.append(tNode.Rlink)
            del tNode

    # 이진 트리(수식 트리) 생성: 스택 구조 활용
    def makeLinkedBTree(self, postfix) -> DNode:
        # 연산자와 피연산자 사이에 공백이 없는 경우를 위해...
        # split을 위해 연산자 앞 뒤에 공백을 넣어준다.
        # postfix = postfix.replace('+', ' + ')
        # postfix = postfix.replace('-', ' - ')
        # postfix = postfix.replace('*', ' * ')
        # postfix = postfix.replace('/', ' / ')
        postfix = postfix.split()
        
        # 스택: 빈 리스트 객체 생성
        S = []
        for st in postfix :
            temp = DNode(st)
            # 연산자일 경우: 스택에서 자식 노드를 구성할 주소를 pop
            if isOperator(st) :
                temp.Rlink = S.pop()
                temp.Llink = S.pop()
            S.append(temp)
        self.__root = S.pop()   # 루트 노드
        return self.__root
        
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
       
    # 너비 우선 순회: 비재귀적 용법(큐 구조 활용)
    def Levelorder(self) :
        Q = []
        Q.append(self.__root)
        while len(Q) :
            tNode = Q.pop(0)
            print(f'{tNode.data}', end= ' ')
            if tNode.Llink :	Q.append(tNode.Llink)
            if tNode.Rlink :	Q.append(tNode.Rlink)
              
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
