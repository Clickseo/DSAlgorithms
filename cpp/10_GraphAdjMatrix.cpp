/*
	그래프 표현(인접 행렬): 알고리즘 구현
		파일명: GraphAdjMatrix.cpp
			- main: 그래프 생성 및 간선 추가
			클래스: GraphType
				- 그래프 생성.소멸: GraphType, ~GraphType
				- 그래프 간선 추가: insertEdge
				- 그래프 전체 출력: printAdjMatrix
*/

#include <iostream>
using namespace std;

// 클래스 설계: GraphType
class GraphType {
public:
	GraphType(int vertex);
	~GraphType(void);
	void	insertEdge(int row, int col, int weight);
	void	printAdjMatrix(void) const;
private:
	int	vertex_;		// 정점의 개수
	int	**adjMatrix_;	// 인접 행렬
};

// 생성자: 2차원 배열의 동적 메모리 할당
GraphType::GraphType(int vertex): vertex_(vertex) {
}

// 그래프 삭제: 모든 노드 삭제
GraphType::~GraphType(void) {
}

// 간선 추가
void  GraphType::insertEdge(int row, int col, int weight = 1) {
}

// 그래프 전체 출력
void  GraphType::printAdjMatrix(void) const {
}

int main(void)
{
	// G2: 무향 그래프
	GraphType	G2 = GraphType(3);

	// 정점: A(0)
	G2.insertEdge(0, 1, 1);		// A(0) - B(1)
	G2.insertEdge(0, 2, 1);		// A(0) - C(2)

	// 정점: B(1)
	G2.insertEdge(1, 0, 1);		// B(1) - A(0)
	G2.insertEdge(1, 2, 1);		// B(1) - C(2)

	// 정점: C(2)
	G2.insertEdge(2, 1, 1);		// C(2) - B(1)
	G2.insertEdge(2, 0, 1);		// C(2) - A(0)

	cout << "\n##### 그래프(G2): 인접 행렬 #####" << endl;
	G2.printAdjMatrix();


	// G4: 유향 그래프
	GraphType	G4 = GraphType(3);

	// 정점: A(0)
	G4.insertEdge(0, 1, 1);		// A(0) - B(1)
	G4.insertEdge(0, 2, 1);		// A(0) - C(2)

	// 정점: B(1)
	G4.insertEdge(1, 0, 1);		// B(1) - A(0)
	G4.insertEdge(1, 2, 1);		// B(1) - C(2)

	cout << "\n##### 그래프(G4): 인접 행렬 #####" << endl;
	G4.printAdjMatrix();

	return 0;
}
