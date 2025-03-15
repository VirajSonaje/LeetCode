class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left =1;
        int right = *max_element(nums.begin(), nums.end());
        int ans =right;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(satisfy(nums,k, mid)){
                ans = mid;
                right = mid-1;
            }
            else left = mid+1;
        }
        return ans;
    }

    bool satisfy(vector<int> &nums, int k, int mid){
        int count =0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= mid){
                count++;
                i++;
            }
        }
        return count >= k;
    }
};