class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> chars(26,0);
        int ans=0;
        for(int i=0; i<s.length(); i++){
            chars[s[i]-'a']++;
            chars[t[i]-'a']--;
        } 
        
        for(int i: chars) ans+=abs(i);
        return ans/2;

    }
};