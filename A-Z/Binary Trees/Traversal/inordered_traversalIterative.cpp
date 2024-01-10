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

vector<int> preOrderTrav(Node *curr)
{
    stack<Node *> st;
    vector<int> ans;
    while (true)
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
            curr = st.top();
            ans.push_back(curr->data);
            st.pop();
            curr = curr->right;
        }
    }
    return ans;
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
    preOrder = preOrderTrav(root);

    cout << "The preOrder Traversal is : ";
    for (int i = 0; i < preOrder.size(); i++)
    {
        cout << preOrder[i] << " ";
    }
    return 0;
    return 0;
}