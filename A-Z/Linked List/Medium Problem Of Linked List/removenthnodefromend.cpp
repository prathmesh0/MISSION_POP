#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// brute force approach
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        ListNode *curr_node = new ListNode();
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        // edge case
        if (count == n)
        {
            ListNode *fnode = head;
            head = head->next;
            delete (fnode);
            return head;
        }
        temp = head;
        for (int i = 1; i < (count - n); i++)
        {
            temp = temp->next;
        }
        curr_node = temp->next;
        temp->next = temp->next->next;
        delete (curr_node);
        return head;
    }
};
// optimal approach

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *start = new ListNode();
        start->next = head;
        ListNode *fast = start;
        ListNode *slow = start;

        for (int i = 1; i <= n; ++i)
            fast = fast->next;

        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return start->next;
    }
};

int main()
{

    return 0;
}