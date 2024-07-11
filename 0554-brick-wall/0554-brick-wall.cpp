class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int ans = wall.size();
        int sum = 0;
        unordered_map<int,int> mp;
        //prefix sum
        for(int i=0; i<wall.size(); i++){
            sum = 0;
            for(int j: wall[i]) {
                sum+=j;
                j = sum;
                mp[sum]++;
            }
            
        }
        int maxend = 0;
        for(auto ends: mp){
            if(ends.first!=sum)
            maxend = max(maxend, ends.second);
        }
        return ans - maxend;
    }
};