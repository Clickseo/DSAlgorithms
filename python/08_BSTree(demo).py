class DNode :
    def __init__ (self, data, Llink=None, Rlink=None):
        self.data = data
        self.Llink = Llink
        self.Rlink = Rlink

class BSTree:
	def __init__(self):
		self.__root = None

	# 이진 검색 트리(BST): 데이터 검색
	def search(self, data) -> DNode:
		return self.__searchBST(self.__root, data)
	def __searchBST(self, tNode:DNode, data) -> DNode:

	# 이진 검색 트리(BST): 데이터 삽입
	def insert(self, data):
		self.__root = self.__insertBST(self.__root, data)
	def __insertBST(self, tNode:DNode, data) -> DNode:

	# 이진 탐색 트리(BST): 데이터 삭제
	def delete(self, data):
		self.__root = self.__deleteBST(self.__root, data)	
	def __deleteBST(self, tNode:DNode, data) -> DNode:

	def __deleteNode(self, tNode:DNode) -> DNode:
		# 3가지 case
		#     1. tNode이 리프 노드
		#     2. tNode이 자식이 하나만 있음
		#     3. tNode이 자식이 둘 있음
		if tNode.Llink == None and tNode.Rlink == None:
			return None
		elif tNode.Llink == None:  # case 2(오른쪽 자식 뿐)
			return tNode.Rlink
		elif tNode.Rlink == None: # case 2(왼쪽 자식 뿐)
			return tNode.Llink
		else: # case 3(두 자식이 다 있음)
			(rtnItem, rtnNode) = self.__deleteMinItem(tNode.Rlink)
			tNode.data = rtnItem
			tNode.Rlink = rtnNode
			return tNode

	def __deleteMinItem(self, tNode:DNode) -> tuple:
		if tNode.Llink == None:
			return (tNode.data, tNode.Rlink)
		else:
			(rtnItem, rtnNode) = self.__deleteMinItem(tNode.Llink)
			tNode.Llink = rtnNode
			return (rtnItem, tNode)
		
	# 기타
	def isEmpty(self) -> bool:
		return self.__root == None

	def clear(self):
		self.__root = None

	def printBSTAll(self):
		def _Preorder(tNode):
			if tNode :
				print(tNode.data, end=' ')
				_Preorder(tNode.Llink)
				_Preorder(tNode.Rlink)
		_Preorder(self.__root)

# from BSTree import *
if __name__ == '__main__':
    bst = BSTree()

    bst.insert(10)
    bst.insert(20)
    bst.insert(5)
    bst.insert(80)
    bst.insert(90)
    bst.insert(7550)
    bst.insert(30)
    bst.insert(77)
    bst.insert(15)
    bst.insert(40)
    # bst.printBSTAll()

    bst.delete(7550)
    bst.delete(10)
    # bst.printBSTAll()

