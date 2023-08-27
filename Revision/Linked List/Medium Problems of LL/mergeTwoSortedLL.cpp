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

//Brute force Approach
class Solution {
    //iterative approach
    
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        // base case
        if(l1 == NULL) return l2;
        if(l2 == NULL)  return l1;
        while(l1 != NULL && l2 != NULL ){
            if(l1-> val < l2-> val){
                tail -> next = l1;
                tail = l1;
                l1 = l1->next;
            }
            else{
                tail -> next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        if(l1 == NULL){
            tail->next = l2;
        }
        if(l2 == NULL){
            tail->next = l1;
        }
        return dummy->next;
    }
};

//Optimal Approach
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
   //optimal approach
    
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // base case
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1-> val > l2->val){
            swap(l1,l2);
        }
        ListNode* res = l1;
        while(l1 != NULL && l2 != NULL){
            ListNode* temp = NULL;
            while(l1 != NULL && l1->val <= l2->val){
                temp = l1;
                l1 = l1 -> next;
            }
            temp->next = l2;
            swap(l1, l2);
        }
        return res;
    }
};