class Solution {
public:
    int maxDifference(string s) {
        int maxodd =0, mineven = s.length() +1;
        unordered_map<char, int> mp;

        for(char c: s)mp[c]++;
        for(auto m: mp){
            if(m.second % 2) maxodd = max(maxodd, m.second);
            else mineven = min(mineven, m.second);
        }
        if(mineven == s.length() +1) return maxodd;
        return maxodd - mineven;
    }
};