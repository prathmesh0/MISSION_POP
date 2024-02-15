#include <iostream>
#include <queue> // for level order traversal

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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL && root->val != val){
            if(val < root->val){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return root;
    }
};

// Function to create a binary tree from an array
TreeNode* createBST(std::vector<int> values, int start, int end) {
    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(values[mid]);
    root->left = createBST(values, start, mid - 1);
    root->right = createBST(values, mid + 1, end);
    return root;
}

// Function to print level order traversal of the tree
void printLevelOrder(TreeNode* root) {
    if (root == nullptr)
        return;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* curr = q.front();
            q.pop();
            std::cout << curr->val << " ";
            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<int> values = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = createBST(values, 0, values.size() - 1);

    Solution solution;
    int target = 5;
    TreeNode* result = solution.searchBST(root, target);

    if (result != nullptr)
        std::cout << "Found node with value " << target << std::endl;
    else
        std::cout << "Node with value " << target << " not found" << std::endl;

    return 0;
}
