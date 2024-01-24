#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool checkTree(TreeNode *root)
    {
        if (root == NULL)
            return true;

        int leftVal = root->left ? root->left->val : 0;
        int rightVal = root->right ? root->right->val : 0;

        return (leftVal + rightVal == root->val);
    }
};

// Function to create a sample binary tree
TreeNode *createBinaryTree()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(3);

    return root;
}

int main()
{
    Solution solution;

    // Example usage:
    TreeNode *root = createBinaryTree();

    bool result = solution.checkTree(root);

    std::cout << "Is the tree valid? " << (result ? "Yes" : "No") << std::endl;

    return 0;
}
