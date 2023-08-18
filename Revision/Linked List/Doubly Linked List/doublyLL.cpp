#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << val << endl;
    }
};

// Insert At Head
void insertAthead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// Insert at Tail
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// insert At any position
void insertAtAnyPosition(Node *&head, Node *&tail, int data, int pos)
{
    // insert At 1st position
    if (pos == 1)
    {
        insertAthead(head, tail, data);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < pos)
    {
        temp = temp->next;
        cnt++;
    }

    // insert At last position
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
    }

    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
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
    Node *node1 = new Node(10);
    // cout << node1->data << " ";
    // cout << node1->next << " ";
    // cout << node1->prev << " ";
    Node *head = node1;
    Node *tail = head;
    insertAthead(head, tail, 15);
    print(head);
    insertAtTail(head, tail, 56);
    print(head);
    insertAtAnyPosition(head, tail, 55, 2);
    print(head);
    insertAtAnyPosition(head, tail, 43, 4);
    print(head);
    return 0;
}