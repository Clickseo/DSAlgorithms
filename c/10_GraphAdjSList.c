/*
	그래프 표현(인접 리스트): 알고리즘 구현
		파일명: GraphAdjSList.c
			- main	: 그래프 생성 및 간선 추가
			구조체: GNode
			구조체: GraphType
			- 함  수: 그래프 노드 생성	: makeGNode
						그래프 생성.소멸	: graphCreate, graphDestroy
						그래프 간선 추가	: insertEdge
						그래프 전체 출력	: printAdjSList
*/

#include <stdio.h>
#include <stdlib.h>		// malloc, calloc, free

// 그래프(노드): GNode
typedef struct _GNode {
	int				vertex;	// 정점
	int				weight;	// 가중치
	struct _GNode*	link;
} GNode;

// 그래프 노드(C): 그래프 노드 생성
GNode *makeGNode(int vertex, int weight);

// 그래프: GraphType
typedef  struct  _GraphType {
	int		vertex;		// 정점의 개수
	GNode **adjSList;	// 인접 리스트
} GraphType;

// 그래프 구현(C): 그래프 생성 및 활용
GraphType	*graphCreate(int vertex);
GraphType	*graphDestroy(GraphType *Graph);
void	insertEdge(GraphType *Graph, int vertex1, int vertex2, int weight);
void	printAdjSList(GraphType *Graph);

int main(void)
{
	// G2 : 무향 그래프
	GraphType* G2 = graphCreate(3);

	// 정점: A(0)
	insertEdge(G2, 0, 1, 0);	// A(0) - B(1)
	insertEdge(G2, 0, 2, 0);	// A(0) - C(2)

	// 정점: B(1)
	insertEdge(G2, 1, 0, 0);	// B(1) - A(0)
	insertEdge(G2, 1, 2, 0);	// B(1) - C(2)

	// 정점: C(2)
	insertEdge(G2, 2, 1, 0);	// C(2) - B(1)
	insertEdge(G2, 2, 0, 0);	// C(2) - A(0)

	printf("\n##### 그래프(G2): 인접 리스트 #####\n\n");
	printAdjSList(G2);
	G2 = graphDestroy(G2);

	// G4 : 유향 그래프
	GraphType* G4 = graphCreate(3);

	// 정점: A(0)
	insertEdge(G4, 0, 1, 0);	// A(0) - B(1)
	insertEdge(G4, 0, 2, 0);	// A(0) - C(2)

	// 정점: B(1)
	insertEdge(G4, 1, 0, 0);	// B(1) - A(0)
	insertEdge(G4, 1, 2, 0);	// B(1) - C(2)

	printf("\n##### 그래프(G4): 인접 리스트 #####\n\n");
	printAdjSList(G4);
	G4 = graphDestroy(G4);

	return 0;
}

// 그래프 노드 생성
GNode* makeGNode(int vertex, int weight) {
	GNode* newGNode = (GNode*)malloc(sizeof(GNode));
	if (newGNode == NULL) {
		printf("노드 생성 실패!!! \n");
		exit(1);
	}
	newGNode->vertex = vertex;
	newGNode->weight = weight;
	newGNode->link = NULL;
	return newGNode;
}

// 그래프 생성
GraphType* graphCreate(int vertex) {
	GraphType *G = (GraphType*)malloc(sizeof(GraphType));
	if (G == NULL) {
		printf("그래프 생성 실패!!! \n");
		exit(1);
	}
	G->vertex = vertex;
	G->adjSList = (GNode**)calloc(vertex + 1, sizeof(GNode*));
	return G;
}

// 그래프 삭제
GraphType *graphDestroy(GraphType *G) {
	GNode *old;
	for (int i = 0; i < G->vertex; ++i) {
		old = G->adjSList[i];
		while (old) {
			G->adjSList[i] = old->link;
			free(old);
			old = G->adjSList[i];
		}
	}
	free(G->adjSList);
	return NULL;
}

// 그래프 간선 추가
void  insertEdge(GraphType* G, int row, int col, int weight) {
	if (row >= G->vertex || col >= G->vertex) {
		// printf("그래프에 없는 정점입니다!!!\n");
		return;
	}

	GNode* newGNode = makeGNode(col, weight);
	if (G->adjSList[row] == NULL) {
		G->adjSList[row] = newGNode;
	}
	else {
		GNode* rNode = G->adjSList[row];
		while (rNode->link) {
			rNode = rNode->link;
		}
		rNode->link = newGNode;
	}
}

// 그래프 전체 출력
void  printAdjSList(GraphType* G) {
	if (G->adjSList == NULL) {
		printf("그래프의 정점이 %d 입니다.\n", G->vertex);
		return;
	}

	for (int i = 0; i < G->vertex; ++i) {
		printf("\t정점 %c의 인접 리스트: ", i + 65);
		GNode* tNode = G->adjSList[i];
		while (tNode) {
			printf("%3c ->", tNode->vertex + 65);
			tNode = tNode->link;
		}
		printf(" NULL\n");
	}
}
