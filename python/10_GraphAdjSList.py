'''
	그래프 표현(인접 리스트): 알고리즘 구현
		파일명: GraphAdjSList.py
			- __main__	: 그래프 생성 및 간선 추가
			- 클래스    : GNode
			- 클래스    : GraphType
                        	그래프 생성.소멸 : __init__, __del__
                        	그래프 간선 추가 : insertEdge
                        	그래프 전체 출력 : printAdjSList
'''

# GNode class
class GNode :
    def __init__(self, vertex: int, weight = 0) :
        self.vertex = vertex    # 정점
        self.weight = weight    # 차수
        self.link = None

# GraphType class
class GraphType :
    def __init__(self, vertex: int) :
        self.__vertex = vertex  # 정점의 개수
        self.__adjSList = []    # 인접 리스트
        for i in range(self.__vertex) :
           self.__adjSList.append(None)

    def __del__(self):
        for i in range(len(self.__adjSList)) :
            temp = self.__adjSList[i]
            while temp :
                self.__adjSList[i] = temp.link
                del temp
                temp = self.__adjSList[i]
        del self
        
    # insertEdge : 간선 추가
    def insertEdge(self, row:int, col:int, weight:int) :
        if row >= self.__vertex or col >= self.__vertex :
		    # print('그래프에 없는 정점입니다!!!')
            return
        if self.__adjSList[row] == None : 
            self.__adjSList[row] = GNode(col, weight)
        else :
            rNode = self.__adjSList[row]
            while rNode.link :
                rNode = rNode.link
            rNode.link = GNode(col, weight)

    # printAdjMatrix : 그래프 전체 출력
    def printAdjSList(self) :
        for i in range(self.__vertex) :
            print(f'\t정점 {chr(i+65)}의 인접 리스트: ', end='')
            tNode = self.__adjSList[i]
            while tNode :
                print(f'{chr(tNode.vertex + 65)} -> ', end='')
                tNode = tNode.link
            print(' NULL')

if __name__ == '__main__' :
    # G2 : 무향 그래프
    G2 = GraphType(3)

    # 정점: A(0)
    G2.insertEdge(0, 1, 0)	# A(0) - B(1)
    G2.insertEdge(0, 2, 0)	# A(0) - C(2)

    # 정점: B(1)
    G2.insertEdge(1, 0, 0)	# B(1) - A(0)
    G2.insertEdge(1, 2, 0)	# B(1) - C(2)

    # 정점: C(2)
    G2.insertEdge(2, 1, 0)	# C(2) - B(1)
    G2.insertEdge(2, 0, 0)	# C(2) - A(0)

    print('\n##### 그래프(G2): 인접 리스트 #####\n')
    G2.printAdjSList()

    # G4 : 유향 그래프
    G4 = GraphType(3)

    # 정점(A)
    G4.insertEdge(0, 1, 0)	# A(0) - B(1)
    G4.insertEdge(0, 2, 0)	# A(0) - C(2)

    # 정점(B)
    G4.insertEdge(1, 0, 0)	# B(1) - A(0)
    G4.insertEdge(1, 2, 0)	# B(1) - C(2)

    print('\n##### 그래프(G4): 인접 리스트 #####\n');
    G4.printAdjSList()

