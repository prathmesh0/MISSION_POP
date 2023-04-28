//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

// } Driver Code Ends
// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
    /*
// Brute force
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> pairs;
        Node *first = head;
        while (first != nullptr) {
            Node *second = first->next;
            while (second != nullptr) {
                if (first->data + second->data == target) {
                    pairs.push_back(make_pair(first->data, second->data));
                }
                second = second->next;
            }
            first = first->next;
        }
        return pairs;
    }
    */
    // optimal solution

public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> result;
        Node *left = head;
        Node *right = head;
        while (right->next != NULL)
        {
            right = right->next;
        }
        while (left != NULL && right != NULL && left != right && left != right->next)
        {
            int sum = left->data + right->data;
            if (sum == target)
            {
                result.push_back(make_pair(left->data, right->data));
                left = left->next;
                right = right->prev;
            }
            else if (sum < target)
            {
                left = left->next;
            }
            else
            {
                right = right->prev;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends