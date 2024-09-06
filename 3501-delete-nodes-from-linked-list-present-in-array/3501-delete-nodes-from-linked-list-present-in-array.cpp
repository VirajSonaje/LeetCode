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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> numsFreq;

        for(int i: nums) numsFreq[i] = 1;
        
        ListNode* dummy = new ListNode(0); 
        dummy->next = head;
        ListNode* current = dummy;

        while (current->next != NULL) {
            if (numsFreq[current->next->val]) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};