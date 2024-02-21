#include <iostream>
#include <vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *build(vector<int> &arr, int &i, int bound)
    {
        if (i == arr.size() || arr[i] > bound)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(arr[i++]);
        root->left = build(arr, i, root->val);
        root->right = build(arr, i, bound);
        return root;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }

public:
    TreeNode *insert(TreeNode *root, int val)
    {
        if (root == nullptr)
            return new TreeNode(val);

        if (val < root->val)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);

        return root;
    }

    // TreeNode *bstFromPreorder(vector<int> &preorder)
    // {
    //     TreeNode *root = nullptr;
    //     for (int val : preorder)
    //     {
    //         root = insert(root, val);
    //     }
    //     return root;
    // }
};

// Function to perform inorder traversal of the BST
void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    std::vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Solution solution;

    TreeNode *root = solution.bstFromPreorder(preorder);

    std::cout << "Inorder traversal of the constructed BST: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
