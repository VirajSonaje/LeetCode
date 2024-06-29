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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(); 
        ListNode* curr = root;
        int remainder =0;
        while(l1 != NULL || l2 != NULL){
            int sum = remainder;
            if(l1 == NULL) sum = l2->val + remainder, l2 = l2->next;
            else if (l2 == NULL) sum = l1->val + remainder, l1 = l1->next;
            else {
                sum = l1->val + l2->val+remainder;
                l1 = l1->next;
                l2 = l2->next;
            }
            if(sum >= 10) remainder = 1;
            else remainder = 0;
            curr->next = new ListNode(sum%10);
            curr = curr->next; 
        }
        if(remainder ==1 ) curr->next = new ListNode(1);
        return root->next;
    }
};