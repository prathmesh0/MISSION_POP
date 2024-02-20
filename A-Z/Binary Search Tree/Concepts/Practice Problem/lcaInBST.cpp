#include <iostream>
#include <vector>

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->val > p->val && root->val > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (root->val < p->val && root->val < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

// Function to create a BST from an array
TreeNode *createBST(std::vector<int> &values, int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;
    TreeNode *root = new TreeNode(values[mid]);
    root->left = createBST(values, start, mid - 1);
    root->right = createBST(values, mid + 1, end);
    return root;
}

// Function to find a node in the tree
TreeNode *findNode(TreeNode *root, int val)
{
    if (root == nullptr || root->val == val)
        return root;

    if (val < root->val)
        return findNode(root->left, val);
    else
        return findNode(root->right, val);
}

int main()
{
    std::vector<int> values = {6, 2, 8, 0, 4, 7, 9, 3, 5};
    TreeNode *root = createBST(values, 0, values.size() - 1);
    Solution solution;

    int p_val = 2;
    int q_val = 8;

    TreeNode *p = findNode(root, p_val);
    TreeNode *q = findNode(root, q_val);

    TreeNode *lca = solution.lowestCommonAncestor(root, p, q);
    if (lca != nullptr)
        std::cout << "Lowest Common Ancestor of " << p_val << " and " << q_val << " is " << lca->val << std::endl;
    else
        std::cout << "Lowest Common Ancestor of " << p_val << " and " << q_val << " not found" << std::endl;

    return 0;
}
