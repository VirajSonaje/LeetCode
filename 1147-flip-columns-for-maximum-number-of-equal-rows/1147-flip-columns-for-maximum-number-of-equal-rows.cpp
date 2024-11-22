class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> counts;

        for(auto row : matrix){
            string pattern = "";
            string compli = "";
            for(int col: row){
                pattern += to_string(col);
                compli += col == 0 ? to_string(1) : to_string(0);
            }
            counts[pattern]++;
            counts[compli]++;
        }

        int ans =0;

        for(auto patterns: counts){
            ans = max(ans, patterns.second);
        }

        return ans;
    }
};