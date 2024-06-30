class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k,0));
        int ans = 0;
        for(int num: nums){
            for(int j=0;j<k;j++){
                int i = num%k;
                dp[i][j] = dp[j][i]+1;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
    
};