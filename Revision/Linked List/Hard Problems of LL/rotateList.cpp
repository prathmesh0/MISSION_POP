

class Solution
{
    // Optimal Approach
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
        {
            return head;
        }
        ListNode *temp = head;
        int length = 1;
        while (temp->next != NULL)
        {
            length++;
            temp = temp->next;
        }
        temp->next = head;
        k = k % length;
        int end = length - k;
        while (end != 0)
        {
            end--;
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }

    // Brute force Approach
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || k == 0)
        {
            return head;
        }

        int length = 0;
        ListNode *temp = head;

        // Calculate the length of the linked list
        while (temp->next != nullptr)
        {
            temp = temp->next;
            length++;
        }
        length++; // Include the last node

        // Perform the rotation k times
        for (int i = 0; i < k % length; i++)
        {
            ListNode *last = head;
            ListNode *secondToLast = nullptr;

            // Find the last and second-to-last nodes
            while (last->next != nullptr)
            {
                secondToLast = last;
                last = last->next;
            }

            // Rotate the list by moving the last node to the front
            last->next = head;
            head = last;
            secondToLast->next = nullptr;
        }

        return head;
    }
};
