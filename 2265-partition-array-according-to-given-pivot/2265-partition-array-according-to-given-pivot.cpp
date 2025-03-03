class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int equal =0;
        int ptr =0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] < pivot){
                ans[ptr] = nums[i];
                ptr++;
            }
            else if(nums[i] == pivot){
                equal++;
            }
        }
        for(int i=0; i<equal; i++) {
            ans[ptr] = pivot;
            ptr++;
        }
        for(int i=0; i<n; i++){
            if(nums[i] > pivot){
                ans[ptr] = nums[i];
                ptr++;
            }
        }
        return ans;
    }
};