#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *pre;
    Node *next;
    // constructor
    Node(int d)
    {
        this->data = d;
        this->pre = NULL;
        this->next = NULL;
    }
    // destructor
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

// traversing LL
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
// gives LL length
int getLength(Node *head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtHead(Node *&tail, Node *&head, int data)
{
    // empty LL
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
        head->pre = temp;
        head = temp;
    }
}

void insertAtTail(Node *&tail, Node *&head, int data)
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
        temp->pre = tail;
        tail = temp;
    }
}
void insertAtPosition(Node *&Head, Node *&tail, int d, int position)
{
    // insert at 1st position
    if (position == 1)
    {
        insertAtHead(Head, tail, d);
        return;
    }
    Node *temp = Head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // insert at last position
    if (temp->next == NULL)
    {
        insertAtTail(tail, Head, d);
        return;
    }
    Node *nodeToinsert = new Node(d);
    nodeToinsert->next = temp->next;
    temp->next->pre = nodeToinsert;
    temp->next = nodeToinsert;
    nodeToinsert->pre = temp;
}

// deletion of LL
void deleteNode(int position, Node *&head)
{

    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->pre = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->pre = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    // cout << "The length of LL = " << getLength(head) << endl;
    insertAtHead(tail, head, 19);
    print(head);
    insertAtHead(tail, head, 30);
    print(head);
    insertAtHead(tail, head, 89);
    print(head);
    insertAtTail(tail, head, 24);
    print(head);
    insertAtTail(tail, head, 80);
    print(head);

    // insert ant any position
    insertAtPosition(head, tail, 15, 2);
    print(head);
    insertAtPosition(head, tail, 100, 1);
    print(head);

    deleteNode(1, head);
    print(head);
    deleteNode(4, head);
    print(head);
    deleteNode(5, head);
    print(head);
    cout << "head = " << head->data << " "
         << "tail = " << tail->data << endl;
    return 0;
}