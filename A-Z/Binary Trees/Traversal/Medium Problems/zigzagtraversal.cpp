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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }

        std::queue<TreeNode*> q;
        bool flag = true;

        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            std::vector<int> level(n);

            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();

                int ind = flag ? i : (n - 1 - i);
                level[ind] = temp->val;

                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
            }

            ans.push_back(level);
            flag = !flag;
        }

        return ans;
    }
};

// Function to create a binary tree for testing
TreeNode* createBinaryTree() {
    /*
       Example binary tree:
              1
             / \
            2   3
           / \
          4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    return root;
}

int main() {
    Solution solution;

    // Create a binary tree
    TreeNode* root = createBinaryTree();

    // Call the zigzagLevelOrder function and print the result
    std::vector<std::vector<int>> result = solution.zigzagLevelOrder(root);

    // Print the result
    std::cout << "Zigzag Level Order Traversal:\n";
    for (const auto& level : result) {
        for (int val : level) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }



    return 0;
}
