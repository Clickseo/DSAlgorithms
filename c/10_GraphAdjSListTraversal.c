/*
	그래프 표현(인접 리스트): 알고리즘 구현
		파일명: GraphAdjSListTraversal.c
			- main	: 그래프 생성 및 간선 추가
				구조체: GNode
				구조체: GraphType
					그래프 노드 생성	: makeGNode
					그래프 생성.소멸	: graphCreate, graphDestroy
					그래프 간선 추가	: insertEdge
					그래프 순회		: DFSAdjSList, BFSAdjSList
					그래프 전체 출력	: printAdjSList
*/

#include <stdio.h>
#include <stdlib.h>			// malloc, calloc, free
#include <stdbool.h>		// bool, true, false
#include "LinkedStack.h"	// LinkedStack
#include "LinkedQueue.h"	// LinkedQueue

// 그래프 설계: GraphType, GNode
typedef struct _GNode {		// 그래프 노드
	int		vertex;			// 정점
	int		weight;			// 가중치
	struct _GNode* link;
} GNode;

GNode *makeGNode(int vertex, int weight);

typedef  struct  _GraphType {	// 그래프
	int		vertex;				// 정점의 개수
	GNode	**adjSList;			// 인접 리스트
} GraphType;

// 그래프 구현(C): 그래프 생성 및 활용
GraphType *graphCreate(int vertex);
GraphType *graphDestroy(GraphType *Graph);
void	insertEdge(GraphType *Graph, int vertex1, int vertex2, int weight);
void	printAdjSList(GraphType* Graph);

// 그래프 순회: 깊이 우선 탐색(DFS), 너비 우선 탐색(BFS)
void	DFSAdjSList(GraphType *Graph, int vertex);
void	BFSAdjSList(GraphType *Graph, int vertex);

int main(void)
{
	// G9 : 무향 그래프
	GraphType *G9 = graphCreate(7);

	// 정점: A(0)
	insertEdge(G9, 0, 1, 0);	// A(0) - B(1)
	insertEdge(G9, 0, 2, 0);	// A(0) - C(2)

	// 정점: B(1)
	insertEdge(G9, 1, 0, 0);	// B(1) - A(0)
	insertEdge(G9, 1, 3, 0);	// B(1) - D(3)
	insertEdge(G9, 1, 4, 0);	// B(1) - E(4)

	// 정점: C(2)
	insertEdge(G9, 2, 0, 0);	// C(2) - A(0)
	insertEdge(G9, 2, 4, 0);	// C(2) - E(4)

	// 정점: D(3)
	insertEdge(G9, 3, 1, 0);	// D(3) - B(6)
	insertEdge(G9, 3, 6, 0);	// D(3) - G(6)

	// 정점: E(4)
	insertEdge(G9, 4, 1, 0);	// E(4) - B(1)
	insertEdge(G9, 4, 2, 0);	// E(4) - C(2)
	insertEdge(G9, 4, 6, 0);	// E(4) - G(6)

	// 정점: F(5)
	insertEdge(G9, 5, 6, 0);	// F(5) - G(6)

	// 정점: G(6)
	insertEdge(G9, 6, 3, 0);	// G(6) - D(3)
	insertEdge(G9, 6, 4, 0);	// G(6) - E(4)
	insertEdge(G9, 6, 5, 0);	// G(6) - F(5)

	printf("\n##### 그래프(G9): 인접 리스트 #####\n\n");
	printAdjSList(G9);

	printf("\n##### 그래프(G9): 깊이 우선 탐색(DFS) #####\n\n");
	DFSAdjSList(G9, 0);

	printf("\n##### 그래프(G9): 너비 우선 탐색(BFS) #####\n\n");
	BFSAdjSList(G9, 0);

	G9 = graphDestroy(G9);
	return 0;
}

// 그래프 노드 생성
GNode *makeGNode(int vertex, int weight) {
	GNode	*newGNode = (GNode*)malloc(sizeof(GNode));
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
GraphType *graphCreate(int vertex) {
	GraphType	*G = (GraphType*)malloc(sizeof(GraphType));
	if (G == NULL) {
		printf("그래프 생성 실패!!! \n");
		exit(1);
	}
	G->vertex = vertex;
	G->adjSList = (GNode**)calloc(vertex + 1, sizeof(GNode*));
	return G;
}

// 그래프 삭제
GraphType	*graphDestroy(GraphType *G) {
	GNode	*old;
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
void  insertEdge(GraphType *G, int row, int col, int weight) {
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
void  printAdjSList(GraphType *G) {
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

// 그래프 순회: 깊이 우선 탐색(DFS)
void  DFSAdjSList(GraphType *G, int vertex) {
	// 각 정점의 방문(Visited) 여부: true, false
	int	*pVisited = (int*)calloc(G->vertex, sizeof(int));

	LinkedStack	*Stack = stackCreate();
	push(Stack, vertex);			// 시작 정점
	pVisited[vertex] = true;		// 정점 방문
	printf(" %3c", vertex + 65);

	int		v = vertex;
	GNode	*w;
	while (!stackEmpty(Stack)) {
		w = G->adjSList[v];
		while (w) {		// 인접한 정점이 있는 동안...
			// 방문 안한 인접 정점에 대해서 수행
			if (!pVisited[w->vertex]) {
				push(Stack, w->vertex);			// 스택에 PUSH
				pVisited[w->vertex] = true;		// 정점 방문
				printf(" %3c", w->vertex + 65);

				v = w->vertex;
				w = G->adjSList[v];
			}
			else w = w->link;
		}
		// 방문안한 인접 정점이 없으면 스택 pop
		v = top(Stack);		pop(Stack);
	}
	printf("\n");
	stackDestroy(Stack);
}

// 그래프 순회: 너비 우선 탐색(BFS)
void	BFSAdjSList(GraphType *G, int vertex) {
	// 각 정점의 방문(Visited) 여부: true, false
	int	*pVisited = (int*)calloc(G->vertex, sizeof(int));

	LinkedQueue	*Queue = queueCreate();
	enQueue(Queue, vertex);			// 시작 정점
	pVisited[vertex] = true;		// 정점 방문
	printf(" %3c", vertex + 65);	// 정점 방문

	int		v = vertex;
	GNode	*w;
	while (!queueEempty(Queue)) {
		v = front(Queue);	deQueue(Queue);
		w = G->adjSList[v];
		while (w) {		// 인접한 정점이 있는 동안...
			// 방문 안한 인접 정점에 대해서 수행
			if (!pVisited[w->vertex]) {
				enQueue(Queue, w->vertex);
				pVisited[w->vertex] = true;
				printf(" %3c", w->vertex + 65);	// 정점 방문
			}
			w = w->link;
		}
	}
	printf("\n");
	queueDestroy(Queue);
}
