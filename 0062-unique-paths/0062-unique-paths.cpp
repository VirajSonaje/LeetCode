class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i-1 < 0 || j-1< 0){
                    dp[i][j] = 1;
                    // cout<<dp[i][j]<<" ";
                }
                else {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                    // cout<<dp[i][j]<<" ";
                }
            }
            // cout<<"\n";
        }
        
        return dp[m-1][n-1];
    }
};