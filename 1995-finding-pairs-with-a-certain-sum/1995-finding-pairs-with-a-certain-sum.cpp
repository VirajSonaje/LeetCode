class FindSumPairs {
private:
    unordered_map<int, int> num2vals;
    vector<int> nums1, nums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        for(int i: nums2) num2vals[i]++;

        this->nums1 = nums1;
        this->nums2 = nums2;
    }
    
    void add(int index, int val) {
        num2vals[nums2[index]]--;
        nums2[index]+=val;
        num2vals[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans =0;
        for(int i: nums1){
            if(i >= tot) break;
            ans+=num2vals[tot - i];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */