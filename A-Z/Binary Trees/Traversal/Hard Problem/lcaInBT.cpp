#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool getPath(TreeNode* root, TreeNode* target, std::vector<TreeNode*>& path) {
        if (root == NULL) return false;

        path.push_back(root);

        if (root == target) {
            return true;
        }

        if (getPath(root->left, target, path) || getPath(root->right, target, path)) {
            return true;
        }

        path.pop_back();
        return false;
    }
//Brute force approach

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> path1;
        std::vector<TreeNode*> path2;

        bool res1 = getPath(root, p, path1);
        bool res2 = getPath(root, q, path2);

        if (!res1 || !res2) {
            return NULL; // One or both of the nodes are not in the tree
        }

        TreeNode* lca = NULL;
        int i = 0;

        while (i < path1.size() && i < path2.size() && path1[i] == path2[i]) {
            lca = path1[i];
            i++;
        }

        return lca;
    }
};

// Function to create a sample binary tree
TreeNode* createBinaryTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    return root;
}

int main() {
    Solution solution;

    // Example usage:
    TreeNode* root = createBinaryTree();
    TreeNode* p = root->left;   // Node with value 5
    TreeNode* q = root->right;  // Node with value 1

    TreeNode* result = solution.lowestCommonAncestor(root, p, q);

    if (result != NULL) {
        std::cout << "Lowest Common Ancestor: " << result->val << std::endl;
    } else {
        std::cout << "One or both of the nodes are not in the tree." << std::endl;
    }

   
    return 0;
}
