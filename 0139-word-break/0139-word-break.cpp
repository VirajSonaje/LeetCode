class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dic;
        vector<bool> dp(s.length()+1, 0);
        for(string a: wordDict) dic.insert(a);

        dp[0] = 1;
        for(int i=0; i<s.length(); i++){
            if(dp[i]){
                for(int j=i; j<=s.length(); j++){
                    if(dic.count(s.substr(i, j-i))) dp[j] = 1;
                }
                if(dp[s.length()]) return 1;
            }
        }
        return dp[s.length()];
    }
};