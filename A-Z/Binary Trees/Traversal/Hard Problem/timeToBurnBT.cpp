#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

// Definition for a binary tree node.
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

template <typename T>
BinaryTreeNode<T> *mapParentNode(BinaryTreeNode<T> *root, unordered_map<BinaryTreeNode<T> *, BinaryTreeNode<T> *> &parents, T start) {
    BinaryTreeNode<T> *ans;
    queue<BinaryTreeNode<T> *> q;
    q.push(root);

    while (!q.empty()) {
        BinaryTreeNode<T> *temp = q.front();
        if (temp->data == start) {
            ans = temp;
        }
        q.pop();
        if (temp->left) {
            parents[temp->left] = temp;
            q.push(temp->left);
        }

        if (temp->right) {
            parents[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return ans;
}

template <typename T>
int timetoBurn(BinaryTreeNode<T> *target, unordered_map<BinaryTreeNode<T> *, BinaryTreeNode<T> *> &mpp) {
    queue<BinaryTreeNode<T> *> q;
    int maxi = 0;
    unordered_map<BinaryTreeNode<T> *, int> visited;
    q.push(target);
    visited[target] = 1;

    while (!q.empty()) {
        int sz = q.size();
        int flag = 0;
        for (int i = 0; i < sz; i++) {
            auto node = q.front();
            q.pop();

            if (node->left && !visited[node->left]) {
                flag = 1;
                visited[node->left] = 1;
                q.push(node->left);
            }
            if (node->right && !visited[node->right]) {
                flag = 1;
                visited[node->right] = 1;
                q.push(node->right);
            }
            if (mpp[node] && !visited[mpp[node]]) {
                flag = 1;
                visited[mpp[node]] = 1;
                q.push(mpp[node]);
            }
        }
        if (flag) {
            maxi++;
        }
    }
    return maxi;
}

template <typename T>
int timeToBurnTree(BinaryTreeNode<T> *root, T start) {
    unordered_map<BinaryTreeNode<T> *, BinaryTreeNode<T> *> parents;
    BinaryTreeNode<T> *s_node = mapParentNode(root, parents, start);
    int distance = timetoBurn(s_node, parents);
    return distance;
}

// Function to create a binary tree based on user input
template <typename T>
BinaryTreeNode<T> *createBinaryTree() {
    cout << "Enter the data for the root node: ";
    T rootData;
    cin >> rootData;
    BinaryTreeNode<T> *root = new BinaryTreeNode<T>(rootData);

    queue<BinaryTreeNode<T> *> q;
    q.push(root);

    while (!q.empty()) {
        BinaryTreeNode<T> *currNode = q.front();
        q.pop();

        cout << "Enter the left child of " << currNode->data << " (or -1 for no left child): ";
        T leftData;
        cin >> leftData;
        if (leftData != -1) {
            BinaryTreeNode<T> *leftChild = new BinaryTreeNode<T>(leftData);
            currNode->left = leftChild;
            q.push(leftChild);
        }

        cout << "Enter the right child of " << currNode->data << " (or -1 for no right child): ";
        T rightData;
        cin >> rightData;
        if (rightData != -1) {
            BinaryTreeNode<T> *rightChild = new BinaryTreeNode<T>(rightData);
            currNode->right = rightChild;
            q.push(rightChild);
        }
    }

    return root;
}

int main() {
    cout << "Enter the starting node value: ";
    int startNode;
    cin >> startNode;

    // Create a binary tree based on user input
    BinaryTreeNode<int> *root = createBinaryTree<int>();

    // Call the timeToBurnTree function
    int distance = timeToBurnTree(root, startNode);

    // Output the result
    cout << "Time to burn the tree starting from node " << startNode << ": " << distance << endl;

    return 0;
}
