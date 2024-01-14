class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> s;

        for(int i: nums){
            if(s.find(i) != s.end()) continue;
            s.insert(i);
            set<int>::iterator a = s.upper_bound(i);
            if(a != s.end()) s.erase(a);
        }
        return s.size();
    }
};