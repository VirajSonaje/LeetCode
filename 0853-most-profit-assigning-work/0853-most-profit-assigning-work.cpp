class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<int> pq;
        int n = profit.size(), ans =0;
        vector<pair<int, int>> jobs;
        for(int i=0; i<n ;i++) jobs.push_back({difficulty[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        int idx =0;
        for(int i=0; i<worker.size(); i++){
            // cout<<idx<<": "<<jobs[idx].first<<" "<<jobs[idx].second<<endl;
            while(idx < n && jobs[idx].first <= worker[i]){
                pq.push(jobs[idx].second);
                idx++;
            } 
            if (!pq.empty()) ans += pq.top();
        }
        return ans;
    }
};