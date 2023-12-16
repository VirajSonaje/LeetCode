class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int gmax = INT_MIN;
        int lmax = 0;
        
        for(int i=0;i<nums.size();i++){
            lmax = max(nums[i],nums[i]+lmax);
            
            gmax = max(lmax, gmax);
            
        }
        
        return gmax;
        
    }
};