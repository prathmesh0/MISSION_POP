#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            std::vector<int> level;

            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
                level.push_back(temp->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

// Function to create a binary tree for testing
TreeNode* createBinaryTree() {
    // Example: Constructing a binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    return root;
}

int main() {
    Solution solution;

    // Create a binary tree
    TreeNode* root = createBinaryTree();

    
    std::vector<std::vector<int>> result = solution.levelOrder(root);

    // Print the result
    std::cout << "Level Order Traversal:\n";
    for (const auto& level : result) {
        for (int val : level) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

   

    return 0;
}
