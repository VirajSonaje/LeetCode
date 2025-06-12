class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxD = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
            maxD = max(maxD, abs(nums[i%n] - nums[(i+1)%n]));
        }
        return maxD;
    }
};