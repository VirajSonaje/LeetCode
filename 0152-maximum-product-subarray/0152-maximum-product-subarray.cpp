class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int global = nums[0];
       
        for(int i=1; i<nums.size(); i++){
            int temp = maxProd;
            maxProd = max(nums[i], max(nums[i]* maxProd, nums[i]*minProd));
            minProd = min(nums[i], min(nums[i]* temp, nums[i]* minProd));
            
            global = max(global, maxProd);
        }
        
        return global;
    }
};