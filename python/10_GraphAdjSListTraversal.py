# GNode class
class GNode :
    def __init__(self, vertex: int, weight = 0):
        self.vertex = vertex    # 정점
        self.weight = weight    # 차수
        self.link = None

# GraphType class
class GraphType :
    def __init__(self, vertex: int):
        self.__vertex = vertex                              # 정점의 개수  
        self.__adjSList = [ None for x in range(vertex) ]   # 인접 리스트

    def __del__(self):
        for i in range(len(self.__adjSList)):
            temp = self.__adjSList[i]
            while temp :
                self.__adjSList[i] = temp.link
                del temp
                temp = self.__adjSList[i]

    # 그래프 간선 추가
    def insertEdge(self, row:int, col:int, weight:int):
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

    # 그래프 전체 출력
    def printAdjSList(self):
        for i in range(self.__vertex) :
            print(f'\t정점 {chr(i+65)}의 인접 리스트: ', end='')
            tNode = self.__adjSList[i]
            while tNode :
                print(f'{chr(tNode.vertex + 65)} -> ', end='')
                tNode = tNode.link
            print(' NULL')

    # 그래프 순회: 깊이 우선 탐색(DFS)
    def DFSAdjSList(self, vertex:int):

    # 그래프 순회: 너비 우선 탐색(BFS)
    def	 BFSAdjSList(self, vertex: int):       

if __name__ == '__main__' :
    # G9 : 무향 그래프
    G9 = GraphType(7)

    # 정점: A(0)
    G9.insertEdge(0, 1, 0)    # A(0) - B(1)
    G9.insertEdge(0, 2, 0)    # A(0) - C(2)

    # 정점: B(1)
    G9.insertEdge(1, 0, 0)    # B(1) - A(0)
    G9.insertEdge(1, 3, 0)    # B(1) - D(3)
    G9.insertEdge(1, 4, 0)    # B(1) - E(4)

    # 정점: C(2)
    G9.insertEdge(2, 0, 0)    # C(2) - A(0)
    G9.insertEdge(2, 4, 0)    # C(2) - E(4)

    # 정점: D(3)
    G9.insertEdge(3, 1, 0)    # D(3) - B(6)
    G9.insertEdge(3, 6, 0)    # D(3) - G(6)

        # 정점: E(4)
    G9.insertEdge(4, 1, 0)    # E(4) - B(1)
    G9.insertEdge(4, 2, 0)    # E(4) - C(2)
    G9.insertEdge(4, 6, 0)    # E(4) - G(6)

    # 정점: F(5)
    G9.insertEdge(5, 6, 0)    # F(5) - G(6)

    # 정점: G(6)
    G9.insertEdge(6, 3, 0)    # G(6) - D(3)
    G9.insertEdge(6, 4, 0)    # G(6) - E(4)
    G9.insertEdge(6, 5, 0)    # G(6) - F(5)

    print('\n##### 그래프(G9): 인접 리스트 #####\n')
    G9.printAdjSList()

    print('\n##### 그래프(G9): 깊이 우선 탐색(DFS) #####\n')
    G9.DFSAdjSList(0)

    print('\n##### 그래프(G9): 너비 우선 탐색(BFS) #####\n')
    G9.BFSAdjSList(0)
