# GNode class
class GNode :
    def __init__(self, vertex: int, weight = 0) :
        self.vertex = vertex    # 정점
        self.weight = weight    # 차수
        self.link = None

# GraphType class
class GraphType :
    def __init__(self, vertex: int) :
        self.__vertex = vertex    # 정점의 개수
        self.__adjSList = []      # 인접 리스트

    def insertEdge(self, row:int, col:int, weight:int) :
    def printAdjSList(self) :

if __name__ == '__main__' :
    # G2 : 무향 그래프
    G2 = GraphType(3)

    # 정점: A(0)
    G2.insertEdge(0, 1, 1)	# A(0) - B(1)
    G2.insertEdge(0, 2, 1)	# A(0) - C(2)

    # 정점: B(1)
    G2.insertEdge(1, 0, 1)	# B(1) - A(0)
    G2.insertEdge(1, 2, 1)	# B(1) - C(2)

    # 정점: C(2)
    G2.insertEdge(2, 1, 1)	# C(2) - B(1)
    G2.insertEdge(2, 0, 1)	# C(2) - A(0)

    print('\n##### 그래프(G2): 인접 행렬 #####\n')
    G2.printAdjMatrix()

    # G4 : 유향 그래프
    G4 = GraphType(3)

    # 정점(A)
    G4.insertEdge(0, 1, 1)	# A(0) - B(1)
    G4.insertEdge(0, 2, 1)	# A(0) - C(2)

    # 정점(B)
    G4.insertEdge(1, 0, 1)	# B(1) - A(0)
    G4.insertEdge(1, 2, 1)	# B(1) - C(2)

    print(f'\n##### 그래프(G4): 인접 행렬 #####\n');
    G4.printAdjMatrix()
