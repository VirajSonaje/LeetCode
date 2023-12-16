class Solution {
public:
    int climbStairs(int n) {
        int ans = 1;
        int temp =1;
        if(n==1) return 1;
        for(int i=2; i<=n;i++){
            int dum = ans;
            ans += temp;
            temp = dum;
        }
        return ans;
    }
};