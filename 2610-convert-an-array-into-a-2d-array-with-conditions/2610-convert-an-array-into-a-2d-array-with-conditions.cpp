class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ct= 0;

        for(auto a: nums){
            mp[a]++;
            ct = max(ct, mp[a]);
        }
        vector<vector<int>> ans(ct);
        for(auto a: mp){
            for(int i=0; i<a.second; i++){
                ans[i].push_back(a.first);
            }
        }
        return ans;
    }
};