class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0; 
        map<char, int> m;
        int i=0, j=0, ans = -1;
        for(j=0; j< s.length(); j++){
            m[s[j]]++;
            if(m.size() == j-i+1){
                ans = max(ans, j-i+1);
            }
            else if(m.size() < j-i+1){
                while(m.size() < j-i+1){
                    m[s[i]]--;
                    if(m[s[i]]== 0) m.erase(s[i]);
                    i++;
                }

            }
        }
        return ans;
    }
};