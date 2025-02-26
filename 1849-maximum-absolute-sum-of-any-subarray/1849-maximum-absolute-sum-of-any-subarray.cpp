class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int sum =0, minsum = INT_MAX, maxsum = INT_MIN;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            minsum = min(minsum, sum);
            maxsum = max(maxsum, sum);
        }
        
        return max({abs(maxsum), abs(minsum), maxsum- minsum});
    }
};