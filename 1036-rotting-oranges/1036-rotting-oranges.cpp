class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans =0;
        vector<vector<int>> dirs = {{0,1}, {1, 0}, {0, -1}, {-1,0}};
        queue<vector<int>> que;
        int m = grid.size();
        int n = grid[0].size();
        int freshCount = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    que.push({i, j});
                }
                if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }

        if(freshCount == 0) return 0;

        while(!que.empty()){
            bool flag = false;
            int size = que.size();
            for(int i=0; i<size; i++){
                auto el = que.front();
                for(auto d: dirs){
                    int a = d[0] + el[0];
                    int b = d[1] + el[1];
                    if(a >= 0 && a < m && b >= 0 && b < n){
                        if(grid[a][b] == 1){
                            que.push({a, b});
                            grid[a][b] = 2;
                            freshCount--;
                            flag = true;
                        }
                    }
                }
                que.pop();
            }
            if(flag) ans++;
        }
        cout<<freshCount << " " << ans;
        return (freshCount == 0) ? ans : -1;
    }
};