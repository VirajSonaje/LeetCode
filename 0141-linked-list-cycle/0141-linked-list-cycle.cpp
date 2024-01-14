/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head == NULL){
            return false;
        }
        while(1){
            slow = slow->next;
            if((slow==NULL) || (fast->next==NULL)){
                return false;
            }
            fast=(fast->next)->next;
            if(fast==NULL){
                return false;
            }
            if(slow == fast){
                return true;
            }
        }
        
    }
};