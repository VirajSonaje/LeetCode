class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;
        vector<vector<int>> ans(2, vector<int>());
        for(int i=0; i<matches.size(); i++){
            if(!mp[matches[i][0]]) mp[matches[i][0]] = 0;
            mp[matches[i][1]]++;
        }

        for(auto team: mp){
            if(team.second == 0) ans[0].push_back(team.first);
            else if(team.second == 1) ans[1].push_back(team.first);
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};