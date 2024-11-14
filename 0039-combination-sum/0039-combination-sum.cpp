class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> sans;
        vector<int> temp;
        combine(sans, candidates, target, 0, 0, temp);

        vector<vector<int>> ans; 
        for(vector<int> v: sans){
            ans.push_back(v);
        }
        return ans;

    }

    void combine(set<vector<int>> &ans, vector<int> &candidates, int &target, 
    int idx, int sum, vector<int> &arr){
        if(sum > target) return;
        if(sum == target) ans.insert(arr);
        // cout<<idx<<" "<<candidates.size()<<endl;
        arr.push_back(candidates[idx]);
        sum+=candidates[idx];
        combine(ans, candidates, target, idx, sum, arr);
        if(idx < candidates.size()-1)
        combine(ans, candidates, target, idx+1, sum, arr);
        sum-=candidates[idx];
        arr.pop_back();
        if(idx < candidates.size()-1)
        combine(ans, candidates, target, idx+1, sum, arr);
    }
};