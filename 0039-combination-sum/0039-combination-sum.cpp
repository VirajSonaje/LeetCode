class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> sans;
        sort(candidates.begin(), candidates.end());
        vector<int> seq;
        combine(target, candidates, 0, seq, 0, sans);

        vector<vector<int>> ans;
        for(auto v: sans){
            ans.push_back(v);
        }

        return ans;
    }

    void combine(int target, vector<int> &candidates, 
    int idx, vector<int> &seq, int sum, set<vector<int>> &sans){
        if(sum == target) {
            sans.insert(seq);
            return;
        }
        
        if(sum<target){
            seq.push_back(candidates[idx]);
            combine(target, candidates, idx, seq, sum+candidates[idx], sans);
            seq.pop_back();
            for(int i= idx+1; i<candidates.size(); i++){
                seq.push_back(candidates[i]);
                combine(target, candidates, i, seq, sum+candidates[i], sans);
                seq.pop_back();
            }
        }
        // if(idx+1 < candidates.size() && candidates[idx+1] <= target){
        //     vector<int> ss;
        //     ss.push_back(candidates[idx+1]);
        //     combine(target, candidates, idx+1, ss, candidates[idx+1], sans);
        // }
        
    }
};