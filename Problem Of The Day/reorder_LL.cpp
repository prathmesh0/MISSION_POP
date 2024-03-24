#include <iostream>
using namespace std;
// Definition for singly-linked list
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
    void reorderList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return;
        // find middle of the LL
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second LL (from next to the middle)
        ListNode *prev = NULL;
        ListNode *next = NULL;
        while (slow != NULL)
        {
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        // connections
        ListNode *s1 = head;
        ListNode *s2 = prev;
        while (s2 != NULL && s1 != NULL)
        {
            ListNode *temp1 = s1->next;
            s1->next = s2;
            ListNode *temp2 = s2->next;
            s2->next = temp1;
            s1 = temp1;
            s2 = temp2;
        }
    }
};

// Function to create a linked list from an array
ListNode *createLinkedList(int arr[], int n)
{
    if (n == 0)
        return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    for (int i = 1; i < n; ++i)
    {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Function to print the linked list
void printLinkedList(ListNode *head)
{
    while (head)
    {
        std::cout << head->val;
        if (head->next)
            std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createLinkedList(arr, n);
    Solution sol;
    sol.reorderList(head);
    printLinkedList(head);

    return 0;
}
