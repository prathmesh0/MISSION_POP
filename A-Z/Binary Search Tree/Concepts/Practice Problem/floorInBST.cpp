#include <bits/stdc++.h>

using namespace std;

// Declaring the struct for Tree implementation.
struct node
{
    int data;
    struct node *left, *right;
};

// Defining a function for inserting new-node in BST
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int Floor(node *root, int input)
{
    int floor = -1;
    while (root != NULL)
    {
        if (root->data == input)
        {
            return input;
        }
        else if (root->data > input)
        {
            root = root->left;
        }
        else
        {
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}

int main()
{
    // Driver Code.
    struct node *root = newNode(10);
    root->left = newNode(5);
    root->left->left = newNode(4);
    root->left->right = newNode(7);
    root->left->right->right = newNode(8);
    root->right = newNode(11);

    cout << Floor(root, 6);
    cout << endl;

    return 0;
}
