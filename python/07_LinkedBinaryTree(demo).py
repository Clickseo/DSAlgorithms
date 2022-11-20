'''
	이진 트리: 알고리즘 구현
        파일명: LinkedBinaryTree(demo).py
        		- main	: 데이터 삽입.삭제, 전체 원소 출력
'''

from LinkedBinaryTree import LinkedBinaryTree

if __name__ == '__main__':
    BT = LinkedBinaryTree()
    
    postfix = input('트리를 구성할 후위 수식: ')
    BT.makeLinkedBinaryTree(postfix)

	# 이진 트리 깊이 우선 순회: 전위.중위.후위 순회
    print('Preorder  : ', end=' ');    BT.Preorder();    print('')
    print('Inorder   : ', end=' ');    BT.Inorder();     print('')
    print('Postorder : ', end=' ');    BT.Postorder();   print('')

	# 이진 트리 너비 우선 순회
    print('Levelorder : ', end=' ');   BT.Levelorder();  print('')
