class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        int n = nums.size();
        for(int i =0 ; i<n; i++){
            nums[i]%= p;
            sum = (sum + nums[i])%p;
        }
        sum %= p;
        if(sum == 0) return 0;

        unordered_map<int,int> mp;
        int prefixsum = 0;
        mp[0] = -1;
        int ans = n;
        for(int i=0; i<n; i++){
            prefixsum = (prefixsum + nums[i])%p;
            int rem = (prefixsum - sum +p)%p;
            if(mp.find(rem) != mp.end()) ans = min(ans, i-mp[rem]);
            mp[prefixsum] = i;
        }
        return ans == n? -1 : ans;
    }
};