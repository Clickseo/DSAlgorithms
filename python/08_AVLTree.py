class AVLNode:
	def __init__(self, newItem, left, right, h):
 		self.item = newItem
 		self.left = left
 		self.right = right
 		self.height = h

class AVLTree:
    def __init__(self):
        self.NIL = AVLNode(None, None, None, 0)
        self.__root = self.NIL
        self.LL = 1; self.LR = 2; self.RR = 3; self.RL = 4
        self.NO_NEED = 0;
        self.ILLEGAL = -1

    def search(x):
        return __searchItem(self.__root, x)   	
    def __searchItem(self, tNode:AVLNode, x) -> AVLNode:
        if tNode == self.NIL:
            return self.NIL
        elif x == tNode.item:
            return tNode
        elif x < tNode.item:
            return __searchItem(tNode.left, x)
        else:
            return __searchItem(tNode.right, x)

    def insert(self, x):
    def __insertItem(self, tNode:AVLNode, x) -> AVLNode:
      
    def delete(self, x):
        self.__root = self.__deleteItem(self.__root, x)   
    def __deleteItem(self, tNode:AVLNode, x) -> AVLNode:
        if tNode == self.NIL:
            return self.NIL	# item not found!
        else:
            if x == tNode.item: # item found at tNode
                tNode = self.__deleteNode(tNode)
            elif x < tNode.item:
                tNode.left = self.__deleteItem(tNode.left, x)
                tNode.height = 1 + max(tNode.right.height, tNode.left.height)
                type = self.__needBalance(tNode)
                if type != self.NO_NEED:
                    tNode = self.__balanceAVL(tNode, type)
            else:
                tNode.right = self.__deleteItem(tNode.right, x)
                tNode.height = 1 + max(tNode.right.height, tNode.left.height)
                type = self.__needBalance(tNode)
                if type != self.NO_NEED:
                    tNode = self.__balanceAVL(tNode, type)
            return tNode
  
    def __deleteNode(self, tNode:AVLNode) -> AVLNode:
        # 3가지 case
        #     1. tNode이 리프 노드
        #     2. tNode이 자식이 하나만 있음
        #     3. tNode이 자식이 둘 있음
        if tNode.left == self.NIL and tNode.right == self.NIL: # case 1(자식이 없음)
            return self.NIL
        elif tNode.left == self.NIL:  # case 2(오른쪽 자식뿐)
            return tNode.right
        elif tNode.right == self.NIL: # case 2(왼쪽 자식뿐)
            return tNode.left
        else: # case 3(두 자식이 다 있음)
            (rtnItem, rtnNode) = self.__deleteMinItem(tNode.right)
            tNode.item = rtnItem
            tNode.right = rtnNode
            tNode.height = 1 + max(tNode.right.height, tNode.left.height)
            type = self.__needBalance(tNode)	
            if type != self.NO_NEED:
                tNode = self.__balanceAVL(tNode, type)
            return tNode  # tNode survived

    def __deleteMinItem(self, tNode:AVLNode) -> tuple:
        if tNode.left == self.NIL:
            # found min at tNode
            return (tNode.item, tNode.right)
        else: # keep branching left, then backtrack
            (rtnItem, rtnNode) = self.__deleteMinItem(tNode.left)
            tNode.left = rtnNode
            tNode.height = 1 + max(tNode.right.height, tNode.left.height) 
            type = self.__needBalance(tNode)
            if type != self.NO_NEED:
                tNode = self.__balanceAVL(tNode, type)
            return (tNode, rtnItem)
 	
    def __needBalance(self, t:AVLNode) -> int:
    def __balanceAVL(self, tNode:AVLNode, type:int) -> AVLNode:
    def __leftRotate(self, t:AVLNode) -> AVLNode:
    def __rightRotate(self, t:AVLNode) -> AVLNode:
      
    # 기타
    def isEmpty(self) -> bool:
        return self.__root == self.NIL
 
    def clear(self):
        self.__root = self.NIL

      
if __name__ == '__main__’:
    bst1 = AVLTree()
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
