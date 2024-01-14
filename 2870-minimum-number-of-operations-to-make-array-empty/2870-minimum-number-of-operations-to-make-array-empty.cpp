class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans =0;
        for(int n: nums) mp[n]++;
        for(auto a: mp){
            if(a.second < 2) return -1;
            ans += a.second/3;
            if(a.second%3)ans++;
        }
        return ans;
    }
};