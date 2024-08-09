class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m-2; i++){
            for(int j=0; j<n-2; j++){
                if(isMagicSquare(grid, i, j)) ans++;
            }
        }

        return ans;
    }

    bool isMagicSquare(vector<vector<int>> &grid, int r, int c){
        vector<int> sums(8, 0);
        set<int> numbers;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(numbers.find(grid[r+i][c+j]) != numbers.end() 
                || grid[r+i][c+j] > 9 || grid[r+i][c+j] < 1) return false; 
                numbers.insert(grid[r+i][c+j]);
                sums[i] += grid[r+i][c+j];
                sums[3+j] += grid[r+i][c+j];
                if(i==j) sums[6]+= grid[r+i][c+j];
                if(2-i == j) sums[7]+= grid[r+i][c+j];
            }
        }

        for(int i=0; i<7; i++)
        if(sums[i] != sums[i+1]) return false;

        return true;
    }
};