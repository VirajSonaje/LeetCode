class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        vector<int> smap(26, 0), s2map(26, 0);
        if(n > s2.length()) return false;
        for(char c: s1) smap[c-'a']++;
        for(int i=0; i<n; i++) s2map[s2[i]-'a']++;
        int l=0, r=n;
        while(r < s2.length()){
            if(smap == s2map) return true;
            else{
                s2map[s2[r]-'a']++;
                s2map[s2[l]-'a']--;
                r++;
                l++;
            }
        }
        if(smap == s2map) return true;
        return false;
    }
};