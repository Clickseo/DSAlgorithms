/*
	그래프 표현(인접 리스트): 알고리즘 구현
		파일명: GraphAdjSListTraversal.cpp
			- main: 그래프 생성 및 간선 추가
			클래스: GNode
			클래스: GraphType
				- 그래프 생성.소멸: GraphType, ~GraphType
				- 그래프 간선 추가: insertEdge
				- 그래프 전체 출력: printAdjSList
				- 그래프 순회(DFS, BFS): DFSAdjSList, BFSAdjSList
*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// 클래스 설계: GNode
class GNode {
public:
	GNode(int vertex, int weight);
private:
	int	vertex_;	// 정점
	int	weight_;	// 가중치
	GNode	*link_;
	friend class GraphType;
};

// 노드 생성
GNode::GNode(int vertex = 0, int weight = 0)
	: vertex_(vertex), weight_(weight), link_(nullptr) {}

// 클래스 설계: GraphType
class GraphType {
public:
	GraphType(int vertex);
	~GraphType(void);
	void	insertEdge(int vertex1, int vertex2, int weight);
	void	printAdjSList(void) const;
	void	DFSAdjSList(int vertex) const;
	void	BFSAdjSList(int vertex) const;
private:
	int	numVertex_;	// 정점 개수
	GNode	**adjSList_;	// 인접 리스트
};

// 빈 그래프 생성
GraphType::GraphType(int vertex) : numVertex_(vertex) {
	adjSList_ = new GNode*[vertex + 1];
	memset(adjSList_, 0, sizeof(GNode*) * (vertex + 1));
}

// 그래프 간선 추가
void  GraphType::insertEdge(int row, int col, int weight) {
	if (row >= numVertex_ || col >= numVertex_) {
		// cout << "그래프에 없는 정점입니다!!!" << endl;
		return;
	}

	// 새로운 노드 생성과 간선 추가
	GNode	*newGNode = new GNode(col, weight);
	if (adjSList_[row] == nullptr) {
		adjSList_[row] = newGNode;
	}
	else {
		GNode	*rNode = adjSList_[row];
		while (rNode->link_)
			rNode = rNode->link_;
		rNode->link_ = newGNode;
	}
}

// 그래프 전체 출력
void  GraphType::printAdjSList(void) const {
	char	ch;
	GNode	*tNode = nullptr;
	for (int i = 0; i < numVertex_; ++i) {
		ch = i + 65;
		cout << "\t정점 " << ch << "의 인접 리스트";
		tNode = adjSList_[i];
		while (tNode) {
			cout.width(3);
			ch = tNode->vertex_ + 65;
			cout << ch << " ->>";
			tNode = tNode->link_;
		}
		cout << " NULL" << endl;
	}
}

// 그래프 삭제: 모든 노드 삭제
GraphType::~GraphType(void) {
	GNode	*tNode = nullptr;
	for (int i = 0; i < numVertex_; ++i) {
		tNode = adjSList_[i];
		while (tNode) {
			adjSList_[i] = tNode->link_;
			delete tNode;
			tNode = adjSList_[i];
		}
	}
	delete[] adjSList_;
}

// 그래프 순회: 깊이 우선 탐색(DFS)
void  GraphType::DFSAdjSList(int vertex) const {
}

// 그래프 순회: 너비 우선 탐색(BFS)
void	GraphType::BFSAdjSList(int  vertex) const {
}

int main(void)
{
	// G9: 무향 그래프
	GraphType	G9 = GraphType(7);

	// 정점: A(0)
	G9.insertEdge(0, 1, 1);		// A(0) - B(1)
	G9.insertEdge(0, 2, 1);		// A(0) - C(2)

	// 정점: B(1)
	G9.insertEdge(1, 0, 1);		// B(1) - A(0)
	G9.insertEdge(1, 3, 1);		// B(1) - D(3)
	G9.insertEdge(1, 4, 1);		// B(1) - E(4)

	// 정점: C(2)
	G9.insertEdge(2, 0, 1);		// C(2) - A(0)
	G9.insertEdge(2, 4, 1);		// C(2) - E(4)

	// 정점: D(3)
	G9.insertEdge(3, 1, 1);		// D(3) - B(6)
	G9.insertEdge(3, 6, 1);		// D(3) - G(6)

	// 정점: E(4)
	G9.insertEdge(4, 1, 1);		// E(4) - B(1)
	G9.insertEdge(4, 2, 1);		// E(4) - C(2)
	G9.insertEdge(4, 6, 1);		// E(4) - G(6)

	// 정점: F(5)
	G9.insertEdge(5, 6, 1);		// F(5) - G(6)

	// 정점: G(6)
	G9.insertEdge(6, 3, 1);		// G(6) - D(3)
	G9.insertEdge(6, 4, 1);		// G(6) - E(4)
	G9.insertEdge(6, 5, 1);		// G(6) - F(5)

	cout << "\n##### 그래프(G9): 인접 리스트 #####\n" << endl;
	G9.printAdjSList();

	printf("\n##### 그래프(G9): 깊이 우선 탐색(DFS) #####\n\n");
	G9.DFSAdjSList(0);

	printf("\n##### 그래프(G9): 너비 우선 탐색(BFS) #####\n\n");
	G9.BFSAdjSList(0);

	return 0;
}
