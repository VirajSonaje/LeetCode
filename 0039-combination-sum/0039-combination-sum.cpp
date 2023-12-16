class Solution {
public:
    int target;
    void sol(int sum , int ind, vector<int> candidates, vector<int> combination, vector<vector<int>> &ans){
        cout<<sum<<" "<<ind<<endl;
        if(ind==candidates.size()){
            if(sum == target){
            ans.push_back(combination);
            return;
            }
            return;
        }
        if(sum == target){
            ans.push_back(combination);
            return;
        }
        else if(sum < target){
            sol(sum, ind+1, candidates, combination, ans);
            if(target >= sum+candidates[ind]){
                combination.push_back(candidates[ind]);
                sol(sum+candidates[ind], ind, candidates, combination, ans);
            }
            
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;
        vector<vector<int>> ans;
        vector<int> combination;

        sol(0, 0, candidates, combination, ans);

        return ans;
    }
};