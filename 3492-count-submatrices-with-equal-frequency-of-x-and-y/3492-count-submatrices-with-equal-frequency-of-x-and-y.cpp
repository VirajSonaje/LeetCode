class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans =0;
        vector<vector<int>> x(m, vector<int>(n, 0));
        vector<vector<int>> y(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 'X') x[i][j] = 1;
                if(grid[i][j] == 'Y') y[i][j] = 1;
                if(i > 0){
                  x[i][j] += x[i-1][j];
                  y[i][j] += y[i-1][j];  
                } 
                if(j > 0){
                  x[i][j] += x[i][j-1];
                  y[i][j] += y[i][j-1];
                }
                if(i>0 && j>0){
                    x[i][j] -= x[i-1][j-1];
                    y[i][j] -= y[i-1][j-1];
                }
                
                if((x[i][j] == y[i][j]) && x[i][j]>0) ans++;
            }
        } 
        
        
        return ans;
    }
};