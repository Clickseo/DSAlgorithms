'''
	이진 트리: 알고리즘 구현
		파일명: BSTree.py
			클래스: TreeNode
			클래스: BinarySearchTree
				- 데이터 검색: search, __searchItem
				- 데이터 삽입: insert, __insertItem
				- 데이터 삭제: delete, __deleteItem, __deleteNode, __deleteMinItem
'''

class TreeNode:
    def __init__(self, newItem, left, right):
        self.item = newItem
        self.left = left
        self.right = right

class BinarySearchTree:
    def __init__(self):
        self.__root = None

    # 이진 탐색 트리(BST): 데이터 검색
    def search(self, x) -> TreeNode:
        return self.__searchItem(self.__root, x)
    def __searchItem(self, tNode:TreeNode, x) -> TreeNode:

    # 이진 탐색 트리(BST): 데이터 삽입
    def insert(self, newItem):
        self.__root = self.__insertItem(self.__root, newItem)
    def __insertItem(self, tNode:TreeNode, newItem) -> TreeNode:

    # 이진 탐색 트리(BST): 데이터 삭제
    def delete(self, x):
        self.__root = self.__deleteItem(self.__root, x)	
    def __deleteItem(self, tNode:TreeNode, x) -> TreeNode:
        if (tNode == None):
             return None		# Error! Item not found
        elif (x == tNode.item):	# item found!
            tNode = self.__deleteNode(tNode)
        elif (x < tNode.item):
            tNode.left = self.__deleteItem(tNode.left, x)
        else:
            tNode.right = self.__deleteItem(tNode.right, x)
        return tNode # tNode: parent에 매달리는 노드

    def __deleteNode(self, tNode:TreeNode) -> TreeNode:
    def __deleteMinItem(self, tNode:TreeNode) -> tuple:

        # 기타
        def isEmpty(self) -> bool:
            return self.__root == self.NIL

        def clear(self):
            self.__root = self.NIL

if __name__ == '__main__':
    bst1 = BinarySearchTree()
    bst1.insert(10)
    bst1.insert(20)
    bst1.insert(5)
    bst1.insert(80)
    bst1.insert(90)
    bst1.insert(7550)
    bst1.insert(30)
    bst1.insert(77)
    bst1.insert(15)
    bst1.insert(40)
    bst1.delete(7550)
    bst1.delete(10)
