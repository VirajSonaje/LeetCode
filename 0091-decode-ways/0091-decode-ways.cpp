class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length()+1, 0);
        int n = s.length();
        if(s[0]=='0') return 0;
        dp[0] = 1;

        //if(n ==1) return dp[0];

        dp[1] = 1;
        for(int i = 2; i<=n; i++){
            if(s[i-1]>='1' && s[i-1] <= '9'){
                dp[i] += dp[i-1];
            }
            string a = s.substr(i-2,2);
            if(stoi(a) <= 26 &&  stoi(a) >= 10){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};