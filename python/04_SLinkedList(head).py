'''
	단순 연결 리스트: 알고리즘 구현(py)
		파일명: SLinkedList(head).py
			- 클래스: SNode
			- 클래스: SLinkedList
				생성자와 소멸자         : __init__, __del__
				노드 확인               : isEmpty, countNode
				노드 탐색               : frontNode, rearNode
				노드 삽입.삭제          : addRear, removeFront
				전체 원소(노드) 출력    : printLinkedList
'''

# 노드(SNode): 데이터(data), 링크(link)
class SNode:
    def __init__(self, data):
        self.__data = data
        self.__link = None
    def getData(self):          return self.__data
    def getLink(self):          return self.__link
    def setData(self, data):    self.__data = data
    def setLink(self, link):    self.__link = link

# 단순 연결 리스트: SLinkedList(head)
class SLinkedList:
    def __init__(self): 		# 생성자
        self.__head = None		# 첫 번째 노드
	    # self.__tail = None	# 맨 마지막 노드
        # self.__count = 0		# 노드의 총 개수

   # 소멸자: 전체 노드 삭제
    def __del__(self):
        # while not self.isEmpty():
        #     self.removeFront()       
        while not self.isEmpty():
            old = self.__head
            self.__head = old.getLink()
            del old

    # 빈 리스트 여부 판단
    def isEmpty(self) -> bool:
        return self.__head == None

    # 탐색: 노드의 총 개수(count)
    def countNode(self) -> int:
        if self.isEmpty():
            return 0
        
        count = 0
        rNode = self.__head
        while rNode:
            count +=1
            rNode = rNode.getLink()
        return count

    # 탐색: 첫 번째 노드
    def frontNode(self) -> SNode:
        # if self.isEmpty():
        #     return None
        return self.__head

    # 탐색: 맨 마지막 노드
    def rearNode(self) -> SNode:
        # if self.isEmpty():
        #     return None
        rNode = self.__head
        while rNode.getLink():
            rNode = rNode.getLink()
        return rNode

    # 삽입: 맨 마지막 노드
    def addRear(self, num) -> None:
        newNode = SNode(num)
        if self.isEmpty():
            self.__head = newNode
        else:
            rNode = self.rearNode()
            rNode.setLink(newNode)

    # 삭제: 첫 번째 노드
    def removeFront(self) -> None:
        if self.isEmpty():
            return
        
        old = self.__head
        self.__head = old.getLink()
        del old

    # 리스트의 전체 노드 출력
    def printLinkedList(self) -> None:
        if self.isEmpty():
            print('입력된 데이터가 없습니다!!!')
            return
        
        print('\n### 입력된 데이터 ###')
        temp = self.__head
        while temp:
            print(f'{temp.getData()} ->>', end=' ')
            temp = temp.getLink()
        print(' NULL')

if __name__ == '__main__':
    sList = SLinkedList()     # head = None

    while (True):
        num = int(input('임의의 정수 입력(종료: 0): '))
        if num == 0:
            break
    
        # 맨 마지막 노드로 삽입
        sList.addRear(num)

    # 전체 원소 출력
    sList.printLinkedList()
    # del sList     # sList.__del__()
