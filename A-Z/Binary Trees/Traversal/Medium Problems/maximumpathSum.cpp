#include <iostream>
#include <climits>

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
    int calculateMaxSum(TreeNode* root, int& maxi) {
        if (root == nullptr) {
            return 0;
        }

        int leftMaxPath = std::max(0, calculateMaxSum(root->left, maxi));
        int rightMaxPath = std::max(0, calculateMaxSum(root->right, maxi));
        int val = root->val;

        maxi = std::max(maxi, leftMaxPath + rightMaxPath + val);
        return std::max(leftMaxPath, rightMaxPath) + val;
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        calculateMaxSum(root, maxi);
        return maxi;
    }
};

// Function to create a binary tree for testing
TreeNode* createBinaryTree() {
    /*
       Example binary tree:
              10
             / \
            2  10
           / \   \
          20  1  -25
                / \
               3   4
    */
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    return root;
}

int main() {
    Solution solution;

    // Create a binary tree
    TreeNode* root = createBinaryTree();

    // Call the maxPathSum function and print the result
    int result = solution.maxPathSum(root);

    // Print the result
    std::cout << "Maximum Path Sum: " << result << std::endl;

    

    return 0;
}
