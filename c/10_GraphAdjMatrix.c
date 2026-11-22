/*
	그래프 표현(인접 행렬): 알고리즘 구현
		파일명: GraphAdjMatrix.c
			- main	: 그래프 생성 및 간선 추가
			- 구조체: GraphType
			- 함  수: 그래프 생성.소멸	: graphCreate, graphDestroy
						그래프 간선 추가	: insertEdge
						그래프 전체 출력	: printAdjSList
*/

#include <stdio.h>
#include <stdlib.h>		// malloc, calloc, free

// 그래프: GraphType
typedef  struct _GraphType {
	int	vertex;			// 정점의 개수
	int	**adjMatrix;	// 인접 행렬
} GraphType;

// 그래프(GraphType) 생성 및 활용
GraphType	*graphCreate(int vertex);
void	graphDestroy(GraphType *Graph);
void	insertEdge(GraphType *Graph, int vertex1, int vertex2, int weight);
void	printAdjMatrix(GraphType *Graph);

int main(void)
{
	// G2: 무향 그래프
	GraphType	*G2 = graphCreate(3);

	// 정점: A(0)
	insertEdge(G2, 0, 1, 1);	// A(0) - B(1)
	insertEdge(G2, 0, 2, 1);	// A(0) - C(2)

	// 정점: B(1)
	insertEdge(G2, 1, 0, 1);	// B(1) - A(0)
	insertEdge(G2, 1, 2, 1);	// B(1) - C(2)

	// 정점: C(2)
	insertEdge(G2, 2, 1, 1);	// C(2) - B(1)
	insertEdge(G2, 2, 0, 1);	// C(2) - A(0)

	printf("\n##### 그래프(G2): 인접 행렬 #####\n");
	printAdjMatrix(G2);
	graphDestroy(G2);

	// G4: 유향 그래프
	GraphType *G4 = graphCreate(3);

	// 정점: A(0)
	insertEdge(G4, 0, 1, 1);	// A(0) - B(1)
	insertEdge(G4, 0, 2, 1);	// A(0) - C(2)

	// 정점: B(1)
	insertEdge(G4, 1, 0, 1);	// B(1) - A(0)
	insertEdge(G4, 1, 2, 1);	// B(1) - C(2)

	printf("\n##### 그래프(G4): 인접 행렬 #####\n");
	printAdjMatrix(G4);
	graphDestroy(G4);

	return 0;
}

// 그래프 생성: 2차원 배열 동적 메모리 할당
GraphType *graphCreate(int vertex) {
	GraphType* G = (GraphType*)malloc(sizeof(GraphType));
	if (G == NULL) {
		printf("그래프 생성 실패!!! \n");
		exit(1);
	}
	G->vertex = vertex;

	// 인접 행렬: 2차원 배열 동적 메모리 할당
	G->adjMatrix = (int**)calloc(vertex + 1, sizeof(int*));
	for (int i = 0; i < vertex; ++i) {
		G->adjMatrix[i] = (int*)calloc(vertex, sizeof(int));
	}
	return G;
}

// 그래프 삭제: 2차원 배열 동적 메모리 할당
void	graphDestroy(GraphType *G) {
	for (int i = 0; i < G->vertex; ++i) {
		free(G->adjMatrix[i]);
	}
	free(G->adjMatrix);
	G->vertex = 0;
}

// 간선 추가: 특정 행과 열의 가중치
void  insertEdge(GraphType* G, int row, int col, int weight) {
	if (row >= G->vertex || col >= G->vertex) {
		// printf("그래프에 없는 정점입니다!!!\n");
		return;
	}
	G->adjMatrix[row][col] = weight;
}

// 그래프 전체 출력: 2차원 배열 동적 메모리 할당
void  printAdjMatrix(GraphType* G) {
	for (int i = 0; i < G->vertex; ++i) {
		printf("\n\t");
		for (int j = 0; j < (G->vertex); ++j) {
			printf("%3d", G->adjMatrix[i][j]);
		}
	}
	printf("\n");
}
