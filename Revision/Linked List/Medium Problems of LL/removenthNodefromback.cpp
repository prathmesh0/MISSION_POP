/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    //Brute force approach
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* curr_node = new ListNode();
        int count =0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        //edge case
        if(count == n){
            ListNode* fnode = head;
            head = head->next;
            delete(fnode);
            return head;
        }
        temp = head;
        for(int i =1; i<(count- n); i++){
            temp = temp->next;
        }
        curr_node = temp->next;
        temp->next = temp->next->next;
        delete(curr_node);
         return head;

    }
    
//Optimal Approach
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode();
        start->next = head;
        ListNode* slow = start;
        ListNode* fast = start;
        for(int i = 1; i<=n; i++){
            fast = fast->next;
        }
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return start->next;


    }

};