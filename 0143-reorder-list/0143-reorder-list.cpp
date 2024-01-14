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
    void reorderList(ListNode* head) {
        ListNode* rev = NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp = head;

        while(1){
            if(fast->next == NULL) break;
            if(fast->next->next == NULL) break;
            fast = fast->next->next;            
            slow = slow->next;
        }
        
        
        ListNode* k = reverse(slow->next, rev);
        slow->next= NULL;

        while(1){
            if(k == NULL) break;
            ListNode* t = temp;
            ListNode* st = k;
            temp = temp-> next;
            k = k->next;
            t->next = st;
            st->next = temp;
        }

        while(head){
            cout<<head->val<<" ";
            head = head->next;
        }
        return;
    }


    ListNode* reverse(ListNode* curr, ListNode* rev){
        
        if(curr == NULL){
            return rev;
        }
        
        ListNode* node = new ListNode();
        node->val = curr->val;
        node->next = rev;
        curr = curr->next;
        return reverse(curr,node);
        
    }
};

