#include <iostream>
#include <vector>
#include <queue>

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

// class Solution {
// public:
//     void helper(TreeNode* root, int & count){
//         if(root == NULL){
//             return;
//         }
//         count++;
//         helper(root->left, count);
//         helper(root->right, count);
//     }

// public:
//     int countNodes(TreeNode* root) {
//         int count = 0;
//         helper(root, count);
//         return count;
//     }
// };

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int calculateLeftHeight(TreeNode *root)
    {
        int count = 0;
        while (root != NULL)
        {
            count++;
            root = root->left;
        }
        return count;
    }
    int calculateRightHeight(TreeNode *root)
    {
        int count = 0;
        while (root != NULL)
        {
            count++;
            root = root->right;
        }
        return count;
    }

public:
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftHeight = calculateLeftHeight(root);
        int rightHeight = calculateRightHeight(root);

        if (leftHeight == rightHeight)
        {
            return (1 << leftHeight) - 1;
        }

        int leftNode = countNodes(root->left);
        int rightNode = countNodes(root->right);
        return 1 + leftNode + rightNode;
    }
};
// Function to create a binary tree from a vector
TreeNode *createBinaryTree(const vector<int> &nodes, int index)
{
    if (index >= nodes.size() || nodes[index] == -1)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(nodes[index]);
    root->left = createBinaryTree(nodes, 2 * index + 1);
    root->right = createBinaryTree(nodes, 2 * index + 2);

    return root;
}

int main()
{
    // Input vector representing the nodes [1, 2, 3, 4, 5, 6]
    vector<int> nodes = {1, 2, 3, 4, 5, 6};

    // Create a binary tree from the input vector
    TreeNode *root = createBinaryTree(nodes, 0);

    // Call the countNodes function
    Solution solution;
    int nodeCount = solution.countNodes(root);

    // Output the result
    cout << "Total number of nodes in the binary tree: " << nodeCount << endl;

    return 0;
}
