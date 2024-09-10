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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;

        int a = head->val;
        ListNode* b = head->next;

        ListNode* gcd = new ListNode(__gcd(a, b->val)); 
        head->next = gcd;
        gcd->next = b;

        insertGreatestCommonDivisors(b);

        return head;
    }
};