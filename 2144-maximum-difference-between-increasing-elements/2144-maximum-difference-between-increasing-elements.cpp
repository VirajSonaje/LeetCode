class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minSoFar = nums[0];
        int ans =-1;

        for(int i: nums){
            ans = max(ans, i-minSoFar);
            minSoFar = min(minSoFar, i);
        }

        return ans == 0 ? -1 : ans;
    }
};