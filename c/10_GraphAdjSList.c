/*
	그래프 표현(인접 리스트): 알고리즘 구현
		파일명: GraphAdjSList.c
			- main	: 그래프 생성 및 정점 추가
			- 그래프 생성 및 활용: graphCreate, graphDestroy, insertEdge, printAdjMatrix
*/

#include <stdio.h>
#include <stdlib.h>	// malloc, calloc, free

// 그래프(노드): GNode
typedef struct __GNode {
	int		__vertex;	// 정점
	int		__weight;	// 가중치
	struct __GNode*	__link;
} GNode;

// 그래프 노드(C): 그래프 노드 생성
GNode* makeGNode(int vertex, int weight);

// 그래프: GraphType
typedef  struct  __GraphType {
	int	__vertex;	// 정점의 개수
	GNode** __adjMatrix;	// 인접 리스트
} GraphType;

// 그래프 구현(C): 그래프 생성 및 활용
GraphType* graphCreate(int vertex);
void	graphDestroy(GraphType* G);
void	insertEdge(GraphType* G, int vertex1, int vertex2, int weight);
void	printAdjMatrix(GraphType* G);

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

	printf("\n##### 그래프(G2): 인접 리스트 #####\n");
	printAdjMatrix(G2);
	graphDestroy(G2);

	// G4 : 유향 그래프
	GraphType* G4 = graphCreate(3);

	// 정점: A(0)
	insertEdge(G4, 0, 1, 0);	// A(0) - B(1)
	insertEdge(G4, 0, 2, 0);	// A(0) - C(2)

	// 정점: B(1)
	insertEdge(G4, 1, 0, 0);	// B(1) - A(0)
	insertEdge(G4, 1, 2, 0);	// B(1) - C(2)

	printf("\n##### 그래프(G4): 인접 리스트 #####\n");
	printAdjMatrix(G4);
	graphDestroy(G4);

	return 0;
}

// 그래프 노드(C): 그래프 노드 생성
GNode* makeGNode(int vertex, int weight) {
	GNode* newGNode = (GNode*)malloc(sizeof(GNode));
	if (newGNode == NULL) {
		printf("노드 생성 실패!!! \n");
		exit(1);
	}
	newGNode->__vertex = vertex;
	newGNode->__weight = weight;
	newGNode->__link = NULL;
	return newGNode;
}

// graphCreate : 그래프 생성
GraphType* graphCreate(int vertex) {
	GraphType* G = (GraphType*)malloc(sizeof(GraphType));
	if (G == NULL) {
		printf("그래프 생성 실패!!! \n");
		exit(1);
	}
	G->__vertex = vertex;
	G->__adjMatrix = (GNode**)calloc(vertex + 1, sizeof(GNode*));
	return G;
}

// graphDestroy : 그래프 삭제
void	graphDestroy(GraphType* G) {
	GNode* old;
	for (int i = 0; i < G->__vertex; i++) {
		old = G->__adjMatrix[i];
		while (old) {
			G->__adjMatrix[i] = old->__link;
			free(old);
		}		
	}
	G->__vertex = 0;
}

// insertEdge : 간선 추가
void  insertEdge(GraphType* G, int  row, int  col, int weight) {
	if (row >= G->__vertex || col >= G->__vertex) {
		// printf("그래프에 없는 정점입니다!!!\n");
		return;
	}

	GNode* newGNode = makeGNode(col, weight);
	if (G->__adjMatrix[row] == NULL)
		G->__adjMatrix[row] = newGNode;
	else {
		GNode* rNode = G->__adjMatrix[row];
		while (rNode->__link)
			rNode = rNode->__link;
		rNode->__link = newGNode;
	}
}

// printAdjMatrix : 그래프 전체 출력
void  printAdjMatrix(GraphType* G) {
	if (G->__adjMatrix == NULL) {
		printf("그래프의 정점이 %d 입니다.\n", G->__vertex);
		return;
	}

	for (int i = 0; i < G->__vertex; i++) {
		printf("\n\t정점 %c의 인접 리스트: ", i + 65);
		GNode* tNode = G->__adjMatrix[i];
		while (tNode) {
			printf("%3c ->>", tNode->__vertex + 65);
			tNode = tNode->__link;
		}
	}
	printf(" NULL\n");
}
