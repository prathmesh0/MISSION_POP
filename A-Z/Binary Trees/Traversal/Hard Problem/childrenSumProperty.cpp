#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

void printTree(node *root)
{
    if (root == NULL)
        return;

    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

void reorder(node *root)
{
    if (root == NULL)
        return;

    int child = 0;
    if (root->left)
    {
        child += root->left->data;
    }
    if (root->right)
    {
        child += root->right->data;
    }

    if (child < root->data)
    {
        if (root->left)
        {
            root->left->data = root->data;
        }
        if (root->right)
        {
            root->right->data = root->data;
        }
    }

    reorder(root->left);
    reorder(root->right);

    // backtracking
    int total = 0;
    if (root->left)
    {
        total += root->left->data;
    }

    if (root->right)
    {
        total += root->right->data;
    }
    if (root->left || root->right)
    {
        root->data = total;
    }
}

void changeTree(node *root)
{
    reorder(root);
}

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int main()
{
    struct node *root = newNode(2);
    root->left = newNode(35);
    root->left->left = newNode(2);
    root->left->right = newNode(3);
    root->right = newNode(10);
    root->right->left = newNode(5);
    root->right->right = newNode(2);

    changeTree(root);

    cout << "Values of nodes after changeTree function call: ";
    printTree(root);

    return 0;
}
