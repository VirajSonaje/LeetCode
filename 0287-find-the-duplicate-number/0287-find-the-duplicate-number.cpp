class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=0, slow =0;
        while (true){
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow) break;
        }
        fast =0;
        while (true){
            fast = nums[fast];
            slow = nums[slow];
            if(fast == slow) return slow;
        }
        return 0;
    }
};