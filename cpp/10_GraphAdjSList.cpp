/*
	그래프 표현(인접 리스트): 알고리즘 구현
		파일명: GraphAdjSList.cpp
			- main: 그래프 생성 및 간선 추가
			클래스: GNode
			클래스: GraphType
				- 그래프 생성.소멸: GraphType, ~GraphType
				- 그래프 간선 추가: insertEdge
				- 그래프 전체 출력: printAdjSList
*/

#include <iostream>
using namespace std;

// 클래스 설계: GNode
class GNode {
public:
	GNode(int vertex, int weight);
private:
	int		vertex_;	// 정점
	int		weight_;	// 가중치
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
private:
	int		numVertex_;		// 정점 개수
	GNode	**adjSList_;	// 인접 리스트
};

// 빈 그래프 생성
GraphType::GraphType(int vertex): numVertex_(vertex) {
	adjSList_ = new GNode * [vertex + 1];
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

	cout << "\n##### 그래프(G2): 인접 리스트 #####" << endl;
	G2.printAdjSList();

	// G4: 유향 그래프
	GraphType	G4 = GraphType(3);

	// 정점: A(0)
	G4.insertEdge(0, 1, 1);		// A(0) - B(1)
	G4.insertEdge(0, 2, 1);		// A(0) - C(2)

	// 정점: B(1)
	G4.insertEdge(1, 0, 1);		// B(1) - A(0)
	G4.insertEdge(1, 2, 1);		// B(1) - C(2)

	cout << "\n##### 그래프(G4): 인접 리스트 #####" << endl;
	G4.printAdjSList();

	return 0;
}
