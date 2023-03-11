#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // creating constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

// insert at head
void insertAtHead(Node *&Head, int d)
{
    Node *temp = new Node(d);
    temp->next = Head;
    Head = temp;
}

// insert at tail
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

// insert in the middle
void insertAtnth(Node *&tail, Node *&Head, int position, int d)
{
    // insert at 1st position
    if (position == 1)
    {
        insertAtHead(Head, d);
        return;
    }
    Node *temp = Head;
    int cnt = 1;
    while (cnt < position)
    {
        temp = temp->next;
        cnt++;
    }
    // insert at last position
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// delete
void deleteNode(int position, Node *&head)
{

    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free start ndoe
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

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void print(Node *&head)
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
    // creating a new node
    Node *node1 = new Node(10);
    // cout << node1->data << " ";
    // cout << node1->next << " ";

    // pointig head to node1
    Node *head = node1;
    Node *tail = node1;
    // print(head);
    // insertAtHead(head, 12);
    // print(head);
    // insertAtHead(head, 15);
    // print(head);
    print(head);
    insertAtTail(tail, 33);
    print(head);
    insertAtTail(tail, 89);
    print(head);
    insertAtTail(tail, 94);
    print(head);
    insertAtnth(tail, head, 4, 22);
    print(head);
    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;
    deleteNode(1, head);
    print(head);
    return 0;
}