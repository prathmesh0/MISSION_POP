#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

void preOrderTrav(Node *curr, vector<int> &ans)
{

    // BC
    if (curr == NULL)
    {
        return;
    }

    ans.push_back(curr->data);
    preOrderTrav(curr->left, ans);
    preOrderTrav(curr->right, ans);
}
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(8);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    vector<int> preOrder;
    preOrderTrav(root, preOrder);

    cout << "The preOrder Traversal is : ";
    for (int i = 0; i < preOrder.size(); i++)
    {
        cout << preOrder[i] << " ";
    }
    return 0;
    return 0;
}