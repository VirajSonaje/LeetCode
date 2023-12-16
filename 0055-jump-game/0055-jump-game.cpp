class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = nums.size()-1;
        int step = 1;
        for(int i=nums.size()-2; i>=0 ; i--){
            if(nums[i] >= step){
                pos = i;
                step = 1;
            }
            else{
                step++;
            }
        }
        if(pos == 0) return true;
        return false;
    }
};