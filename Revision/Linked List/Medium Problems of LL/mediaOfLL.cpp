#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Brute force
// Node *middleNode(Node *head)
// {
//     Node *temp = head;
//     int count = 1;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//         count++;
//     }
//     temp = head;
//     for (int i = 0; i < (count / 2); i++)
//     {
//         temp = temp->next;
//     }
//     return temp;
// }

Node *middleNode(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Optimal Approach

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = head;
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);
    print(head);
    Node *ans = middleNode(head);
    print(ans);

    return 0;
}