class Solution {
public:
    int findMin(vector<int>& nums) {
        int last = nums.size() - 1;
        int first = 0;
        int mid;
        if (nums[first] < nums[last]) return nums[0];
        while(first < last){
            //cout<<first<<" "<<last<<endl;
            mid = (first + last)/2;
            if(mid == first || mid == last) break;
            if(nums[first]>nums[mid]){
                last = mid;
            }
            else if(nums[mid]>nums[last]){
                first = mid;
            }
        }
        return nums[mid+1];
    }
};