class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int bits = -1, curmin = INT_MAX, curmax = INT_MIN;
        int lastLimit = -1;
        for(int i=0; i<n; i++){
            int count = getSetBits(nums[i]);
            if(bits == -1, bits == count){
                bits = count;
                curmin = min(curmin, nums[i]);
                curmax = max(curmax, nums[i]);
            }
            else{
                if(lastLimit > curmin) return false;
                bits = count;
                lastLimit = curmax;
                curmin = nums[i];
                curmax = nums[i];
            }
        }
        if(lastLimit > curmin) return false;
        return true;
    }

    int getSetBits(int n){
        int ans =0;
        for(int i=0; i<=8; i++){
            if(n & (1<<i)) ans++;
        }
        return ans;
    }
};