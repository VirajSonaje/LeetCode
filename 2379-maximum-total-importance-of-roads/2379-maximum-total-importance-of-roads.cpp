class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> degrees;
        priority_queue<int> max_heap;
        long long ans = 0;
        for(auto road: roads){
            degrees[road[0]]++;
            degrees[road[1]]++;
        }

        for(int i=0; i<n; i++) max_heap.push(degrees[i]);
        
        for(long long i=n; i>0; i--){
            ans+= i * max_heap.top();
            max_heap.pop();
        }
        return ans;
    }
};