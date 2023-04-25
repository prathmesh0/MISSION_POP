#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0)
        {
            int sum = 0;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            // creating new node
            ListNode *new_node = new ListNode(sum % 10);
            temp->next = new_node;
            temp = temp->next;
        }
        return dummy->next;
    }
};

int main()
{
    // Creating first linked list: 2 -> 4 -> 3
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Creating second linked list: 5 -> 6 -> 4
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Adding the two linked lists together
    Solution sol;
    ListNode *result = sol.addTwoNumbers(l1, l2);

    // Printing the result: 7 -> 0 -> 8
    while (result != NULL)
    {
        cout << result->val << " -> ";
        result = result->next;
    }
    cout << "NULL" << endl;
    return 0;
}