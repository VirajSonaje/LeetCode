class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        if (nums[left] < nums[right]) return nums[0];
        while(left < right){
            int mid = left + (right-left)/2;
            if(mid == left || mid == right) break;
            if(nums[mid] < nums[right]) right = mid;
            else left = mid;
        }
        cout<<nums[mid]<<" "<<nums[left]<<" "<<nums[right]<<endl;
        return nums[right];
    }
};