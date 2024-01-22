#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void recursion(TreeNode* root, int level, std::vector<int>& ans) {
        if (root == nullptr)
            return;

        if (ans.size() == level) {
            ans.push_back(root->val);
        }
        recursion(root->left, level + 1, ans);
        recursion(root->right, level + 1, ans);
    }

    std::vector<int> leftSideView(TreeNode* root) {
        std::vector<int> ans;
        recursion(root, 0, ans);
        return ans;
    }
};

// Function to create a binary tree for testing
TreeNode* createBinaryTree() {
    /*
       Example binary tree:
              1
             / \
            2   3
             \   \
              5   4
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    return root;
}

int main() {
    Solution solution;
    TreeNode* root = createBinaryTree();
    std::vector<int> result = solution.leftSideView(root);

    std::cout << "Left Side View: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << "\n";


    return 0;
}
