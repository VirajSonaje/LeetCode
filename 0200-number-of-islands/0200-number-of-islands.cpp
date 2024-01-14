class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int ans=0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i=0; i< m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    DFS(grid, i, j, visited);
                    ans++;
                }
                
            }
        }
        
        return ans;
    }
    
    void DFS(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited){
        
                visited[i][j] = true;
        
                if(i < grid.size()-1)    
                if(!visited[i+1][j] && grid[i+1][j] == '1') DFS(grid, i+1, j, visited);
                
                if(j < grid[0].size()-1)
                if(!visited[i][j+1] && grid[i][j+1] == '1') DFS(grid, i, j+1, visited);
                
                if(i>0)
                if(!visited[i-1][j] && grid[i-1][j] == '1') DFS(grid, i-1, j, visited);
                
                if( j>0)
                if(!visited[i][j-1] && grid[i][j-1] == '1') DFS(grid, i, j-1, visited);
        
    }
};