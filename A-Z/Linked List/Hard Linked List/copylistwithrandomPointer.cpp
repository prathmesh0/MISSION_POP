#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int value)
    {
        val = value;
        next = NULL;
        random = NULL;
    }
};

// Brute force approach
/*
Node* copyRandomList(Node* head) {
    unordered_map<Node*,Node*> hashMap;
    Node* temp = head;
//first iteration for inserting deep nodes of every node in the hashmap.
    while(temp != NULL) {
        Node* newNode = new Node(temp->val);
        hashMap[temp] = newNode;
        temp = temp->next;
    }
    Node* t = head;
//second iteration for linking next and random pointer as given question.
    while(t != NULL) {
        Node* node = hashMap[t];
        node->next = (t->next != NULL) ? hashMap[t->next]:NULL;
        node->random = (t->random != NULL) ? hashMap[t->random]:NULL;
        t = t->next;
    }
    return hashMap[head];
}
*/
// optimal appraoch
Node *copyRandomList(Node *head)
{
    Node *temp = head;
    // step 1
    while (temp != NULL)
    {
        Node *newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }
    // step 2
    Node *itr = head;
    while (itr != NULL)
    {
        if (itr->random != NULL)
            itr->next->random = itr->random->next;
        itr = itr->next->next;
    }
    // step 3
    Node *dummy = new Node(0);
    itr = head;
    temp = dummy;
    Node *fast;
    while (itr != NULL)
    {
        fast = itr->next->next;
        temp->next = itr->next;
        itr->next = fast;
        temp = temp->next;
        itr = fast;
    }
    return dummy->next;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << ':';
        head->next != NULL ? cout << head->next->val : cout << "NULL";
        head->random != NULL ? cout << "," << head->random->val : cout << ",NULL";
        cout << endl;
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;

    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    head = node1;
    head->next = node2;
    head->next->next = node3;
    head->next->next->next = node4;

    head->random = node4;
    head->next->random = node1;
    head->next->next->random = NULL;
    head->next->next->next->random = node2;

    cout << "Original list:(current node:node pointed by next pointer,node pointed by random pointer)";
    printList(head);

    cout << "Copy list:(current node:node pointed by next pointer,node pointed by random pointer)\n";
    Node *newHead = copyRandomList(head);
    printList(newHead);
    return 0;
}