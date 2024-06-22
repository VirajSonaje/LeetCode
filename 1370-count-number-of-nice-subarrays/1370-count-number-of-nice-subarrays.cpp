class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left= 0, right =0;
        int oddCount = 0;
        int n = nums.size();
        int ans = 0, adds = 0;
        for(right =0; right < n; right++){
            if(nums[right]%2) oddCount++;
            
            if(oddCount == k){
                adds = 0;    
                while(oddCount == k){
                    oddCount-= nums[left]%2;
                    adds++;
                    left++;
                }
            }
            ans+=adds;
        }
        return ans;
    }
};