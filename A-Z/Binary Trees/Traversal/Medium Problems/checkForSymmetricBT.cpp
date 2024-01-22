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
    bool isMirror(TreeNode *node1, TreeNode *node2)
    {
        if (node1 == nullptr || node2 == nullptr)
        {
            return node1 == node2;
        }
        if (node1->val != node2->val)
        {
            return false;
        }
        return isMirror(node1->left, node2->right) &&
               isMirror(node1->right, node2->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return isMirror(root->left, root->right);
    }
};

// Function to create a symmetric binary tree for testing
TreeNode *createSymmetricBinaryTree()
{
    /*
       Example symmetric binary tree:
              1
             / \
            2   2
           / \ / \
          3  4 4  3
    */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    return root;
}

int main()
{
    Solution solution;
    TreeNode *symmetricRoot = createSymmetricBinaryTree();

    bool isSymmetricResult = solution.isSymmetric(symmetricRoot);

    std::cout << "Is Symmetric: " << (isSymmetricResult ? "true" : "false") << std::endl;
    return 0;
}
