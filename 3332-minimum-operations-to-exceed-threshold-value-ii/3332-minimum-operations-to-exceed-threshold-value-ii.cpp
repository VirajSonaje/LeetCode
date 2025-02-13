class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        int ans =0;
        while(pq.top() < k){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            long long t = max(a,b) + 2*min(a,b);
            pq.push(t);
            ans++;
        }
        return ans;
    }
};