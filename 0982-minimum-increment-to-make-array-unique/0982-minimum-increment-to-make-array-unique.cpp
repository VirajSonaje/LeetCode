class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        set<int> s;
        int ans = 0;
        sort(nums.begin(), nums.end());
        s.insert(nums[0]);

        for(int i=1; i<nums.size(); i++){
            if(s.find(nums[i])!= s.end()){
                int a = nums[i];
                nums[i] = nums[i-1]+1;
                ans+=nums[i]-a;
            }
            s.insert(nums[i]);
        }
        return ans;
    }
};