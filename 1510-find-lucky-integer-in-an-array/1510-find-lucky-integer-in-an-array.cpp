class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i: arr) mp[i]++;
        int ans = -1;
        for(auto el: mp){
            if(el.first == el.second){
                ans = max(ans, el.first);
            }
        }
        return ans;
    }
};