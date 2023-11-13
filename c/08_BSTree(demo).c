/*
    이진 탐색 트리(BST): 알고리즘 구현
        파일명: BSTree(demo).cpp
            - main: 삽입(Insert), 삭제(Delete), 검색(Search), 전체 원소 출력
*/

#include <stdio.h>
#include <stdlib.h>			// exit
#include <stdbool.h>		// bool, true, false
#include "BSTree.h"			// DNode
#define	 bufferMAXSIZE 1024

DNode	*InsertBST(DNode *root);
void	SearchBST(DNode *root);
void	DeleteBST(DNode *root);
void	printBSTAll(DNode* root);

int main(void)
{
	int		num;
	DNode	*root = NULL;
	while (true) {
		system("cls");
		printf("\n ### 이진 검색 트리 ### \n\n");
		printf("1) 데이터 삽입 \n");
		printf("2) 데이터 검색 \n");
		printf("3) 데이터 삭제 \n");
		printf("4) 전체 원소 출력 \n");
		printf("5) 프로그램 종료 \n");
		printf("\n메뉴 선택: ");
		scanf_s("%d%*c", &num);
		// scanf("%d%*c", &num);

		switch (num) {
			case 1: root = InsertBST(root);	break;
			case 2: SearchBST(root);		break;
			case 3: DeleteBST(root);		break;
			case 4: printBSTAll(root);		break;
			case 5: printf("프로그램 종료!!!\n");
					return 0;
			default: printf("메뉴를 잘못 선택하셨습니다. \n");
		}
		system("pause");
	}
	return 0;
}

// 이진 검색 트리(BST): 데이터 입력
DNode	*InsertBST(DNode *root) {
	int	num;
	while (true) {
		printf("임의의 정수 입력 (종료 : 0) : ");
		scanf_s("%d%*c", &num);
		// scanf("%d%*c", &num);
		if (num == 0)
			break;

		// 데이터 삽입
		root = insertBST(root, num);
	}
	return root;
}

// 이진 검색 트리(BST): 데이터 검색
void  SearchBST(DNode *root) {
	int		num;
	DNode	*tNode = NULL;
	while (true) {
		printf("\n찾을 임의의 정수 값을 입력하세요(종료: 0): ");
		scanf_s("%d%*c", &num);
		// scanf("%d%*c", &num);
		if (num == 0)
			break;

		// 데이터 검색
		tNode = searchBST(root, num);
		if (tNode)	printf("%d 키를 찾았습니다!!! \n", tNode->__data);
		else		printf("키를 찾지 못했습니다. \n");
	}
	return;
}

// 이진 검색 트리(BST): 데이터 삭제
void  DeleteBST(DNode *root) {
	int		num;
	DNode	*tNode = NULL;
	while (true) {
		printf("\n삭제할 임의의 정수 값을 입력하세요(종료: 0): ");
		scanf_s("%d%*c", &num);
		// scanf("%d%*c", &num);
		if (num == 0)
			break;

		// 데이터 삭제
		deleteBST(root, num);
		if (tNode)	printf("%d 키를 찾았습니다!!! \n", tNode->__data);
		else		printf("키를 찾지 못했습니다. \n");
	}
	return;
}

// 이진 검색 트리(BST): 전체 노드 출력(중위 순회)
void printBSTAll(DNode *root) {
	if (root) {
		printBSTAll(root->__Llink);
		printf("%3d", root->__data);
		printBSTAll(root->__Rlink);
	}
}
