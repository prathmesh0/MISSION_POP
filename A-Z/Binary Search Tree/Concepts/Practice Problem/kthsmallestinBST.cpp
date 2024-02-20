
#include <bits/stdc++.h>
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
    // brute force

    // public:
    //     void prerderTraversal(TreeNode *root, vector<int> &pre)
    //     {
    //         if (root == NULL)
    //         {
    //             return;
    //         }
    //         pre.push_back(root->val);
    //         prerderTraversal(root->left, pre);
    //         prerderTraversal(root->right, pre);
    //     }

    // public:
    //     int kthSmallest(TreeNode *root, int k)
    //     {
    //         vector<int> preorder;
    //         prerderTraversal(root, preorder);
    //         sort(preorder.begin(), preorder.end());
    //         return preorder[k - 1];
    //     }

    // optimal approach
public:
    void solve(TreeNode *root, int &ans, int &count, int k)
    {
        if (root == nullptr)
        {
            return;
        }
        solve(root->left, ans, count, k);
        count++;
        if (count == k)
        {
            ans = root->val;
            return;
        }
        solve(root->right, ans, count, k);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        int count = 0;
        int ans;
        solve(root, ans, count, k);
        return ans;
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

int main()
{
    std::vector<int> values = {3, 1, 4, 2, 5};
    TreeNode *root = createBST(values, 0, values.size() - 1);
    Solution solution;

    int k = 3;

    int result = solution.kthSmallest(root, k);
    std::cout << "The " << k << "th smallest element in the BST is: " << result << std::endl;

    return 0;
}
