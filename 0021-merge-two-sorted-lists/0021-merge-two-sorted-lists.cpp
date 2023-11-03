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
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        bool f1 = false, f2 = false;
        ListNode* head;
        ListNode* temp;
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        if(l1->val <= l2->val){
               head =l1;
                l1= l1->next;
           }
        else{
            head = l2;
            l2 = l2->next;
        }
        temp = head;
       while(1){
           
           if(l1 == NULL){
               f1=true;
               temp->next= l2;
               return head;
           }
           if(l2 == NULL){
               f2 = true;
               temp->next = l1;
               return head;
           }
           if(f1 && f2){
               return head;
           }
           if(l1->val <= l2->val){
               
               temp->next = l1;
               l1 = l1->next;
               temp = temp->next;
               
           }
           else if(l2->val < l1->val){
               
               temp->next = l2;
               temp = temp->next;
               l2 = l2->next;
               
           }
           
       } 
        
    }
};