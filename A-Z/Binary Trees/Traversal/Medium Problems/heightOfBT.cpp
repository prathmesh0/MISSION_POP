#include <iostream>
#include <queue>
#include <math.h>
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

// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         int depth = 0;
//         if (root == nullptr) {
//             return 0;
//         }
//         std::queue<TreeNode*> q;
//         q.push(root);
//         while (!q.empty()) {
//             int n = q.size();
//             for (int i = 0; i < n; i++) {
//                 TreeNode* temp = q.front();
//                 q.pop();
//                 if (temp->left != nullptr) {
//                     q.push(temp->left);
//                 }
//                 if (temp->right != nullptr) {
//                     q.push(temp->right);
//                 }
//             }
//             depth++;
//         }
//         return depth;
//     }
// };

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        // Base Case
        if (root == NULL)
        {
            return 0;
        }
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
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

    // Call the maxDepth function and print the result
    int result = solution.maxDepth(root);

    // Print the result
    std::cout << "Max Depth of the Binary Tree: " << result << "\n";

    return 0;
}
