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
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* minNode = curr;
            ListNode* temp = curr->next;
            while(temp != NULL){
                if(temp->val < minNode->val){
                    minNode = temp;
                }
                temp = temp->next;   
            }
            
             int tempVal = curr->val;
             curr->val = minNode->val;
             minNode->val = tempVal;
            curr= curr->next;
        }
        return head;
    }
    //Optimal approach
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // base case
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val > l2->val)
        {
            swap(l1, l2);
        }
        ListNode *res = l1;
        while (l1 != NULL && l2 != NULL)
        {
            ListNode *temp = NULL;
            while (l1 != NULL && l1->val <= l2->val)
            {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            swap(l1, l2);
        }
        return res;
    }    
public:
    ListNode* sortList(ListNode* head) {
       if(head == NULL || head -> next == NULL){
           return head;
       }
       //find mid
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = NULL;
        while(fast != NULL && fast->next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp ->next = NULL; //end of first half
        //left and right recursive call
        ListNode* l1 = sortList(head); 
        ListNode* r1 = sortList(slow); 
        return mergeTwoLists(l1,r1);

        
    }
};