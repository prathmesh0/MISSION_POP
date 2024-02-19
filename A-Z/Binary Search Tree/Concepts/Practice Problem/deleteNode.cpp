#include <iostream>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left && !root->right)
                return nullptr;
            if (!root->left || !root->right)
                return root->left ? root->left : root->right;

            TreeNode* temp = root->left;
            while (temp->right != nullptr)
                temp = temp->right;

            root->val = temp->val;
            root->left = deleteNode(root->left, temp->val);
        }
        return root;
    }
};

// Function to create a BST from an array
TreeNode* createBST(std::vector<int>& values, int start, int end) {
    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(values[mid]);
    root->left = createBST(values, start, mid - 1);
    root->right = createBST(values, mid + 1, end);
    return root;
}

// Function to perform inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;
    
    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    std::vector<int> values = {5, 3, 8, 2, 4, 7, 9};
    TreeNode* root = createBST(values, 0, values.size() - 1);
    Solution solution;

    std::cout << "Inorder traversal of the original BST: ";
    inorderTraversal(root);
    std::cout << std::endl;

    // Deleting node with key 3
    root = solution.deleteNode(root, 3);

    std::cout << "Inorder traversal of the BST after deletion: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
