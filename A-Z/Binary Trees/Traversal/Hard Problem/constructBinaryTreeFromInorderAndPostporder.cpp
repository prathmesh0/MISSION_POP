#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* constructTree(vector<int>& inorder, int ins, int ine, vector<int>& postorder, int ps, int pe, unordered_map<int, int>& mpp) {
        if (ins > ine || ps > pe) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[pe]);
        int ele = mpp[root->val];
        int nEle = ele - ins;

        root->left = constructTree(inorder, ins, ele - 1, postorder, ps, ps + nEle - 1, mpp);
        root->right = constructTree(inorder, ele + 1, ine, postorder, ps + nEle, pe - 1, mpp);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inStart = 0, inEnd = inorder.size() - 1;
        int postStart = 0, postEnd = postorder.size() - 1;
        unordered_map<int, int> mpp;
        for (int i = inStart; i <= inEnd; i++) {
            mpp[inorder[i]] = i;
        }
        return constructTree(inorder, inStart, inEnd, postorder, postStart, postEnd, mpp);
    }
};

// Function to print the inorder traversal of a binary tree
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Sample input
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    // Solution object
    Solution solution;

    // Construct the binary tree
    TreeNode* root = solution.buildTree(inorder, postorder);

    // Print the inorder traversal of the constructed tree
    cout << "Inorder Traversal of the Constructed Tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
