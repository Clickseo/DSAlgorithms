#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

void	searchBST(BinarySearchTree* bst);
void	insertBST(BinarySearchTree* bst);
void	deleteBST(BinarySearchTree* bst);

int main(void)
{
	int			num;
	BinarySearchTree*	bst = new BinarySearchTree();
	while (true) {
		system("cls");
		cout << "\n ### 이진 탐색 트리 ### \n" << endl;
		cout << "1) 데이터 삽입" << endl;
		cout << "2) 데이터 검색" << endl;
		cout << "3) 데이터 삭제" << endl;
		cout << "4) 전체 출력" << endl;
		cout << "5) 프로그램 종료" << endl;
		cout << "\n메뉴 선택: ";
		cin >> num;
		switch (num) {
			case 1: insertBST(bst);			break;
			case 2: searchBST(bst);			break;
			case 3: deleteBST(bst);			break;
			case 4: bst->printBSTAll(bst->getRoot());	break;
			case 5: cout << "프로그램 종료!!!\n" << endl;	return 0;
			default: cout << "메뉴를 잘못 선택하셨습니다." << endl;
		}
		system("pause");
	}
	return 0;
}

// 이진 탐색 트리(BST): 데이터 검색
void  searchBST(BinarySearchTree* bst) {
	int		num;
	DNode*	temp = nullptr;
	while (true) {
		cout << "\n찾을 임의의 정수 값을 입력하세요(종료: 0): ";
		cin >> num;
		if (num == 0)
			break;

		// 데이터검색
		temp = bst->search(num);
		if (temp)	cout << temp->__data << " 키를 찾았습니다!!!" << endl;
		else		cout << "키를 찾지 못했습니다." << endl;
	}
}

// 이진 탐색 트리(BST): 데이터 입력
void insertBST(BinarySearchTree* bst) {
	int		num;
	while (true) {
		cout << "임의의 정수 입력(종료: 0): ";
		cin >> num;
		if (num == 0)
			break;

		// 데이터 삽입
		bst->insert(num);
	}
}

// 이진 탐색 트리(BST): 데이터 삭제
void  deleteBST(BinarySearchTree* bst) {
	int		num;
	DNode* temp = nullptr;
	while (true) {
		cout << "\n삭제할 임의의 정수 값을 입력하세요(종료: 0): ";
		cin >> num;
		if (num == 0)
			break;

		// 데이터 삭제
		bst->remove(num);
	}
}
