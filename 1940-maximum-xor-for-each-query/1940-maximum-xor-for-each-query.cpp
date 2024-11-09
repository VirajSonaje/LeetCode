class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans(n);
        int mask = (1<<maximumBit)-1;
        int xorval = nums[0];
        for(int i=1; i<n; i++) xorval ^= nums[i];
        
        for(int i=0; i<n; i++){
            ans[i] = xorval ^ mask;
            xorval ^= nums[n-i-1];
            cout<<xorval<<" ";
        }
        return ans;
    }
};