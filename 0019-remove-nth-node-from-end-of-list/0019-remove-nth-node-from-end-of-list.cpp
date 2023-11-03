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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;

        for(int i=0; i<n; i++){
            temp = temp->next;
        }
        ListNode* rem = head;
        if(temp == nullptr) return head->next;
        while(temp->next!= nullptr){
            rem= rem->next;
            temp = temp->next;
        }

        rem->next = rem->next->next;
        return head;
    }
};