#include <iostream>
#include <vector>
#include <stack>

class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

std::vector<std::vector<int>> getTreeTraversal(TreeNode *root) {
    std::vector<std::vector<int>> ans;
    std::vector<int> preorder, postorder, inorder;

    std::stack<std::pair<TreeNode*, int>> st;
    st.push({root, 1});

    if (root == NULL) {
        return ans;
    }

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        if (it.second == 1) {
            preorder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        } else if (it.second == 2) {
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        } else {
            postorder.push_back(it.first->data);
        }
    }
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    return ans;
}

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
    TreeNode* root = createBinaryTree();

    
    std::vector<std::vector<int>> result = getTreeTraversal(root);

    // Print the result
    std::cout << "Inorder Traversal: ";
    for (int val : result[0]) {
        std::cout << val << " ";
    }
    std::cout << "\nPreorder Traversal: ";
    for (int val : result[1]) {
        std::cout << val << " ";
    }
    std::cout << "\nPostorder Traversal: ";
    for (int val : result[2]) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    

    return 0;
}
