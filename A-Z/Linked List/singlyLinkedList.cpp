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

// Insert at head
void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

// Insert at Tail
void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
}

// Insert at any position
void insertAtnthNode(Node *&head, Node *&tail, int postion, int data)
{
    if (postion == 1)
    {
        insertAtHead(head, data);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < postion)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// Delete the nth node
void deleteNthNode(Node *&head, int pos)
{
    // deete first node
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        Node *prev = NULL;
        Node *current = head;
        int count = 1;
        while (count < pos)
        {
            prev = current;
            current = current->next;
            count++;
        }
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}
// Print Node
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
    Node *node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    Node *head = node1;
    Node *tail = node1;
    insertAtHead(head, 12);
    print(head);
    insertAtHead(head, 13);
    print(head);
    insertAtHead(head, 15);
    print(head);
    insertAtTail(tail, 122);
    print(head);
    insertAtTail(tail, 344);
    print(head);
    insertAtnthNode(head, tail, 3, 53);
    print(head);
    // cout<<"Head data = "<<head->data<<endl;
    // cout<<"Tail data = "<<tail->data<<endl;
    deleteNthNode(head, 3);
    print(head);

    return 0;
}