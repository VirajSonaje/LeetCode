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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int step =0;
        int maxDist, minDist = INT_MAX;
        ListNode* prev = NULL;
        ListNode* nextNode = head->next;
        vector<int> points;
        while(head != NULL && nextNode != NULL){
            if(prev != NULL && nextNode!=NULL){
                //find criticalPoint
                if((head->val > prev->val && head->val > nextNode->val) ||
                   (head->val < prev->val && head->val < nextNode->val)){
                    points.push_back(step);
                }
            }
            prev = head;
            head = head->next;
            nextNode = head->next;
            step++;
        }

        if(points.size() < 2) return {-1, -1};

        maxDist = points.back() - points.front();
        
        for(int i=1; i<points.size(); i++) 
            minDist = min(minDist, points[i] - points[i-1]);

        return {minDist, maxDist};
    }

};