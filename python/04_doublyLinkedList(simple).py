/*
	이중 연결 리스트: 알고리즘 구현
		- DNode		: 노드(data, Llink, Rlink)
		- DLinkedList	: head
*/

class DNode:
    # def __init__(self, data, Llink:'SNode', Rlink:'SNode'):
    def __init__(self, data):
        self.__data = data
        self.__Llink = None
        self.__Rlink = None
    def getData(self): return self.__data            # getattr(DNode, '__data')
    def getLlink(self): return self.__Llink          # getattr(DNode, '__Llink')
    def getRlink(self): return self.__Rlink          # getattr(DNode, '__Rlink')
    def setData(self, data): self.__data = data      # setattr(DNode, '__data', 'data')
    def setLlink(self, Llink): self.__Llink = Llink  # setattr(DNode, '__Llink', 'Llink')
    def setRlink(self, Rlink): self.__Rlink = Rlink  # setattr(DNode, '__Rlink', 'Rlink')

class DLinkedList:
    def __init__(self):          # 생성자
        self.__head = None       # 첫 번째 노드
        # self.__head = DNode('dummy', None)
        # self.__tail = None     # 맨 마지막 노드
        # self.__count = 0       # 노드의 총 개수

    # 빈 리스트 여부 판단
    def isEmpty(self) -> bool:
        return self.__head == None

    # 탐색: 노드의 총 개수(count)
    def countDNode(self) -> int:
        if self.isEmpty() : return 0
        count = 0
        rNode = self.__head
        while rNode.getRlink():
            count +=1
            rNode = rNode.getRlink()
        return count

    # 탐색: 첫 번째 노드
    def frontDNode(self) -> DNode:
        if self.isEmpty() : return None
        return self.__head

    # 탐색: 맨 마지막 노드
    def rearDNode(self) -> DNode:
        if self.isEmpty() : return None
        rNode = self.__head
        while rNode.getRlink() :
            rNode = rNode.getRlink()
        return rNode

    # 삽입: 맨 마지막 노드
    def addRear(self, num):
        nNode = DNode(num)
        if self.isEmpty() : self.__head = nNode
        else :
            rNode = self.rearDNode()
            rNode.setRlink(nNode)
            nNode.setLlink(rNode)
            
    # 삭제: 첫 번째 노드
    def removeFront(self) -> None:
        if self.isEmpty() : return
        old = self.__head
        self.__head = old.getRlink()
        if not old.getRlink() :
            old.getRlink().setLlink(None)
        del old

    # 소멸자: 전체 노드 삭제
    def __del__(self):
        # if self.isEmpty() : return
        while not self.isEmpty() :
            self.removeFront()

    # 리스트의 전체 노드 출력(순방향)
    def printDLinkedList(self):
        if self.isEmpty() : return
        temp = self.__head
        while temp :
            print(f'{temp.getData()} ->>', end=' ')
            temp = temp.getRlink()
        print(' NULL')
        
    # 리스트의 전체 노드 출력(역방향)
    def revPrintDLinkedList(self):
        if self.isEmpty() : return
        temp = self.rearDNode()
        while temp :
            print(f'{temp.getData()} ->>', end=' ')
            temp = temp.getLlink()
        print(' NULL')

if __name__ == '__main__' :
    s = DLinkedList()     # 생성자 메소드 호출 됨.
    while (True):
        num = int(input('임의의 정수 입력(종료: 0): '))
        if num == 0 :
            break
        s.addRear(num)    # 맨 마지막 노드로 삽입

	# 전체 원소 출력
    if s.isEmpty() : print('입력된 데이터가 없습니다...')
    else :
        print('\n### 입력된 데이터 ###')
        s.printDLinkedList()
        s.revPrintDLinkedList()
    del s    # 소멸자 메소드를 호출: s.__del__()
