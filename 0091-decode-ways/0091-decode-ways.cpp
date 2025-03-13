class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);

        if(s[0] == '0') return 0;
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n;i++){
            int dw = stoi(s.substr(i-2, 2));
            int single = stoi(s.substr(i-1,1));
            if(single >0) dp[i]+=dp[i-1];
            if(dw <= 26 && s[i-1] != 0){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};