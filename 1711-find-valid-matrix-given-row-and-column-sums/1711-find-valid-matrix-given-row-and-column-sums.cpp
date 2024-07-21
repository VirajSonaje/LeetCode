class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
       int numRows = rowSum.size();
        int numCols = colSum.size();
        vector<vector<int>> result(numRows, vector<int>(numCols, 0));

        int i = 0, j = 0;

        while (i < numRows && j < numCols) {
            int val = min(rowSum[i], colSum[j]);
            result[i][j] = val;
            rowSum[i] -= val;
            colSum[j] -= val;

            if (rowSum[i] == 0) {
                i++;
            }
            if (colSum[j] == 0) {
                j++;
            }
        }
        return result; 
    }

    //   4            7
    // 3 min(4, 3)   min(7, 0)
    // 8 min(1, 8)   min(7, 8)

};