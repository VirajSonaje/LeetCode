class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int l =0, r=0;
        int n = nums.size();
        int ans = 1;
        while(r<n){
            if(nums[r] - nums[l] > k){
                l = r;
                ans++;
            }
            r++;
        }

        return ans;
    }
};