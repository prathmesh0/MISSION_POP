#include <iostream>

// Definition for singly-linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution class
class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *currNode = list1;
        int index = 0;
        while (index < a - 1)
        {
            currNode = currNode->next;
            index++;
        }
        ListNode *front = currNode;

        while (index < b + 1)
        {
            currNode = currNode->next;
            index++;
        }
        ListNode *rear = currNode;
        ListNode *secondListTail = list2;
        ListNode *secondListHead = list2;
        while (secondListTail->next != NULL)
        {
            secondListTail = secondListTail->next;
        }
        front->next = secondListHead;
        secondListTail->next = rear;
        return list1;
    }
};

// Function to print the linked list
void printLinkedList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Input function
void inputFunction()
{
    // Create list1: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = new ListNode(5);

    // Create list2: 6 -> 7 -> 8
    ListNode *list2 = new ListNode(6);
    list2->next = new ListNode(7);
    list2->next->next = new ListNode(8);

    std::cout << "List 1 before merging: ";
    printLinkedList(list1);

    std::cout << "List 2: ";
    printLinkedList(list2);

    Solution solution;
    ListNode *mergedList = solution.mergeInBetween(list1, 2, 4, list2);

    std::cout << "List 1 after merging: ";
    printLinkedList(mergedList);
}

int main()
{
    inputFunction();
    return 0;
}
