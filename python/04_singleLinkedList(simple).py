'''
	단순 연결 리스트: 알고리즘 구현
		- SNode 	: 노드(data, link)
		- SLinkedList	: head
'''

# 노드: 데이터, 링크
class SNode :
    # def __init__(self, data, link:'SNode'):
    def __init__(self, data):
        self.__data = data
        self.__link = None
    def getData(self):  return self.__data
    def getLink(self):  return self.__link
    def setData(self, data):  self.__data = data
    def setLink(self, link):  self.__link = link

# 단순 연결 리스트
class SLinkedList :
    def __init__(self): 		# 생성자
        self.__head = None		# 첫 번째 노드
        # self.__head = SNode('dummy', None)
        # self.__numItems = 0
	# self.__tail = None		# 맨 마지막 노드
        # self.__count = 0		# 노드의 총 개수

    # 빈 리스트 여부 판단
    def isEmpty(self) -> bool:
        return self.__head == None

    # 탐색: 노드의 총 개수(count)
    def countSNode(self) -> int:
        if self.isEmpty() : return 0
        count = 0;
        rNode = self.__head
        while rNode.getLink() :
            count +=1
            rNode = rNode.getLink()
        return count

    # 탐색: 첫 번째 노드
    def frontSNode(self) -> SNode:
        if self.isEmpty() : return None
        return self.__head

    # 탐색: 맨 마지막 노드
    def rearSNode(self) -> SNode:
        if self.isEmpty() : return None
        rNode = self.__head
        while rNode.getLink() :
            rNode = rNode.getLink()
        return rNode

    # 삽입: 맨 마지막 노드
    def addRear(self, num):
        nNode = SNode(num)
        if self.isEmpty() : self.__head = nNode
        else :
            rNode = self.rearSNode()
            rNode.setLink(nNode)

    # 삭제: 첫 번째 노드
    def removeFront(self) -> None:
        if self.isEmpty() : return
        old = self.__head
        self.__head = old.getLink()
        del old

   # 소멸자: 전체 노드 삭제
    def __del__(self):
        if self.isEmpty() : return
        while not self.isEmpty() :
            self.removeFront()

    # 리스트의 전체 노드 출력
    def printSLinkedList(self):
        if self.isEmpty() : return
        temp = self.__head
        while temp :
            print(f'{temp.getData()} ->>', end=' ')
            temp = temp.getLink()
        print(' NULL')

if __name__ == '__main__' :
    s = SLinkedList()     # 생성자 메소드 호출
    while (True):
        num = int(input('임의의 정수 입력(종료: 0): '))
        if num == 0 :
            break
        s.addRear(num)    # 맨 마지막 노드로 삽입

    # 전체 원소 출력
    if s.isEmpty() : print('입력된 데이터가 없습니다...')
    else :
        print('\n### 입력된 데이터 ###')
        s.printSLinkedList()
    del s    # 소멸자 메소드 호출: s.__del__()
