class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        int p2 = 0, p3 = 0, p5 = 0;
        dp[0] = 1;
        for(int i=1; i<n; i++){
            int mul2 = dp[p2]*2;
            int mul3 = dp[p3]*3;
            int mul5 = dp[p5]*5;

            dp[i] = min(mul2, min(mul3, mul5));
            if(dp[i] == mul2)p2++;
            if(dp[i] == mul3)p3++;
            if(dp[i] == mul5)p5++;
        }

        return dp[n-1];
    }
};