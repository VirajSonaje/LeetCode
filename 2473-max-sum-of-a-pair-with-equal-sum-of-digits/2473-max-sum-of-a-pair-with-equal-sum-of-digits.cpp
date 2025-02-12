class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, vector<int>> mp;
        for(int i: nums){
            int sumD = findsum(i);
            if(mp[sumD].size()==2){
                vector<int> pr = mp[sumD];
                mp[sumD][0] = max(pr[0], max(i, pr[1]));
                mp[sumD][1] = min(i, max(pr[0], pr[1]));
                ans = max(ans, mp[sumD][0] + mp[sumD][1]);
            }
            else{
                mp[sumD].push_back(i);
                if(mp[sumD].size()==2) ans = max(ans, mp[sumD][0] + mp[sumD][1]);
            }
        }
        
        return ans;
    }

    int findsum(int i){
        int sum =0;
        while(i>0){
            sum+=i%10;
            i/=10;
        }
        return sum;
    }
};