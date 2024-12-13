class Solution {
public:
    long long findScore(vector<int>& nums) {
        unordered_set<int> idxs;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> least;
        int ans =0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            least.push({nums[i], i});
        }

        while(idxs.size() < n){
            auto leastPair = least.top();
            least.pop();
            if(idxs.count(leastPair.second) == 0){
                idxs.insert(leastPair.second);
                ans += leastPair.first;
                if(leastPair.second < n-1) idxs.insert(leastPair.second + 1);
                if(leastPair.second > 0) idxs.insert(leastPair.second - 1);
            }

        }

        return ans;
    }
};