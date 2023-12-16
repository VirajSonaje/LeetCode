class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> last;
        for(auto inter: intervals){
            if(ans.size()== 0) ans.push_back(inter);
            else{
                last = ans.back();
                if(last[1] >= inter[0]){
                    ans.pop_back();
                    if(last[1] < inter[1]) ans.push_back({last[0], inter[1]});
                    else ans.push_back({last[0], last[1]});
                }
                else ans.push_back(inter); 
            }
        }
        return ans;
    }
};