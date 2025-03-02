class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int ptr0 =0;
        int ptr1 =0;
        vector<vector<int>> ans;
        while(ptr0 < nums1.size() && ptr1 < nums2.size()){
            if(nums1[ptr0][0] < nums2[ptr1][0]){
                ans.push_back(nums1[ptr0]);
                ptr0++;
            }
            else if(nums1[ptr0][0] > nums2[ptr1][0]){
                ans.push_back(nums2[ptr1]);
                ptr1++;
            }
            else{
                ans.push_back({nums2[ptr1][0], nums1[ptr0][1]+nums2[ptr1][1]});
                ptr1++;
                ptr0++;
            }
        }

        while(ptr0 < nums1.size()){
            ans.push_back(nums1[ptr0]);
            ptr0++;
        }
        while(ptr1 < nums2.size()){
            ans.push_back(nums2[ptr1]);
            ptr1++;
        }

        return ans;
    }
};