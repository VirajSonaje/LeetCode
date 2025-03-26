class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> values;

        for(int i=0; i<grid.size(); i++){
            for(int j: grid[i]){
                values.push_back(j);
            }
        }
        sort(values.begin(), values.end());
        for(int val: values){
            if(abs(val-values[0]) %x != 0) return -1;
        }

        int median = values[values.size() /2];
        int ans =0;

        for(int val: values){
            ans+= abs(val - median)/x;
        }

        return ans;
    }
};