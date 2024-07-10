class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> seq = {};

        helper(ans, 0, k, n, seq);

        return ans;
    }

    void helper(vector<vector<int>> &ans, int i, int k , int n, vector<int> &seq){
        if(n < 0) return;
        if(n == 0 && k == 0) {
            ans.push_back(seq);
            return;
        }
        for(int s = i+1; s<10; s++){
            seq.push_back(s);
            helper(ans, s, k-1, n-s, seq);
            seq.pop_back();
        }

    }
};