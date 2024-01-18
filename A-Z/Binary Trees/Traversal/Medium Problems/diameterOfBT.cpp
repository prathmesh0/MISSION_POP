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

// class Solution {
// public:
//     int calculateDiameter(TreeNode* root, int& maxi) {
//         if (root == nullptr) {
//             return 0;
//         }

//         int lh = calculateDiameter(root->left, maxi);
//         int rh = calculateDiameter(root->right, maxi);

//         maxi = std::max(maxi, lh + rh);
//         return 1 + std::max(lh, rh);
//     }

// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         int maxi = 0;
//         calculateDiameter(root, maxi);
//         return maxi;
//     }
// };

class Solution
{
public:
    int HeightoBT(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int leftH = HeightoBT(root->left);
        int rightH = HeightoBT(root->right);

        return 1 + max(leftH, rightH);
    }

public:
    void calculateDiameter(TreeNode *root, int &maxi)
    {
        if (root == NULL)
            return;
        int lh = HeightoBT(root->left);
        int rh = HeightoBT(root->right);
        maxi = max(maxi, lh + rh);
        calculateDiameter(root->left, maxi);
        calculateDiameter(root->right, maxi);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int maxi = 0;
        calculateDiameter(root, maxi);
        return maxi;
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

    // Call the diameterOfBinaryTree function and print the result
    int result = solution.diameterOfBinaryTree(root);

    // Print the result
    std::cout << "Diameter of the binary tree: " << result << std::endl;

    // Remember to free the memory allocated for the binary tree nodes
    // ... (deallocation code)

    return 0;
}
