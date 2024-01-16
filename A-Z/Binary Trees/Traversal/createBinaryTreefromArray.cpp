#include <iostream>
#include <vector>

class Node {
public:
    int data;
    Node *left, *right;

    Node() {
        this->data = 0;
        left = NULL;
        right = NULL;
    }

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    Node(int data, Node* left, Node* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node* createBinary(std::vector<int>& arr, int start) {
    if (start >= arr.size()) {
        return NULL;
    }
    Node* root = new Node(arr[start]);

    root->left = createBinary(arr, 2 * start + 1);
    root->right = createBinary(arr, 2 * start + 2);
    return root;
}

Node* createTree(std::vector<int>& arr) {
    return createBinary(arr, 0);
}

// Function to print the inorder traversal of the binary tree
void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    // Example: Create a binary tree from an array
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node* root = createTree(arr);

    // Print the inorder traversal of the created binary tree
    std::cout << "Inorder Traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    // You can create other arrays and test the functions with different inputs

    return 0;
}
