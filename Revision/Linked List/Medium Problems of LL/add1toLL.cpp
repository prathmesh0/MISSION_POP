//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    //Optimal approach
    public:
    Node* reverseLL(Node *&head){
        Node* prev = NULL;
        
        while(head != NULL){
            Node* next = head->next;
            head -> next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
    public:
    Node* addOne(Node *head) 
    {
        Node* newHead = reverseLL(head);
        
        Node* curr = newHead;
        Node* curr1 = newHead;
        Node* prev = NULL;
        int carry = 0;
        while(curr != NULL){
            int sum = 0;
            if(prev == NULL){
                sum = curr->data + 1;
            }
            else{
                sum = curr->data +carry;
            }
            
            carry = sum/10;
            curr->data = sum%10;
            prev = curr;
            curr = curr->next;
        }
        
        if(carry == 1){
            Node* new_node = new Node(1);
            prev->next = new_node;
        }
        return reverseLL(curr1);
        
    }
    //Brute force Approach
    public:
    Node* addOne(Node *head) 
    {
        if(head == NULL){
            return NULL; // empty list
        }
        
        Node* curr = head;
        vector<int> digits;
        while(curr !=  NULL){
            digits.push_back(curr->data);
            curr = curr -> next;
        }
        int carry = 1;
        for(int i = digits.size()-1; i>=0; i--){
            //calculate the sum
            int sum = digits[i]+carry;
            // calculate the updated digits
            digits[i] = sum%10;
            //calculate carry
            carry = sum/10;
        }
        //if carry is 1 then we need to add one at the beginning of the vector
        if(carry == 1){
            digits.insert(digits.begin(), carry);
        }
        Node* newHead = new Node(digits[0]);
        Node* temp = newHead;
        for(int i = 1; i<digits.size(); i++){
            temp -> next = new Node(digits[i]);
            temp = temp->next;
        }
        return newHead;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends