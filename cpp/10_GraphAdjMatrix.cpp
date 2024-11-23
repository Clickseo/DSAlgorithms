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
	int		vertex_;		// 정점의 개수
	int		**adjMatrix_;	// 인접 행렬
};

// 생성자
GraphType::GraphType(int vertex): vertex_(vertex) {
	// 인접 행렬: 2차원 배열의 동적 메모리 할당
	adjMatrix_ = new int*[vertex+1];		// 포인터 배열
	for (int i = 0; i < vertex; ++i) {
		adjMatrix_[i] = new int[vertex];	// 1차원 배열
		memset(adjMatrix_[i], 0, sizeof(int) * vertex);
	}
	adjMatrix_[vertex] = nullptr;
}

// 그래프 삭제: 모든 노드 삭제
GraphType::~GraphType(void) {
	for (int i = 0; i < vertex_; ++i) {
		delete[] adjMatrix_[i];
	}
	delete[] adjMatrix_;
	// vertex_ = 0;
}

// 간선 추가
void  GraphType::insertEdge(int row, int col, int weight = 1) {
	if (row >= vertex_ || col >= vertex_) {
		// cout << "그래프에 없는 정점입니다!!!" << endl;
		return;
	}
	adjMatrix_[row][col] = weight;
}

// 그래프 전체 출력
void  GraphType::printAdjMatrix(void) const {
	for (int i = 0; i < vertex_; ++i) {
		cout << "\n\t";
		for (int j = 0; j < vertex_; ++j) {
			cout.width(3);
			cout << adjMatrix_[i][j];
		}
	}
	cout << endl;
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
