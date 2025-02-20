class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string s = "";
        int n = nums.size();
        for(int i =0; i<n; i++){
            if(nums[i][i] == '1') s+='0';
            else s+='1';
        }

        return s;
    }
};