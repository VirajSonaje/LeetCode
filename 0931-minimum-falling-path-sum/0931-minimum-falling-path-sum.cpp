class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // int ans = INT_MAX;
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int taken = matrix[i-1][j];
                if(j-1 >= 0) taken = min(taken, matrix[i-1][j-1]);
                if(j+1 <= n-1)taken = min(taken, matrix[i-1][j+1]);

                matrix[i][j] +=taken;
            }
        }
        
        return *min_element(matrix[n-1].begin(), matrix[n-1].end());

        // for(int i=0; i<n; i++){
        //     ans = min(ans, getMinfor(matrix, 0, i));
        // }

        // return ans;
    }

    ///FOR RECURSIVE WITHOUT DP
    // int getMinfor(vector<vector<int>> &matrix, int row, int col){
    //     int n = matrix.size();
    //     if(row == n-1) return matrix[row][col];
    //     int r = INT_MAX, m = INT_MAX , l=INT_MAX;

    //     if(col-1 >= 0) l = getMinfor(matrix, row+1, col-1);
    //     m = getMinfor(matrix, row+1, col);
    //     if(col+1 <= n-1) r = getMinfor(matrix, row+1, col+1);

    //     return matrix[row][col] + min(l, min(m, r));
    //     // m = min(matrix[row+1][col-1 >= 0 ? col-1 : col], matrix)    

    // }

};