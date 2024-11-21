class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 1));
        for(auto &wall: walls){
            grid[wall[0]][wall[1]] = 2;
        }

        for(auto &guard: guards){
            grid[guard[0]][guard[1]] = 2;
        }
        
        for(auto &guard: guards){
            int i=guard[0];
            int j=guard[1];
            //right
            int k =1;
            while(j+k < n) {
                if(grid[i][j+k] != 2){
                    grid[i][j+k] = 0;
                    k++;
                }
                else break;
            }
            //left
            k=1;
            while(j-k >= 0) {
                if(grid[i][j-k] != 2){
                    grid[i][j-k] = 0;
                    k++;
                }
                else break;
            }
            //up
            k=1;
            while(i-k >= 0) {
                if(grid[i-k][j] != 2){
                    grid[i-k][j] = 0;
                    k++;
                }
                else break;
            }
            //down
            k=1;
            while(i+k < m) {
                if(grid[i+k][j] != 2){
                    grid[i+k][j] = 0;
                    k++;
                }
                else break;
            }
        }
        int ans=0;
        for(auto i: grid){
            for(int j: i){
                if(j == 1)ans++;
                cout<<j<<" ";
            }
            cout<<endl;
        }
        
        return ans;
    }
};