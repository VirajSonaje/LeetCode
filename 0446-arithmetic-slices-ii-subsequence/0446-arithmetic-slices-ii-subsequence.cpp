class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        vector<unordered_map<int, int>> dp(n);

        for(int i = 1; i<n; i++){
            for(int j = 0; j< i; j++){
                long long diff = static_cast<long long> (nums[i]) - nums[j];

                if(diff > INT_MAX || diff < INT_MIN) continue;

                int differ = static_cast<int>(diff);

                dp[i][differ] += 1;

                if(dp[j].count(differ)){
                    dp[i][differ] += dp[j][differ];
                    ans += dp[j][differ];
                }
            }
        }
        return ans;
    }
};