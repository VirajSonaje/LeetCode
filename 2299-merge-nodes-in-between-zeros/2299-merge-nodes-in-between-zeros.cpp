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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* node = head;
        ListNode* currNode = head->next;
        while(node != nullptr && currNode!=NULL){
            while(currNode->val != 0){
                node->val+=currNode->val;
                currNode = currNode->next;
            }
            node->next = currNode;
            if(currNode->next)
            currNode = currNode->next;
            else node->next = NULL;
            node = node->next;
        }
        return head;
    }
};