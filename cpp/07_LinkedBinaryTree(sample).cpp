#include <iostream>
using namespace std;

template <typename T>
class BinaryTree;

template <typename T>
class TreeNode {
    friend class BinaryTree<T>;
private:
    T           data;
    TreeNode*   left;
    TreeNode*   right;
public:
    TreeNode(T data = 0, TreeNode* left = NULL, TreeNode* right = NULL) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

template <typename T>
class BinaryTree {
private:
    TreeNode<T>* root;
public:
    BinaryTree(T data = 0) {
        root = new TreeNode<T>(data);
    }
    // Tree 만들기
    /*
                -
            *        /
          A   B   C    D
    */
    void buildTree() {
        root->left = new TreeNode<T>('*', new TreeNode<T>('A'), new TreeNode<T>('B'));
        root->right = new TreeNode<T>('/', new TreeNode<T>('C'), new TreeNode<T>('D'));
    }

    TreeNode<T>* getRoot() {
        return root;
    }

    void visit(TreeNode<T>* current) {
        cout << current->data << " ";
    }

    // 전위 순회 Current - Left - Right
    void preorder(TreeNode<T>* current) {
        if (current != NULL) {
            visit(current);
            preorder(current->left);
            preorder(current->right);
        }
    }

    // 중위 순회 Left - Current - Right
    void inorder(TreeNode<T>* current) {
        if (current != NULL) {
            inorder(current->left);
            visit(current);
            inorder(current->right);
        }
    }

    // 후위 순회 Left - Right - Current
    void postorder(TreeNode<T>* current) {
        if (current != NULL) {
            postorder(current->left);
            postorder(current->right);
            visit(current);
        }
    }
};

int main(void) {
    // A B * C D / -
    BinaryTree<char> tree('-');
    tree.buildTree();

    cout << "Preorder >> ";
    tree.preorder(tree.getRoot());
    cout << endl;

    cout << "Inorder >> ";
    tree.inorder(tree.getRoot());
    cout << endl;

    cout << "Postorder >> ";
    tree.postorder(tree.getRoot());
    cout << endl;

    return 0;
}
