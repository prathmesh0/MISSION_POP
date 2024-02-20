#include <iostream>
#include <vector>
#include <climits> // for LONG_MIN and LONG_MAX

// Definition for a binary tree node.
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
    bool helper(TreeNode *root, long min, long max)
    {
        // Base Case
        if (root == nullptr)
        {
            return true;
        }
        if (min >= root->val || max <= root->val)
        {
            return false;
        }
        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

// Function to create a binary tree from a vector representing the inorder traversal
TreeNode *createTree(std::vector<int> &inorder, int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;
    TreeNode *root = new TreeNode(inorder[mid]);
    root->left = createTree(inorder, start, mid - 1);
    root->right = createTree(inorder, mid + 1, end);
    return root;
}

int main()
{
    // Example input values
    std::vector<int> inorder = {1, 2, 3, 4, 5, 6, 7};
    TreeNode *root = createTree(inorder, 0, inorder.size() - 1);
    Solution solution;

    // Check if the tree is a valid BST
    bool isValid = solution.isValidBST(root);
    std::cout << "The tree is " << (isValid ? "a valid" : "an invalid") << " BST." << std::endl;

    return 0;
}
