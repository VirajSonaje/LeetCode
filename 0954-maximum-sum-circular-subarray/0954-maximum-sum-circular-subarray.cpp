class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum =nums[0], curmax= 0; 
        int minSum =nums[0], curmin= 0;
        int totalSum =0;
        for(int i: nums)totalSum+=i;
        for(int i: nums){
            curmax = max(i, curmax+i);
            maxSum = max(maxSum, curmax);

            curmin = min(i, curmin+i);
            minSum = min(minSum, curmin);

        }

        return maxSum > 0? max(maxSum, totalSum-minSum) : maxSum;
    }
};