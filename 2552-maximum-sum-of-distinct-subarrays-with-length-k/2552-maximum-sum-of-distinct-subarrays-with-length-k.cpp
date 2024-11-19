class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0, ans = 0;
        int left = 0;
        int count = 0, n = nums.size();
        unordered_map<int, int> numMap;

        for(int right = 0; right< n; right++ ){
            numMap[nums[right]]++;
            sum+=nums[right];
            if(numMap[nums[right]] == 1){
                count++;
            }
            if(right-left+1 == k){
                if(count == k){
                    ans = max(ans, sum);
                }
                sum-=nums[left];
                if(numMap[nums[left]]==1) count--;
                numMap[nums[left]]--;
                left++;
            }
        }
        return ans;
    }
};