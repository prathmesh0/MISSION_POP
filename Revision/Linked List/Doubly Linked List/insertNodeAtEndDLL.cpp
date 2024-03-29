#include<bits/stdc++.h>

using namespace std;

class node {
  public:
    int data;
  node * next;
  node * prev;
  node(int val) {
    data = val;
    next = NULL;
    prev = NULL;
  }
};

void insertAtTail(node * & head, int val) {
  node * new_node = new node(val);
  if (head == NULL) {
    head = new_node;
    return;
  }
  node * temp = head;
  while (temp -> next != NULL) {
    temp = temp -> next;
  }
  temp -> next = new_node;
  new_node -> prev = temp;
}

void display(node * head) {
  node * temp = head;
  while (temp != NULL) {
    cout << temp -> data << "-->";
    temp = temp -> next;
  }
  cout << "NULL\n";
}

int main() {
  node* head=NULL;
  insertAtTail(head,1);
  insertAtTail(head,2);
  insertAtTail(head,3);
  insertAtTail(head,4);
  insertAtTail(head,5);
  display(head);

}