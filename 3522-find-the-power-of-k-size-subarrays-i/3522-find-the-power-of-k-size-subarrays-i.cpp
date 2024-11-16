class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        map<int, int> mp;
        int left = 0;
        int cnt =1;
        for(int i=0; i<n; i++){
            if(i > 0 && nums[i-1] == nums[i]-1)cnt++;

            if(i-left+1 > k){
                if(nums[left]+1 == nums[left+1]) cnt--;
                left++;
            }

            if(i-left+1 ==k){
                ans.push_back(cnt == k ? nums[i] : -1);
            }
        }
        return ans;
    }
};