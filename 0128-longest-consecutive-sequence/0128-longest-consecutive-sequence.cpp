class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i: nums) s.insert(i);
        int l =0, t =1;
        for(int i:nums)    
            if(s.count(i-1) == 0){
                t=1;
                while(s.count(i+t)) t++ ;
                l= max(l, t); 
            }
        
        return l;
    }
};