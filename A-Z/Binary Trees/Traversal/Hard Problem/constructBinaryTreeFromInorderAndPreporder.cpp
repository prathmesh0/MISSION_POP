#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

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
    TreeNode *constructTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mpp)
    {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        TreeNode *root = new TreeNode(preorder[preStart]);
        int elem = mpp[root->val];
        int nElem = elem - inStart;

        root->left = constructTree(preorder, preStart + 1, preStart + nElem, inorder, inStart, elem - 1, mpp);
        root->right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder, elem + 1, inEnd, mpp);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> mpp;
        int inStart = 0, inEnd = inorder.size() - 1;
        int preStart = 0, preEnd = preorder.size() - 1;

        for (int i = 0; i < inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }

        return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mpp);
    }
};

// Function to print the inorder traversal of a binary tree
void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    // Sample input
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    // Solution object
    Solution solution;

    // Construct the binary tree
    TreeNode *root = solution.buildTree(preorder, inorder);

    // Print the inorder traversal of the constructed tree
    cout << "Inorder Traversal of the Constructed Tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
