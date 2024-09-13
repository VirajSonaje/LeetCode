class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n);
        vector<int> ans;
        int xorval = 0;
        for(int i=0; i<n; i++){
            xorval ^= arr[i];
            prefix[i] = xorval;
        }

        for(auto q: queries){
            if(q[0] == 0) ans.push_back(prefix[q[1]] ^ 0);
            else ans.push_back(prefix[q[1]] ^ prefix[q[0]-1]);
        }
        return ans;
    }
};