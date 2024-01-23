#include <iostream>
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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        long long ans = 0;
        std::queue<std::pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long curMin = q.front().second;
            long long leftMost, rightMost;
            for (int i = 0; i < size; i++) {
                long long cur_id = q.front().second - curMin;
                TreeNode* temp = q.front().first;
                q.pop();

                if (i == 0) leftMost = cur_id;
                if (i == size - 1) rightMost = cur_id;

                if (temp->left != NULL)
                    q.push({
                        temp->left,
                        cur_id * 2 + 1
                    });

                if (temp->right != NULL)
                    q.push({
                        temp->right,
                        cur_id * 2 + 2
                    });

            }
            ans = std::max(ans, rightMost - leftMost + 1);
        }
        return ans;
    }
};

// Function to create a sample binary tree
TreeNode* createBinaryTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    return root;
}

int main() {
    Solution solution;

    // Example usage:
    TreeNode* root = createBinaryTree();

    int result = solution.widthOfBinaryTree(root);

    std::cout << "Width of Binary Tree: " << result << std::endl;

  

    return 0;
}
