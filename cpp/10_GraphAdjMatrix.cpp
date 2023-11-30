/*
	그래프 표현(인접 행렬): 알고리즘 구현
		파일명: GraphAdjMatrix.cpp
			- main	: 그래프 생성 및 간선 추가
			클래스	: GraphType
				- 그래프 생성.소멸: GraphType, ~GraphType
				- 그래프 간선 추가: insertEdge
				- 그래프 전체 출력: printAdjMatrix
*/

#include <iostream>
using namespace std;

// GraphType class
class GraphType {
private:
	int	__vertex;	// 정점의 개수
	int	**__adjMatrix;	// 인접 행렬
public:
	GraphType(int vertex);
	~GraphType(void);
	void	insertEdge(int vertex1, int vertex2, int weight);
	void	printAdjMatrix(void) const;
};

// GraphType: 생성자(소멸자)와 메소드 정의
GraphType::GraphType(int vertex) : __vertex(vertex) {
	// 인접 행렬: 2차원 배열 동적 메모리 할당
	__adjMatrix = new int*[vertex+1];
	for (int i = 0; i < vertex; i++) {
		__adjMatrix[i] = new int[vertex];
		memset(__adjMatrix[i], 0, sizeof(int) * vertex);
	}
	__adjMatrix[vertex] = nullptr;
}

// graphDestroy: 그래프 삭제
GraphType::~GraphType(void) {
	for (int i = 0; i < __vertex; i++)
		delete[] __adjMatrix[i];
	delete[] __adjMatrix;
	__vertex = 0;
}

// insertEdge: 간선 추가
void  GraphType::insertEdge(int  row, int  col, int weight = 1) {
	if (row >= __vertex || col >= __vertex) {
		// cout << "그래프에 없는 정점입니다!!!" << endl;
		return;
	}
	__adjMatrix[row][col] = weight;
}

// printAdjMatrix: 그래프 전체 출력
void  GraphType::printAdjMatrix(void) const {
	for (int i = 0; i < __vertex; i++) {
		cout << "\n\t";
		for (int j = 0; j < __vertex; j++) {
			cout.width(3);
			cout << __adjMatrix[i][j];
		}
	}
	cout << endl;
}

int main(void)
{
	// G2: 무향 그래프
	GraphType	G2 = GraphType(3);

	// 정점: A(0)
	G2.insertEdge(0, 1, 1);	// A(0) - B(1)
	G2.insertEdge(0, 2, 1);	// A(0) - C(2)

	// 정점: B(1)
	G2.insertEdge(1, 0, 1);	// B(1) - A(0)
	G2.insertEdge(1, 2, 1);	// B(1) - C(2)

	// 정점: C(2)
	G2.insertEdge(2, 1, 1);	// C(2) - B(1)
	G2.insertEdge(2, 0, 1);	// C(2) - A(0)

	cout << "\n##### 그래프(G2): 인접 행렬 #####" << endl;
	G2.printAdjMatrix();

	// G4: 유향 그래프
	GraphType	G4 = GraphType(3);

	// 정점(A)
	G4.insertEdge(0, 1, 1);	// A(0) - B(1)
	G4.insertEdge(0, 2, 1);	// A(0) - C(2)

	// 정점(B)
	G4.insertEdge(1, 0, 1);	// B(1) - A(0)
	G4.insertEdge(1, 2, 1);	// B(1) - C(2)

	cout << "\n##### 그래프(G4): 인접 행렬 #####" << endl;
	G4.printAdjMatrix();

	return 0;
}
