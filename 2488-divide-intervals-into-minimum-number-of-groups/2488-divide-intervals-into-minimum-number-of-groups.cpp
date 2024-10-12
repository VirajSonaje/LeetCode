class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
       sort(intervals.begin(), intervals.end());
       priority_queue<int, vector<int> , greater<int>> pq;
    
       for(auto interval: intervals){
            if(!pq.empty() && pq.top() < interval[1]){
                pq.pop();
                pq.push(interval[1]);
            }
            else{
                pq.push(interval[1]);
            }        
       }
        return pq.size();
    }
};