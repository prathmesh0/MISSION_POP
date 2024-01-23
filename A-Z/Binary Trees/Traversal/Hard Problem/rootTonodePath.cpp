#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

bool getPath(node *root, vector<int> &arr, int x)
{
    if (root == NULL)
    {
        return false;
    }
    arr.push_back(root->data);

    if (root->data == x)
    {
        return true;
    }

    if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
    {
        return true;
    }

    arr.pop_back();
    return false;
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

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->left->right->right = newNode(7);
    root->right = newNode(3);

    vector<int> arr;

    bool res;
    res = getPath(root, arr, 7);

    cout << "The path is ";
    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}