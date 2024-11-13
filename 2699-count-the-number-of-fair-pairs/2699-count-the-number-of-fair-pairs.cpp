class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        // for(int n: nums) cout<<n<<" ";
        // cout<<endl;
        for(int i=0; i<nums.size()-1; i++){
            auto left = lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i]);
            auto right = upper_bound(nums.begin()+i+1, nums.end(), upper-nums[i]);
            
            ans += (right - left);
        }
        return ans;   
    }
};