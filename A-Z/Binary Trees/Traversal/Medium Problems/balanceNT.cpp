#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution
// {
// public:
//     int findHeight(TreeNode *root)
//     {
//         if (root == nullptr)
//         {
//             return 0;
//         }
//         int lh = findHeight(root->left);
//         int rh = findHeight(root->right);
//         return 1 + std::max(lh, rh);
//     }

// public:
//     bool isBalanced(TreeNode *root)
//     {
//         if (root == nullptr)
//         {
//             return true;
//         }

//         int leftH = findHeight(root->left);
//         int rightH = findHeight(root->right);

//         if (std::abs(leftH - rightH) > 1)
//         {
//             return false;
//         }

//         bool left = isBalanced(root->left);
//         bool right = isBalanced(root->right);
//         if (!left || !right)
//         {
//             return false;
//         }
//         return true;
//     }
// };
class Solution
{
    int dfsHeight(TreeNode *root)
    {
        if (root == NULL)
            return true;
        int leftH = dfsHeight(root->left);
        if (leftH == -1)
            return -1;
        int rightH = dfsHeight(root->right);
        if (rightH == -1)
            return -1;
        if (abs(leftH - rightH) > 1)
        {
            return -1;
        }
        return 1 + max(leftH, rightH);
    }

public:
    bool isBalanced(TreeNode *root)
    {
        if (dfsHeight(root) == -1)
        {
            return false;
        }
        return true;
    }
};

// Function to create a binary tree for testing
TreeNode *createBinaryTree()
{
    /*
       Example binary tree:
              1
             / \
            2   3
           / \
          4   5
    */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    return root;
}

int main()
{
    Solution solution;

    // Create a binary tree
    TreeNode *root = createBinaryTree();

    // Call the isBalanced function and print the result
    bool result = solution.isBalanced(root);

    // Print the result
    if (result)
    {
        std::cout << "The binary tree is balanced.\n";
    }
    else
    {
        std::cout << "The binary tree is not balanced.\n";
    }

    return 0;
}
