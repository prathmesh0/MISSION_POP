#include <bits/stdc++.h>

using namespace std;

//Declaring the struct for Tree implementation.
struct node
{
    int data;
    struct node *left, *right;
};

//Defining a function for inserting new-node in BST
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int findCeil(node *root, int input)
{

    int ceil = -1;
    
    while (root)
    {
        // If the input is already available in BST, return that.
        if (root->data == input)
            return input;

        // If the input is greater than root, then the ceil value must be in the right subtree.
        else if (root->data < input)
        {
            root = root->right;
        }

        // Otherwise, we mark ceil to be root and move to 
        // left subtree where it may be further closer to the input value
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }

    //Return computed ceil value.
    return ceil;
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

    cout << findCeil(root, 6);
    cout << endl;

    return 0;
}