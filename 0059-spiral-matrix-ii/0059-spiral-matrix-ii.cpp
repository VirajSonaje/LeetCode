class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> grid(n, vector<int> (n, 0));
        int left =0, top =0;
        int right = n-1;
        int bottom = n-1;
        int num =1;
        while(top<=bottom && left<=right){
            for(int i=left; i<=right; i++)grid[top][i] = num++;
            top++;

            for(int i=top; i<=bottom; i++)grid[i][right] = num++;
            right--;

            if(top <=bottom){
                for(int i=right; i>=left; i--)grid[bottom][i] = num++;
                bottom--;
            }
            
            if(left <= right){
                for(int i=bottom; i>=top; i--)grid[i][left] = num++;
                left++;
            }
        }
        return grid;
    }
};