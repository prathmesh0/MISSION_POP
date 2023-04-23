#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
//brute force
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head)
            return NULL; // empty list
        ListNode *cur = head;
        while (cur != NULL)
        {
            ListNode *minNode = cur;
            ListNode *temp = cur->next;
            while (temp != NULL)
            {
                if (temp->val < minNode->val)
                {
                    minNode = temp;
                }
                temp = temp->next;
            }
            // swap values
            int tempVal = cur->val;
            cur->val = minNode->val;
            minNode->val = tempVal;
            cur = cur->next;
        }
        return head;
    }
};
*/
// optimal approach
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // base case
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val > l2->val)
        {
            swap(l1, l2);
        }
        ListNode *res = l1;
        while (l1 != NULL && l2 != NULL)
        {
            ListNode *temp = NULL;
            while (l1 != NULL && l1->val <= l2->val)
            {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            swap(l1, l2);
        }
        return res;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        // find mid
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *temp = NULL;
        while (fast != NULL && fast->next != NULL)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL; // end of first half
        // left and right recursive call
        ListNode *l1 = sortList(head);
        ListNode *r1 = sortList(slow);
        return mergeTwoLists(l1, r1);
    }
};

int main()
{
    // create the linked list: 4 -> 2 -> 1 -> 3
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution s;
    ListNode *sortedList = s.sortList(head);

    // print the sorted linked list
    while (sortedList != NULL)
    {
        cout << sortedList->val << " ";
        sortedList = sortedList->next;
    }
    cout << endl;

    return 0;
}
