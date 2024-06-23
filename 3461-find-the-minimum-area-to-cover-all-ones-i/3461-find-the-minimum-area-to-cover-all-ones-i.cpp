class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minRow = INT_MAX, maxRow =-1;
        int minCol = INT_MAX, maxCol =-1;
        int r = grid.size(), c = grid[0].size();

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]){
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }
        return (maxRow - minRow+1) * (maxCol - minCol+1);
    }
};