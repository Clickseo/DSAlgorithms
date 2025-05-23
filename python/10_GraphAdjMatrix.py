'''
	그래프 표현(인접 행렬): 알고리즘 구현
		파일명: GraphAdjMatrix.py
			- __main__: 그래프 생성 및 간선 추가
			클래스: GraphType
				- 그래프 생성: __init__
				- 간선 추가: insertEdge
				- 전체 출력: printAdjMatrix
'''

# 클래스 설계: GraphType
class GraphType:
    def __init__(self, vertex:int): 
        self.__vertex = vertex		# 정점의 개수
        self.__adjMatrix = []		# 인접 행렬: 2차원 배열
        for i in range(self.__vertex):
            s = []
            for j in range(self.__vertex):
                s.append(0)
            self.__adjMatrix.append(s)

    # insertEdge: 간선 추가
    def insertEdge(self, row:int, col:int, weight:int):
        if row >= self.__vertex or col >= self.__vertex:
            # print('그래프에 없는 정점입니다!!!')
            return
        self.__adjMatrix[row][col] = weight
        
    # printAdjMatrix: 그래프 전체 출력
    def printAdjMatrix(self):
        for i in range(self.__vertex):
            print('\t', end='')
            for j in range(self.__vertex):
                print(f'{self.__adjMatrix[i][j]:3}', end='')
            print('')

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

    print('\n##### 그래프(G2): 인접 행렬 #####\n')
    G2.printAdjMatrix()

    # G4 : 유향 그래프
    G4 = GraphType(3)

    # 정점: A(0)
    G4.insertEdge(0, 1, 1)	# A(0) - B(1)
    G4.insertEdge(0, 2, 1)	# A(0) - C(2)

    # 정점: B(0)
    G4.insertEdge(1, 0, 1)	# B(1) - A(0)
    G4.insertEdge(1, 2, 1)	# B(1) - C(2)

    print('\n##### 그래프(G4): 인접 행렬 #####\n')
    G4.printAdjMatrix()
