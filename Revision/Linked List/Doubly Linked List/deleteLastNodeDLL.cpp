/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() : data(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : data(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : data(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node * deleteLastNode(Node *head) {
    if(head->next == nullptr){
        return nullptr;
    }
    Node* curr = head;
    Node* temp = head;
    while(curr->next != NULL){
        temp = curr;
        curr = curr->next;
    }
    temp->next = nullptr;
    delete(curr);
    return head;
}
