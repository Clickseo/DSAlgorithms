'''
	그래프 표현(인접 리스트): 알고리즘 구현
		파일명: GraphAdjSList.py
			- __main__: 그래프 생성 및 간선 추가
			- 클래스: GraphType
                    		그래프 생성.소멸: __init__, __del__
                    		그래프 간선 추가: insertEdge
                    		그래프 전체 출력: printAdjSList
'''

# GraphType class
class GraphType:
    class GNode:
        def __init__(self, vertex: int, weight = 0):
            self.vertex = vertex    # 정점
            self.weight = weight    # 차수
            self.link = None

    def __init__(self, vertex: int) :
        self.__vertex = vertex                              # 정점의 개수  
        self.__adjSList = [ None for x in range(vertex) ]   # 인접 리스트

    # 그래프 삭제: 전체 노드 삭제
    def __del__(self):
        pass
        
    # insertEdge: 간선 추가
    def insertEdge(self, row:int, col:int, weight:int):
        pass
      
    # printAdjMatrix: 그래프 전체 출력
    def printAdjSList(self):
        pass

if __name__ == '__main__' :
    # G2: 무향 그래프
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

    print('\n##### 그래프(G2): 인접 리스트 #####\n')
    G2.printAdjSList()

    # G4: 유향 그래프
    G4 = GraphType(3)

    # 정점: A(0)
    G4.insertEdge(0, 1, 1)	# A(0) - B(1)
    G4.insertEdge(0, 2, 1)	# A(0) - C(2)

    # 정점: B(1)
    G4.insertEdge(1, 0, 1)	# B(1) - A(0)
    G4.insertEdge(1, 2, 1)	# B(1) - C(2)

    print('\n##### 그래프(G4): 인접 리스트 #####\n')
    G4.printAdjSList()
	
'''
if __name__ == '__main__' :
    # G9 : 무향 그래프
    G9 = GraphType(7)

    # 정점: A(0)
    G9.insertEdge(0, 1, 1)    # A(0) - B(1)
    G9.insertEdge(0, 2, 1)    # A(0) - C(2)

    # 정점: B(1)
    G9.insertEdge(1, 0, 1)    # B(1) - A(0)
    G9.insertEdge(1, 3, 1)    # B(1) - D(3)
    G9.insertEdge(1, 4, 1)    # B(1) - E(4)

    # 정점: C(2)
    G9.insertEdge(2, 0, 1)    # C(2) - A(0)
    G9.insertEdge(2, 4, 1)    # C(2) - E(4)

    # 정점: D(3)
    G9.insertEdge(3, 1, 1)    # D(3) - B(6)
    G9.insertEdge(3, 6, 1)    # D(3) - G(6)

    # 정점: E(4)
    G9.insertEdge(4, 1, 1)    # E(4) - B(1)
    G9.insertEdge(4, 2, 1)    # E(4) - C(2)
    G9.insertEdge(4, 6, 1)    # E(4) - G(6)

    # 정점: F(5)
    G9.insertEdge(5, 6, 1)    # F(5) - G(6)

    # 정점: G(6)
    G9.insertEdge(6, 3, 1)    # G(6) - D(3)
    G9.insertEdge(6, 4, 1)    # G(6) - E(4)
    G9.insertEdge(6, 5, 1)    # G(6) - F(5)

    print('\n##### 그래프(G9): 인접 리스트 #####\n')
    G9.printAdjSList()

    print('\n##### 그래프(G9): 깊이 우선 탐색(DFS) #####\n')
    G9.DFSAdjSList(0)

    print('\n##### 그래프(G9): 너비 우선 탐색(BFS) #####\n')
    G9.DFSAdjSList(0)
'''

