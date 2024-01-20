
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    ~TreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

bool isLeaf(TreeNode<int>* root) {
    if (root->left == nullptr && root->right == nullptr)
        return true;
    return false;
}

void addLeftBoundary(TreeNode<int>* root, std::vector<int>& res) {
    TreeNode<int>* curr = root->left;
    while (curr != nullptr) {
        if (!isLeaf(curr)) {
            res.push_back(curr->data);
        }
        if (curr->left != nullptr) {
            curr = curr->left;
        } else
            curr = curr->right;
    }
}

void addRightBoundary(TreeNode<int>* root, std::vector<int>& res) {
    TreeNode<int>* curr = root->right;
    std::vector<int> temp;
    while (curr != nullptr) {
        if (!isLeaf(curr)) {
            temp.push_back(curr->data);
        }
        if (curr->right != nullptr) {
            curr = curr->right;
        } else
            curr = curr->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        res.push_back(temp[i]);
    }
}

void addLeafNodeBoundary(TreeNode<int>* root, std::vector<int>& res) {
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if (root->left != nullptr) {
        addLeafNodeBoundary(root->left, res);
    }
    if (root->right != nullptr) {
        addLeafNodeBoundary(root->right, res);
    }
}

std::vector<int> traverseBoundary(TreeNode<int>* root) {
    std::vector<int> res;
    if (root == nullptr)
        return res;

    if (!isLeaf(root)) {
        res.push_back(root->data);
    }

    addLeftBoundary(root, res);
    addLeafNodeBoundary(root, res);
    addRightBoundary(root, res);
    return res;
}

TreeNode<int>* createBinaryTree() {
    TreeNode<int>* root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);

    return root;
}

int main() {
    TreeNode<int>* root = createBinaryTree();

    std::vector<int> result = traverseBoundary(root);

    std::cout << "Boundary Elements: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
