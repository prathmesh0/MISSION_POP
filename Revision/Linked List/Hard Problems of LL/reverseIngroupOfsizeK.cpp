/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    // Using Recursion
public:
    void reverse(ListNode *s, ListNode *e)
    {
        ListNode *prev = NULL;
        while (prev != e)
        {
            ListNode *next = s->next;
            s->next = prev;
            prev = s;
            s = next;
        }
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 1)
        {
            return head;
        }
        ListNode *s = head, *e = head;
        int inc = k - 1;
        while (inc--)
        {
            e = e->next;
            if (e == NULL)
                return head;
        }

        ListNode *nextHead = reverseKGroup(e->next, k);
        reverse(s, e);
        s->next = nextHead;
        return e;
    }

    // Using Iterative Approach
public:
    void reverse(ListNode *s, ListNode *e)
    {
        ListNode *prev = NULL;
        while (prev != e)
        {
            ListNode *next = s->next;
            s->next = prev;
            prev = s;
            s = next;
        }
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 1)
        {
            return head;
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *beforeStart = dummy, *e = head;
        int i = 0;
        while (e != NULL)
        {
            i++;
            if (i % k == 0)
            {
                ListNode *s = beforeStart->next;
                ListNode *temp = e->next;
                reverse(s, e);
                beforeStart->next = e;
                s->next = temp;
                beforeStart = s;
                e = temp;
            }
            else
            {
                e = e->next;
            }
        }
        return dummy->next;
    }
};