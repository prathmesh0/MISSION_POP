#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


int main(){
    struct Node* root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(13);
    root->left->right = new Node(19);

    return 0;
}