#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    std::vector<std::vector<int>> verticalTraversal(TreeNode *root)
    {
        std::map<int, std::map<int, std::multiset<int>>> ans;
        std::queue<std::pair<TreeNode *, std::pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode *temp = p.first;

            int x = p.second.first;
            int y = p.second.second;

            ans[x][y].insert(temp->val);

            if (temp->left != nullptr)
            {
                q.push({temp->left, {x - 1, y + 1}});
            }
            if (temp->right != nullptr)
            {
                q.push({temp->right, {x + 1, y + 1}});
            }
        }
        std::vector<std::vector<int>> nodes;

        for (auto it : ans)
        {
            std::vector<int> col;
            for (auto q : it.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            nodes.push_back(col);
        }
        return nodes;
    }
};

// Function to create a binary tree for testing
TreeNode *createBinaryTree()
{
    /*
       Example binary tree:
              1
             / \
            2   3
           / \ / \
          4  5 6  7
    */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    return root;
}

int main()
{
    Solution solution;
    TreeNode *root = createBinaryTree();
    std::vector<std::vector<int>> result = solution.verticalTraversal(root);

    std::cout << "Vertical Traversal:\n";
    for (const auto &col : result)
    {
        for (int val : col)
        {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
