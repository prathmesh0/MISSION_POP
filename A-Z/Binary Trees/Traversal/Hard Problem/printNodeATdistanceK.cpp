#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left != NULL){
                parent_track[temp->left] = temp;
                q.push(temp->left);
            }

            if(temp->right != NULL){
                parent_track[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParent(root, parent_track);

        unordered_map<TreeNode* , bool> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;
        int curr_lev = 0;

        while(!q.empty()){
            int n = q.size();
            if(curr_lev++ == k){
                break;
            }

            for(int i = 0; i<n; i++){
                TreeNode* curr =  q.front();
                q.pop();

                if(curr->left != NULL && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }

                if(curr->right != NULL && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }

                if(parent_track[curr] != NULL && !visited[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]] = true;
                }
            }
        }

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};

// Function to create a sample binary tree
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    return root;
}

int main() {
    Solution solution;

    // Create a sample binary tree
    TreeNode* root = createSampleTree();

    // Set the target node and distance
    TreeNode* targetNode = root->left;
    int k = 2;

    // Call the distanceK function
    vector<int> result = solution.distanceK(root, targetNode, k);

    // Output the result
    cout << "Nodes at distance " << k << " from the target node: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
